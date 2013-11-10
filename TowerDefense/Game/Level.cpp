/* 
 * File:   Level.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:30 PM
 */

#include "Level.h"

Level::Level()
{
}

Level::Level(const Level& orig)
{
}

Level::~Level()
{
}

void Level::SetEffect(Effect effect)
{
        this->effect = effect;
}

Effect Level::GetEffect() const
{
        return effect;
}

void Level::SetSpeed(int speed)
{
        this->speed = speed;
}

int Level::GetSpeed() const
{
        return speed;
}

void Level::SetDamage(int damage)
{
        this->damage = damage;
}

int Level::GetDamage() const
{
        return damage;
}

void Level::SetRadius(int radius)
{
        this->radius = radius;
}

int Level::GetRadius() const
{
        return radius;
}

void Level::SetCost(int cost)
{
        this->cost = cost;
}

int Level::GetCost() const
{
        return cost;
}

