/*
 * AdpressoAdModule.h
 *
 *  Created on: 2016/12/09
 *      Author: mitakahashi
 */

#ifndef ANDROID_ADPRESSOADMODULE_H_
#define ANDROID_ADPRESSOADMODULE_H_

#include "cocos2d.h"

USING_NS_CC;


class AdpressoAdModule {
public:
	static void createAdpressoAd(char* publisherId,cocos2d::Point pos);
	static void hiddenAdpressoAd();
};

#endif /* ANDROID_ADPRESSOADMODULE_H_ */
