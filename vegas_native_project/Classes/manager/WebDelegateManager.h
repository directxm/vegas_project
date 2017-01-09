#ifndef __WEB_DELEGATE_MANAGER_H__
#define __WEB_DELEGATE_MANAGER_H__

#include "network/WebSocket.h"
#include "Singleton.h"

class WebSocketDelegate : public cocos2d::network::WebSocket::Delegate
{
public:
	enum class ErrorCode
	{
		TIME_OUT,           /** &lt; value 0 */
		CONNECTION_FAILURE, /** &lt; value 1 */
		UNKNOWN,            /** &lt; value 2 */
		NO_NET,           /** &lt; value 3 */
	};
public:
	WebSocketDelegate();
	~WebSocketDelegate();


	//void httpRequest();

	bool hasNetwork();
	// app当前是否有权限连接网络
	bool checkPermission();

	std::string getIp();
	int getPort();

	bool resetNetwork();

	bool connect();
	bool disconnect();
	bool isConnect();

	bool send();

	void clear();

protected:
	virtual void onOpen(cocos2d::network::WebSocket* ws) override;

	virtual void onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data) override;

	virtual void onClose(cocos2d::network::WebSocket* ws) override;

	virtual void onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error) override;

	virtual void onError(const ErrorCode& error);

	virtual bool doConnect();
protected:
	//void onHttpRequest(CCHttpClient* client, CCHttpResponse* response);

protected:
	int connectRetryTimes;

	cocos2d::network::WebSocket* citySocket;
private:
};

typedef Singleton<WebSocketDelegate> WebDelegateManager;


#endif // __WEB_DELEGATE_MANAGER_H__