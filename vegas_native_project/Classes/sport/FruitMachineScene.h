#ifndef __FRUITMACHINE_SCENE_H__
#define __FRUITMACHINE_SCENE_H__

#include "cocos2d.h"
#include "CocosBuilderLayer.h"

class NoticeLable;

/************************************************************************/
/* 奖池统计管理，游戏独立运行                                             */
/************************************************************************/
class FruitMachineLayer
	: CocosBuilderLayer
{
public:
	//桔子 铃铛 barX25 barX50 苹果 苹果X2 哈密瓜
	//	铃铛X2                             西瓜
	//	苹果                               西瓜X2
	//	goodluck                           goodluck
	//	星星X2                             苹果
	//	星星                               桔子X2
	//	哈密瓜 哈密瓜X2 苹果 77 77X2 铃铛 桔子
	enum SlotType
	{
		Orange,
		OrangeX2,
		Bell,
		BellX2,
		BarX50,
		BarX25,
		Apple,
		AppleX2,
		Star,
		StarX2,
		GoodLuck1,
		GoodLuck2,
		HamiMelon,
		HamiMelonX2,
		WaterMelon,
		WaterMelonX2,
		Number77,
		Number77X2,
		MAX = Number77X2,
	};

	enum LosePercentType
	{
		Percent10,
		Percent50,
		Percent100,
	};

	enum GameStatus
	{
		Wait,
		CountDownLottery,
		Lottery,
		CountDownPuzzle,
		Puzzle,
		Prize,
	};

public:
	static cocos2d::Scene* createScene();

	FruitMachineLayer();

	virtual bool init();

	void startup();

	// implement the "static create()" method manually
	CREATE_FUNC(FruitMachineLayer);

	void clear();

public:
	// user operate

	inline bool canBet() { return _status == GameStatus::CountDownLottery; }
	inline bool canGust() { return _status == GameStatus::CountDownPuzzle; }

protected:
	void drawLottery();
	void endLottery();
	void drawPuzzle();
	void endPuzzle();
	void drawPrize();
	void endPrize();

	void updateCountDownLottery(float delta);
	void updateCountDownPuzzle(float delta);

	void onLottery();
	void onPuzzle();
	void onPrize();

protected:
	bool onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName, cocos2d::Node * pNode) override;
	bool onAssignCCBCustomProperty(cocos2d::Ref* pTarget, const char* pMemberVariableName, const cocos2d::Value& pCCBValue) override;

	void touchDownBeting(cocos2d::Ref* sender, cocos2d::extension::Control::EventType controlEvent);
protected:
	//cocos2d::Vector<cocos2d::Sprite*> _slots;
	std::vector<cocos2d::Sprite*> _slots;
	std::vector<SlotType> _slotTypes; // 左上角为起点
	std::vector<cocos2d::Sprite*> _focusSlots;
	//cocos2d::Sprite* _focusSlot;
	std::vector<cocos2d::extension::ControlButton*> _bettingButtons;

	// 倒计时板
	cocos2d::LabelAtlas* _lotteryCountDownLabel;
	cocos2d::LabelAtlas* _puzzleCountDownLabel;

	int _mid; // machine id
	int _rewardValue;
	GameStatus _status;

	std::vector<int> _slotBettingValues;
	std::vector<int> _slotTotalBettingValues;

	SlotType _sourceSlot;
	SlotType _targetSlot; // prize
	std::vector<SlotType> _threePrize;

	LosePercentType _losePercent;
	int _puzzleValue;

	int _countDownTime;
	NoticeLable* _noticeLable;


	// fake value
private:
};

#endif // __FRUITMACHINEDELUXE_SCENE_H__
