#include "GameManager.h"

USING_NS_CC;

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}

void GameManager::quit(cocos2d::Object* p /* = nullptr */)
{
	//cocos2d::extension::CCDevice::finishGame();

	CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}