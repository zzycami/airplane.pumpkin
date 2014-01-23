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

private:
	SpriteBatchNode *bulletBatchNode;
};