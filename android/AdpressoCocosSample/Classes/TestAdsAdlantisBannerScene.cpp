//
//  TestAdsAdlantisBannerScene.cpp
//  HelloPlugins
//
//  Created on 6/5/14.
//
//

#include "TestAdsAdlantisBannerScene.h"
#include "MainMenuScene.h"
#include "platform/android/jni/JniHelper.h"

#include "AdpressoAdModule.h"

USING_NS_CC;

const std::string s_aTestPoses[] = {
	"Banner",
};

Scene* TestAdsAdlantisBanner::createScene()
{
  // 'scene' is an autorelease object
  Scene *scene = Scene::create();

  // 'layer' is an autorelease object
  TestAdsAdlantisBanner *layer = TestAdsAdlantisBanner::create();

  // add layer as a child to scene
  scene->addChild(layer);

  // return the scene
  return scene;
}

// on "init" you need to initialize your instance
bool TestAdsAdlantisBanner::init()
{
  //////////////////////////////
  // 1. super init first
  if ( !Layer::init() )
  {
    return false;
  }

  Size visibleSize = Director::getInstance()->getVisibleSize();
  cocos2d::Point origin = Director::getInstance()->getVisibleOrigin();
  cocos2d::Point posMid = Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
  cocos2d::Point posBR = Point(origin.x + visibleSize.width, origin.y);


  /////////////////////////////
  // 2. add a menu item with "X" image, which is clicked to quit the program
  //    you may modify it.

  // add a "close" icon to exit the progress. it's an autorelease object
  MenuItemFont *pBackItem = MenuItemFont::create("Back", CC_CALLBACK_1(TestAdsAdlantisBanner::menuBackCallback, this));
  Size backSize = pBackItem->getContentSize();
  pBackItem->setPosition(posBR + Point(- backSize.width / 2, backSize.height / 2));

  // create menu, it's an autorelease object
  Menu* pMenu = Menu::create(pBackItem, NULL);
  pMenu->setPosition( Point::ZERO );

  auto label1 = Label::createWithSystemFont("ShowAds", "Arial", 24);
	MenuItemLabel* pItemShow = MenuItemLabel::create(label1, CC_CALLBACK_1(TestAdsAdlantisBanner::testShow, this));
	pItemShow->setAnchorPoint(Point(0.5f, 0));
	pMenu->addChild(pItemShow, 0);
	pItemShow->setPosition(posMid + Point(-100, -120));

	auto label2 = Label::createWithSystemFont("HideAds", "Arial", 24);
	MenuItemLabel* pItemHide = MenuItemLabel::create(label2, CC_CALLBACK_1(TestAdsAdlantisBanner::testHide, this));
	pItemHide->setAnchorPoint(Point(0.5f, 0));
	pMenu->addChild(pItemHide, 0);
	pItemHide->setPosition(posMid + Point(100, -120));

	// poses item
	_posItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(TestAdsAdlantisBanner::posChanged, this),
                                                MenuItemFont::create( s_aTestPoses[0].c_str() ),
                                                NULL );
	int posLen = sizeof(s_aTestPoses) / sizeof(std::string);
	for (int i = 1; i < posLen; ++i)
	{
		_posItem->getSubItems().pushBack( MenuItemFont::create( s_aTestPoses[i].c_str() ) );
	}
	_posItem->setPosition(posMid + Point(0, 120));
	pMenu->addChild(_posItem);

	// init options
	_pos = 0;


  this->addChild(pMenu, 1);

  testShow(nullptr);

  return true;
}

void TestAdsAdlantisBanner::testShow(Ref* pSender)
{
	  char* publisherId = "Mjc3NzI%3D%0A";
	  Size visibleSize = Director::getInstance()->getVisibleSize();
	  cocos2d::Point origin = Director::getInstance()->getVisibleOrigin();
	  cocos2d::Point posMid = Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	  cocos2d::Point posBR = Point(origin.x + visibleSize.width, origin.y);

	  AdpressoAdModule::createAdpressoAd(publisherId, posBR);
}

void TestAdsAdlantisBanner::testHide(Ref* pSender)
{
	char* publisherId = "Mjc3NzI%3D%0A";

	AdpressoAdModule::hiddenAdpressoAd();
}

void TestAdsAdlantisBanner::menuBackCallback(Ref* pSender)
{

  TestAdsAdlantisBanner::testHide(pSender);
  Scene* newScene = MainMenu::createScene();
  Director::getInstance()->replaceScene(newScene);
}

void TestAdsAdlantisBanner::posChanged(Ref* pSender)
{
	log("pos selected change to : %d", 0);
}
