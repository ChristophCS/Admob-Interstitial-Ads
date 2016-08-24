//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"

#include <FMX.Platform.Android.hpp>
#include <Androidapi.Helpers.hpp>
#include <FMX.Helpers.Android.hpp>
#include <Androidapi.JNI.PlayServices.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   FInterStitial = TJInterstitialAd::JavaClass->init(MainActivity());
   FInterStitial->setAdUnitId(StringToJString("ca-app-pub-9940854835711080/9251925222"));
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{

  _di_JAdRequest_Builder LADRequestBuilder;
  _di_JAdRequest LadRequest;

  LADRequestBuilder = TJAdRequest_Builder::Create();
  LADRequestBuilder->addTestDevice(MainActivity()->getDeviceID());
  LadRequest = LADRequestBuilder->build();

  LAdViewListener = new TMyAdViewListener(FInterStitial);


  FInterStitial->setAdListener(TJAdListenerAdapter::JavaClass->init(LAdViewListener));
  FInterStitial->loadAd(LadRequest);

}
//---------------------------------------------------------------------------

__fastcall TMyAdViewListener::TMyAdViewListener(_di_JInterstitialAd AAD)
{
FAD = AAD;
}


void __cdecl TMyAdViewListener::onAdClosed()
{
//
}


void __cdecl TMyAdViewListener::onAdFailedToLoad(int errorCode)
{
ShowMessage("test");
}


void __cdecl TMyAdViewListener::onAdLeftApplication()
{
//
}


void __cdecl TMyAdViewListener::onAdLoaded()
{
FAD->show();
}


void __cdecl TMyAdViewListener::onAdOpened()
{
//
}
