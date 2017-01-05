#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "cocos2d.h"

class GameManager : public cocos2d::Object
{
public:
	GameManager();
	~GameManager();

	void quit(cocos2d::Object* p = nullptr);
protected:
private:
};

#endif // __GAME_MANAGER_H__