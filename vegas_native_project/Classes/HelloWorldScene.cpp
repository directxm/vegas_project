#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "component\NoticeLable.h"
#include "component\DigitalScrollLable.h"
#include "2d\CCTweenFunction.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

HelloWorld::HelloWorld()
{

}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/*CCLabelAtlas* plabelAtlas = CCLabelAtlas::create("0123456789", "FontsNums.png", 38, 44, '0');
	plabelAtlas->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	//设置显示文字 25  
	plabelAtlas->setString("25");
	this->addChild(plabelAtlas);

	//CCLabelAtlas *atlas2 = CCLabelAtlas::create("LabelAtlas", "testfont.plist");
	//atlas2->setPosition(ccp(10, 500));
	//addChild(atlas2);

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("ui_serverlist.plist");

	ccBlendFunc __maskBF = { GL_ONE, GL_ONE };
	ccBlendFunc __imgBF = { GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA };

	// 水平滚动公告  
	CCSprite* textbase = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("login_textbase.png"));
	textbase->setPosition(ccp(visibleSize.width / 2, 50));
	textbase->setScaleX(2.5f);
	textbase->setBlendFunc(__maskBF);
	this->addChild(textbase);
	CCLabelTTF* text2 = CCLabelTTF::create("Hi! Welcome to JackyStudio,My Blog is blog.csdn.net/jackystudio!", "Arial", 12);
	text2->setPosition(ccp(visibleSize.width + text2->getContentSize().width / 2, 50));
	text2->setColor(ccc3(255, 0, 0));// 红色字体  
	text2->setBlendFunc(__imgBF);
	this->addChild(text2);




	ccBlendFunc __maskBF = { GL_ONE, GL_ONE };
	ccBlendFunc __imgBF = { GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA };

	CCSprite* __pMask = CCSprite::createWithTexture(sprite->getTexture());
	__pMask->setAnchorPoint(ccp(0, 0));
	__pMask->setPosition(ccp(0, 0));

	CCSprite* __pImg = CCSprite::createWithTexture(sprite->getTexture());
	__pImg->setAnchorPoint(ccp(0, 0));
	__pImg->setPosition(ccp(0, 0));

	__pMask->setBlendFunc(__maskBF);
	__pImg->setBlendFunc(__imgBF);

	CCSize __size = __pImg->getContentSize();
	CCRenderTexture* __pRender = CCRenderTexture::create(__size.width, __size.height);
	__pRender->begin();
	__pMask->visit();
	__pImg->visit();
	__pRender->end();

	CCTexture2D* __pTex = new CCTexture2D();
	__pTex->initWithImage(__pRender->newCCImage(true));
	__pTex->autorelease();
	CCSprite* __newSprite = CCSprite::createWithTexture(__pTex);
	this->addChild(__newSprite);


	ClippingNode* cliper = ClippingNode::create();
	DrawNode* drawNode = DrawNode::create();
	Point points[] = {Point(getPosition()),Point(getPositionX(),getPositionY()+m_fontSize),
	Point(getPositionX()+m_length*m_fontSize,getPositionY()+m_fontSize),Point(getPositionX()+m_length*m_fontSize,getPositionY())};
	drawNode->drawPolygon(points,4,Color4F(0,0,0,1),0,Color4F(0,0,0,1));

	cliper->setStencil(drawNode);
	cliper->addChild(m_visibleNode);
	this->addChild(cliper);

	//this->scheduleUpdate();//执行更新  */

	/*LabelAtlas* labelAtlas = LabelAtlas::create("0123456789", "fonts/tuffy_bold_italic-charmap.plist");
	labelAtlas->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	//labelAtlas->setLineBreakWithoutSpace(true);
	//labelAtlas->setPosition(0, 0);
	//设置显示文字 25  
	labelAtlas->setString("25555555");
	labelAtlas->setAnchorPoint(Point(0, 0));
	labelAtlas->setRotation(-90);
	//labelAtlas->setColor(Color3B.YELLOW);
	this->addChild(labelAtlas, 9999);*/

	CCPointArray * array = CCPointArray::create(20);
	std::vector<Sprite*> slots;

	int STAR_POS_X = 200;
	int STAR_POS_Y = 100;

	for (int i = 0; i < 6; ++i)
	{
		auto slot = Sprite::create("Star.png");
		slot->setScale(0.25);
		//slot->setOpacity(0.0f);
		Size s = slot->getContentSize();
		float x = STAR_POS_X;
		float y = STAR_POS_Y + i * (s.height * slot->getScale());
		slot->setPosition(x, y);
		addChild(slot, 9998);

		array->addControlPoint(slot->getPosition());
		
		auto spark = Sprite::create("Image 272.png");
		spark->setScale(0.25);
		spark->setOpacity(0.0f);
		spark->setPosition(x, y);
		addChild(spark, 9999);
		slots.push_back(spark);
	}

	for (int i = 0; i < 6; ++i)
	{
		auto slot = Sprite::create("Star.png");
		slot->setScale(0.25);
		//slot->setOpacity(0.0f);
		Size s = slot->getContentSize();
		float x = STAR_POS_X + (i + 1) * (s.width * slot->getScale());
		float y = STAR_POS_Y + 5 * (s.height * slot->getScale());
		slot->setPosition(x, y);
		addChild(slot, 9998);

		array->addControlPoint(slot->getPosition());
		
		auto spark = Sprite::create("Image 272.png");
		spark->setScale(0.25);
		spark->setOpacity(0.0f);
		spark->setPosition(x, y);
		addChild(spark, 9999);
		slots.push_back(spark);
	}

	for (int i = 5; i >= 0; --i)
	{
		auto slot = Sprite::create("Star.png");
		slot->setScale(0.25);
		//slot->setOpacity(0.0f);
		Size s = slot->getContentSize();
		float x = STAR_POS_X + 6 * (s.width * slot->getScale());
		float y = STAR_POS_Y + i * (s.height * slot->getScale());
		slot->setPosition(x, y);
		addChild(slot, 9998);

		array->addControlPoint(slot->getPosition());
		
		auto spark = Sprite::create("Image 272.png");
		spark->setScale(0.25);
		spark->setOpacity(0.0f);
		spark->setPosition(x, y);
		addChild(spark, 9999);
		slots.push_back(spark);
	}

	for (int i = 5; i >= 0; --i)
	{
		auto slot = Sprite::create("Star.png");
		slot->setScale(0.25);
		//slot->setOpacity(0.0f);
		Size s = slot->getContentSize();
		float x = STAR_POS_X + (i + 1) * (s.width * slot->getScale());
		float y = STAR_POS_Y;
		slot->setPosition(x, y);
		addChild(slot, 9998);

		array->addControlPoint(slot->getPosition());

		auto spark = Sprite::create("Image 272.png");
		spark->setScale(0.25);
		spark->setOpacity(0.0f);
		spark->setPosition(x, y);
		addChild(spark, 9999);
		slots.push_back(spark);
	}

	log("tweenfunc::sineEaseInOut(0) = %f", tweenfunc::sineEaseInOut(0.0f));
	log("tweenfunc::sineEaseInOut(0.5) = %f", tweenfunc::sineEaseInOut(0.5f));
	log("tweenfunc::sineEaseInOut(1) = %f", tweenfunc::sineEaseInOut(1.0f));
	log("tweenfunc::sineEaseInOut(1.5) = %f", tweenfunc::sineEaseInOut(1.5f));
	log("tweenfunc::sineEaseInOut(2) = %f", tweenfunc::sineEaseInOut(2.0f));
	log("tweenfunc::sineEaseInOut(2.5) = %f", tweenfunc::sineEaseInOut(2.5f));
	
	int source = 12;
	int target = 10;

	int count = (slots.size() - source) + slots.size() * 3 + target;
	float rate = 2.0f / count;
	for (int i = source; i <= count; ++i)
	{
		auto sp = slots[i % slots.size()];
		if (sp != nullptr)
		{
			float delta = rate * i;
			float time = (i - source + 1) * 0.1f + 1.0f - tweenfunc::sineEaseInOut(delta);
			CCActionInterval* predelay = CCDelayTime::create(time);
			log("delay index %d delta %f time  %f", i, delta, time);
			CCActionInterval* fadein = CCFadeIn::create(1);
			//CCActionInterval* delaytime = CCDelayTime::create(0.2);
			CCActionInterval* fadeout = CCFadeOut::create(1);

			//CCFiniteTimeAction* seq = CCSequence::create(predelay, fadein, delaytime, fadeout, nullptr);
			CCFiniteTimeAction* seq = nullptr;
			if (i == count)
			{
				seq = CCSequence::create(predelay, fadein, nullptr);
			}
			else
			{
				seq = CCSequence::create(predelay, fadein, fadeout, nullptr);
			}
			
			//CCFiniteTimeAction* repeat = CCRepeat::create(seq, 3);
			//seq->setTarget(sp);
			if (seq != nullptr)
			{
				sp->runAction(seq);
			}
		}
	}



	/*auto spark = Sprite::create("Image 272.png");
	spark->setScale(0.5);
	addChild(spark, 9999);
	CCActionInterval  * CardinalSplineTo = CCCardinalSplineTo::create(6, array, 0);
	//spark->runAction(CardinalSplineTo);

	streak = MotionStreak::create(0.5f, 50, 30, Color3B::WHITE, "Image 272.png");
	streak->setPosition(STAR_POS_X, STAR_POS_Y); // 设置拖尾streak的位置
	this->addChild(streak, 9999);
	//streak->runAction(CardinalSplineTo);


	// 动作缓慢开始和终止
	CCActionInterval* move = CCMoveTo::create(6, ccp(300, 300));
	ActionInterval * easeExponentialInOut = CCEaseExponentialInOut::create(CardinalSplineTo);
	spark->runAction(easeExponentialInOut);*/

	

	/*DigitalIntegerLable* lable = DigitalIntegerLable::create(0, "01234567890", "fonts/tuffy_bold_italic-charmap.plist", 48, 64, 0);
	//lable->setNumber(9, true);
	lable->setNumber(6);
	lable->setPosition(Point(100, 100));
	this->addChild(lable, 888);*/
	


	/*auto node = Node::create();
	this->addChild(node, 888);

	this->scheduleUpdate();

	for (int i = 0; i < 10; i++){
		char str[2];
		str[0] = i + '0';
		str[1] = '\0';

		Label* temp = Label::create(str, "", 24);
		temp->setAnchorPoint(Point(0, 0));
		temp->setPosition(Point(10, i * 24));
		node->addChild(temp);
	}
	char str[2];
	str[0] = '0';
	str[1] = '\0';
	Label* temp = Label::create(str, "", 24);
	temp->setAnchorPoint(Point(0, 0));
	temp->setPosition(Point(10, 10 * 24));
	node->addChild(temp);*/


	/*Size size = labelAtlas->getContentSize();

	ClippingNode* clipingNode = ClippingNode::create();
	DrawNode* drawNode = DrawNode::create();
	Point points[] = { Point(20, 20), Point(20, 400), Point(400, 400), Point(400, 20) };
	drawNode->drawPolygon(points, 4, Color4F(0, 0, 0, 1), 0, Color4F(0, 0, 0, 1));

	clipingNode->setStencil(drawNode);
	clipingNode->addChild(labelAtlas);
	this->addChild(clipingNode);*/




	/*NoticeLable* lable = NoticeLable::createWithSystemFont("bar.png", "Marker Felt", 24, 0.5);
	lable->pushString("测试");
	//lable->pushString("WWWWWWWWWWWWWWWWWWWWWWWWWWWW");
	//lable->pushString("MMMMMMMMMMMMMMMMMMMMMMMMMMMM");
	//lable->pushString("fuck fuck fuck fcuk ");
	//lable->pushString("1");
	lable->pushString("哈哈，我是个测试，肯定是带不了颜色了");
	//lable->pushString("testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest");
	lable->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	addChild(lable, 99);*/

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    /*auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);*/

    // add "HelloWorld" splash screen"
    /*auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);*/

	auto s = Director::getInstance()->getWinSize();

	auto to1 = Sequence::createWithTwoActions(ProgressTo::create(2, 100), ProgressTo::create(0, 0));

	auto left = ProgressTimer::create(Sprite::create("HelloWorld.png"));
	left->setType(ProgressTimer::Type::BAR);
	//    Setup for a bar starting from the left since the midpoint is 0 for the x
	left->setMidpoint(Vec2(0, 0));
	//    Setup for a horizontal bar since the bar change rate is 0 for y meaning no vertical change
	left->setBarChangeRate(Vec2(1, 0));
	addChild(left);
	left->setPosition(100, s.height / 2);
	left->runAction(RepeatForever::create(to1));

	/*ActionInterval* collapse = ScaleTo::create(2, 1, 0.01);
	//ActionInterval* scale = scaleY->reverse();
	//sprite->runAction(Sequence::create(collapse, CallFunc::create(this, onCollapse)));
	sprite->runAction(Sequence::create(
		ScaleTo::create(2, 1, 0.01),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::onCollapse, this)),
		nullptr)
		);

	sprite->setScaleY(0.01);
	sprite->runAction(Sequence::create(
						ScaleTo::create(2, 1, 1),
						CallFunc::create(CC_CALLBACK_0(HelloWorld::onToggle, this)),
						nullptr)
		);*/
	

	// websocket
	//cocos2d::network::WebSocket* wsiSendText = new network::WebSocket();
	//wsiSendText->init(*this, "ws://localhost/game");
    
    return true;
}

void HelloWorld::onCollapse()
{
	int a = 1;
}

void HelloWorld::onToggle()
{
	int a = 1;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}

void HelloWorld::onOpen(cocos2d::network::WebSocket* ws)
{
	//label->setString("onOpen");
	int a = 1;
}

void HelloWorld::onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data)
{
	//label->setString("onMessage");
	int a = 1;
}

void HelloWorld::onClose(cocos2d::network::WebSocket* ws)
{
	//label->setString("onClose");
	int a = 1;
}

void HelloWorld::onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error)
{
	//label->setString("onError");
	int a = 1;
}

// 触摸事件 回调函数
bool HelloWorld::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	// 获取触摸点位置
	Vec2 pos = pTouch->getLocation();

	streak->setPosition(pos);

	// 删除所有活动条带段
	streak->reset();

	return true;
}

void HelloWorld::onTouchMoved(Touch* pTouch, Event* pEvent)
{
	// 触摸移动的偏移量
	Vec2 delta = pTouch->getDelta();

	// 设置位置
	//star->setPosition(star->getPosition() + delta);
	streak->setPosition(streak->getPosition() + delta);
}
