#ifndef _NUMBERSCROLLER_H_
#define _NUMBERSCROLLER_H_

#include "cocos2d.h"
USING_NS_CC;

class NumberColumn : public Node{
private:
	NumberColumn();
public:
	static NumberColumn* create(int fontSize);
	void setNumber(int number,bool direction=true);
	void setTime(float time);
private:
	bool init(int fontSize);
	void update(float delta);
private:
	Node* m_numbers;
	int m_cur_num;
	int m_target_num;
	int m_fontSize;

	float m_time;

	float update_moveSum;
	float update_speed;
};



class NumberScroller : public Node{
private:
	NumberScroller();
public:
	static NumberScroller* create(int length,int fontSize);
	void setTime(float time);
	void setNumber(int number);
	int getNumber();
private:
	bool init(int length,int fontSize);
private:
	Vector<NumberColumn*> m_columns;
	int m_cur_num;
	int m_length;
	int m_time;
	int m_fontSize;
	Node* m_visibleNode;
};
#endif