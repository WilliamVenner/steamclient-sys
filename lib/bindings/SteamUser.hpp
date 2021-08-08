#pragma once

class CSteamID {
public:
	long long m_unAll64Bits;
};

class SteamUser {
public:
	virtual void GetHSteamUser(void) = 0;
	virtual void LogOn(CSteamID) = 0;
	virtual void LogOnWithPassword(char const*, char const*) = 0;
	virtual void LogOnAndCreateNewSteamAccountIfNeeded(void) = 0;
	virtual void VerifyOfflineLogon(void) = 0;
	virtual void LogOff(void) = 0;
	virtual int BLoggedOn(void) = 0;
	virtual int GetLogonState(void) = 0;
	virtual int BConnected(void) = 0;
	virtual void BTryingToLogin(void) = 0;
	virtual CSteamID GetSteamID(void) = 0;
	virtual void GetConsoleSteamID(void) = 0;
	virtual void GetClientInstanceID(void) = 0;
	virtual void IsVACBanned(unsigned int) = 0;
	virtual void SetEmail(char const*) = 0;
	virtual void SetConfigString(int, char const*, char const*) = 0;
	virtual void GetConfigString(int, char const*, char *, int) = 0;
	virtual void SetConfigInt(int, char const*, int) = 0;
	virtual void GetConfigInt(int, char const*, int *) = 0;
	virtual void SetConfigBinaryBlob(int, char const*, int *) = 0;
	virtual void GetConfigBinaryBlob(int, char const*, int *) = 0;
	virtual void DeleteConfigKey(int, char const*) = 0;
	virtual void GetConfigStoreKeyName(int, char const*, char *, int) = 0;
	virtual void InitiateGameConnection(void *, int, CSteamID, int, unsigned int, unsigned short, bool) = 0;
	virtual void InitiateGameConnectionOld(void *, int, CSteamID, int, unsigned int, unsigned short, bool, void *, int) = 0;
	virtual void TerminateGameConnection(unsigned int, unsigned short) = 0;
	virtual void SignalAppsToShutDown(int) = 0;
	virtual void TerminateAppMultiStep(int, unsigned int) = 0;
	virtual void SetSelfAsChatDestination(bool) = 0;
	virtual void IsPrimaryChatDestination(void) = 0;
	virtual void RequestLegacyCDKey(unsigned int) = 0;
	virtual void AckGuestPass(char const*) = 0;
	virtual void RedeemGuestPass(char const*) = 0;
	virtual void GetGuestPassToGiveCount(void) = 0;
	virtual void GetGuestPassToRedeemCount(void) = 0;
	virtual void GetGuestPassToGiveInfo(unsigned int, unsigned long long *, unsigned int *, unsigned int *, unsigned int *, unsigned int *, unsigned int *, char *, int) = 0;
	virtual void GetGuestPassToGiveOut(unsigned int) = 0;
	virtual void GetGuestPassToRedeem(unsigned int) = 0;
	virtual void GetGuestPassToRedeemInfo(unsigned int, unsigned long long *, unsigned int *, unsigned int *, unsigned int *, unsigned int *, unsigned int *) = 0;
	virtual void GetGuestPassToRedeemSenderName(unsigned int, char *, int) = 0;
	virtual void GetNumAppsInGuestPassesToRedeem(void) = 0;
	virtual void GetAppsInGuestPassesToRedeem(unsigned int *, unsigned int) = 0;
	virtual void GetCountUserNotifications(void) = 0;
	virtual void GetCountUserNotification(int) = 0;
	virtual void RequestStoreAuthURL(char const*) = 0;
	virtual void SetLanguage(char const*) = 0;
	virtual void TrackAppUsageEvent(int, int, char const*) = 0;
	virtual void RaiseConnectionPriority(int, int) = 0;
	virtual void ResetConnectionPriority(int) = 0;
	virtual bool BHasCachedCredentials(char const*) = 0;
	virtual int SetAccountNameForCachedCredentialLogin(char const*, bool) = 0;
	virtual void DestroyCachedCredentials(char const*) = 0;
	virtual void GetCurrentWebAuthToken(char *, int, char *, int) = 0;
	virtual void RequestWebAuthToken(void) = 0;
	virtual void SetLoginInformation(char const*, char const*, bool) = 0;
	virtual void SetTwoFactorCode(char const*) = 0;
	virtual void ClearAllLoginInformation(void) = 0;
	virtual void BEnableEmbeddedClient(unsigned int) = 0;
	virtual void ResetEmbeddedClient(unsigned int) = 0;
	virtual void BHasEmbeddedClientToken(unsigned int) = 0;
	virtual void RequestEmbeddedClientToken(unsigned int) = 0;
	virtual void AuthorizeNewDevice(unsigned int, unsigned int, char const*) = 0;
	virtual void GetLanguage(char *, int) = 0;
	virtual void BIsCyberCafe(void) = 0;
	virtual void BIsAcademicAccount(void) = 0;
	virtual void BIsPortal2EducationAccount(void) = 0;
	virtual void BIsAlienwareDemoAccount(void) = 0;
	virtual void TrackNatTraversalStat(int const*) = 0;
	virtual void TrackSteamUsageEvent(int, unsigned char const*, unsigned int) = 0;
	virtual void TrackSteamGUIUsage(char const*) = 0;
	virtual void SetComputerInUse(void) = 0;
	virtual void BIsGameRunning(int) = 0;
	virtual void BIsGameWindowReady(int) = 0;
	virtual void BUpdateAppOwnershipTicket(unsigned int, bool) = 0;
	virtual void RequestCustomBinary(char const*, unsigned int, bool, bool) = 0;
	virtual void GetCustomBinariesState(unsigned int, long long *, long long *) = 0;
	virtual void RequestCustomBinaries(unsigned int, bool, bool, unsigned int *) = 0;
	virtual void SetCellID(unsigned int) = 0;
	virtual void GetUserBaseFolder(void) = 0;
	virtual void GetUserDataFolder(int, char *, int) = 0;
	virtual void GetUserConfigFolder(char *, int) = 0;
	virtual void GetAccountName(char *, unsigned int) = 0;
	virtual void GetAccountName(CSteamID, char *, unsigned int) = 0;
	virtual void IsPasswordRemembered(void) = 0;
	virtual void CheckoutSiteLicenseSeat(unsigned int) = 0;
	virtual void GetAvailableSeats(unsigned int) = 0;
	virtual void GetAssociatedSiteName(void) = 0;
	virtual void BIsRunningInCafe(void) = 0;
	virtual void BAllowCachedCredentialsInCafe(void) = 0;
	virtual void RequiresLegacyCDKey(unsigned int, bool *) = 0;
	virtual void GetLegacyCDKey(unsigned int, char *, int) = 0;
	virtual void SetLegacyCDKey(unsigned int, char const*) = 0;
	virtual void WriteLegacyCDKey(unsigned int) = 0;
	virtual void RemoveLegacyCDKey(unsigned int) = 0;
	virtual void RequestLegacyCDKeyFromApp(unsigned int, unsigned int, unsigned int) = 0;
	virtual void BIsAnyGameRunning(void) = 0;
	virtual void GetSteamGuardDetails(void) = 0;
	virtual void GetTwoFactorDetails(void) = 0;
	virtual void BHasTwoFactor(void) = 0;
	virtual void GetEmail(char *, int, bool *) = 0;
	virtual void FindAccountsByCdKey(char const*) = 0;
	virtual void Test_FakeConnectionTimeout(void) = 0;
	virtual void RunInstallScript(unsigned int, char const*, bool) = 0;
	virtual void IsInstallScriptRunning(void) = 0;
	virtual void GetInstallScriptState(char *, unsigned int, unsigned int *, unsigned int *) = 0;
	virtual void SpawnProcess(char const*, char const*, unsigned int, char const*, int, char const*, unsigned int, unsigned int, unsigned int) = 0;
	virtual void GetAppOwnershipTicketLength(unsigned int) = 0;
	virtual void GetAppOwnershipTicketData(unsigned int, void *, unsigned int) = 0;
	virtual void GetAppOwnershipTicketExtendedData(unsigned int, void *, unsigned int, unsigned int *, unsigned int *, unsigned int *, unsigned int *) = 0;
	virtual void GetMarketingMessageCount(void) = 0;
	virtual void GetMarketingMessage(int, unsigned long long *, char *, int, void *) = 0;
	virtual void GetAuthSessionTicket(void *, int, unsigned int *) = 0;
	virtual void BeginAuthSession(void const*, int, CSteamID) = 0;
	virtual void EndAuthSession(CSteamID) = 0;
	virtual void CancelAuthTicket(unsigned int) = 0;
	virtual void IsUserSubscribedAppInTicket(CSteamID, unsigned int) = 0;
	virtual void GetAuthSessionTicketForGameID(void *, int, unsigned int *, int) = 0;
	virtual void AdvertiseGame(int, CSteamID, unsigned int, unsigned short) = 0;
	virtual void RequestEncryptedAppTicket(void *, int) = 0;
	virtual void GetEncryptedAppTicket(void *, int, unsigned int *) = 0;
	virtual void GetGameBadgeLevel(int, bool) = 0;
	virtual void GetPlayerSteamLevel(void) = 0;
	virtual void SetAccountLimited(bool) = 0;
	virtual void BIsAccountLimited(void) = 0;
	virtual void SetAccountCommunityBanned(bool) = 0;
	virtual void BIsAccountCommunityBanned(void) = 0;
	virtual void SetLimitedAccountCanInviteFriends(bool) = 0;
	virtual void BLimitedAccountCanInviteFriends(void) = 0;
	virtual void SendValidationEmail(void) = 0;
	virtual void BGameConnectTokensAvailable(void) = 0;
	virtual void NumGamesRunning(void) = 0;
	virtual void GetRunningGameID(int) = 0;
	virtual void GetRunningGamePID(int) = 0;
	virtual void RaiseWindowForGame(int) = 0;
	virtual void GetAccountSecurityPolicyFlags(void) = 0;
	virtual void SetClientStat(int, long long, unsigned int, unsigned int, unsigned int) = 0;
	virtual void VerifyPassword(char const*) = 0;
	virtual void BSupportUser(void) = 0;
	virtual void BNeedsSSANextSteamLogon(void) = 0;
	virtual void ClearNeedsSSANextSteamLogon(void) = 0;
	virtual void BIsAppOverlayEnabled(int) = 0;
	virtual void BOverlayIgnoreChildProcesses(int) = 0;
	virtual void BIsBehindNAT(void) = 0;
	virtual void GetMicroTxnAppID(unsigned long long) = 0;
	virtual void GetMicroTxnOrderID(unsigned long long) = 0;
	virtual void BGetMicroTxnPrice(unsigned long long, int *, int *, bool *, int *) = 0;
	virtual void GetMicroTxnLineItemCount(unsigned long long) = 0;
	virtual void BGetMicroTxnLineItem(unsigned long long, unsigned int, int *, unsigned int *, char *, unsigned int, int *, unsigned char *, int *, bool *) = 0;
	virtual void BIsSandboxMicroTxn(unsigned long long, bool *) = 0;
	virtual void BMicroTxnRequiresCachedPmtMethod(unsigned long long, bool *) = 0;
	virtual void AuthorizeMicroTxn(unsigned long long, int) = 0;
	virtual void BGetWalletBalance(bool *, int *, int *) = 0;
	virtual void RequestMicroTxnInfo(unsigned long long) = 0;
	virtual void BMicroTxnRefundable(unsigned long long) = 0;
	virtual void BGetAppMinutesPlayed(unsigned int, int *, int *) = 0;
	virtual void GetAppLastPlayedTime(unsigned int) = 0;
	virtual void GetAppUpdateDisabledSecondsRemaining(unsigned int) = 0;
	virtual void BGetGuideURL(unsigned int, char *, unsigned int) = 0;
	virtual void BPromptToVerifyEmail(void) = 0;
	virtual void BPromptToChangePassword(void) = 0;
	virtual void BAccountExtraSecurity(void) = 0;
	virtual void BAccountShouldShowLockUI(void) = 0;
	virtual void GetCountAuthedComputers(void) = 0;
	virtual void BSteamGuardNewMachineNotification(void) = 0;
	virtual void GetSteamGuardEnabledTime(void) = 0;
	virtual void GetSteamGuardHistoryEntry(int, unsigned int *, unsigned int *, bool *, char *, int, char *, int) = 0;
	virtual void SetSteamGuardNewMachineDialogResponse(bool, bool) = 0;
	virtual void SetPhoneIsVerified(bool) = 0;
	virtual void BIsPhoneVerified(void) = 0;
	virtual void SetPhoneIsIdentifying(bool) = 0;
	virtual void BIsPhoneIdentifying(void) = 0;
	virtual void SetPhoneIsRequiringVerification(bool) = 0;
	virtual void BIsPhoneRequiringVerification(void) = 0;
	virtual void ChangeTwoFactorAuthOptions(int) = 0;
	virtual void Set2ndFactorAuthCode(char const*, bool) = 0;
	virtual void SetUserMachineName(char const*) = 0;
	virtual void GetUserMachineName(char *, int) = 0;
	virtual void GetEmailDomainFromLogonFailure(char *, int) = 0;
	virtual void GetDurationControl(void) = 0;
	virtual void GetDurationControlForApp(unsigned int) = 0;
	virtual void BSetDurationControlOnlineState(int) = 0;
	virtual void BSetDurationControlOnlineStateForApp(int, unsigned int) = 0;
	virtual void BIsSubscribedApp(unsigned int) = 0;
	virtual void GetSubscribedApps(unsigned int *, unsigned int, bool) = 0;
	virtual void RegisterActivationCode(char const*) = 0;
	virtual void AckSystemIM(unsigned long long) = 0;
	virtual void RequestSpecialSurvey(unsigned int) = 0;
	virtual void SendSpecialSurveyResponse(unsigned int, unsigned char const*, unsigned int) = 0;
	virtual void RequestNotifications(void) = 0;
	virtual void GetAppOwnershipInfo(unsigned int, unsigned int *, unsigned int *, char *) = 0;
	virtual void SendGameWebCallback(unsigned int, char const*) = 0;
	virtual void BIsStreamingUIToRemoteDevice(void) = 0;
	virtual void BIsCurrentlyNVStreaming(void) = 0;
	virtual void OnBigPictureForStreamingStartResult(bool, void *) = 0;
	virtual void OnBigPictureForStreamingDone(void) = 0;
	virtual void OnBigPictureForStreamingRestarting(void) = 0;
	virtual void StopStreaming(unsigned int) = 0;
	virtual void LockParentalLock(void) = 0;
	virtual void UnlockParentalLock(char const*) = 0;
	virtual void BIsParentalLockEnabled(void) = 0;
	virtual void BIsParentalLockLocked(void) = 0;
	virtual void BlockApp(unsigned int) = 0;
	virtual void UnblockApp(unsigned int) = 0;
	virtual void BIsAppBlocked(unsigned int) = 0;
	virtual void BIsAppInBlockList(unsigned int) = 0;
	virtual void BlockFeature(int) = 0;
	virtual void UnblockFeature(int) = 0;
	virtual void BIsFeatureBlocked(int) = 0;
	virtual void BIsFeatureInBlockList(int) = 0;
	virtual void GetParentalUnlockTime(void) = 0;
	virtual void BGetRecoveryEmail(char *, int) = 0;
	virtual void RequestParentalRecoveryEmail(void) = 0;
	virtual void BIsLockFromSiteLicense(void) = 0;
	virtual void BGetSerializedParentalSettings(int *) = 0;
	virtual void BSetParentalSettings(int *) = 0;
	virtual void BDisableParentalSettings(void) = 0;
	virtual void BGetParentalWebToken(int *, int *) = 0;
	virtual void GetCommunityPreference(int) = 0;
	virtual void SetCommunityPreference(int, bool) = 0;
	virtual void BCanLogonOfflineMode(void) = 0;
	virtual void LogOnOfflineMode(void) = 0;
	virtual void ValidateOfflineLogonTicket(char const*) = 0;
	virtual void BGetOfflineLogonTicket(char const*, int *) = 0;
	virtual void UploadLocalClientLogs(void) = 0;
	virtual void SetAsyncNotificationEnabled(unsigned int, bool) = 0;
	virtual void BIsOtherSessionPlaying(unsigned int *) = 0;
	virtual void BKickOtherPlayingSession(void) = 0;
	virtual void BIsAccountLockedDown(void) = 0;
	virtual void ClearAndSetAppTags(int, int const*) = 0;
	virtual void RemoveAppTag(int, char const*) = 0;
	virtual void AddAppTag(int, char const*) = 0;
	virtual void ClearAppTags(int) = 0;
	virtual void SetAppHidden(int, bool) = 0;
	virtual void RequestAccountLinkInfo(void) = 0;
	virtual void RequestSurveySchedule(void) = 0;
	virtual void RequestNewSteamAnnouncementState(void) = 0;
	virtual void UpdateSteamAnnouncementLastRead(unsigned long long, unsigned int) = 0;
	virtual void GetMarketEligibility(void) = 0;
	virtual void UpdateGameVrDllState(int, bool, bool) = 0;
	virtual void BIsAnyGameOrServiceAppRunning(void) = 0;
	virtual void BGetAppArrayMinutesPlayed(unsigned int *, int, int *, int *) = 0;
	virtual void BGetAppsLastPlayedTime(unsigned int *, int, unsigned int *) = 0;
	virtual void SendSteamServiceStatusUpdate(int, int) = 0;
	virtual void RequestSteamGroupChatMessageNotifications(unsigned long long, unsigned long long, int) = 0;
	virtual void RequestSteamGroupChatMessageHistory(unsigned long long, unsigned long long, unsigned int) = 0;
	virtual void RequestSendSteamGroupChatMessage(unsigned long long, unsigned long long, unsigned int, char const*) = 0;
	virtual void OnNewGroupChatMsgAdded(unsigned long long, unsigned long long, unsigned int, unsigned int, unsigned int, char const*) = 0;
	virtual void OnGroupChatUserStateChange(unsigned long long, unsigned int, int) = 0;
	virtual void OnReceivedGroupChatSubscriptionResponse(unsigned long long, unsigned long long, bool) = 0;
	virtual void GetTimedTrialStatus(unsigned int, unsigned int *, unsigned int *) = 0;
	virtual void RequestTimedTrialStatus(unsigned int) = 0;
};