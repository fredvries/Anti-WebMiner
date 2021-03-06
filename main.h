//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <pngimage.hpp>
#include <GIFImg.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------

class TSSLThread : public TThread
{
private:
   String FURL;

protected:
		void __fastcall TSSLThread::Execute();
public:
  __fastcall TSSLThread::TSSLThread(bool CreateSuspended, String URL);

   String FResult;
   int iResult;

};

class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TTimer *timUpdate;
	TPopupMenu *pmnLang;
	TMenuItem *constHostsfilepathfoundpathFatalError;
	TMenuItem *constHosstCannotRead;
	TMenuItem *constSystemError;
	TMainMenu *MainMenu;
	TMenuItem *F1;
	TMenuItem *V1;
	TMenuItem *mnRefresh;
	TMenuItem *mnCheckupdate;
	TMenuItem *mnDisplayLog;
	TMenuItem *N1;
	TMenuItem *mnUninstall;
	TMenuItem *N2;
	TMenuItem *mnExit;
	TMenuItem *H1;
	TMenuItem *mnVisitHomePage;
	TPanel *pnlTop;
	TImage *imgIcon;
	TLabel *lblHeader;
	TLabel *lblSubHeader;
	TMenuItem *constInstall;
	TMenuItem *constUninstall;
	TMenuItem *constInstallUpdate;
	TPanel *pnlStatus;
	TLabel *lblStatus;
	TImage *imgStatus;
	TPanel *pnlImages;
	TImage *imgInfo;
	TImage *imgPreloader;
	TImage *imgOK;
	TMenuItem *constYourcomputerisprotected;
	TMenuItem *constDatabaseversion;
	TMenuItem *constInstallationdate;
	TButton *btUpdate;
	TMenuItem *constClickInstalltosetprotection;
	TMenuItem *constClickInstallUpdatetoupdateprotection;
	TMenuItem *constLocalblacklistdoesnotexist;
	TMenuItem *constCheckingforupdates;
	TButton *btMoreInfo;
	TMenuItem *constNewdatabaseversion;
	TTimer *timProgramCheckUpdate;
	TMenuItem *constCheckingforprogramsupdates;
	TMenuItem *constFoundnewversion;
	TButton *btDownload;
	TMenuItem *constClickDownload;
	TImage *imgDownload;
	TImage *imgError;
	TLabel *lblCopyright;
	TButton *btLicense;
	TMenuItem *ShowWindowsHostsFile1;
	TBitBtn *btInstall;
	TBitBtn *btUninstall;
	TPanel *pnlProtected;
	TImage *Image1;
	TLabel *Label1;
	TMenuItem *N3;
	TMenuItem *CreateReadytoUseHosts1;
	TMenuItem *N4;
	void __fastcall timUpdateTimer(TObject *Sender);
	void __fastcall mnExitClick(TObject *Sender);
	void __fastcall mnUninstallClick(TObject *Sender);
	void __fastcall mnCheckupdateClick(TObject *Sender);
	void __fastcall mnRefreshClick(TObject *Sender);
	void __fastcall mnDisplayLogClick(TObject *Sender);
	void __fastcall mnVisitHomePageClick(TObject *Sender);
	void __fastcall imgIconClick(TObject *Sender);
	void __fastcall btUninstallClick(TObject *Sender);
	void __fastcall btInstallClick(TObject *Sender);
	void __fastcall imgPreloaderClick(TObject *Sender);
	void __fastcall timProgramCheckUpdateTimer(TObject *Sender);
	void __fastcall btDownloadClick(TObject *Sender);
	void __fastcall btLicenseClick(TObject *Sender);
	void __fastcall lblCopyrightClick(TObject *Sender);
	void __fastcall ShowWindowsHostsFile1Click(TObject *Sender);
	void __fastcall CreateReadytoUseHosts1Click(TObject *Sender);
