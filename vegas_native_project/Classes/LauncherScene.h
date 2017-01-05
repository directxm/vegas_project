#ifndef __LAUNCHER_SCENE_H__
#define __LAUNCHER_SCENE_H__

#include "cocos2d.h"

class LauncherScene : public cocos2d::Layer
{
protected:
	//cocos2d::Label* label;
public:
    static cocos2d::Scene* createScene();

	LauncherScene();

    virtual bool init();

	// 触摸事件 回调函数
	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) override;
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) override;
    
    // implement the "static create()" method manually
	CREATE_FUNC(LauncherScene);

protected:
};

#endif // __LAUNCHER_SCENE_H__
