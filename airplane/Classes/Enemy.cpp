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
    Enemy *enemy = new Enemy();
    enemy->autorelease();
    return enemy;
}

void Enemy::bindSprite(Sprite* sprite, int life)
{
    this->sprite = sprite;
    this->life = life;
    this->addChild(sprite);
}

Sprite* Enemy::getSprite()
{
    return sprite;
}

int Enemy::getLife()
{
    return life;
}

void Enemy::loseLife()
{
    this->life --;
}


Rect Enemy::getBoundingBox(){
	Rect rect = this->sprite->getBoundingBox();
    Point point = this->convertToWorldSpace(rect.origin);
    return Rect(point.x, point.y, rect.size.width, rect.size.height);
}
