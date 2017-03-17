//
//  TestAdsAdlantisInterstitialScene.cpp
//
//

#include "TestAdsAdlantisInterstitialScene.h"
#include "MainMenuScene.h"

#include "AdpressoInterstitialAdModule.h"

USING_NS_CC;


Scene* TestAdsAdlantisInterstitial::createScene()
{
  // 'scene' is an autorelease object
  Scene *scene = Scene::create();
  
  // 'layer' is an autorelease object
  TestAdsAdlantisInterstitial *layer = TestAdsAdlantisInterstitial::create();
  
  // add layer as a child to scene
  scene->addChild(layer);
  
  // return the scene
  return scene;
}

// on "init" you need to initialize your instance
bool TestAdsAdlantisInterstitial::init()
{
  //////////////////////////////
  // 1. super init first
  if ( !Layer::init() )
  {
    return false;
  }
  
  Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();
  Point posMid = Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
  Point posBR = Point(origin.x + visibleSize.width, origin.y);

  
  /////////////////////////////
  // 2. add a menu item with "X" image, which is clicked to quit the program
  //    you may modify it.
  
  // add a "close" icon to exit the progress. it's an autorelease object
  MenuItemFont *pBackItem = MenuItemFont::create("Back", CC_CALLBACK_1(TestAdsAdlantisInterstitial::menuBackCallback, this));
  Size backSize = pBackItem->getContentSize();
  pBackItem->setPosition(posBR + Point(- backSize.width / 2, backSize.height / 2));
  
  // create menu, it's an autorelease object
  Menu* pMenu = Menu::create(pBackItem, NULL);
  pMenu->setPosition( Point::ZERO );
  
    auto label1 = Label::createWithSystemFont("ShowAds", "Arial", 24);
	MenuItemLabel* pItemShow = MenuItemLabel::create(label1, CC_CALLBACK_1(TestAdsAdlantisInterstitial::testShow, this));
	pItemShow->setAnchorPoint(Point(0.5f, 0));
	pMenu->addChild(pItemShow, 0);
	pItemShow->setPosition(posMid);
  
  
  this->addChild(pMenu, 1);
  
  return true;
}

void TestAdsAdlantisInterstitial::testShow(Ref* pSender)
{
	  Size visibleSize = Director::getInstance()->getVisibleSize();
	  cocos2d::Point origin = Director::getInstance()->getVisibleOrigin();
	  cocos2d::Point posMid = Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	  cocos2d::Point posBR = Point(origin.x + visibleSize.width, origin.y);

	char* publisherId = "Mjc3NzA%3D%0A";
	AdpressoInterstitialAdModule::createAdpressoInterstitialAd(publisherId, posBR);
}

void TestAdsAdlantisInterstitial::testHide(Ref* pSender)
{
}

void TestAdsAdlantisInterstitial::menuBackCallback(Ref* pSender)
{
  Scene* newScene = MainMenu::createScene();
  Director::getInstance()->replaceScene(newScene);
}



