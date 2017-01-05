#ifndef __FRUITMACHINE_SCENE_H__
#define __FRUITMACHINE_SCENE_H__

#include "cocos2d.h"
#include "CocosBuilderLayer.h"

class NoticeLable;

/************************************************************************/
/* ����ͳ�ƹ�����Ϸ��������                                             */
/************************************************************************/
class FruitMachineLayer
	: CocosBuilderLayer
{
public:
	//���� ���� barX25 barX50 ƻ�� ƻ��X2 ���ܹ�
	//	����X2                             ����
	//	ƻ��                               ����X2
	//	goodluck                           goodluck
	//	����X2                             ƻ��
	//	����                               ����X2
	//	���ܹ� ���ܹ�X2 ƻ�� 77 77X2 ���� ����
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
	//cocos2d::Vector<cocos2d::Sprite*> _slots;
	std::vector<cocos2d::Sprite*> _slots;
	std::vector<SlotType> _slotTypes; // ���Ͻ�Ϊ���
	std::vector<cocos2d::Sprite*> _focusSlots;
	//cocos2d::Sprite* _focusSlot;
	std::vector<int> _slotBettingValues;
	std::vector<int> _slotTotalBettingValues;

	// ����ʱ��
	cocos2d::LabelAtlas* _lotteryCountDownLabel;
	cocos2d::LabelAtlas* _puzzleCountDownLabel;

	int _mid; // machine id
	int _rewardValue;
	GameStatus _status;

	SlotType _sourceSlot;
	SlotType _targetSlot; // prize
	std::vector<SlotType> _threePrize;

	LosePercentType _losePercent;
	int _puzzleValue;

	int _countDownTime;
	NoticeLable* _noticeLable;
private:
};

#endif // __FRUITMACHINEDELUXE_SCENE_H__