private:	// User declarations

		  TStringList *strHosts;
		  String sHostsPath;
		  String sLocalBlackListVersion;
		  String sRemoteBlackListVersion;
		  String sHostsBlackListVersion;

		  String sRemoteProgramVersion;
		  int iInstallDate; // date of install into Hosts

		  String sCriticalError;

		  TSSLThread *FThread;
		  bool bNeedUpdateHosts;

		  bool bCheckProgramUpdate;

		  String __fastcall TfrmMain::sExpandEnvStrings(String sSource);
		  String __fastcall TfrmMain::sGetHostsPath();
		  String __fastcall TfrmMain::AddLastSlash(String sSource);

		  // Manipulating with Hosts file
		  bool __fastcall TfrmMain::ReadHostsFile(String sFilePath, TStringList *strOut);
		  bool __fastcall TfrmMain::SaveHostsFile(); // saved from strHosts
		  bool __fastcall TfrmMain::BackupHostsFile(bool bOverWritePrevious);

		  bool __fastcall TfrmMain::InstallIntoHosts();
		  bool __fastcall TfrmMain::UninstallFromHosts();
		  bool __fastcall TfrmMain::IsInstalledIntoHosts();

		  // Works with strHosts
		  int __fastcall TfrmMain::sGetOurStartPosInHosts();
		  int __fastcall TfrmMain::sGetOurFinalPosInHosts(int iStart);

		  String __fastcall TfrmMain::sGetOurVersionFromHosts(int iStartRow, int &iOutInstallDate);
		  bool __fastcall TfrmMain::RemoveOurStringsFromHostsStrings(int iStart, int iFinish);

		  bool __fastcall TfrmMain::AddTostrHosts(TStringList *strIn);
		  // end of strHosts functions

		  bool __fastcall TfrmMain::ReadRawStringsFromIniFile(String FileName, String Section, TStringList *strOut);

		   // Black List functions
		  String __fastcall TfrmMain::sGetBlackListFilePath();
		  String __fastcall TfrmMain::ReadBlackListFile(String sFile, TStringList *strOut);
		  String __fastcall TfrmMain::sGetBlackListVersion(String sFile);

		  bool __fastcall TfrmMain::IsLocalVersUptodate(String RemoteVers, String LocalVers);
		  // Program/Database Updating
		  void __fastcall TfrmMain::CheckUpdates(); //Async version
		  void __fastcall TfrmMain::ThreadDone(TObject *Sender);  // Func aftrer finishing thread

		  bool  __fastcall TfrmMain::CheckUpdatesSynchronous(int iWhatUpdate); // Sync version

		  bool  __fastcall TfrmMain::ProgramUpdateShowStatus(String sMemIniFile);
		  bool  __fastcall TfrmMain::BlackListUpdateShowStatus(String sMemIniFile);

		  String __fastcall TfrmMain::sGetDBVersionFromStrings(TStringList *str);
		  bool __fastcall TfrmMain::UpdateLocalBlackListFromRemote(String sRemoteText);

		  String __fastcall TfrmMain::sGetVersionFromMemoryIni(String sRemoteText);


		  // UI functions
		   // Main router
		  void __fastcall TfrmMain::DisplayStatus(int iStatus);

		  // refresh functon
		  bool __fastcall TfrmMain::ReadMainStatus();

		  // display preloader icon
		  void __fastcall TfrmMain::DisplayPreloader(bool bSet);
		  void __fastcall TfrmMain::ShowProtectButton(bool bShow);



public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
	__fastcall TfrmMain::~TfrmMain();

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------

int __fastcall GetInternetRequest(String sURL, String &sOutResult);
void __fastcall WriteLogMessage(AnsiString sText);

#define MAIN_LABEL  String("Anti-WebMiner")
#define START_LABEL MAIN_LABEL+String(" Start")
#define FIN_LABEL MAIN_LABEL+String(" End")

#define BLACKLIST_DB String("blacklist.txt")

#define URL_BLACKLIST String("https://raw.githubusercontent.com/greatis/Anti-WebMiner/master/blacklist.txt")
#define URL_PROGRAM_VERSION String("https://raw.githubusercontent.com/greatis/Anti-WebMiner/master/AntiWebMiner.ini")

#define DISP_ALL_DONE      0
#define DISP_INSTALL_TO_HOSTS  1
#define DISP_FOUND_UPDATES      2
#define DISP_NO_BLACKLIST      3
#define DISP_CHECK_UPDATE      4
#define DISP_CHECK_PROGRAM_UPDATE      6
#define DISP_FOUND_PROGRAM_UPDATES         76

#define DISP_FATAL_ERROR      -1

#define MAIN_VERS String("1.1.0.2")


#define CHECK_UPD_BLACKLIST 1
#define CHECK_UPD_PROGRAM  2
#define CHECK_UPD_ALL      3
#endif
