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
#include "string.h"
using namespace cocos2d;

const int ENEMY1_MAXLIFE = 1;
const int ENEMY2_MAXLIFE = 3;
const int ENEMY3_MAXLIFE = 5;

const std::string ENEMY1_DOWN = "enemy1_down";
const std::string ENEMY2_DOWN = "enemy2_down";
const std::string ENEMY3_DOWN = "enemy3_down";

class EnemyLayer:public Layer
{
public:
    EnemyLayer();
    ~EnemyLayer();
    virtual bool init();
    CREATE_FUNC(EnemyLayer);
    
    
    void addEnemy1(float dt);
    void enemy1MoveFinished(Node *sender);
    void removeEnemy1(Node *sender);
    void enemy1Blowup(Enemy *enemy1);
    Array *allEnemy1;
    
    void addEnemy2(float dt);
    void enemy2MoveFinished(Node *sender);
    void enemy2Blowup(Enemy *enemy2);
    void removeEnemy2(Node *sender);
    Array *allEnemy2;
    
    void addEnemy3(float dt);
    void enemy3MoveFinished(Node *sender);
    void enemy3Blowup(Enemy *enemy3);
    void removeEnemy3(Node *sender);
    Array *allEnemy3;
    
private:
    Point initEnemyPlace(Enemy *enemy);
    
    SpriteFrame *enemy1SpriteFrame;
    SpriteFrame *enemy2SpriteFrame;
    SpriteFrame *enemy3SpriteFrame1;
    SpriteFrame *enemy3SpriteFrame2;
};