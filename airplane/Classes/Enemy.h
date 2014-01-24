//
//  Enemy.h
//  airplane
//
//  Created by damingdan on 14-1-24.
//
//

#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class Enemy: public Node
{
public:
    Enemy();
    ~Enemy();
    virtual bool init();
    static Enemy* create();
    void bindSprite(Sprite* sprite, int life);
    Sprite* getSprite();
    int getLife();
    void loseLife();
    Rect getBoundingBox();
    
private:
    Sprite *sprite;
    int life;
};