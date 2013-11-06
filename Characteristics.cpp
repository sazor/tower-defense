/* 
 * File:   Characteristics.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:30 PM
 */

#include "Characteristics.h"

Characteristics::Characteristics()
{
}

Characteristics::Characteristics(const Characteristics& orig)
{
}

Characteristics::~Characteristics()
{
}

void Characteristics::setLevels(Level* levels)
{
        this->levels = levels;
}

Level* Characteristics::getLevels() const
{
        return levels;
}

