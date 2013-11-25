/* 
 * File:   Lair.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:26 PM
 */

#include "Lair.h"
const int waves = 15;

Lair::Lair()
{
	rendered = false;
	time_interval = 5;
	std::thread interval(&Lair::release_enemy, this);
	interval.detach();
}

Lair::Lair(const Lair& orig)
{

}

void Lair::release_enemy(){
	std::this_thread::sleep_for(std::chrono::seconds(3));
	for(int i = 0; i < waves; ++i){
		std::this_thread::sleep_for(std::chrono::seconds(MathUtil::RandomIntInRange(2, time_interval)));
		Vector2 vec = GetPosition();
		vec.Y -= 1.25f;	
		Enemy* enemy = (Enemy*)Actor::Create("enemy");
		enemy->SetPosition(vec);
		theWorld.Add(enemy, 2);
    	enemy->GoTo(GameApp::getCastlePosition());
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