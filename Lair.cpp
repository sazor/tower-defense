/* 
 * File:   Lair.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:26 PM
 */

#include "Lair.h"

Lair::Lair()
{
}

Lair::Lair(const Lair& orig)
{
}

Lair::~Lair()
{
}

EnemyNode* Lair::getCurrent_enemy() const
{
        return current_enemy;
}

