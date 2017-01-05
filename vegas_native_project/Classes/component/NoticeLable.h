#ifndef __NOTICE_LABLE_H__
#define __NOTICE_LABLE_H__

#include "cocos2d.h"
//#include "cocosbuilder/CocosBuilder.h"

#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

class NoticeLable : public cocos2d::Node
{
public:
	static NoticeLable* createWithSystemFont(const std::string& boardFile, const std::string& fontFilePath, float fontSize, float noticeDelta);


	int pushString(std::string str);

CC_CONSTRUCTOR_ACCESS :
	NoticeLable();
	virtual ~NoticeLable();

	/* Initializes an empty sprite with no parameters. */
	bool initWithSystemFont(const std::string& boardFile, const std::string& fontFilePath, float fontSize, float noticeDelta);

	/**
	* Initializes a sprite with a texture.
	*
	* After initialization, the rect used will be the size of the texture, and the offset will be (0,0).
	*
	* @param   texture    A pointer to an existing Texture2D object.
	*                      You can use a Texture2D object for many sprites.
	* @return  True if the sprite is initialized properly, false otherwise.
	*/
	//virtual bool initWithTexture(Texture2D *texture);

	virtual void onCollapse();
	virtual void endCollapse();
	virtual void onToggle();
	virtual void endToggle();
	virtual void onScroll();
	virtual void endScroll();
	

	void update(float delta) override;

protected:
	// mask
	cocos2d::ClippingNode* _clipingNode;
	cocos2d::DrawNode* _drawNode;
	cocos2d::Size _clipingSize;

	//cocos2d::Action* _collapseAction;
	//cocos2d::Action* _toggleAction;

	cocos2d::Sprite* _board;
	cocos2d::Label* _label;

	std::queue<std::string> _notices;
	bool _isToggle;
	bool _isScroll;
	bool _isPlayAction;
	float _fontSize;
	float _noticeDelta;
	float _delta;

private:
	CC_DISALLOW_COPY_AND_ASSIGN(NoticeLable);

};

#endif // __NOTICE_LABLE_H__
