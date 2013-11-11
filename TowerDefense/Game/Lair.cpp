/* 
 * File:   Lair.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:26 PM
 */

#include "Lair.h"

Lair::Lair()
{
	rendered = false;
	time_interval = 4;
	std::thread interval(&Lair::release_enemy, this);
	interval.detach();
}

Lair::Lair(const Lair& orig)
{

}

void Lair::release_enemy(){
	while(!rendered);
	Vector2 vec = GetPosition();
	vec.Y -= 1.25f;	
	while(true){
		std::this_thread::sleep_for(std::chrono::seconds(time_interval));
		Enemy* enemy = new Enemy(vec);
	}
}

Lair::~Lair()
{
}

bool Lair::change_position(Point){
	
}

void Lair::Render()
{
    Actor::Render();
    if(!rendered){
		rendered = true;
	}
}

void Lair::ReceiveMessage(Message *message){
}