#ifndef __WEB_DELEGATE_MANAGER_H__
#define __WEB_DELEGATE_MANAGER_H__

#include "network/WebSocket.h"
#include "Singleton.h"

class WebSocketDelegate : public cocos2d::network::WebSocket::Delegate
{
public:
	WebSocketDelegate();
	~WebSocketDelegate();

	virtual void onOpen(cocos2d::network::WebSocket* ws) override;

	virtual void onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data) override;

	virtual void onClose(cocos2d::network::WebSocket* ws) override;

	virtual void onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error) override;


	void httpRequest();

protected:
	//void onHttpRequest(CCHttpClient* client, CCHttpResponse* response);

private:
};

typedef Singleton<WebSocketDelegate> WebDelegateManager;


#endif // __WEB_DELEGATE_MANAGER_H__