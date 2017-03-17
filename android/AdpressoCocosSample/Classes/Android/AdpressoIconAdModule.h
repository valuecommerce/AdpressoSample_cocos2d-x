/*
 * AdpressoIconAdModule.h
 *
 *  Created on: 2016/12/09
 *      Author: mitakahashi
 */

#ifndef ANDROID_ADPRESSOICONADMODULE_H_
#define ANDROID_ADPRESSOICONADMODULE_H_

#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"

USING_NS_CC;

class AdpressoIconAdModule {
public:
	static void createAdpressoIconAd(char* publisherId, cocos2d::Point pos);
	static void hiddenAdpressoIconAd();
};

#endif /* ANDROID_ADPRESSOICONADMODULE_H_ */
