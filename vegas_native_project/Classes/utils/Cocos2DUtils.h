#ifndef __COCOS2D_UTILS_H__
#define __COCOS2D_UTILS_H__

#include "cocos2d.h"

namespace Utils
{
	inline bool isTouchInside(cocos2d::Node *pNode, cocos2d::Touch *pTouch)
	{
		if (!pNode || !pNode->getParent())
			return false;
		
		cocos2d::Point point = pNode->getParent()->convertToNodeSpace(pTouch->getLocation());
		cocos2d::Rect rect = pNode->getBoundingBox();
		return rect.containsPoint(point);
	}

	inline bool isNodeVisible(cocos2d::CCNode *node)
	{
		if (!node->getParent()) {
			return node->isVisible();
		}
		if (!node->isVisible()) {
			return false;
		}
		else {
			return isNodeVisible(node->getParent());
		}
	}
};

#endif // __COCOS2D_UTILS_H__