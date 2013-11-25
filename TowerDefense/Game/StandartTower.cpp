/* 
 * File:   StandartTower.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:29 PM
 */

#include "StandartTower.h"
#include "Enemy.h"
 
float radius = MathUtil::PixelsToWorldUnits(180.0);
const int time_interval = 1;
const int dmg = 40;

StandartTower::StandartTower()
{
	rendered = false;
	circle = new Actor();
	circle->SetPosition(this->GetPosition());
	circle->SetColor(1.0f, 0.0f, 0.0f);
	circle->SetDrawShape(ADS_Circle);
	circle->SetSize(MathUtil::PixelsToWorldUnits(180.0));
	circle->SetAlpha(0.2);
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
        	float dist = Vector2::DistanceSquared(en_pos, pos);
        	if (dist <= MathUtil::PixelsToWorldUnits(180.0) && dist < min_dist){
        		min_dist = dist;
        		for_dmg = (Enemy*)(*it); 
        	}
        	it++;
        }
        if(for_dmg){
        	Actor *circle = new Actor();
			circle->SetPosition(this->GetPosition());
			circle->SetColor(0.0f, 1.0f, 0.0f);
			circle->SetDrawShape(ADS_Circle);
			circle->SetSize(0.1);
			theWorld.Add(circle, 3);
			circle->MoveTo(for_dmg->GetPosition(), 0.1);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			theWorld.Remove(circle);
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