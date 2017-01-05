#include "NumberScroller.h"

NumberColumn::NumberColumn():
	m_cur_num(0),
	m_target_num(0),
	m_time(1.0f),
	update_moveSum(0),
	update_speed(0)
{

}

NumberColumn* NumberColumn::create(int fontSize){
	NumberColumn* ret = new NumberColumn();
	if(ret && ret->init(fontSize)){
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool NumberColumn::init(int fontSize){
	if(!Node::init())	return false;
	m_numbers = Node::create();
	this->addChild(m_numbers);
	m_fontSize = fontSize;

	this->scheduleUpdate();

	for(int i=0;i<10;i++){
		char str[2];
		str[0] = i + '0';
		str[1] = '\0';

		Label* temp = Label::create(str,"",fontSize);
		temp->setAnchorPoint(Point(0,0));
		temp->setPosition(Point(0,i * fontSize));
		m_numbers->addChild(temp);
	}
	char str[2];
	str[0]='0';
	str[1]='\0';
	Label* temp = Label::create(str,"",fontSize);
	temp->setAnchorPoint(Point(0,0));
	temp->setPosition(Point(0,10 * fontSize));
	m_numbers->addChild(temp);

	return true;
}
void NumberColumn::setNumber(int number,bool direction){
	m_target_num = number;
	int delta = m_target_num - m_cur_num;
	update_speed = (delta * m_fontSize / m_time);
}

void NumberColumn::setTime(float time){
	m_time = time;
}

void NumberColumn::update(float d){
	if(m_cur_num != m_target_num){
		float dis = update_speed*d;
		m_numbers->setPositionY(m_numbers->getPositionY() - dis);
		update_moveSum += dis;
		if(update_moveSum >= m_fontSize){
			m_cur_num++;
			m_numbers->setPositionY( - m_cur_num%10 * m_fontSize);
			update_moveSum = 0; 
		}
	}
}

/************************************************************************/

NumberScroller::NumberScroller():
	m_cur_num(0),
	m_length(0),
	m_time(1.0f)
{

}

NumberScroller* NumberScroller::create(int length,int fontSize){
	NumberScroller* ret = new NumberScroller();
	if(ret && ret->init(length,fontSize)){
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool NumberScroller::init(int length,int fontSize){
	if(!Node::init())	return false;
	m_length = length;
	m_fontSize = fontSize;
	m_visibleNode = Node::create();
	
	//排好length行数字
	for(int i=0;i<length;i++){
		NumberColumn* column = NumberColumn::create(fontSize);
		m_columns.pushBack(column);
		column->setAnchorPoint(Point(0,0));
		column->setPosition(i * fontSize,0);
		column->setTime(m_time);
		m_visibleNode->addChild(column);
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
	this->addChild(m_visibleNode);
}

void NumberScroller::setNumber(int number){
	if(number > m_cur_num){
		m_cur_num = number;

		for(int i=0;i<m_length;i++){
			m_columns.at(m_length - i -1)->setNumber(number);
			number /= 10;
		}		
	}
}

int NumberScroller::getNumber(){
	return m_cur_num;
}

void NumberScroller::setTime(float time){
	m_time = time;
	for(int i=0;i<m_length;i++){
		m_columns.at(i)->setTime(time);
	}	
}
