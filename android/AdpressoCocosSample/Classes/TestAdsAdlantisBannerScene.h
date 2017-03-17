//
//  TestAdsAdlantisBannerScene.h
//  HelloPlugins
//
//  Created on 6/5/14.
//
//

#ifndef __TestAdsAdlantis_Banner_Scene_H__
#define __TestAdsAdlantis_Banner_Scene_H__

#include "cocos2d.h"

typedef std::map<std::string, std::string> TAdlantisIconInfo;


class TestAdsAdlantisBanner : public cocos2d::Layer
{
public:
  // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
  virtual bool init();
  
  // there's no 'id' in cpp, so we recommend returning the class instance pointer
  static cocos2d::Scene* createScene();
  
  // a selector callback
  void menuBackCallback(Ref* pSender);
  void testShow(Ref* pSender);
	void testHide(Ref* pSender);
  
	// option changed callback
	void posChanged(Ref* pSender);
  
  // implement the "static node()" method manually
  CREATE_FUNC(TestAdsAdlantisBanner);
  
private:
  cocos2d::MenuItemToggle* _posItem;
  cocos2d::Point* _pos;

};


#endif /* defined(__TestAdsAdlantis_Banner_Scene_H__) */
