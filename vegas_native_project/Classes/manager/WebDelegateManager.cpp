#include "WebDelegateManager.h"

USING_NS_CC;

WebSocketDelegate::WebSocketDelegate()
{

}

WebSocketDelegate::~WebSocketDelegate()
{

}


void WebSocketDelegate::onOpen(cocos2d::network::WebSocket* ws)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void WebSocketDelegate::onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void WebSocketDelegate::onClose(cocos2d::network::WebSocket* ws)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void WebSocketDelegate::onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error)
{
	throw std::logic_error("The method or operation is not implemented.");
}

