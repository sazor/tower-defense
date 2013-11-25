#include "Tower.h"

void Tower::setCharacteristics(Characteristics characteristics)
{
        this->characteristics = characteristics;
}

Characteristics Tower::getCharacteristics() const
{
        return characteristics;
}

void Tower::setLevel(int level)
{
        this->level = level;
}

int Tower::getLevel() const
{
        return level;
}

void Tower::Render()
{
    Actor::Render();
}

void Tower::ReceiveMessage(Message *message){

}

Tower::Tower(){
}

Tower::Tower(const Tower& orig){
}
