#ifndef __CITY_SCENE_H__
#define __CITY_SCENE_H__

#include "network/WebSocket.h"
#include "cocos2d.h"

class CityScene : public cocos2d::Layer, public cocos2d::network::WebSocket::Delegate
{
public:
	static cocos2d::Scene* createScene();

	CityScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(CityScene);

protected:
	virtual void onOpen(cocos2d::network::WebSocket* ws) override;

	virtual void onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data) override;

	virtual void onClose(cocos2d::network::WebSocket* ws) override;

	virtual void onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error) override;

public:
protected:

	cocos2d::network::WebSocket* citySocket;
private:
};

#endif // __CITY_SCENE_H__