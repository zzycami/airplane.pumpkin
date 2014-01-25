#pragma once
#include "cocos2d.h"
#include "PlaneLayer.h"
#include "BulletLayer.h"
#include "EnemyLayer.h"

USING_NS_CC;

class GameLayer:public Layer
{
public:
	GameLayer();
	~GameLayer();
	CREATE_FUNC(GameLayer);
	bool virtual init();
    void virtual onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	void moveBackground(float dt);
    void update(float delta);

private:
	Sprite *background1;
	Sprite *background2;
	PlaneLayer* planeLayer;
    BulletLayer* bulletLayer;
    EnemyLayer* enemyLayer;
};