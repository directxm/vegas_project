#ifndef __ACTOR_BASE_H__
#define __ACTOR_BASE_H__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class ActorBase : public Sprite
{
public:
    ActorBase();
    ~ActorBase();
    virtual bool init() override;
    CREATE_FUNC(ActorBase);
    
    Animation* createAnimation(std::string prefixName, int framesNum, float delay);
    virtual void changeDirection(float dt){};
    virtual void enemyExpload(){};
    Node* currPoint();
    Node* nextPoint();
    void runFllowPoint();
    void setPointsVector(Vector<Node*> points);
	//void createAndSetHpBar();
private:
    Vector<Node*> _pointsVector;
    
protected:
    int _pointCounter;
    Animation* _animationRight;
    Animation* _animationLeft;
    Animation* _animationExplode;
    CC_SYNTHESIZE(float, _runSpeed, RunSpeed);
    //CC_SYNTHESIZE(int, maxHp, MaxHp);
    //CC_SYNTHESIZE(int, currHp, CurrHp);
	//CC_SYNTHESIZE(float, hpPercentage, HpPercentage);
    //CC_SYNTHESIZE_READONLY(ProgressTimer*, hpBar, HpBar);
	Sprite* _sprite;
    //Sprite* hpBgSprite;
};



#endif // __ACTOR_BASE_H__
