//
//  TestAdsAdlantisIconScene.cpp
//  HelloPlugins
//
//  Created on 6/5/14.
//
//

#include "TestAdsAdlantisIconScene.h"
#include "MainMenuScene.h"
#include "platform/android/jni/JniHelper.h"

#include "AdpressoIconAdModule.h"

USING_NS_CC;

// const std::string s_aTestTextColors[] = {
// 	"",
// };

const std::string s_aTestIconTextVisibility[] = {
	"Icon",
};

Scene* TestAdsAdlantisIcon::createScene()
{
  // 'scene' is an autorelease object
  Scene *scene = Scene::create();

  // 'layer' is an autorelease object
  TestAdsAdlantisIcon *layer = TestAdsAdlantisIcon::create();

  // add layer as a child to scene
  scene->addChild(layer);

  // return the scene
  return scene;
}

// on "init" you need to initialize your instance
bool TestAdsAdlantisIcon::init()
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
  MenuItemFont *pBackItem = MenuItemFont::create("Back", CC_CALLBACK_1(TestAdsAdlantisIcon::menuBackCallback, this));
  Size backSize = pBackItem->getContentSize();
  pBackItem->setPosition(posBR + Point(- backSize.width / 2, backSize.height / 2));

  // create menu, it's an autorelease object
  Menu* pMenu = Menu::create(pBackItem, NULL);
  pMenu->setPosition( Point::ZERO );

	auto label1 = Label::createWithSystemFont("ShowAds", "Arial", 24);
	MenuItemLabel* pItemShow = MenuItemLabel::create(label1, CC_CALLBACK_1(TestAdsAdlantisIcon::testShow, this));
	pItemShow->setAnchorPoint(Point(0.5f, 0));
	pMenu->addChild(pItemShow, 0);
	pItemShow->setPosition(posMid + Point(-100, -120));

    auto label2 = Label::createWithSystemFont("HideAds", "Arial", 24);
	MenuItemLabel* pItemHide = MenuItemLabel::create(label2, CC_CALLBACK_1(TestAdsAdlantisIcon::testHide, this));
	pItemHide->setAnchorPoint(Point(0.5f, 0));
	pMenu->addChild(pItemHide, 0);
	pItemHide->setPosition(posMid + Point(100, -120));

	// create optional menu

	// text colors item
	// _textColorItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(TestAdsAdlantisIcon::textColorChanged, this),
  //                                               MenuItemFont::create( s_aTestTextColors[0].c_str() ),
  //                                               NULL );
	// int textColorsLen = sizeof(s_aTestTextColors) / sizeof(std::string);
	// for (int i = 1; i < textColorsLen; ++i)
	// {
	// 	_textColorItem->getSubItems().pushBack( MenuItemFont::create( s_aTestTextColors[i].c_str() ) );
	// }
	// _textColorItem->setPosition(posMid + Point(110, 100));
	// pMenu->addChild(_textColorItem);

  // textColorChanged(nullptr);  // init

  // icon text visibility menu item
  _textVisibility = true;
  _iconTextVisibility = MenuItemToggle::createWithCallback(CC_CALLBACK_1(TestAdsAdlantisIcon::iconTextVisibilityChanged, this),
                                                           MenuItemFont::create( s_aTestIconTextVisibility[0].c_str() ),
                                                           NULL );
	int iconTextVisibilityLen = sizeof(s_aTestIconTextVisibility) / sizeof(std::string);
	for (int i = 1; i < iconTextVisibilityLen; ++i)
	{
		_iconTextVisibility->getSubItems().pushBack( MenuItemFont::create( s_aTestIconTextVisibility[i].c_str() ) );
	}
	_iconTextVisibility->setPosition(posMid + Point(-110, 100));
	pMenu->addChild(_iconTextVisibility);

  this->addChild(pMenu, 1);

  testShow(nullptr);

  return true;
}

template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}

void TestAdsAdlantisIcon::testShow(Ref* pSender)
{
	  char* publisherId = "Mjc3NzE%3D%0A";
	  Size visibleSize = Director::getInstance()->getVisibleSize();
	  cocos2d::Point origin = Director::getInstance()->getVisibleOrigin();
	  cocos2d::Point posMid = Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	  cocos2d::Point posBR = Point(origin.x + visibleSize.width, origin.y);

	  AdpressoIconAdModule::createAdpressoIconAd(publisherId, posBR);
}

void TestAdsAdlantisIcon::testHide(Ref* pSender)
{
	AdpressoIconAdModule::hiddenAdpressoIconAd();
}

void TestAdsAdlantisIcon::menuBackCallback(Ref* pSender)
{

  AdpressoIconAdModule::hiddenAdpressoIconAd();
  Scene* newScene = MainMenu::createScene();
  Director::getInstance()->replaceScene(newScene);
}

// void TestAdsAdlantisIcon::textColorChanged(Ref* pSender)
// {
// 	int selectIndex = _textColorItem->getSelectedIndex();
// }

void TestAdsAdlantisIcon::iconTextVisibilityChanged(Ref* pSender)
{
	int selectIndex = _iconTextVisibility->getSelectedIndex();
  switch (selectIndex) {
    case 0:
      _textVisibility = true;
      break;
    case 1:
      _textVisibility = false;
      break;
    default:
      break;
  }
}
