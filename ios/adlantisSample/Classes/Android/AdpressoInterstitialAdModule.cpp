/*
 * AdpressoInterstitialAdModule.cpp
 *
 *  Created on: 2016/12/09
 *      Author: mitakahashi
 */

#include "AdpressoInterstitialAdModule.h"
#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"
USING_NS_CC;

#define CLASS_NAME "com/valuecommerce/android/cocosIF/AdpressoInterstitialAdModule"

void AdpressoInterstitialAdModule::createAdpressoInterstitialAd(char* publisherId, cocos2d::Point pos)
{
	  cocos2d::JniMethodInfo methodInfo;
	  // AdpressoInterstitialAdModule#createAdpressoAd(publisherId,x,y)
	  if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "createAdpressoInterstitialAd", "(Ljava/lang/String;FF)V")) {
		jstring jpublisherId = methodInfo.env->NewStringUTF(publisherId);
		cocos2d::Point newPos;
		newPos.x = pos.x;
		newPos.y = pos.y;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID,jpublisherId,pos.x,pos.y);
		methodInfo.env->DeleteLocalRef(jpublisherId);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	  }

}

void AdpressoInterstitialAdModule::hiddenAdpressoInterstitialAd()
{

}
