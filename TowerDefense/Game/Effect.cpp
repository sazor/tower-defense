#include "Effect.h"
#include "Enemy.h"
 
Effect::Effect()
{
}

Effect::Effect(const Effect& orig)
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

bool Effect::tick(Enemy&){
	this->remaining_time -= 1;
	return (this->remaining_time <= 0);
}

int Effect::getRemaining_time() const
{
        return remaining_time;
}

