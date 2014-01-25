#include "BulletLayer.h"
#include "PlaneLayer.h"

BulletLayer::BulletLayer()
{
	bulletBatchNode = NULL;
    allBullet = Array::create();
    allBullet->retain();
}

BulletLayer::~BulletLayer()
{
    allBullet->release();
    allBullet = NULL;
}

bool BulletLayer::init()
{
	if(Layer::init()){
        //Texture2D *texture = Director::getInstance()->getTextureCache()->getTextureForKey("shoot.png");
		//bulletBatchNode = SpriteBatchNode::createWithTexture(texture);
        bulletBatchNode = SpriteBatchNode::create("shoot.png");
		this->addChild(bulletBatchNode);
		return true;
	}else {
		return false;
	}
}

void BulletLayer::startShoot(float delay)
{
    this->schedule(schedule_selector(BulletLayer::addBullet), 0.1f, kRepeatForever, delay);
}

void BulletLayer::stopShoot()
{
    this->unschedule(schedule_selector(BulletLayer::addBullet));
}

void BulletLayer::addBullet(float dt)
{
	Sprite *bullet = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("bullet1.png"));
	bulletBatchNode->addChild(bullet);
    allBullet->addObject(bullet);

	// Set the bullet first place
	Point planePoint = PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getPosition();
	bullet->setPosition(planePoint.x, planePoint.y + PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getContentSize().height*0.5);

	// Set bullet animation
    float length = Director::getInstance()->getWinSize().height + bullet->getContentSize().height*0.5 - bullet->getPositionY();
    float speed = 420/1;
    float moveDuration = length/speed;
    FiniteTimeAction *actionMove = MoveTo::create(moveDuration, Point(bullet->getPositionX(), Director::getInstance()->getWinSize().height + bullet->getContentSize().height*0.5));
    FiniteTimeAction *actionDone = CallFuncN::create(this, callfuncN_selector(BulletLayer::bulletMoveFinished));
    Sequence *sequence = Sequence::create(actionMove, actionDone, NULL);
    bullet->runAction(sequence);
}

void BulletLayer::bulletMoveFinished(Node *sender)
{
    Sprite *bullet = (Sprite *)sender;
    bullet->removeFromParent();
    //bulletBatchNode->removeChild(bullet, true);
    allBullet->removeObject(bullet);
}

void BulletLayer::removeBullet(Sprite *bullet)
{
    if (bullet != NULL) {
        //bulletBatchNode->removeChild(bullet, true);
        bullet->removeFromParent();
        allBullet->removeObject(bullet);
    }
}

