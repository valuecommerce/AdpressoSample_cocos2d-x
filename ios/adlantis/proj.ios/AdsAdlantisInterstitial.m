//
//  AdsAdlantisInterstitial.m
//  PluginAdlantis
//
//  Created on 6/2/14.
//  Copyright (c) 2014 Atlantis Inc. All rights reserved.
//

#import "AdsAdlantisInterstitial.h"
#import "AdsWrapper.h"
#import "AdpressoInterstitialAd.h"

@interface AdsAdlantisInterstitial () <AdlantisInterstitialAdDelegate>

@property (strong, nonatomic) AdpressoInterstitialAd *interstitialAd;

@end

@implementation AdsAdlantisInterstitial

- (void)configDeveloperInfo:(NSMutableDictionary*) devInfo
{
  OUTPUT_LOG(@"configDeveloperInfo");
  self.strPublisherID = (NSString*) [devInfo objectForKey:kAdlantisPublisherIdKey];
  OUTPUT_LOG(@"set publisherid to :%@", self.strPublisherID);
}

- (void)showAds:(NSMutableDictionary*)info position:(int) pos
{
  OUTPUT_LOG(@"show adlantis ads");
  
  if (self.strPublisherID == nil ||
      [self.strPublisherID length] == 0) {
    OUTPUT_LOG(@"configDeveloperInfo() not correctly invoked in Adlantis!");
    return;
  }
  
  [self showInterstitial];
}

- (void)showInterstitial
{
  if (nil != self.interstitialAd) {
    [self.interstitialAd cancel];
    self.interstitialAd = nil;
  }
  
  self.interstitialAd = [AdpressoInterstitialAd interstitialAdWithPublisherId:self.strPublisherID];
  self.interstitialAd.delegate = self;
  [self.interstitialAd show];
}

- (void)hideAds:(NSMutableDictionary*)info
{
  if (nil != self.interstitialAd) {
    [self.interstitialAd cancel];
    self.interstitialAd = nil;
  }
}

#pragma mark AdlantisInterstitialAdDelegate impl

- (void)interstitialAdRequestComplete:(AdpressoInterstitialAd*)interstitialAd
{
  OUTPUT_LOG(@"interstitialAdRequestComplete");
  [AdsWrapper onAdsResult:self withRet:kAdsReceived withMsg:@"AdLantis interstitial ad request success"];
}

- (void)interstitialAdRequestFailed:(AdpressoInterstitialAd*)interstitialAd
{
  OUTPUT_LOG(@"interstitialAdRequestFailed");
  [AdsWrapper onAdsResult:self withRet:kUnknownError withMsg:@"AdLantis interstitial ad request failed"];
}

- (void)interstitialAdWillBePresented:(AdpressoInterstitialAd*)interstitialAd
{
    OUTPUT_LOG(@"interstitialAdWillBePresented");
    [AdsWrapper onAdsResult:self withRet:kAdsShown withMsg:@"AdLantis interstitial ad will be presented"];
}

- (void)interstitialAdWasDismissed:(AdpressoInterstitialAd*)interstitialAd
{
    OUTPUT_LOG(@"interstitialAdWasDismissed");
    [AdsWrapper onAdsResult:self withRet:kAdsDismissed withMsg:@"AdLantis interstitial ad was dismissed"];
}
@end
