#include "LoadingScene.h"


USING_NS_CC;

Scene* LoadingScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = LoadingScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

LoadingScene::LoadingScene()
{

}

// on "init" you need to initialize your instance
bool LoadingScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//addProgressBar();

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	//this->addChild(sprite, 0);
    
	auto s = Director::getInstance()->getWinSize();

	auto to1 = Sequence::createWithTwoActions(ProgressTo::create(2, 100), ProgressTo::create(0, 0));

	auto left = ProgressTimer::create(Sprite::create("HelloWorld.png"));
	left->setType(ProgressTimer::Type::BAR);
	//    Setup for a bar starting from the left since the midpoint is 0 for the x
	left->setMidpoint(Vec2(0, 0));
	//    Setup for a horizontal bar since the bar change rate is 0 for y meaning no vertical change
	left->setBarChangeRate(Vec2(1, 0));
	addChild(left, 0);
	left->setPosition(100, s.height / 2);
	left->runAction(RepeatForever::create(to1));
	

    return true;
}

/*void LoadingScene::update(float delta)
{
	// 获取当前进度
	int num = progressBar->getPercentage();
	// 设置进度速度（此处为每帧+1）
	progressBar->setPercentage(++num);
	// 设置了循环播放
	if (num >= 100)
		progressBar->setPercentage(0);
}*/

// 触摸事件 回调函数
bool LoadingScene::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	// 获取触摸点位置
	Vec2 pos = pTouch->getLocation();

	return true;
}

void LoadingScene::onTouchMoved(Touch* pTouch, Event* pEvent)
{
	// 触摸移动的偏移量
	Vec2 delta = pTouch->getDelta();

}


void LoadingScene::onEnter()
{
	//CCTextureCache::sharedTextureCache()->addImageAsync("background.png", this, callfuncO_selector(Assets::loadingCallBack));
	//加载纹理时，每加载一张纹理调用一次Assets::loadingCallBack，Assets::loadingCallBack实现进度条的进度跟进和判断跳转
	//Director::getInstance()->getTextureCache()->addImageAsync("HelloWorld.png", this, callfuncO_selector(HelloWorld::loadingCallback));
	//CCUserDefault::sharedUserDefault()->getIntegerForKey(""); // 用户存档
	//FileUtils
	

	// 资源加载
	// http://www.cocoachina.com/bbs/read.php?tid=219154
}

void LoadingScene::onExit()
{
	int a = 0;
}

////////////////////////////////////////////////////////////////////////////
void LoadingScene::pvrPlistImageAsyncCallback(cocos2d::Texture2D* texture)
{
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile(reloadPvrPlists[curReloadPvrPlistNum].append("plist"), texture);
}

void LoadingScene::plistImageAsyncCallback(cocos2d::Texture2D* texture)
{
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile(reloadPlists[curReloadPlistNum].append("plist"), texture);
}

void LoadingScene::imageAsyncCallback(cocos2d::Texture2D* texture)
{

}

////////////////////////////////////////////////////////////////////////////
void LoadingScene::addVersionLable()
{

}

void LoadingScene::addProgressBar()
{
	/*auto sprite = Sprite::create("sliderProgress2.png");
	progressBar = ProgressTimer::create(sprite);
	progressBar->setPosition(100, 100);
	progressBar->setType(ProgressTimer::Type::BAR);
	//    Setup for a bar starting from the left since the midpoint is 0 for the x
	progressBar->setMidpoint(Vec2(0, 0));
	//    Setup for a horizontal bar since the bar change rate is 0 for y meaning no vertical change
	progressBar->setBarChangeRate(Vec2(1, 0));

	this->addChild(progressBar, 10);

	auto to2 = Sequence::createWithTwoActions(ProgressTo::create(2, 100), ProgressTo::create(0, 0));
	progressBar->runAction(RepeatForever::create(to2));*/

	// 设置初始的百分比，0~100 可以是0或者100
	//progressBar->setPercentage(100);
	// 选择类型，是条型还是时针型
	//progressBar->setType(ProgressTimer::Type::BAR);
	// 下面两个条形的进阶
	//progressBar->setMidpoint(Point(0, 0));
	//progressBar->setBarChangeRate(Point(0, 1));
	
	scheduleUpdate();
}