#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(200,0,155,255)) )
    {
        return false;
    }

	Size winSize = Director::getInstance()->getWinSize();

	auto spr = Sprite::create("Icon-57.png");
	spr->setAnchorPoint(Point(.5f, .5f));
	spr->setPosition(Point::ZERO + Point(winSize.width, winSize.height));
	addChild(spr);

	setScale(0.5f);
	

	auto label = Label::createWithSystemFont("HelloWorld", "Gulim", 60);
	label->setPosition(Point(240, 160));
	addChild(label);

	label = Label::createWithSystemFont("안녕하세요", "Thonburi", 60);
	label->setPosition(Point(240, 100));
	addChild(label);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
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
