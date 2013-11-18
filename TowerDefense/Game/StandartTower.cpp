/* 
 * File:   StandartTower.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:29 PM
 */

#include "StandartTower.h"
#include "Enemy.h"
 
const float radius = 3.5;
const int time_interval = 3;
const int dmg = 40;

StandartTower::StandartTower()
{
	rendered = false;
	circle = new Actor();
	circle->SetPosition(this->GetPosition());
	circle->SetColor(1.0f, 0.0f, 0.0f);
	circle->SetDrawShape(ADS_Circle);
	circle->SetSize(radius);
	circle->SetAlpha(0.5);
	SetSprite("Resources/Images/standart_tower.png");
	std::thread interval(&StandartTower::attack, this);
	interval.detach();
}

StandartTower::StandartTower(const StandartTower& orig)
{
}

StandartTower::~StandartTower()
{

}

bool StandartTower::attack(){
	for(;;){
		std::this_thread::sleep_for(std::chrono::seconds(time_interval));
		Vector2 pos = this->GetPosition();
		ActorSet enemies = theTagList.GetObjectsTagged("enemy");
		ActorSet::iterator it = enemies.begin();
		float min_dist = 1000.0;
		Enemy* for_dmg = NULL;
        while(it != enemies.end()){
        	Vector2 en_pos = (*it)->GetPosition();
        	Vector2 dist = Vector2(en_pos.X - pos.X, en_pos.Y - pos.Y);
        	if (dist.Length() <= radius && dist.Length() < min_dist){
        		min_dist = dist.Length();
        		for_dmg = (Enemy*)(*it); 
        	}
        	it++;
        }
        if(for_dmg){
        	Actor *circle = new Actor();
			circle->SetPosition(this->GetPosition());
			circle->SetColor(0.0f, 1.0f, 0.0f);
			circle->SetDrawShape(ADS_Circle);
			circle->SetSize(0.5);
			theWorld.Add(circle, 3);
			circle->MoveTo(for_dmg->GetPosition(), 0.1);
        	for_dmg->get_damage(dmg);
        }
	}
}

void StandartTower::Render(){
	Tower::Render();
	 if(!rendered){
		rendered = true;
		circle->SetPosition(this->GetPosition());	
		theWorld.Add(circle, 1);
	}
}