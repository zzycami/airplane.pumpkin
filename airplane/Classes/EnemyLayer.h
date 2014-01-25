//
//  EnemyLayer.h
//  airplane
//
//  Created by damingdan on 14-1-25.
//
//

#pragma once
#include "cocos2d.h"
#include "Enemy.h"
using namespace cocos2d;

const int ENEMY1_MAXLIFE = 1;
const int ENEMY2_MAXLIFE = 3;
const int ENEMY3_MAXLIFE = 5;

class EnemyLayer:public Layer
{
public:
    EnemyLayer();
    ~EnemyLayer();
    virtual bool init();
    CREATE_FUNC(EnemyLayer);
    
    
    void addEnemy1(float dt);
    void enemy1MoveFinished(Node *sender);
    Array *allEnemy1;
    
    void addEnemy2(float dt);
    void enemy2MoveFinished(Node *sender);
    Array *allEnemy2;
    
    void addEnemy3(float dt);
    void enemy3MoveFinished(Node *sender);
    Array *allEnemy3;
    
private:
    Point initEnemyPlace(Enemy *enemy);
    
    SpriteFrame *enemy1SpriteFrame;
    SpriteFrame *enemy2SpriteFrame;
    SpriteFrame *enemy3SpriteFrame1;
    SpriteFrame *enemy3SpriteFrame2;
};