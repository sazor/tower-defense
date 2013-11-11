/* 
 * File:   Lair.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:26 PM
 */

#include "Lair.h"

Lair::Lair()
{
	//theWorld.Add(this);
	/*theSwitchboard.SubscribeTo(this, "EnemyRelease");
	BoundingBox bounds(Vector2(-20, -20), Vector2(20, 20));
	theSpatialGraph.CreateGraph(0.6f, bounds);
	ConsoleLog *c = new ConsoleLog();
    c->Printf("X: %4.4f Y: %4.4f", _position.X, _position.Y);
	std::thread interval(&Lair::release_enemy, this, GetPosition());
	interval.join();*/
}

Lair::Lair(const Lair& orig)
{

}

void Lair::release_enemy(Vector2 vec){
	vec.Y -= 1.25f;
	while(true){
		std::this_thread::sleep_for(std::chrono::seconds(4));	
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
    if(!first_render){
		std::thread interval(&Lair::release_enemy, this, GetPosition());
		interval.detach();
		first_render = true;
	}
}

void Lair::ReceiveMessage(Message *message){
	if (message->GetMessageName() == "EnemyRelease"){
	//	release_enemy();
	}
}