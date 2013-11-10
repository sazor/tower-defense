/* 
 * File:   Castle.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:30 PM
 */
#include "Castle.h"

Castle::Castle()
{
}

Castle::Castle(const Castle& orig)
{
}

Castle::~Castle()
{
}

void Castle::setCash(int cash)
{
        this->cash = cash;
}

int Castle::getCash() const
{
        return cash;
}

void Castle::setMax_health(int max_health)
{
        this->max_health = max_health;
}

int Castle::getMax_health() const
{
        return max_health;
}

void Castle::setHealth(int health)
{
        this->health = health;
}

int Castle::getHealth() const
{
        return health;
}

bool Castle::change_position(Point){
	
}