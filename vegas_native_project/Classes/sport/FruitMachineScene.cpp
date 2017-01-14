#include "FruitMachineScene.h"
#include "CocosBuilderLayerLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocosbuilder;

static int MAX_SLOT = 10;
static int MAX_BET = 10;

FruitMachineLayer::FruitMachineLayer()
{


}

bool FruitMachineLayer::init()
{
	// test
	_slotTypes.push_back(Orange);
	_slotTypes.push_back(Bell);
	_slotTypes.push_back(BarX25);
	_slotTypes.push_back(BarX50);
	_slotTypes.push_back(Apple);
	_slotTypes.push_back(AppleX2);
	_slotTypes.push_back(HamiMelon);
	_slotTypes.push_back(WaterMelon);
	_slotTypes.push_back(WaterMelonX2);
	_slotTypes.push_back(GoodLuck1);
	_slotTypes.push_back(Apple);
	_slotTypes.push_back(OrangeX2);
	_slotTypes.push_back(Bell);
	_slotTypes.push_back(Number77X2);
	_slotTypes.push_back(Number77);
	_slotTypes.push_back(Apple);
	_slotTypes.push_back(HamiMelonX2);
	_slotTypes.push_back(HamiMelon);
	_slotTypes.push_back(Star);
	_slotTypes.push_back(StarX2);
	_slotTypes.push_back(GoodLuck2);
	_slotTypes.push_back(Apple);
	_slotTypes.push_back(BellX2);

	auto slot = Sprite::create("Image 272.png");
	slot->setPosition(10, 10);
	slot->setScale(0.25);
	addChild(slot);

	// wait server status
	_status = GameStatus::Wait;

	//Node* ccbNode = loadCCB("", "", CocosBuilderLayerLoader::loader());
	return true;
}

void FruitMachineLayer::startup()
{
	clear();
	_status = GameStatus::CountDownLottery;
}

void FruitMachineLayer::clear()
{
	_countDownTime = 0;
}

void FruitMachineLayer::drawLottery()
{
	int count = (_slots.size() - _sourceSlot) + _slots.size() * 3 + _targetSlot;
	float rate = 2.0f / count;
	for (int i = _sourceSlot; i <= count; ++i)
	{
		auto sp = _slots[i % _slots.size()];
		if (sp != nullptr)
		{
			float delta = rate * i;
			float time = (i - _sourceSlot + 1) * 0.1f + 1.0f - tweenfunc::sineEaseInOut(delta);
			ActionInterval* predelay = DelayTime::create(time);
			log("delay index %d delta %f time  %f", i, delta, time);
			ActionInterval* fadein = FadeIn::create(1);
			//CCActionInterval* delaytime = CCDelayTime::create(0.2);
			

			//CCFiniteTimeAction* seq = CCSequence::create(predelay, fadein, delaytime, fadeout, nullptr);
			FiniteTimeAction* seq = nullptr;
			if (i == count)
			{
				ActionInterval* end = nullptr;
				if (i == SlotType::GoodLuck1 || i == SlotType::GoodLuck2)
				{
					// ��α��ֻ�û���
					seq = Sequence::create(predelay, fadein, end);
				}
				else
				{
					seq = Sequence::create(predelay, fadein, end);
				}
			}
			else
			{
				ActionInterval* fadeout = FadeOut::create(1);
				seq = Sequence::create(predelay, fadein, fadeout, nullptr);
			}

			if (seq != nullptr)
			{
				sp->runAction(seq);
			}
		}
	}
}

void FruitMachineLayer::endLottery()
{
	// ûѺ��ֱ�����¿�ʼ
	clear();
	_status = GameStatus::CountDownPuzzle;
}

void FruitMachineLayer::drawPuzzle()
{

}

void FruitMachineLayer::endPuzzle()
{
	// û���н����������û������Ƿ����������������
	clear();
}

void FruitMachineLayer::drawPrize()
{

}

void FruitMachineLayer::endPrize()
{
	clear();
	_status = GameStatus::CountDownLottery;
}

void FruitMachineLayer::updateCountDownLottery(float delta)
{
	if (_status == GameStatus::CountDownLottery)
	{
		_countDownTime += delta;

		// update count ui

		// lottery
		onLottery();
	}
	
}

void FruitMachineLayer::updateCountDownPuzzle(float delta)
{
	if (_status == GameStatus::CountDownPuzzle)
	{
		_countDownTime += delta;

		// update count ui

		// lottery
		onPuzzle();
	}

}

void FruitMachineLayer::onLottery()
{
	// test code
	_targetSlot = (SlotType)(random() % SlotType::MAX);
	if (random() % 10 > 5)
	{
		_threePrize.push_back((SlotType)(random() % SlotType::MAX));
		_threePrize.push_back((SlotType)(random() % SlotType::MAX));
		_threePrize.push_back((SlotType)(random() % SlotType::MAX));
	}

	drawLottery();
}

void FruitMachineLayer::onPuzzle()
{
	// test code
	_puzzleValue = random() % 10;

	drawPuzzle();
}

void FruitMachineLayer::onPrize()
{
	drawPrize();
}

bool FruitMachineLayer::onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName, cocos2d::Node * pNode)
{
	CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "lotteryCountDownLabel", LabelAtlas*, this->_lotteryCountDownLabel);
	CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "puzzleCountDownLabel", LabelAtlas*, this->_puzzleCountDownLabel);

	// slots
	for (int i = 0; i < _slotTypes.size(); ++i)
	{
		Sprite* tmp = nullptr;
		CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "slot_" + i, Sprite*, tmp);
		_slots.push_back(tmp);
	}

	for (int i = 0; i < _slotTypes.size(); ++i)
	{
		Sprite* tmp = nullptr;
		CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "focus_" + i, Sprite*, tmp);
		_focusSlots.push_back(tmp);
	}

	// betting button
	for (int i = 0; i < _slotTypes.size(); ++i)
	{
		ControlButton* tmp = nullptr;
		CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "betting_" + i, ControlButton*, tmp);
		_bettingButtons.push_back(tmp);
	}
	


	return true;
}

bool FruitMachineLayer::onAssignCCBCustomProperty(cocos2d::Ref* pTarget, const char* pMemberVariableName, const cocos2d::Value& pCCBValue)
{
	return true;
}

void FruitMachineLayer::touchDownBeting(cocos2d::Ref* sender, cocos2d::extension::Control::EventType controlEvent)
{
	if (canBet())
	{
		// do something
	}
}
