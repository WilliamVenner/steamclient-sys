#pragma once

class IEngine {
public:
	virtual int CreateSteamPipe(int*) = 0;
	virtual int BReleaseSteamPipe(int) = 0;
	virtual int CreateGlobalUser(int *) = 0;
	virtual int ConnectToGlobalUser(int) = 0;
	virtual int CreateLocalUser(int *, int) = 0;
	virtual int CreatePipeToLocalUser(int, int *) = 0;
	virtual int ReleaseUser(int, int) = 0;
	virtual int IsValidHSteamUserPipe(int, int) = 0;
	virtual void* GetIClientUser(int, int) = 0;
	virtual int GetIClientGameServer(int, int) = 0;
	virtual int SetLocalIPBinding(unsigned int, unsigned short) = 0;
	virtual int GetUniverseName(int) = 0;
	virtual int GetIClientFriends(int, int) = 0;
	virtual void* GetIClientUtils(int) = 0;
	virtual int GetIClientBilling(int, int) = 0;
	virtual int GetIClientMatchmaking(int, int) = 0;
	virtual int GetIClientApps(int, int) = 0;
	virtual int GetIClientMatchmakingServers(int, int) = 0;
	virtual int GetIClientGameSearch(int, int) = 0;
	virtual int RunFrame(void) = 0;
	virtual int GetIPCCallCount(void) = 0;
	virtual int GetIClientUserStats(int, int) = 0;
	virtual int GetIClientGameServerStats(int, int) = 0;
	virtual int GetIClientNetworking(int, int) = 0;
	virtual void* GetIClientRemoteStorage(int, int) = 0;
	virtual void GetIClientScreenshots(int, int) = 0;
	virtual void SetWarningMessageHook(void*) = 0;
	virtual void GetIClientGameCoordinator(int, int) = 0;
	virtual void SetOverlayNotificationPosition(int) = 0;
	virtual void SetOverlayNotificationInset(int, int) = 0;
	virtual void HookScreenshots(bool) = 0;
	virtual void IsScreenshotsHooked(void) = 0;
	virtual void IsOverlayEnabled(void) = 0;
	virtual void GetAPICallResult(int, unsigned long long, void *, int, int, bool *) = 0;
	virtual void GetIClientProductBuilder(int, int) = 0;
	virtual void GetIClientDepotBuilder(int, int) = 0;
	virtual void GetIClientNetworkDeviceManager(int) = 0;
	virtual void ConCommandInit(void*) = 0;
	virtual void GetIClientAppManager(int, int) = 0;
	virtual void GetIClientConfigStore(int, int) = 0;
	virtual void BOverlayNeedsPresent(void) = 0;
	virtual void GetIClientGameStats(int, int) = 0;
	virtual void GetIClientHTTP(int, int) = 0;
	virtual void FlushBeforeValidate(void) = 0;
	virtual void BShutdownIfAllPipesClosed(void) = 0;
	virtual void GetIClientAudio(int, int) = 0;
	virtual void GetIClientMusic(int, int) = 0;
	virtual void GetIClientUnifiedMessages(int, int) = 0;
	virtual void GetIClientController(int) = 0;
	virtual void GetIClientParentalSettings(int, int) = 0;
	virtual void GetIClientStreamLauncher(int, int) = 0;
	virtual void GetIClientDeviceAuth(int, int) = 0;
	virtual void GetIClientRemoteClientManager(int) = 0;
	virtual void GetIClientStreamClient(int, int) = 0;
	virtual void GetIClientShortcuts(int, int) = 0;
	virtual void* GetIClientUGC(int, int) = 0;
	virtual void GetIClientInventory(int, int) = 0;
	virtual void GetIClientVR(int) = 0;
	virtual void GetIClientGameNotifications(int, int) = 0;
	virtual void GetIClientHTMLSurface(int, int) = 0;
	virtual void GetIClientVideo(int, int) = 0;
	virtual void GetIClientControllerSerialized(int) = 0;
	virtual void GetIClientAppDisableUpdate(int, int) = 0;
	virtual void Set_Client_API_CCheckCallbackRegisteredInProcess(unsigned int (*)(int)) = 0;
	virtual void GetIClientBluetoothManager(int) = 0;
	virtual void GetIClientSharedConnection(int, int) = 0;
	virtual void GetIClientShader(int, int) = 0;
	virtual void GetIClientNetworkingSocketsSerialized(int, int) = 0;
	virtual void GetIClientCompat(int, int) = 0;
	virtual void SetClientCommandLine(int, char **) = 0;
	virtual void GetIClientParties(int, int) = 0;
	virtual void GetIClientNetworkingMessages(int, int) = 0;
	virtual void GetIClientNetworkingSockets(int, int) = 0;
	virtual void GetIClientNetworkingUtils(int) = 0;
	virtual void GetIClientNetworkingUtilsSerialized(int) = 0;
	virtual void GetIClientSTARInternal(int, int) = 0;
	virtual void GetIClientRemotePlay(int, int) = 0;
};