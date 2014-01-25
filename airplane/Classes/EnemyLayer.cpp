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
        
        // add enemies
        this->schedule(schedule_selector(EnemyLayer::addEnemy1), 0.4f);
        this->schedule(schedule_selector(EnemyLayer::addEnemy2), 1.0f);
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


void EnemyLayer::addEnemy3(float dt)
{
    // create enemy3
    
    // random the init place
    
    // add frame animation
    
    // add move animation
}

void EnemyLayer::enemy3MoveFinished(cocos2d::Node *sender)
{
    
}











