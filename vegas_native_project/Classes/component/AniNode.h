#ifndef __ANI_NODE_H__
#define __ANI_NODE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"


class AniNode : cocos2d::Node
{
public:
	AniNode() : _animationMgr(nullptr){}
	virtual ~AniNode() {}

	CREATE_FUNC(AniNode);

	void setAnimationManager(cocosbuilder::CCBAnimationManager *pAnimationMgr)
	{
		_animationMgr = pAnimationMgr;
	}
	cocosbuilder::CCBAnimationManager* getAnimationManager()
	{
		return _animationMgr;
	}
protected:
	cocosbuilder::CCBAnimationManager* _animationMgr;
private:
};


#endif // __ANI_NODE_H__