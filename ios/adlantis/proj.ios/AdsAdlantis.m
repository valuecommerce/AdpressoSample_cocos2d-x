//
//  AdsAdlantis.m
//  PluginAdlantis
//
//  Created on 6/5/14.
//  Copyright (c) 2014 Atlantis Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "AdsAdlantis.h"
#import "AdpressoAdManager.h"

NSString const *kAdlantisPublisherIdKey = @KEY_PUBLISHER_ID;

@implementation AdsAdlantis

- (void)showAds:(NSMutableDictionary*)info position:(int)pos
{
}

- (void)hideAds:(NSMutableDictionary*)info
{
}

- (void)configDeveloperInfo:(NSMutableDictionary*)devInfo
{
  OUTPUT_LOG(@"configDeveloperInfo");
  self.strPublisherID = (NSString*) [devInfo objectForKey:kAdlantisPublisherIdKey];
}

- (void)queryPoints
{
  OUTPUT_LOG(@"queryPoints");
}

- (void)spendPoints:(int)points
{
  OUTPUT_LOG(@"spendPoints");
}

- (void)setDebugMode:(BOOL)debug
{
  OUTPUT_LOG(@"setDebugMode");
}

- (NSString*)getSDKVersion
{
  OUTPUT_LOG(@"getSDKVersion");
  return AdpressoAdManager.sharedManager.fullVersionString;
}

- (NSString*)getPluginVersion
{
  OUTPUT_LOG(@"getPluginVersion");
  return @"Adpresso SDK for Cocos2d-x iOS 2.0.0";
}

- (NSNumber*) getScale:(NSDictionary*)info
{
  float scale = 1.0;

  if ([[UIScreen mainScreen] respondsToSelector:@selector(scale)]) {
    scale = [[UIScreen mainScreen] scale];
  }
  
  return [NSNumber numberWithFloat:scale];
}

@end
