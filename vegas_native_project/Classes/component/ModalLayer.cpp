#include "ModalLayer.h"
#include "utils\Cocos2DUtils.h"

USING_NS_CC;

bool ModalLayer::init()
{
	if (CCLayer::init()) 
	{
		setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
		setSwallowsTouches(true);
		setTouchEnabled(true);
		_touchEnabled = true;
		return true;
	}
	return false;
}

bool ModalLayer::onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	if (!Utils::isNodeVisible(this) || (_restraintTouchInside && !Utils::isTouchInside(this, pTouch)))
		return false;

	return true;
}

void ModalLayer::setTouchPriority(int priority)
{
	if (_touchPriority != priority) 
	{
		_touchPriority = priority;

		if (_touchEnabled) 
		{
			setTouchEnabled(false);
			setTouchEnabled(true);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////

bool ModalLayerColor::init()
{
	if (CCLayerColor::init()) 
	{
		setSwallowsTouches(true);
		setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
		setTouchEnabled(true);
		return true;
	}
	return false;
}

void ModalLayerColor::onEnter()
{
	Node::onEnter();
}

void ModalLayerColor::onExit()
{
	Node::onExit();
}

bool ModalLayerColor::onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	if (!Utils::isNodeVisible(this) || (_restraintTouchInside && !Utils::isTouchInside(this, pTouch)))
		return false;

	if (_throughBegan)
	{
		_touchThrough = _throughBegan(pTouch, pEvent);
	}
	return true;
}

void ModalLayerColor::onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	if (_touchThrough)
	{
		_throughEnd(pTouch, pEvent);
	}
	if (_function) 
	{
		_function(pTouch);
	}
}

void ModalLayerColor::setThroughEnd(std::function<void(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)> function)
{
	_throughEnd = function;
}

void ModalLayerColor::setThroughBegan(std::function<bool(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)> function)
{
	_throughBegan = function;
}


