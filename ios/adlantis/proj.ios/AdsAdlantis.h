//
//  AdsAdlantis.h
//  PluginAdlantis
//
//  Created on 6/5/14.
//  Copyright (c) 2014 Atlantis Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "InterfaceAds.h"

#define KEY_PUBLISHER_ID "AdlantisPublisherID"

#define OUTPUT_LOG(...)     if (self.debug) NSLog(__VA_ARGS__);

extern NSString const *kAdlantisPublisherIdKey;

@interface AdsAdlantis : NSObject <InterfaceAds>

- (NSNumber*) getScale:(NSDictionary*)info;

@property (copy, nonatomic) NSString* strPublisherID;

@property BOOL debug;

@end
