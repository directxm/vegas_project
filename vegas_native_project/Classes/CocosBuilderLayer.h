#ifndef __COCOSBUILDER_LAYER_H__
#define __COCOSBUILDER_LAYER_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

class CocosBuilderLayer 
	: public cocos2d::Layer
	, public cocosbuilder::CCBSelectorResolver
	, public cocosbuilder::CCBMemberVariableAssigner
	, public cocosbuilder::NodeLoaderListener
{

public:
	CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(CocosBuilderLayer, create);

	CocosBuilderLayer();
	virtual ~CocosBuilderLayer();

	cocos2d::Node* loadCCB(const char* ccbFileName, const char* nodeName, cocosbuilder::NodeLoader* nodeLoader);

public:
	// 绑定ccb中的菜单
	virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char * pSelectorName);
	// 绑定控制按钮点击操作
	virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget, const char * pSelectorName);
	// 绑定时间轴的回调函数
	virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(cocos2d::Ref * pTarget, const char* pSelectorName);
	// 绑定变量与ccb文件中元素相对应
	virtual bool onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName, cocos2d::Node * pNode);
	// 绑定自定义类型相关的变量
	virtual bool onAssignCCBCustomProperty(cocos2d::Ref* pTarget, const char* pMemberVariableName, const cocos2d::Value& pCCBValue);
	virtual void onNodeLoaded(cocos2d::Node * node, cocosbuilder::NodeLoader * nodeLoader);
};

#endif // __COCOSBUILDER_LAYER_H__