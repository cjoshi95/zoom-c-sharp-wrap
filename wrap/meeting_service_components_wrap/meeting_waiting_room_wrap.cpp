#include "meeting_waiting_room_wrap.h"
#include "meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingWaitingRoomController* InitIMeetingWaitingRoomControllerFunc(IMeetingWaitingRoomEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingWaitingRoomController* pObj = pOwner->GetSDKObj()->GetMeetingWaitingRoomController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingWaitingRoomControllerFunc(IMeetingWaitingRoomController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual bool IsSupportWaitingRoom() = 0;
IMPL_FUNC_0(IMeetingWaitingRoomController, IsSupportWaitingRoom, bool, false)
//virtual bool IsWaitingRoomOnEntryFlagOn() = 0;
IMPL_FUNC_0(IMeetingWaitingRoomController, IsWaitingRoomOnEntryFlagOn, bool, false)
//virtual SDKError EnableWaitingRoomOnEntry(bool bEnable) = 0;
IMPL_FUNC_1(IMeetingWaitingRoomController, EnableWaitingRoomOnEntry, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual IList<unsigned int >* GetWaitingRoomLst() = 0;
IMPL_FUNC_0(IMeetingWaitingRoomController, GetWaitingRoomLst, IList<unsigned int >*, NULL)
//virtual IUserInfo* GetWaitingRoomUserInfoByID(unsigned int userid) = 0;
IMPL_FUNC_1(IMeetingWaitingRoomController, GetWaitingRoomUserInfoByID, IUserInfo*, unsigned int, userid, NULL)
//virtual SDKError AdmitToMeeting(unsigned int userid) = 0;
IMPL_FUNC_1(IMeetingWaitingRoomController, AdmitToMeeting, SDKError, unsigned int, userid, SDKERR_UNINITIALIZE)
//virtual SDKError AdmitAllToMeeting() = 0;
IMPL_FUNC_0(IMeetingWaitingRoomController, AdmitAllToMeeting, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError PutInWaitingRoom(unsigned int userid) = 0;
IMPL_FUNC_1(IMeetingWaitingRoomController, PutInWaitingRoom, SDKError, unsigned int, userid, SDKERR_UNINITIALIZE)
//virtual bool IsAudioEnabledInWaitingRoom() = 0;
IMPL_FUNC_0(IMeetingWaitingRoomController, IsAudioEnabledInWaitingRoom, bool, false)
//virtual bool IsVideoEnabledInWaitingRoom() = 0;
IMPL_FUNC_0(IMeetingWaitingRoomController, IsVideoEnabledInWaitingRoom, bool, false)
//virtual SDKError RequestCustomWaitingRoomData() = 0;
IMPL_FUNC_0(IMeetingWaitingRoomController, RequestCustomWaitingRoomData, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError CanRenameUser(bool& bIsCan) = 0;
IMPL_FUNC_1(IMeetingWaitingRoomController, CanRenameUser, SDKError, bool&, bIsCan, SDKERR_UNINITIALIZE)
//virtual SDKError RenameUser(unsigned userid, const zchar_t* newName) = 0;
IMPL_FUNC_2(IMeetingWaitingRoomController, RenameUser, SDKError, unsigned, userid, const zchar_t*, newName, SDKERR_UNINITIALIZE)
//virtual SDKError CanExpelUser(bool& bIsCan) = 0;
IMPL_FUNC_1(IMeetingWaitingRoomController, CanExpelUser, SDKError, bool&, bIsCan, SDKERR_UNINITIALIZE)
//virtual SDKError ExpelUser(unsigned int userid) = 0;
IMPL_FUNC_1(IMeetingWaitingRoomController, ExpelUser, SDKError, unsigned int, userid, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE