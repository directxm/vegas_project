#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "network/WebSocket.h"

class HelloWorld : public cocos2d::Layer, public cocos2d::network::WebSocket::Delegate
{
protected:
	//cocos2d::Label* label;
public:
    static cocos2d::Scene* createScene();

	HelloWorld();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	void onOpen(cocos2d::network::WebSocket* ws);
	void onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data);
	void onClose(cocos2d::network::WebSocket* ws);
	void onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error);

	void onCollapse();
	void onToggle();


	// 触摸事件 回调函数
	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) override;
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) override;
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

protected:
	cocos2d::MotionStreak* streak;
};

#endif // __HELLOWORLD_SCENE_H__
