#include "NoticeLable.h"
#include "ui\UIScale9Sprite.h"

USING_NS_CC;
using namespace ui;

NoticeLable::NoticeLable()
{
	_clipingNode = nullptr;
	_drawNode = nullptr;
	_clipingSize = Size::ZERO;

	//_collapseAction = nullptr;
	//_toggleAction = nullptr;

	_board = nullptr;
	_label = nullptr;

	_notices;
	_isToggle = false;
	_isScroll = false;
	_isPlayAction = false;
	_noticeDelta = 0.0f;
	_delta = 0.0f;
}

NoticeLable::~NoticeLable()
{
	this->stopAllActions();

	if (_clipingNode)
	{
		//_clipingNode->release();
	}
	//CC_SAFE_DELETE(_clipingNode);

	if (_drawNode)
	{
		//_drawNode->release();
	}
	//CC_SAFE_DELETE(_drawNode);

	if (_board)
	{
		//_board->resetRender();
		//_board->release();
	}
	//CC_SAFE_DELETE(_board);

	if (_label)
	{
		//_label->release();
	}
	//CC_SAFE_DELETE(_label);

	for (int i = 0; !_notices.empty(); ++i)
	{
		_notices.pop();
	}

}

NoticeLable* NoticeLable::createWithSystemFont(const std::string& boardFile, const std::string& fontFilePath, float fontSize, float noticeDelta)
{
	NoticeLable *ret = new (std::nothrow) NoticeLable();

	if (ret && ret->initWithSystemFont(boardFile, fontFilePath, fontSize, noticeDelta))
	{
		ret->autorelease();
		return ret;
	}

	delete ret;
	return nullptr;
}

int NoticeLable::pushString(std::string str)
{
	// startup update schedule
	scheduleUpdate();

	_notices.push(str);

	return _notices.size();
}

bool NoticeLable::initWithSystemFont(const std::string& boardFile, const std::string& fontFilePath, float fontSize, float noticeDelta)
{
	if (!Node::init()) return false;

	_isToggle = false;
	_isScroll = false;

	_board = Sprite::create(boardFile);
	_clipingNode = ClippingNode::create();
	_drawNode = DrawNode::create();
	_clipingSize = _board->getContentSize();
	addChild(_board);

	_label = Label::createWithSystemFont("NoticeLable", fontFilePath, fontSize);
	_label->setVisible(false);
	_label->setLineBreakWithoutSpace(false);
	//addChild(_label);

	Point points[] = { Point(_board->getPositionX() - _clipingSize.width * 0.5, _board->getPositionY() - _clipingSize.height * 0.5),
		Point(_board->getPositionX() - _clipingSize.width * 0.5, _board->getPositionY() + _clipingSize.height),
		Point(_board->getPositionX() + _clipingSize.width * 0.5, _board->getPositionY() + _clipingSize.height), 
		Point(_board->getPositionX() + _clipingSize.width * 0.5, _board->getPositionY() - _clipingSize.height * 0.5) 
	};
	_drawNode->drawPolygon(points, 4, Color4F(0, 0, 0, 1), 20, Color4F(0, 0, 0, 1));

	_clipingNode->setStencil(_drawNode);
	_clipingNode->addChild(_label);
	//_clipingNode->addChild(_board);
	addChild(_clipingNode);
	//addChild(_label, 99999);

	//auto bar = Sprite::create("bar.png");
	//addChild(bar);
	//_clipingSize = bar->getContentSize();

	_fontSize = fontSize;
	_noticeDelta = noticeDelta;

	return true;
}

void NoticeLable::onCollapse()
{
	_isPlayAction = true;
	runAction(Sequence::create(
		ScaleTo::create(2, 1, 0.01),
		CallFunc::create(CC_CALLBACK_0(NoticeLable::endToggle, this)),
		nullptr)
		);

}

void NoticeLable::endCollapse()
{
	_isToggle = false;
	_isPlayAction = false;
	setVisible(false);
}

void NoticeLable::onToggle()
{
	_isPlayAction = true;
	setVisible(true);
	setScaleY(0.01f);

	runAction(Sequence::create(
		ScaleTo::create(2, 1, 1),
		CallFunc::create(CC_CALLBACK_0(NoticeLable::endToggle, this)),
		nullptr)
		);
}

void NoticeLable::endToggle()
{
	_isToggle = true;
	_isPlayAction = false;
}

void NoticeLable::onScroll()
{
	_isPlayAction = true;
	_isScroll = true;
	_delta = 0;
	std::string str = _notices.front();
	if (str.size() > 0 && _label)
	{
		_notices.pop();
		
		_label->setString(str);
		float fontWidth = _label->getStringLength() * _fontSize * _label->getScale();
		Point startPoint = Point(0 + _clipingSize.width * 0.5 + fontWidth * 0.5, 0);
		_label->setPosition(startPoint);
		_label->setVisible(true);

		Point endPoint = Point(0 - _clipingSize.width * 0.5 - fontWidth * 0.5, 0);
		_label->runAction(Sequence::create(
			MoveTo::create(endPoint.distance(startPoint) * 0.02, endPoint),
			CallFunc::create(CC_CALLBACK_0(NoticeLable::endScroll, this)),
			nullptr)
			);
	}
}

void NoticeLable::endScroll()
{
	_isScroll = false;
	_isPlayAction = false;
	_label->setVisible(false);
}

void NoticeLable::update(float delta)
{
	// no action
	if (!_isPlayAction)
	{
		if (!_isToggle)
		{
			onToggle();
			return;
		}
		else
		{
			if (!_notices.empty())
			{
				if (_delta >= _noticeDelta)
				{
					onScroll();
				}
				else
				{
					_delta += delta;
				}
			}
			// ending logic
			else if (_notices.empty() && !_isScroll)
			{
				// stop update schedule
				unscheduleUpdate();
				onCollapse();
			}
		}
	}
}