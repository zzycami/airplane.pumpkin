//
//  EnemyLayer.cpp
//  airplane
//
//  Created by damingdan on 14-1-25.
//
//

#include "EnemyLayer.h"

EnemyLayer::EnemyLayer()
{
    this->allEnemy1 = Array::create();
    this->allEnemy1->retain();
    this->enemy1SpriteFrame = NULL;
    
    this->allEnemy2 = Array::create();
    this->allEnemy2->retain();
    this->enemy1SpriteFrame = NULL;
    
    this->allEnemy3 = Array::create();
    this->allEnemy3->retain();
    this->enemy3SpriteFrame1 = NULL;
    this->enemy3SpriteFrame2 = NULL;
}

EnemyLayer::~EnemyLayer()
{
    this->allEnemy1->release();
    this->allEnemy1 = NULL;
    
    this->allEnemy2->release();
    this->allEnemy2 = NULL;
    
    this->allEnemy3->release();
    this->allEnemy3 = NULL;
}

bool EnemyLayer::init()
{
    if (Layer::init()) {
        enemy1SpriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy1.png");
        enemy2SpriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy2.png");
        enemy3SpriteFrame1 = SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_n1.png");
        enemy3SpriteFrame2 = SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_n2.png");
        
        // cache all blowup animation
        Animation *animation1 = Animation::create();
        animation1->setDelayPerUnit(0.1f);
        animation1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy1_down1.png"));
        animation1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy1_down2.png"));
        animation1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy1_down3.png"));
        animation1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy1_down4.png"));
        AnimationCache::getInstance()->addAnimation(animation1, ENEMY1_DOWN);
        
        Animation *animation2 = Animation::create();
        animation2->setDelayPerUnit(0.1f);
        animation2->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy2_down1.png"));
        animation2->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy2_down2.png"));
        animation2->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy2_down3.png"));
        animation2->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy2_down4.png"));
        AnimationCache::getInstance()->addAnimation(animation2, ENEMY2_DOWN);
        
        Animation *animation3 = Animation::create();
        animation3->setDelayPerUnit(0.1f);
        animation3->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_down1.png"));
        animation3->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_down2.png"));
        animation3->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_down3.png"));
        animation3->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_down4.png"));
        animation3->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_down5.png"));
        animation3->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("enemy3_down6.png"));
        AnimationCache::getInstance()->addAnimation(animation3, ENEMY3_DOWN);
        
        // add enemies
        this->schedule(schedule_selector(EnemyLayer::addEnemy1), 0.4f);
        this->schedule(schedule_selector(EnemyLayer::addEnemy2), 1.0f);
        this->schedule(schedule_selector(EnemyLayer::addEnemy3), 2.0f);
        return true;
    }else {
        return false;
    }
}

// random the initial place
Point EnemyLayer::initEnemyPlace(Enemy *enemy)
{
    Size winSize = Director::getInstance()->getWinSize();
    Size spriteSize = enemy->getContentSize();
    int range = winSize.width - spriteSize.width;
    float initialX = (rand() % range) + spriteSize.width*0.5;
    Point position = Point(initialX, winSize.height + spriteSize.height*0.5);
    enemy->setPosition(position);
    return position;
}

void EnemyLayer::addEnemy1(float dt)
{
    // create enemy1
    Enemy *enemy1 = Enemy::create();
    enemy1->bindSprite(Sprite::createWithSpriteFrame(enemy1SpriteFrame), ENEMY1_MAXLIFE);
    this->addChild(enemy1);
    allEnemy1->addObject(enemy1);
    
    // random the initial place
    Point position = initEnemyPlace(enemy1);
    
    // add movement animation
    float minDuration = 4.0;
    float maxDuration = 6.0;
    int durationRange = maxDuration - minDuration;
    float duration = (rand() % durationRange) + minDuration;
    FiniteTimeAction *actionMove = MoveTo::create(duration, Point(position.x, - enemy1->getSprite()->getContentSize().height*0.5));
    FiniteTimeAction *actionDone = CCCallFuncN::create(this, callfuncN_selector(EnemyLayer::enemy1MoveFinished));
    Sequence *sequence = Sequence::create(actionMove, actionDone, NULL);
    enemy1->runAction(sequence);
}

void EnemyLayer::enemy1MoveFinished(Node *sender)
{
    Enemy *enemy1 = (Enemy *) sender;
    enemy1->removeFromParent();
    allEnemy1->removeObject(enemy1);
}

void EnemyLayer::enemy1Blowup(Enemy *enemy1)
{
    Animation *animation = AnimationCache::getInstance()->getAnimation(ENEMY1_DOWN);
    Animate *animate = Animate::create(animation);
	CCCallFuncND *actionDone = CCCallFuncND::create(this, callfuncND_selector(EnemyLayer::removeEnemy1), enemy1);
    Sequence *sequence = Sequence::create(animate, actionDone, NULL);
    enemy1->getSprite()->runAction(sequence);
}

