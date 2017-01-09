#ifndef __MODAL_LAYER_H__
#define __MODAL_LAYER_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

class ModalLayer : public cocos2d::Layer
{
public:
	ModalLayer(bool bRestraintTouchInside = true);;
	virtual ~ModalLayer();;

	CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(ModalLayer, create);

	virtual bool init();

	virtual bool onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	//virtual void registerWithTouchDispatcher(void);

	void setTouchPriority(int priority);
	int getTouchPriority()
	{
		return _touchPriority;
	}

protected:
	int _touchPriority;

	CC_SYNTHESIZE(bool, _restraintTouchInside, RestraintTouchInside);
};


class ModalLayerColor : public cocos2d::LayerColor
{
public:
	ModalLayerColor(bool bRestraintTouchInside = true)
		: _restraintTouchInside(bRestraintTouchInside), _touchPriority(1), _function(nullptr), _throughBegan(nullptr), _throughEnd(nullptr), _touchThrough(false) {};
	virtual ~ModalLayerColor(){};

	CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(ModalLayerColor, create);

	//    static const char* comFunc_static(const std::string& func, CCDictionary* argsDict, Ref*& retDict);
	//    const char* comFunc(const std::string& func, CCDictionary* argsDict, Ref*& retDict);

	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	//   virtual void registerWithTouchDispatcher(void);

	void setTouchPriority(int priority);
	void setTouchFunction(std::function<void(cocos2d::CCTouch *pTouch)> function);

	void setThroughBegan(std::function<bool(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)> function);
	void setThroughEnd(std::function<void(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)> function);

	int getTouchPriority()
	{
		return _touchPriority;
	}

protected:

	std::function<void(cocos2d::CCTouch *pTouch)> _function;

	std::function<bool(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)> _throughBegan;
	std::function<void(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)> _throughEnd;
	bool _touchThrough;
	int _touchPriority;

	CC_SYNTHESIZE(bool, _restraintTouchInside, RestraintTouchInside);
};


#endif // __MODAL_LAYER_H__