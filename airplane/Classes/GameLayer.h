#pragma once
#include "cocos2d.h"
#include "PlaneLayer.h"
#include "BulletLayer.h"

USING_NS_CC;

class GameLayer:public Layer
{
public:
	GameLayer();
	~GameLayer();

	CREATE_FUNC(GameLayer);
	bool virtual init();

	void moveBackground(float dt);

private:
	Sprite *background1;
	Sprite *background2;
	PlaneLayer* planeLayer;
    BulletLayer* bulletLayer;
};