void EnemyLayer::removeEnemy1(cocos2d::Node *target, void* data)
{
    Enemy *enemy1 = (Enemy *) data;
    if (enemy1 != NULL) {
        enemy1->removeFromParent();
        allEnemy1->removeObject(enemy1);
    }
}

void EnemyLayer::addEnemy2(float dt)
{
    // create enemy2
    Enemy *enemy2 = Enemy::create();
    enemy2->bindSprite(Sprite::createWithSpriteFrame(enemy2SpriteFrame), ENEMY2_MAXLIFE);
    this->addChild(enemy2);
    allEnemy2->addObject(enemy2);
    
    // random the init place
    Point position = initEnemyPlace(enemy2);
    
    // add movement ainmation
    float minDuration = 6.0;
    float maxDuration = 8.0;
    int durationRange = maxDuration - minDuration;
    float duration = (rand() % durationRange) + minDuration;
    FiniteTimeAction *actionMove = MoveTo::create(duration, Point(position.x, - enemy2->getSprite()->getContentSize().height*0.5));
    FiniteTimeAction *actionDone = CCCallFuncN::create(this, callfuncN_selector(EnemyLayer::enemy2MoveFinished));
    Sequence *sequence = Sequence::create(actionMove, actionDone, NULL);
    enemy2->runAction(sequence);
}


void EnemyLayer::enemy2MoveFinished(cocos2d::Node *sender)
{
    Enemy *enemy2 = (Enemy *) sender;
    enemy2->removeFromParent();
    allEnemy2->removeObject(enemy2);
}

void EnemyLayer::enemy2Blowup(Enemy *enemy2)
{
    Animation *animation= AnimationCache::getInstance()->getAnimation(ENEMY2_DOWN);
    Animate *animate = Animate::create(animation);
	FiniteTimeAction *actionDone = CCCallFuncND::create(this, callfuncND_selector(EnemyLayer::removeEnemy2), enemy2);
    Sequence *sequence = Sequence::create(animate, actionDone, NULL);
    enemy2->getSprite()->runAction(sequence);
}

void EnemyLayer::removeEnemy2(cocos2d::Node *target, void* data)
{
    Enemy *enemy2 = (Enemy *) data;
    if (enemy2 != NULL) {
        enemy2->removeFromParent();
        allEnemy2->removeObject(enemy2);
    }
}


void EnemyLayer::addEnemy3(float dt)
{
    // create enemy3
    Enemy *enemy3 = Enemy::create();
    enemy3->bindSprite(Sprite::createWithSpriteFrame(enemy3SpriteFrame1), ENEMY3_MAXLIFE);
    this->addChild(enemy3);
    allEnemy3->addObject(enemy3);
    
    // random the init place
    Point position = initEnemyPlace(enemy3);
    
    // add frame animation
    Animation *animation = Animation::create();
    animation->setDelayPerUnit(0.2f);
    animation->addSpriteFrame(enemy3SpriteFrame1);
    animation->addSpriteFrame(enemy3SpriteFrame2);
    Animate *animate = Animate::create(animation);
    enemy3->getSprite()->runAction(RepeatForever::create(animate));
    
    // add move animation
    float minDuration = 10.0;
    float maxDuration = 12.0;
    int range = maxDuration - minDuration;
    float duration = (rand()%range) + minDuration;
    FiniteTimeAction *actionMove = MoveTo::create(duration, Point(position.x, - enemy3->getSprite()->getContentSize().height*0.5));
    FiniteTimeAction *actionDone = CCCallFuncN::create(this, callfuncN_selector(EnemyLayer::enemy3MoveFinished));
    Sequence *sequence = Sequence::create(actionMove, actionDone, NULL);
    enemy3->runAction(sequence);
}

void EnemyLayer::enemy3MoveFinished(cocos2d::Node *sender)
{
    Enemy *enemy3 = (Enemy *) sender;
    enemy3->removeFromParent();
    allEnemy3->removeObject(enemy3);
}

void EnemyLayer::enemy3Blowup(Enemy *enemy3)
{
    Animation *animation= AnimationCache::getInstance()->getAnimation(ENEMY3_DOWN);
    Animate *animate = Animate::create(animation);
	FiniteTimeAction *actionDone = CCCallFuncND::create(this, callfuncND_selector(EnemyLayer::removeEnemy3), enemy3);
    Sequence *sequence = Sequence::create(animate, actionDone, NULL);
	enemy3->getSprite()->stopAllActions();
    enemy3->getSprite()->runAction(sequence);
}

void EnemyLayer::removeEnemy3(cocos2d::Node *target, void* data)
{
    Enemy *enemy3 = (Enemy *) data;
    if (enemy3 != NULL) {
		enemy3->stopAllActions();
        enemy3->removeFromParent();
        allEnemy2->removeObject(enemy3);
    }
}










