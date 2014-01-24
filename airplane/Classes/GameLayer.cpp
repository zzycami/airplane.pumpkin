#include "GameLayer.h"

GameLayer::GameLayer(void)
{
	background1 = NULL;
	background2 = NULL;
}

GameLayer::~GameLayer(void)
{}

bool GameLayer::init()
{
	if(Layer::init()){
		// Add backgrounds to cache
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot_background.plist");

		// Load background 1
		background1 = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("background.png"));
		background1->setAnchorPoint(Point(0, 0));
		background1->setPosition(Point(0, 0));
		background1->getTexture()->setAntiAliasTexParameters();
		this->addChild(background1);

		// Load background 2
		background2 = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("background.png"));
		background2->setAnchorPoint(Point(0, 0));
		background2->getTexture()->setAntiAliasTexParameters();
		background2->setPosition(Point(0, background2->getContentSize().height - 2));
		this->addChild(background2);

		// Add the hero layer
		this->planeLayer = PlaneLayer::create();
		this->addChild(this->planeLayer);
        
        // Add the bullet to layer and start to shoot
        this->bulletLayer = BulletLayer::create();
        this->addChild(this->bulletLayer);
        this->bulletLayer->startShoot();

		this->schedule(schedule_selector(GameLayer::moveBackground), 0.01f);
		return true;
	}
	return false;
}

void GameLayer::moveBackground(float dt)
{
	background1->setPositionY(background1->getPositionY() - 2);
	background2->setPositionY(background1->getPositionY() + background1->getContentSize().height - 2);
	if (background2->getPositionY() == 0)
	{
		// If background 2 is nearly to the bottom of the screen, bring background 1.
		background1->setPositionY(0);
	}
}