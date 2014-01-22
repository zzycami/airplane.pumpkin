#pragma once
#include "cocos2d.h"
#include "GameLayer.h"

USING_NS_CC;


class GameScene :public Scene
{
public:
	GameScene(void);
	~GameScene(void);

	virtual bool init();

	GameLayer *_gameLayer;

	CREATE_FUNC(GameScene);
};

