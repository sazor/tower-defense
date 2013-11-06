/* 
 * File:   EffectContainer.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:31 PM
 */

#include "EffectContainer.h"

EffectContainer::EffectContainer()
{
}

EffectContainer::EffectContainer(const EffectContainer& orig)
{
}

EffectContainer::~EffectContainer()
{
}

void EffectContainer::setNumber(int number)
{
        this->number = number;
}

int EffectContainer::getNumber() const
{
        return number;
}

void EffectContainer::setEffects(Effect* effects)
{
        this->effects = effects;
}

Effect* EffectContainer::getEffects() const
{
        return effects;
}

