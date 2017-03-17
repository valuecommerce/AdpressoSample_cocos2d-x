/*
 * AdpressoAdModule.cpp
 *
 *  Created on: 2016/12/09
 *      Author: mitakahashi
 */

#include "AdpressoAdModule.h"
#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"
USING_NS_CC;


#define CLASS_NAME "com/valuecommerce/android/cocosIF/AdpressoAdModule"

void AdpressoAdModule::createAdpressoAd(char* publisherId, cocos2d::Point pos)
{
	  cocos2d::JniMethodInfo methodInfo;
	  // AdpressoAdBanner#createAdpressoAd(publisherId,x,y)
	  if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "createAdpressoAd", "(Ljava/lang/String;FF)V")) {
		jstring jpublisherId = methodInfo.env->NewStringUTF(publisherId);
		cocos2d::Point newPos;
		newPos.x = pos.x;
		newPos.y = pos.y;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID,jpublisherId,newPos.x,newPos.y);
	  }

}

void AdpressoAdModule::hiddenAdpressoAd()
{
	cocos2d::JniMethodInfo methodInfo;
	// AdpressoAdBanner#hideAdpressoAd()
	if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "hideAdpressoAd", "()V")) {
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);

		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

}
