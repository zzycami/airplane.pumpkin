#include "BulletLayer.h"
#include "PlaneLayer.h"

BulletLayer::BulletLayer()
{
	bulletBatchNode = NULL;
}

BulletLayer::~BulletLayer()
{}

bool BulletLayer::init()
{
	if(Layer::init()){
		Texture2D *texture = TextureCache::getInstance()->textureForKey("ui/shoot.png");
		bulletBatchNode = SpriteBatchNode::createWithTexture(texture);
		this->addChild(bulletBatchNode);
		return true;
	}else {
		return false;
	}
}

void BulletLayer::addBullet(float dt)
{
	Sprite *bullet = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("bullet1.png"));
	bulletBatchNode->addChild(bullet);

	// Set the bullet first place
	Point planePoint = PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getPosition();
	bullet->setPosition(planePoint.x, planePoint.y + PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getContentSize().height*0.5);

	// Set bullet animation
}