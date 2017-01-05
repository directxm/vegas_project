#ifndef __CITY_SCENE_H__
#define __CITY_SCENE_H__

#include "cocos2d.h"

class CityScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	CityScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(CityScene);

public:
protected:
private:
};

#endif // __CITY_SCENE_H__