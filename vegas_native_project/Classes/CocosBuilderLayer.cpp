#include "CocosBuilderLayer.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocosbuilder;

CocosBuilderLayer::CocosBuilderLayer()
{

}

CocosBuilderLayer::~CocosBuilderLayer()
{

}

cocos2d::Node* CocosBuilderLayer::loadCCB(const char* ccbFileName, const char* nodeName, cocosbuilder::NodeLoader* nodeLoader)
{
	/* Create an autorelease NodeLoaderLibrary. */
	NodeLoaderLibrary * ccNodeLoaderLibrary = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();

	if (nodeName != nullptr && nodeLoader != nullptr) {
		ccNodeLoaderLibrary->registerNodeLoader(nodeName, nodeLoader);
	}

	/* Create an autorelease CCBReader. */
	cocosbuilder::CCBReader * ccbReader = new cocosbuilder::CCBReader(ccNodeLoaderLibrary);
	ccbReader->autorelease();

	/* Read a ccbi file. */
	// Load the scene from the ccbi-file, setting this class as
	// the owner will cause lblTestTitle to be set by the CCBReader.
	// lblTestTitle is in the TestHeader.ccbi, which is referenced
	// from each of the test scenes.
	auto node = ccbReader->readNodeGraphFromFile(ccbFileName, this);

	return node;
}

cocos2d::SEL_MenuHandler CocosBuilderLayer::onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char * pSelectorName)
{
	return nullptr;
}

cocos2d::extension::Control::Handler CocosBuilderLayer::onResolveCCBCCControlSelector(cocos2d::Ref * pTarget, const char * pSelectorName)
{
	//CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onMenuTestClicked", HelloCocosBuilderLayer::onMenuTestClicked);

	return nullptr;
}

bool CocosBuilderLayer::onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName, cocos2d::Node * node)
{
	//CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "mBurstSprite", Sprite *, this->mBurstSprite);

	return true;
}

bool CocosBuilderLayer::onAssignCCBCustomProperty(cocos2d::Ref* pTarget, const char* pMemberVariableName, const cocos2d::Value& pCCBValue)
{
	bool bRet = false;
	if (pTarget == this)
	{
		if (0 == strcmp(pMemberVariableName, "mCustomPropertyInt"))
		{
			//this->mCustomPropertyInt = pCCBValue.asInt();
			//log("mCustomPropertyInt = %d", mCustomPropertyInt);
			bRet = true;
		}
	}
	return true;
}

void CocosBuilderLayer::onNodeLoaded(cocos2d::Node * node, cocosbuilder::NodeLoader * nodeLoader)
{

}