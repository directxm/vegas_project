#include "CityScene.h"

USING_NS_CC;

Scene* CityScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = CityScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

CityScene::CityScene()
{

}

// on "init" you need to initialize your instance
bool CityScene::init()
{
	bool ret = false;

	//////////////////////////////
	// 1. super init first
	if (Layer::init())
	{
		if (citySocket != nullptr)
		{
			citySocket->close();
			citySocket = nullptr;
		}

		// HTTP ÇëÇóurl
		citySocket = new cocos2d::network::WebSocket();
		citySocket->init(*this, "ws://localhost/city");


		ret = true;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	return ret;
}

void CityScene::onOpen(cocos2d::network::WebSocket* ws)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void CityScene::onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data)
{
	if (!data.isBinary)
	{
	}

	throw std::logic_error("The method or operation is not implemented.");
}

void CityScene::onClose(cocos2d::network::WebSocket* ws)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void CityScene::onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error)
{
	throw std::logic_error("The method or operation is not implemented.");
}
