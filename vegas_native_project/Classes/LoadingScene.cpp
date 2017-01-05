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
	// ��ȡ��ǰ����
	int num = progressBar->getPercentage();
	// ���ý����ٶȣ��˴�Ϊÿ֡+1��
	progressBar->setPercentage(++num);
	// ������ѭ������
	if (num >= 100)
		progressBar->setPercentage(0);
}*/

// �����¼� �ص�����
bool LoadingScene::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	// ��ȡ������λ��
	Vec2 pos = pTouch->getLocation();

	return true;
}

void LoadingScene::onTouchMoved(Touch* pTouch, Event* pEvent)
{
	// �����ƶ���ƫ����
	Vec2 delta = pTouch->getDelta();

}


void LoadingScene::onEnter()
{
	//CCTextureCache::sharedTextureCache()->addImageAsync("background.png", this, callfuncO_selector(Assets::loadingCallBack));
	//��������ʱ��ÿ����һ���������һ��Assets::loadingCallBack��Assets::loadingCallBackʵ�ֽ������Ľ��ȸ������ж���ת
	//Director::getInstance()->getTextureCache()->addImageAsync("HelloWorld.png", this, callfuncO_selector(HelloWorld::loadingCallback));
	//CCUserDefault::sharedUserDefault()->getIntegerForKey(""); // �û��浵
	//FileUtils
	

	// ��Դ����
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

	// ���ó�ʼ�İٷֱȣ�0~100 ������0����100
	//progressBar->setPercentage(100);
	// ѡ�����ͣ������ͻ���ʱ����
	//progressBar->setType(ProgressTimer::Type::BAR);
	// �����������εĽ���
	//progressBar->setMidpoint(Point(0, 0));
	//progressBar->setBarChangeRate(Point(0, 1));
	
	scheduleUpdate();
}