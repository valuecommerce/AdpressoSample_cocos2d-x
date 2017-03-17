/*
 * AdpressoInterstitialAdModule.h
 *
 *  Created on: 2016/12/09
 *      Author: mitakahashi
 */

#ifndef ANDROID_ADPRESSOINTERSTITIALADMODULE_H_
#define ANDROID_ADPRESSOINTERSTITIALADMODULE_H_

#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"

USING_NS_CC;

class AdpressoInterstitialAdModule {
public:
	static void createAdpressoInterstitialAd(char* publisherId,cocos2d::Point pos);
	static void hiddenAdpressoInterstitialAd();
};

#endif /* ANDROID_ADPRESSOINTERSTITIALADMODULE_H_ */
