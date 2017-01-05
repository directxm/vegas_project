
#include "ActorBase.h"

ActorBase::ActorBase()
:_sprite(NULL)
//,hpBgSprite(NULL)
,_pointCounter(0)
,_animationRight(NULL)
,_animationLeft(NULL)
,_animationExplode(NULL)
,_pointsVector(NULL)
,_runSpeed(0)
//,maxHp(0)
//,currHp(0)
//,hpPercentage(100)
//,hpBar(NULL)
{
}

ActorBase::~ActorBase()
{}

bool ActorBase::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	return true;
}

/*void ActorBase::createAndSetHpBar()
{
    hpBgSprite = Sprite::createWithSpriteFrameName("hpBg1.png");
    hpBgSprite->setPosition(Point(_sprite->getContentSize().width / 2, _sprite->getContentSize().height ));
    _sprite->addChild(hpBgSprite);
    
	hpBar = CCProgressTimer::create(Sprite::createWithSpriteFrameName("hp1.png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0.5f));
	hpBar->setBarChangeRate(Point(1, 0));
	hpBar->setPercentage(hpPercentage);
    hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 3 * 2 ));
    hpBgSprite->addChild(hpBar);
}*/

Animation* ActorBase::createAnimation(std::string prefixName, int framesNum, float delay)
{
    Vector<SpriteFrame*> animFrames;
    
	for (int i = 1; i <= framesNum; i++)
    {
        char buffer[20] = { 0 };
        sprintf(buffer, "_%i.png",  i);
        std::string str =  prefixName + buffer;
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    return Animation::createWithSpriteFrames(animFrames, delay);
}

Node* ActorBase::currPoint()
{
    return this->_pointsVector.at(_pointCounter);
}

Node* ActorBase::nextPoint()
{
    auto maxCount = int(_pointsVector.size());
	_pointCounter++;
	if (_pointCounter < maxCount  ){
		auto node =this->_pointsVector.at(_pointCounter);
        return node;
    }
	else{
		_pointCounter = maxCount - 1 ;
	}
    return NULL;
}

void ActorBase::runFllowPoint()
{
    auto temp = currPoint();
    _sprite->setPosition(temp->getPosition());
    auto point = nextPoint();
    
    if( point!= NULL ){
		auto duration =  temp->getPosition().getDistance(point->getPosition()) /getRunSpeed() ;
        _sprite->runAction(Sequence::create(MoveTo::create(duration, point->getPosition())
                                           , CallFuncN::create(CC_CALLBACK_0(ActorBase::runFllowPoint, this))
                                           , NULL));
    }
}


void ActorBase::setPointsVector(Vector<Node*> points)
{
    this->_pointsVector = points;
}



