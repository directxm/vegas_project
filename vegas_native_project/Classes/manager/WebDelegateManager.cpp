#include "WebDelegateManager.h"

USING_NS_CC;

WebSocketDelegate::WebSocketDelegate()
{
	connectRetryTimes = 0;
}

WebSocketDelegate::~WebSocketDelegate()
{

}


bool WebSocketDelegate::hasNetwork()
{
	return true;
}

// app当前是否有权限连接网络
bool WebSocketDelegate::checkPermission()
{
	return true;
}

std::string WebSocketDelegate::getIp()
{
	return "";
}

int WebSocketDelegate::getPort()
{
	return 0;
}

bool WebSocketDelegate::resetNetwork()
{
	disconnect();
	clear();

	return true;
}

bool WebSocketDelegate::connect()
{
	// 网络是否正常
	if (hasNetwork() == false || checkPermission() == false)
	{
		onError(ErrorCode::NO_NET);
		return false;
	}

	// 是否正在连接
	if (false)
	{
		return false;
	}

	// 重连次数过多
	++connectRetryTimes;
	if (connectRetryTimes >= 3)
	{
		onError(ErrorCode::NO_NET);
		return false;
	}

	if (doConnect())
	{
		return true;
	}
	else
	{
		onError(ErrorCode::UNKNOWN);
		return false;
	}
}

bool WebSocketDelegate::disconnect()
{
	return true;
}

bool WebSocketDelegate::isConnect()
{
	return true;
}

bool WebSocketDelegate::send()
{
	return true;
}

void WebSocketDelegate::clear()
{

}



void WebSocketDelegate::onOpen(cocos2d::network::WebSocket* ws)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void WebSocketDelegate::onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data)
{
	if (!data.isBinary)
	{
	}

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

void WebSocketDelegate::onError(const ErrorCode& error)
{

}

bool WebSocketDelegate::doConnect()
{
	return true;
}