//
//  TestAdsAdlantisInterstitialScene.cpp
//  HelloPlugins
//
//  Created on 6/5/14.
//
//

#include "TestAdsAdlantisInterstitialScene.h"
#include "PluginManager.h"
#include "MainMenuScene.h"

USING_NS_CC;
using namespace cocos2d::plugin;


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
  
  _listener = new AdlantisAdsInterstitialListener();
  _adlantisAdsInterstitial = dynamic_cast<ProtocolAds*>(PluginManager::getInstance()->loadPlugin("AdsAdlantisInterstitial"));
  
  TAdsDeveloperInfo devInfo;
  
  devInfo["AdlantisPublisherID"] = "Mjc3NzA%3D%0A";//is
  _adlantisAdsInterstitial->configDeveloperInfo(devInfo);
    
  _adlantisAdsInterstitial->setDebugMode(true);
  _adlantisAdsInterstitial->setAdsListener(_listener);
  
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
  
	LabelTTF* label1 = LabelTTF::create("ShowAds", "Arial", 24);
	MenuItemLabel* pItemShow = MenuItemLabel::create(label1, CC_CALLBACK_1(TestAdsAdlantisInterstitial::testShow, this));
	pItemShow->setAnchorPoint(Point(0.5f, 0));
	pMenu->addChild(pItemShow, 0);
	pItemShow->setPosition(posMid);
  
	// init options
	_ads = _adlantisAdsInterstitial;
	_pos = ProtocolAds::kPosCenter;

  
  _adlantisAdsInterstitial->showAds(adInfo);
  
  this->addChild(pMenu, 1);
  
  return true;
}

void TestAdsAdlantisInterstitial::testShow(Ref* pSender)
{
  if (_ads)
	{
    _ads->showAds(adInfo, _pos);
	}
}

void TestAdsAdlantisInterstitial::testHide(Ref* pSender)
{
	_ads->hideAds(adInfo);
}

void TestAdsAdlantisInterstitial::menuBackCallback(Ref* pSender)
{
  
  if (_adlantisAdsInterstitial != NULL)
  {
    PluginManager::getInstance()->unloadPlugin("AdsAdlantisInterstitial");
    _adlantisAdsInterstitial = NULL;
  }
  
  if (NULL != _listener)
  {
    delete _listener;
    _listener = NULL;
  }
  
  Scene* newScene = MainMenu::createScene();
  Director::getInstance()->replaceScene(newScene);
}

void AdlantisAdsInterstitialListener::onAdsResult(AdsResultCode code, const char* msg)
{
	log("OnAdsResult, code : %d, msg : %s", code, msg);
}


