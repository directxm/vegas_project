#ifndef __NET_DELEGATE_H__
#define __NET_DELEGATE_H__

#include "network/WebSocket.h"

class NetDelegate : public cocos2d::network::WebSocket::Delegate
{
public:
	virtual ~NetDelegate();

public:
	virtual void onOpen(cocos2d::network::WebSocket* ws);
	virtual void onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data);
	virtual void onClose(cocos2d::network::WebSocket* ws);
	virtual void onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error);
};

#endif