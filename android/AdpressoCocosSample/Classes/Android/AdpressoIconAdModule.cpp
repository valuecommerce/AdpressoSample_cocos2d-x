/*
 * AdpressoIconAdModule.cpp
 *
 *  Created on: 2016/12/09
 *      Author: mitakahashi
 */

#include "AdpressoIconAdModule.h"
#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"
USING_NS_CC;

#define CLASS_NAME "com/valuecommerce/android/cocosIF/AdpressoIconAdModule"


void AdpressoIconAdModule::createAdpressoIconAd(char* publisherId, cocos2d::Point pos)
{
	  cocos2d::JniMethodInfo methodInfo;
	  // AdpressoAdBanner#createAdpressoAd(publisherId,x,y)
	  if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "createAdpressoIconAd", "(Ljava/lang/String;FF)V")) {
		jstring jpublisherId = methodInfo.env->NewStringUTF(publisherId);
		cocos2d::Point newPos;
		newPos.x = pos.x;
		newPos.y = pos.y;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID,jpublisherId,newPos.x,newPos.y);

		methodInfo.env->DeleteLocalRef(jpublisherId);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	  }

}

void AdpressoIconAdModule::hiddenAdpressoIconAd()
{
	  cocos2d::JniMethodInfo methodInfo;
	  // AdpressoAdBanner#createAdpressoAd(publisherId,x,y)
	  if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "hideAdpressoIconAd", "()V")) {
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
	  }

}
