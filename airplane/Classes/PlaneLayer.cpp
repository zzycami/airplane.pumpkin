#include "PlaneLayer.h"

PlaneLayer* PlaneLayer::sharedPlane = NULL;

PlaneLayer::PlaneLayer()
{}

PlaneLayer::~PlaneLayer()
{}

bool PlaneLayer::init()
{
	if(Layer::init()){
		// Add plane sprite
		Size winSize = Director::getInstance()->getWinSize();
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot.plist");
		Sprite *plane = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero1.png"));
		plane->setPosition(winSize.width*0.5, plane->getContentSize().height*0.5);
		this->addChild(plane,0,AIRPLANE);

		// Add blank animation
		Blink *blank = Blink::create(1, 3);
		plane->runAction(blank);

		// Add frame animation
		Animation *animation = Animation::create();
		animation->setDelayPerUnit(0.1f);
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero1.png"));
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero2.png"));
		Animate *animate = Animate::create(animation);
		plane->runAction(RepeatForever::create(animate));
		return true;
	}
	return false;
}

 PlaneLayer* PlaneLayer::create()
{
	PlaneLayer* pRet = new PlaneLayer();
	if (pRet && pRet->init()){
		pRet->autorelease();
		PlaneLayer::sharedPlane = pRet;
		return pRet;
	}else {
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}