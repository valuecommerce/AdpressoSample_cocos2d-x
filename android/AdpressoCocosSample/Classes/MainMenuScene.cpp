//
//  MainMenuScene.cpp
//
//  Created by Glossom,inc on 6/5/14.
//
//
#include "MainMenuScene.h"
#include "TestAdsAdlantisBannerScene.h"
#include "TestAdsAdlantisInterstitialScene.h"
#include "TestAdsAdlantisIconScene.h"

USING_NS_CC;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
std::string g_testCases[] = {
    "Test Banner Ads",
    "Test Interstitial",
    "Test Icon Ads",
};
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
std::string g_testCases[] = {
    "Test Banner Ads",
    "Test Interstitial",
};
#endif

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainMenu::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = LabelTTF::create("Adpresso Test", "Helvetica", 24);

    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    //add test menu
    Point beginPos = Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 100);
    float step = 60.0f;
    int nCaseCount = sizeof(g_testCases) / sizeof(std::string);
    for (int i = 0; i < nCaseCount; ++i) {
        std::string caseName = g_testCases[i];
        MenuItemFont *item = MenuItemFont::create(caseName.c_str(), CC_CALLBACK_1(MainMenu::menuCallback, this));
        item->setTag(i);
        item->setPosition(Point(beginPos.x, beginPos.y - i * step));
        menu->addChild(item);
    }
    return true;
}

void MainMenu::menuCallback(Ref* pSender)
{
    MenuItemFont *pItem = (MenuItemFont*) pSender;
    Scene* newScene = NULL;
    switch (pItem->getTag()) {
        case 0:
            newScene = TestAdsAdlantisBanner::createScene();
            break;
        case 1:
            newScene = TestAdsAdlantisInterstitial::createScene();
            break;
        case 2:
            newScene = TestAdsAdlantisIcon::createScene();
            break;
        default:
            break;
    }

    if (newScene) {
        Director::getInstance()->replaceScene(newScene);
    }
}

void MainMenu::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
