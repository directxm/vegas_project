#include "NetDelegate.h"

USING_NS_CC;


void NetDelegate::onOpen(cocos2d::network::WebSocket* ws)
{
	//label->setString("onOpen");
	int a = 1;
}

void NetDelegate::onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data)
{
	//label->setString("onMessage");
	int a = 1;
}

void NetDelegate::onClose(cocos2d::network::WebSocket* ws)
{
	//label->setString("onClose");
	int a = 1;
}

void NetDelegate::onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error)
{
	//label->setString("onError");
	int a = 1;
}
