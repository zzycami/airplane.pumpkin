#include "cocos2d.h"

using namespace cocos2d;

class BulletLayer:public Layer
{
public:
	BulletLayer();
	~BulletLayer();
	virtual bool init();
	CREATE_FUNC(BulletLayer);
	void addBullet(float dt);
    void removeBullet(Sprite *bullet);
    void startShoot(float delay = 0.0f);
    void stopShoot();
private:
	SpriteBatchNode *bulletBatchNode;
    void bulletMoveFinished(Node *sender);
    Array *allBullet;
};