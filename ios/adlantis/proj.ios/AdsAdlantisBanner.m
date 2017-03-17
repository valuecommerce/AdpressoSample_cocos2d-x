//
//  AdsAdlantisBanner.m
//  PluginAdlantis
//
//  Created on 6/2/14.
//  Copyright (c) 2014 Atlantis Inc. All rights reserved.
//

#import "AdsAdlantisBanner.h"
#import "AdsWrapper.h"
#import "adlantis_sdk/AdpressoView.h"

@interface AdsAdlantisBanner ()

@property (strong, nonatomic) AdpressoView* bannerView;

@end

@implementation AdsAdlantisBanner

- (void)showAds:(NSMutableDictionary*)info position:(int)pos
{
  OUTPUT_LOG(@"show adlantis ads");
  
  if (self.strPublisherID == nil ||
      [self.strPublisherID length] == 0) {
    OUTPUT_LOG(@"configDeveloperInfo() not correctly invoked in Adlantis!");
    return;
  }
  
  [self showBanner:pos];
}

- (void)showBanner:(int)pos
{
  OUTPUT_LOG(@"show adlantis banner");
  
  if (nil != self.bannerView) {
    [self.bannerView removeFromSuperview];
    self.bannerView = nil;
  }
  
  CGSize suggestedViewSize = AdpressoViewSizeForOrientation(UIApplication.sharedApplication.statusBarOrientation);
  
  self.bannerView = [[AdpressoView alloc] initWithFrame: CGRectMake(0, 0, suggestedViewSize.width, suggestedViewSize.height)];
  [self.bannerView setPublisherID:self.strPublisherID];
  [AdsWrapper addAdView:self.bannerView atPos:pos];
}

- (void)hideAds:(NSMutableDictionary*)info
{
  if (nil != self.bannerView) {
    [self.bannerView removeFromSuperview];
    self.bannerView = nil;
  }
}

@end
