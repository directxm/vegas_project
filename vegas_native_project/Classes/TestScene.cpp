#include "TestScene.h"
#include "SimpleAudioEngine.h"
#include "component\NoticeLable.h"
#include "component\DigitalScrollLable.h"
#include "2d\CCTweenFunction.h"

USING_NS_CC;

Scene* TestScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TestScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

TestScene::TestScene()
{

}

// on "init" you need to initialize your instance
bool TestScene::init()
{
	bool ret = false;
	// load loading resources

    //////////////////////////////
    // 1. super init first
    if ( Layer::init() )
    {
		// splash
		// check update
		// do update
		// check net
		// loading

		addProgressBar();



		ret = true;
    }

	
    
	

	Director::getInstance()->getTextureCache()->addImageAsync("C9HB1PEK0BGT0025.jpg",
		CC_CALLBACK_1(TestScene::imageAsyncCallback, this));

	Director::getInstance()->getTextureCache()->addImageAsync("animated-grossini.png",
		CC_CALLBACK_1(TestScene::plistImageAsyncCallback, this));

	Director::getInstance()->getTextureCache()->addImageAsync("game.pvr.ccz",
		CC_CALLBACK_1(TestScene::pvrPlistImageAsyncCallback, this));

	
	
    
    return ret;
}

void TestScene::update(float delta)
{
	// 获取当前进度
	int num = progressBar->getPercentage();
	// 设置进度速度（此处为每帧+1）
	progressBar->setPercentage(++num);
	// 设置了循环播放
	if (num >= 100)
		progressBar->setPercentage(0);
	
}

// 触摸事件 回调函数
bool TestScene::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	// 获取触摸点位置
	Vec2 pos = pTouch->getLocation();

	return true;
}

void TestScene::onTouchMoved(Touch* pTouch, Event* pEvent)
{
	// 触摸移动的偏移量
	Vec2 delta = pTouch->getDelta();
}

////////////////////////////////////////////////////////////////////////////////////
void TestScene::addProgressBar()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto s = Director::getInstance()->getWinSize();

	auto to1 = Sequence::createWithTwoActions(ProgressTo::create(2, 100), ProgressTo::create(0, 0));

	progressBar = ProgressTimer::create(Sprite::create("HelloWorld.png"));
	progressBar->setType(ProgressTimer::Type::BAR);
	//    Setup for a bar starting from the left since the midpoint is 0 for the x
	progressBar->setMidpoint(Vec2(0, 0));
	//    Setup for a horizontal bar since the bar change rate is 0 for y meaning no vertical change
	progressBar->setBarChangeRate(Vec2(1, 0));
	addChild(progressBar);
	progressBar->setPosition(100, s.height / 2);
	//progressBar->runAction(RepeatForever::create(to1));

	this->scheduleUpdate();
}

////////////////////////////////////////////////////////////////////////////
void TestScene::pvrPlistImageAsyncCallback(cocos2d::Texture2D* texture)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("game.plist", texture);

	auto a = Sprite::createWithSpriteFrameName("btn_home_dow.png");

	a->setPosition(300, 300);
	addChild(a, 10);
}

void TestScene::plistImageAsyncCallback(cocos2d::Texture2D* texture)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("animated-grossini.plist", texture);

	auto a = Sprite::createWithSpriteFrameName("grossini-body.png");

	a->setPosition(200, 200);
	addChild(a, 10);
}

void TestScene::imageAsyncCallback(cocos2d::Texture2D* texture)
{
	int a = 0;
}