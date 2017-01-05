#ifndef __LOADING_SCENE_H__
#define __LOADING_SCENE_H__

#include "cocos2d.h"

class LoadingScene : public cocos2d::Layer
{
protected:
	//cocos2d::Label* label;
public:
    static cocos2d::Scene* createScene();

	LoadingScene();

    virtual bool init();

	//void update(float delta) override;

	// 触摸事件 回调函数
	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) override;
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) override;
    
    // implement the "static create()" method manually
	CREATE_FUNC(LoadingScene);

protected:
	void pvrPlistImageAsyncCallback(cocos2d::Texture2D* texture);
	void plistImageAsyncCallback(cocos2d::Texture2D* texture);
	void imageAsyncCallback(cocos2d::Texture2D* texture);

protected:
	void addVersionLable();
	void addProgressBar();

	cocos2d::ProgressTimer* progressBar;

private:
	virtual void onEnter();
	virtual void onExit();
};

#endif // __LOADING_SCENE_H__
