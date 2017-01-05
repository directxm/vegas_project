#ifndef __DIGITALSCROLL_LABLE_H__
#define __DIGITALSCROLL_LABLE_H__

#include "cocos2d.h"

class DigitalIntegerLable : public cocos2d::Node
{
public:
	static DigitalIntegerLable* create(float duration, const std::string& string, const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap);

	void setNumber(int number, bool immediately = false);
	void setTime(float time);

CC_CONSTRUCTOR_ACCESS :
	DigitalIntegerLable();
	virtual ~DigitalIntegerLable();

	bool init(float duration, const std::string& string, const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap);

	void update(float delta) override;

protected:
	cocos2d::LabelAtlas* _labelAtlas;
	bool _isVertical;
	int _currentValue;
	int _targetValue;
	float _fontHeight;
	float _fontWidth;

	float _duration;

	float _moveDistance;
	float _speed;
private:
};


class DigitalIntegerScrollLable : public cocos2d::Node
{
public:
	static DigitalIntegerScrollLable* create(float duration, const std::string& string, const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap);

	void setNumber(int number, bool immediately = false);

CC_CONSTRUCTOR_ACCESS :
	DigitalIntegerScrollLable();
	virtual ~DigitalIntegerScrollLable();

	bool init(float duration, const std::string& string, const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap);

protected:
	cocos2d::Vector<DigitalIntegerLable*> _columns;
	int _currentValue;
	int m_length;
	int m_time;
	int m_fontSize;
	cocos2d::Node* _visibleNode;

private:
};




#endif // __DIGITALSCROLL_LABLE_H__