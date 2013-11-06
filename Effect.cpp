/* 
 * File:   Effect.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:32 PM
 */

#include "Effect.h"

Effect::Effect()
{
}

Effect::Effect(const Effect& orig)
{
}

Effect::~Effect()
{
}

void Effect::setValue(int value)
{
        this->value = value;
}

int Effect::getValue() const
{
        return value;
}

void Effect::setRemaining_time(int remaining_time)
{
        this->remaining_time = remaining_time;
}

int Effect::getRemaining_time() const
{
        return remaining_time;
}

