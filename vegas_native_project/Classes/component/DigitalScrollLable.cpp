#include "DigitalScrollLable.h"

USING_NS_CC;

DigitalIntegerLable::DigitalIntegerLable()
{
	
	_labelAtlas = nullptr;
	_isVertical = true;
	_currentValue = 0;
	_targetValue = 0;
	_fontHeight = 0;
	_fontWidth = 0;

	_duration = 0;

	_moveDistance = 0;
	_speed = 0;
}

DigitalIntegerLable::~DigitalIntegerLable()
{

}

DigitalIntegerLable* DigitalIntegerLable::create(float duration, const std::string& string, const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap)
{
	DigitalIntegerLable *ret = new (std::nothrow) DigitalIntegerLable();

	if (ret && ret->init(duration, string, charMapFile, itemWidth, itemHeight, startCharMap))
	{
		ret->autorelease();
		return ret;
	}

	delete ret;
	return nullptr;
}

bool DigitalIntegerLable::init(float duration, const std::string& string, const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap)
{
	if (!Node::init()) return false;

	_labelAtlas = LabelAtlas::create(string, charMapFile);

	Size a = _labelAtlas->getContentSize();

	// 字体制作时需要旋转90度
	if (_isVertical)
		_labelAtlas->setRotation(90);
	_labelAtlas->setAnchorPoint(Point(0, 0));
	_labelAtlas->setPosition(0, 0);
	this->addChild(_labelAtlas);
	_fontHeight = itemHeight;
	_fontWidth = itemWidth;
	_currentValue = 0;
	_duration = duration;


	//auto label1 = LabelAtlas::create("0123456789", "fonts/tuffy_bold_italic-charmap.plist");
	//addChild(label1);
	//label1->setPosition(Vec2(10, 100));
	//label1->setOpacity(200);

	return true;
}

void DigitalIntegerLable::setNumber(int number, bool immediately)
{
	if (immediately)
	{
		_currentValue = number;
		if (_isVertical)
		{
			_labelAtlas->setPositionY(-_currentValue % 10 * _fontHeight);
		}
		else
		{
			_labelAtlas->setPositionX(-_currentValue % 10 * _fontWidth);
		}
	}
	else
	{
		this->scheduleUpdate();

		_targetValue = number;
		int delta = _targetValue - _currentValue;

		if (_isVertical)
		{
			if (delta >= 0)
				_speed = -10;
			else
				_speed = 10;
		}
		else
		{
			if (delta >= 0)
				_speed = 10;
			else
				_speed = -10;
		}

		//_speed = 10.0f * (delta >= 0) ? 1.0f : -1.0f;//(delta * _fontHeight / _duration);

		/*if (_isVertical)
			_speed = 10;//(delta * _fontHeight / _duration);
		else
			_speed = 10;//(delta * _fontWidth / _duration);*/
	}
}

void DigitalIntegerLable::setTime(float time)
{
	time = time;
}

void DigitalIntegerLable::update(float delta)
{
	if (_currentValue != _targetValue)
	{
		float dis = _speed * delta;

		if (_isVertical)
			_labelAtlas->setPositionY(_labelAtlas->getPositionY() - dis);
		else
			_labelAtlas->setPositionX(_labelAtlas->getPositionX() - dis);
		
		_moveDistance += dis;
		
		if (_isVertical)
		{
			if (_moveDistance >= _fontHeight)
			{
				_currentValue += (_currentValue > _targetValue) ? -1 : 1;
				_labelAtlas->setPositionY(-_currentValue % 10 * _fontHeight);
				_moveDistance = 0;
				
			}
		}
		else
		{
			if (_moveDistance >= _fontWidth)
			{
				_currentValue += (_currentValue > _targetValue) ? -1 : 1;
				_labelAtlas->setPositionX(-_currentValue % 10 * _fontWidth);
				_moveDistance = 0;
			}
		}
		

		if (_currentValue == _targetValue)
		{
			unscheduleUpdate();
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////

DigitalIntegerScrollLable::DigitalIntegerScrollLable()
{

}

DigitalIntegerScrollLable::~DigitalIntegerScrollLable()
{

}

DigitalIntegerScrollLable* DigitalIntegerScrollLable::create(float duration, const std::string& string, const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap)
{
	DigitalIntegerScrollLable *ret = new (std::nothrow) DigitalIntegerScrollLable();

	if (ret && ret->init(duration, string, charMapFile, itemWidth, itemHeight, startCharMap))
	{
		ret->autorelease();
		return ret;
	}

	delete ret;
	return nullptr;
}

bool DigitalIntegerScrollLable::init(float duration, const std::string& string, const std::string& charMapFile, int itemWidth, int itemHeight, int length)
{
	if (!Node::init())	return false;
	//m_length = length;
	//m_fontSize = fontSize;
	_visibleNode = Node::create();

	//排好length行数字
	for (int i = 0; i< length; i++)
	{
		DigitalIntegerLable* column = DigitalIntegerLable::create(duration, string, charMapFile, itemWidth, itemHeight, 0);
		_columns.pushBack(column);
		column->setAnchorPoint(Point(0, 0));

		//column->setPosition(i * fontSize, 0);
		column->setTime(m_time);
		_visibleNode->addChild(column);
	}
	/*设置遮罩层*/
	/*ClippingNode* cliper = ClippingNode::create();
	DrawNode* drawNode = DrawNode::create();
	Point points[] = {Point(getPosition()),Point(getPositionX(),getPositionY()+m_fontSize),
	Point(getPositionX()+m_length*m_fontSize,getPositionY()+m_fontSize),Point(getPositionX()+m_length*m_fontSize,getPositionY())};
	drawNode->drawPolygon(points,4,Color4F(0,0,0,1),0,Color4F(0,0,0,1));

	cliper->setStencil(drawNode);
	cliper->addChild(m_visibleNode);
	this->addChild(cliper);*/
	this->addChild(_visibleNode);

	return true;
}

void DigitalIntegerScrollLable::setNumber(int number, bool immediately)
{
	if (number > _currentValue)
	{
		_currentValue = number;

		for (int i = 0; i < m_length; i++)
		{
			_columns.at(m_length - i - 1)->setNumber(number);
			number /= 10;
		}
	}
}