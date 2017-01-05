#include "LauncherScene.h"


USING_NS_CC;

Scene* LauncherScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = LauncherScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

LauncherScene::LauncherScene()
{

}

// on "init" you need to initialize your instance
bool LauncherScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    return true;
}

// 触摸事件 回调函数
bool LauncherScene::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	// 获取触摸点位置
	Vec2 pos = pTouch->getLocation();

	return true;
}

void LauncherScene::onTouchMoved(Touch* pTouch, Event* pEvent)
{
	// 触摸移动的偏移量
	Vec2 delta = pTouch->getDelta();

}
