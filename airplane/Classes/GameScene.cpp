#include "GameScene.h"


GameScene::GameScene(void)
{
	_gameLayer = NULL;
}


GameScene::~GameScene(void)
{
}

bool GameScene::init()
{
	if(Scene::init()){
		_gameLayer = GameLayer::create();
		if (_gameLayer){
			this->addChild(_gameLayer);
			return true;
		}
	}
	return false;
}