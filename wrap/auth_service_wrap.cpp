#pragma once
#include "auth_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::IAuthService* InitIAuthServiceFunc(ZOOM_SDK_NAMESPACE::IAuthServiceEvent* pEvent)
{
	ZOOM_SDK_NAMESPACE::IAuthService* pObj(NULL);
	CSDKImpl::GetInst().CreateAuthService(&pObj);
	if (pObj)
	{
		pObj->SetEvent(pEvent);
	}
	return pObj;
}

void UninitIAuthServiceFunc(ZOOM_SDK_NAMESPACE::IAuthService* obj)
{
	CSDKImpl::GetInst().DestroyAuthService(obj);
}
	//IMPL_FUNC_1(IAuthService, SetEvent, SDKError, IAuthServiceEvent*, pEvent, SDKERR_UNINITIALIZE)
	IMPL_FUNC_1(IAuthService, SDKAuth, SDKError, AuthContext&, authContext, SDKERR_UNINITIALIZE)
	IMPL_FUNC_0(IAuthService, GetAuthResult, AuthResult, AUTHRET_NONE)
	IMPL_FUNC_0(IAuthService, GetSDKIdentity, const wchar_t*, NULL)
	IMPL_FUNC_1(IAuthService, GenerateSSOLoginWebURL, const wchar_t*, const wchar_t*, prefix_of_vanity_url, NULL)
	IMPL_FUNC_1(IAuthService, SSOLoginWithWebUriProtocol, SDKError, const wchar_t*, uri_protocol, SDKERR_UNINITIALIZE)
	IMPL_FUNC_0(IAuthService, LogOut, SDKError, SDKERR_UNINITIALIZE)
	IMPL_FUNC_0(IAuthService, GetAccountInfo, IAccountInfo*, NULL)
	IMPL_FUNC_0(IAuthService, GetLoginStatus, LOGINSTATUS, LOGIN_IDLE)

#if (defined UserInterfaceClass)
	//virtual IDirectShareServiceHelper* GetDirectShareServiceHeler() = 0;
	IMPL_FUNC_0(IAuthService, GetDirectShareServiceHeler, IDirectShareServiceHelper*, NULL)
#endif
	IMPL_FUNC_AND_MEMBER(IAuthService, T_GetDirectShareServiceHeler, IDirectShareServiceHelperWrap)

END_ZOOM_SDK_NAMESPACE
