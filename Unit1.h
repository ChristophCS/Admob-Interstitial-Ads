
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <System.Types.hpp>
#include <System.UITypes.hpp>
#include <System.Classes.hpp>
#include <System.Variants.hpp>
#include <Androidapi.JNIBridge.hpp>
#include <Androidapi.JNI.Embarcadero.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.StdCtrls.hpp>
#include <Androidapi.JNI.AdMob.hpp>
#include <Androidapi.JNI.JavaTypes.hpp>
#include <FMX.Advertising.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <System.Generics.Collections.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.ImageList.hpp>
#include <FMX.Effects.hpp>
#include <System.Actions.hpp>
#include <System.Rtti.hpp>
#include <FMX.ImgList.hpp>
//---------------------------------------------------------------------------

class TForm1;
class TMyAdViewListener;




class TMyAdViewListener: public TJavaLocal, public JIAdListener {
  typedef TJavaLocal inherited;
  friend class TForm2;
  private:
  _di_JInterstitialAd  FAD;
  public:
  __fastcall TMyAdViewListener(_di_JInterstitialAd FAD);
	virtual void __cdecl onAdClosed(void);
	virtual void __cdecl onAdFailedToLoad(int errorCode);
	virtual void __cdecl onAdLeftApplication(void);
	virtual void __cdecl onAdOpened(void);
	virtual void __cdecl onAdLoaded(void);
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void ** ppvObject) {return S_OK;};
	virtual ULONG   STDMETHODCALLTYPE AddRef(){return 1;};
	virtual ULONG   STDMETHODCALLTYPE Release(){return 1;};
  public:
	/* TJavaLocal.Destroy */ inline __fastcall virtual ~TMyAdViewListener(void) {};

private:
	void *__JIAdListener;	// Androidapi::Jni::Embarcadero::JIAdListener

public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {8E46C3D5-1846-458C-9FA4-EFC3DDCA705F}
	operator Androidapi::Jni::Embarcadero::_di_JIAdListener()
	{
		Androidapi::Jni::Embarcadero::_di_JIAdListener intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Androidapi::Jni::Embarcadero::JIAdListener*(void) { return (Androidapi::Jni::Embarcadero::JIAdListener*)&__JIAdListener; }
	#endif
};

class TForm1 : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
    TButton *Button1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:	// Benutzer-Deklarationen
   TMyAdViewListener * LAdViewListener;
  _di_JInterstitialAd FInterStitial;
public:		// Benutzer-Deklarationen
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// Benutzer-Deklarationen
public:		// Benutzer-Deklarationen
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

