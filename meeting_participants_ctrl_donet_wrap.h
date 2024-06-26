#pragma once
using namespace System;
using namespace System::Windows;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	public delegate void onUserJoin(array<unsigned int >^ lstUserID);
	public delegate void onUserLeft(array<unsigned int >^ lstUserID);
	public delegate void onHostChangeNotification(unsigned int userId);
	public delegate void onCoHostChangeNotification(unsigned int userId, bool isCoHost);
	public delegate void onLowOrRaiseHandStatusChanged(bool bLow, unsigned int userid);
	public delegate void onUserNamesChanged(array<unsigned int >^ lstUserID);

	public interface class IMeetingParticipantsControllerDotNetWrap
	{
	public:
		array<unsigned int >^ GetParticipantsList();
		IUserInfoDotNetWrap^ GetUserByUserID(unsigned int userId);
		SDKError LowerAllHands(bool forWebinarAttendees);
		SDKError ChangeUserName(const unsigned int userId, String^ userName, bool bSaveUserName);
		SDKError LowerHand(unsigned int userId);
		SDKError RaiseHand();
		SDKError MakeHost(unsigned int userId);
		SDKError ExpelUser(unsigned int userId);
		SDKError ReclaimHost();
		SDKError CanReclaimHost(bool^% bCanReclaimHost);
		SDKError ReclaimHostByHostKey(String^ host_key);
		SDKError CanBeCoHost(unsigned int userId);
		SDKError AssignCoHost(unsigned int userId);
		SDKError RevokeCoHost(unsigned int userId);

		void Add_CB_onUserJoin(onUserJoin^ cb);
		void Add_CB_onUserLeft(onUserLeft^ cb);
		void Add_CB_onHostChangeNotification(onHostChangeNotification^ cb);
		void Add_CB_onCoHostChangeNotification(onCoHostChangeNotification^ cb);
		void Add_CB_onLowOrRaiseHandStatusChanged(onLowOrRaiseHandStatusChanged^ cb);
		void Add_CB_onUserNamesChanged(onUserNamesChanged^ cb);
		void Remove_CB_onUserJoin(onUserJoin^ cb);
		void Remove_CB_onUserLeft(onUserLeft^ cb);
		void Remove_CB_onHostChangeNotification(onHostChangeNotification^ cb);
		void Remove_CB_onLowOrRaiseHandStatusChanged(onLowOrRaiseHandStatusChanged^ cb);
		void Remove_CB_onUserNamesChanged(onUserNamesChanged^ cb);
	};

	private ref class CMeetingParticipantsControllerDotNetWrap sealed : public IMeetingParticipantsControllerDotNetWrap
	{
	public:
		static property CMeetingParticipantsControllerDotNetWrap^ Instance
		{
			CMeetingParticipantsControllerDotNetWrap^ get() { return m_Instance; }
		}

		void BindEvent();
		void procUserJoin(array<unsigned int >^ lstUserID);
		void procUserLeft(array<unsigned int >^ lstUserID);
		void procHostChangeNotification(unsigned int userId);
		void procCoHostChangeNotification(unsigned int userId, bool isCoHost);
		void procLowOrRaiseHandStatusChanged(bool lower, unsigned int userId);
		void procUserNamesChanged(array<unsigned int >^ lstUserID);
		virtual array<unsigned int >^ GetParticipantsList();
		virtual IUserInfoDotNetWrap^ GetUserByUserID(unsigned int userId);
		virtual SDKError LowerAllHands(bool forWebinarAttendees);
		virtual SDKError ChangeUserName(const unsigned int userId, String^ userName, bool saveUserName);
		virtual SDKError LowerHand(unsigned int userId);
		virtual SDKError RaiseHand();
		virtual SDKError MakeHost(unsigned int userId);
		virtual SDKError ExpelUser(unsigned int userId);
		virtual SDKError ReclaimHost();
		virtual SDKError CanReclaimHost(bool^% canReclaimHost);
		virtual SDKError ReclaimHostByHostKey(String^ hostKey);
		virtual SDKError CanBeCoHost(unsigned int userId);
		virtual SDKError AssignCoHost(unsigned int userId);
		virtual SDKError RevokeCoHost(unsigned int userId);

		virtual void Add_CB_onUserJoin(onUserJoin^ cb)
		{
			event_onUserJoin += cb;
		}

		virtual void Remove_CB_onUserJoin(onUserJoin^ cb)
		{
			event_onUserJoin -= cb;
		}

		virtual void Add_CB_onUserLeft(onUserLeft^ cb)
		{
			event_onUserLeft += cb;
		}

		virtual void Remove_CB_onUserLeft(onUserLeft^ cb)
		{
			event_onUserLeft -= cb;
		}

		virtual void Add_CB_onHostChangeNotification(onHostChangeNotification^ cb)
		{
			event_onHostChangeNotification += cb;
		}

		virtual void Remove_CB_onHostChangeNotification(onHostChangeNotification^ cb)
		{
			event_onHostChangeNotification -= cb;
		}

		virtual void Add_CB_onCoHostChangeNotification(onCoHostChangeNotification^ cb) {
			event_onCoHostChangeNotification += cb;
		}

		virtual void Remove_CB_onCoHostChangeNotification(onCoHostChangeNotification^ cb) {
			event_onCoHostChangeNotification -= cb;
		}

		virtual void Add_CB_onLowOrRaiseHandStatusChanged(onLowOrRaiseHandStatusChanged^ cb)
		{
			event_onLowOrRaiseHandStatusChanged += cb;
		}

		virtual void Remove_CB_onLowOrRaiseHandStatusChanged(onLowOrRaiseHandStatusChanged^ cb)
		{
			event_onLowOrRaiseHandStatusChanged -= cb;
		}

		virtual void Add_CB_onUserNamesChanged(onUserNamesChanged^ cb)
		{
			event_onUserNamesChanged += cb;
		}

		virtual void Remove_CB_onUserNamesChanged(onUserNamesChanged^ cb)
		{
			event_onUserNamesChanged -= cb;
		}

	private:
		event onUserJoin^ event_onUserJoin;
		event onUserLeft^ event_onUserLeft;
		event onHostChangeNotification^ event_onHostChangeNotification;
		event onCoHostChangeNotification^ event_onCoHostChangeNotification;
		event onLowOrRaiseHandStatusChanged^ event_onLowOrRaiseHandStatusChanged;
		event onUserNamesChanged^ event_onUserNamesChanged;
		static CMeetingParticipantsControllerDotNetWrap^ m_Instance = gcnew CMeetingParticipantsControllerDotNetWrap;
	};
}