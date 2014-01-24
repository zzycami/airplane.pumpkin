//
//  Enemy.c
//  airplane
//
//  Created by damingdan on 14-1-24.
//
//

#include "Enemy.h"

Enemy::Enemy()
{
    sprite = NULL;
    life = 0;
}

Enemy::~Enemy()
{}

Enemy* Enemy::create()
{
    Enemy *ret = new Enemy();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }else {
        CC_SAFE_DELETE(ret);
        return NULL;
    }
}

bool Enemy::init(){
    if (Node::init()) {
        return true;
    }else {
        return false;
    }
}

void Enemy::bindSprite(Sprite* sprite, int life)
{
}

Sprite* Enemy::getSprite()
{
    return sprite;
}

int Enemy::getLife()
{
    return life;
}

void Enemy::loseLife(){}


Rect Enemy::getBoundingBox(){
    return NULL;
}
