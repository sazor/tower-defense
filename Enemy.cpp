/* 
 * File:   Enemy.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:27 PM
 */

#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(const Enemy& orig)
{
}

Enemy::~Enemy()
{
}

void Enemy::setEffects(EffectContainer effects)
{
        this->effects = effects;
}

EffectContainer Enemy::getEffects() const
{
        return effects;
}

void Enemy::setSpeed(int speed)
{
        this->speed = speed;
}

int Enemy::getSpeed() const
{
        return speed;
}

void Enemy::setCash(int cash)
{
        this->cash = cash;
}

int Enemy::getCash() const
{
        return cash;
}

void Enemy::setMax_health(int max_health)
{
        this->max_health = max_health;
}

int Enemy::getMax_health() const
{
        return max_health;
}

void Enemy::setHeath(int heath)
{
        this->heath = heath;
}

int Enemy::getHeath() const
{
        return heath;
}

