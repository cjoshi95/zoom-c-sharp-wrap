#include "stdafx.h"
#include "auth_service_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
#include "wrap/sdk_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	//translate account info
	private ref class IAccountInfoImpl sealed : public IAccountInfo
	{
	public:
		IAccountInfoImpl()
		{
			m_pCPlusObject = NULL;
		}

		IAccountInfoImpl(ZOOM_SDK_NAMESPACE::IAccountInfo* pInfo)
		{
			m_pCPlusObject = pInfo;
		}

		virtual String^ GetDisplayName()
		{
			if (m_pCPlusObject)
				return WChar2PlatformString(m_pCPlusObject->GetDisplayName());

			return nullptr;
		}

		virtual LoginType GetLoginType()
		{
			if (m_pCPlusObject)
				return (LoginType)m_pCPlusObject->GetLoginType();

			return LoginType::LoginType_Unknown;
		}
	private:
		ZOOM_SDK_NAMESPACE::IAccountInfo* m_pCPlusObject;
	};

	IAccountInfo^ TranslateAccountInfo(ZOOM_SDK_NAMESPACE::IAccountInfo* pInfo)
	{
		//to do
		if (pInfo)
		{
			return gcnew IAccountInfoImpl(pInfo);
		}
		return nullptr;
	}
	//

	//Translate event
	class AuthEventHanlder
	{
	public:
		static AuthEventHanlder& GetInst()
		{
			static AuthEventHanlder inst;
			return inst;
		}

		void onAuthenticationReturn(ZOOM_SDK_NAMESPACE::AuthResult ret)
		{
			if (ZOOM_SDK_NAMESPACE::AUTHRET_SUCCESS == ret)
			{
				ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().Init();
				ZOOM_SDK_NAMESPACE::ISettingServiceWrap& settingWrap = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap();
				ZOOM_SDK_NAMESPACE::IVideoSettingContextWrap& videosettingwrap = settingWrap.GetVideoSettings();
				videosettingwrap.Init(&settingWrap);
				
				ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& meetingWrap = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap();
				meetingWrap.Init();

				ZOOM_SDK_NAMESPACE::IMeetingConfigurationWrap& config = meetingWrap.GetMeetingConfiguration();
				config.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingUIControllerWrap& uiCtrl = meetingWrap.GetUIController();
				uiCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IAnnotationControllerWrap& annoCtrl = meetingWrap.GetAnnotationController();
				annoCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingVideoControllerWrap& videoCtrl = meetingWrap.GetMeetingVideoController();
				videoCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingRemoteControllerWrap& remoteCtrl = meetingWrap.GetMeetingRemoteController();
				remoteCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingShareControllerWrap& shareCtrl = meetingWrap.GetMeetingShareController();
				shareCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingAudioControllerWrap& autioCtrl = meetingWrap.GetMeetingAudioController();
				autioCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingRecordingControllerWrap& recCtrl = meetingWrap.GetMeetingRecordingController();
				recCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingChatControllerWrap& chatCtrl = meetingWrap.GetMeetingChatController();
				chatCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingWaitingRoomControllerWrap& waitingroomCtrl = meetingWrap.GetMeetingWaitingRoomController();
				waitingroomCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingH323HelperWrap& h323Ctrl = meetingWrap.GetH323Helper();
				h323Ctrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingPhoneHelperWrap& phoneCtrl = meetingWrap.GetMeetingPhoneHelper();
				phoneCtrl.Init(&meetingWrap);
				ZOOM_SDK_NAMESPACE::IMeetingParticipantsControllerWrap& participantsCtrl = meetingWrap.GetMeetingParticipantsController();
				participantsCtrl.Init(&meetingWrap);
			}
	
			//post msg

			CAuthServiceDotNetWrap::Instance->ProcAuthenticationReturn((AuthResult)ret);
		}

		void onLoginRet(ZOOM_SDK_NAMESPACE::LOGINSTATUS ret, ZOOM_SDK_NAMESPACE::IAccountInfo* pAccountInfo, ZOOM_SDK_NAMESPACE::LoginFailReason reason)
		{
			//post msg
			CAuthServiceDotNetWrap::Instance->ProcLoginRet((LOGINSTATUS)ret, TranslateAccountInfo(pAccountInfo), (LOGINFAILREASON)reason);
		}

		void onLogout()
		{
			//post msg
			CAuthServiceDotNetWrap::Instance->ProcLogout();
		}

		void onZoomIdentityExpired()
		{
			CAuthServiceDotNetWrap::Instance->ProcZoomIdentityExpired();
		}
	private:
		AuthEventHanlder() {}
	};

	
	//
	CAuthServiceDotNetWrap::CAuthServiceDotNetWrap()
	{
	}

	CAuthServiceDotNetWrap::~CAuthServiceDotNetWrap()
	{
	}

	SDKError CAuthServiceDotNetWrap::SDKAuth(AuthContext authParam)
	{
		ZOOM_SDK_NAMESPACE::AuthContext param_;
		param_.jwt_token = PlatformString2WChar(authParam.jwt_token);

		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().SDKAuth(param_);
	}

	AuthResult CAuthServiceDotNetWrap::GetAuthResult()
	{
		return (AuthResult)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().GetAuthResult();
	}

	String^ CAuthServiceDotNetWrap::GetSDKIdentity()
	{
		return WChar2PlatformString(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().GetSDKIdentity());
	}

	SDKError CAuthServiceDotNetWrap::LogOut()
	{
		return (SDKError)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().LogOut();
	}

	IAccountInfo^ CAuthServiceDotNetWrap::GetAccountInfo()
	{
		return TranslateAccountInfo(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().GetAccountInfo());
	}

	LOGINSTATUS CAuthServiceDotNetWrap::GetLoginStatus()
	{
		return (LOGINSTATUS)ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().GetLoginStatus();
	}

	String^ CAuthServiceDotNetWrap::getWebinalLegalNoticesPrompt()
	{
		return WChar2PlatformString(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingWebinarController().getWebinarLegalNoticesPrompt());
	}

	bool CAuthServiceDotNetWrap::getAnnotationLegalNoticesExplained(WebinarLegalNoticesExplainedInfo^% info_)
	{
		if (nullptr == info_)
			return false;
		ZOOM_SDK_NAMESPACE::WebinarLegalNoticesExplainedInfo notice_info;
		bool bRet = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingWebinarController().getWebinarLegalNoticesExplained(notice_info);
		if (bRet)
		{
			info_->explained_content = WChar2PlatformString(notice_info.explained_content);
			info_->url_register_account_owner = WChar2PlatformString(notice_info.url_register_account_owner);
			info_->url_register_privacy_policy = WChar2PlatformString(notice_info.url_register_account_owner);
			info_->url_register_terms = WChar2PlatformString(notice_info.url_register_terms);
		}
		return bRet;
	}
	////handle event
	void CAuthServiceDotNetWrap::ProcAuthenticationReturn(AuthResult ret)
	{
		event_onAuthenticationReturn(ret);
	}

	void CAuthServiceDotNetWrap::ProcLoginRet(LOGINSTATUS ret, IAccountInfo^ pAccountInfo, LOGINFAILREASON reason)
	{
		event_onLoginRet(ret, pAccountInfo, reason);
	}

	void CAuthServiceDotNetWrap::ProcLogout()
	{
		event_onLogout();
	}

	void CAuthServiceDotNetWrap::ProcZoomIdentityExpired()
	{
		event_onZoomIdentityExpired();
	}

	void CAuthServiceDotNetWrap::BindEvent()
	{
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().m_cbonAuthenticationReturn =
			std::bind(&AuthEventHanlder::onAuthenticationReturn, &AuthEventHanlder::GetInst(), std::placeholders::_1);
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().m_cbonLoginReturnWithReason =
			std::bind(&AuthEventHanlder::onLoginRet, &AuthEventHanlder::GetInst(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().m_cbonLogout =
			std::bind(&AuthEventHanlder::onLogout, &AuthEventHanlder::GetInst());
		ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().m_cbonZoomIdentityExpired =
			std::bind(&AuthEventHanlder::onZoomIdentityExpired, &AuthEventHanlder::GetInst());
	}
}