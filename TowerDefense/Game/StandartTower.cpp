/* 
 * File:   StandartTower.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:29 PM
 */

#include "StandartTower.h"
#include "Enemy.h"
 
StandartTower::StandartTower()
{
	rendered = false;
	circle = new Actor();
	circle->SetPosition(this->GetPosition());
	circle->SetColor(1.0f, 0.0f, 0.0f);
	circle->SetDrawShape(ADS_Circle);
	circle->SetSize(MathUtil::PixelsToWorldUnits(Level::Radius(level)));
	circle->SetAlpha(0.2);
	SetSprite("Resources/Images/standart_tower.png");
	theSwitchboard.SubscribeTo(this, "Tick");
	ticks = 0;
	//std::thread interval(&StandartTower::attack, this);
	//interval.detach();
}

StandartTower::StandartTower(const StandartTower& orig)
{
}

StandartTower::~StandartTower()
{

}

bool StandartTower::attack(){
		int opt = thePrefs.GetInt("PlayerSettings", "Tactics");
		bool (*tactics[6])(Enemy*, Enemy*) = { (bool(*)(Enemy*, Enemy*))&Tower::nearest_tower, (bool(*)(Enemy*, Enemy*))&Tower::nearest_castle, 
			(bool(*)(Enemy*, Enemy*))&Tower::weakest, (bool(*)(Enemy*, Enemy*))&Tower::strongest, 
			(bool(*)(Enemy*, Enemy*))&Tower::fastest, (bool(*)(Enemy*, Enemy*))&Tower::slowest };
		Vector2 pos = this->GetPosition();
		ActorSet enemies = theTagList.GetObjectsTagged("enemy");
		ActorSet::iterator it = enemies.begin();
		float min_dist = 1000.0;
		Enemy* for_dmg = NULL;
        while(it != enemies.end()){
        	Vector2 en_pos = (*it)->GetPosition();
        	float dist = Vector2::DistanceSquared(en_pos, pos);
        	if ((dist <= MathUtil::PixelsToWorldUnits(Level::Radius(level))) && ((for_dmg == NULL) || (tactics[opt]((Enemy*)(*it), for_dmg)))){
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
			std::thread for_del(&StandartTower::delete_circle, this, circle);
			for_del.detach();
        	for_dmg->get_damage(thePrefs.GetFloat("TowerSettings", "StandartDmg"));
        }
}

void StandartTower::delete_circle(Actor* c){
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	theWorld.Remove(c);
}

void StandartTower::Render(){
	Tower::Render();
	 if(!rendered){
		rendered = true;
		circle->SetPosition(this->GetPosition());	
		theWorld.Add(circle, 1);
	}
}

void StandartTower::ReceiveMessage(Message *message){
    if (message->GetMessageName() == "Tick"){
        ticks++;
        if (ticks == thePrefs.GetFloat("TowerSettings", "StandartTime")){
            attack();
            ticks = 0;
        }
    }
    if (message->GetMessageName() == "MouseDown")
    {
        TypedMessage<Vec2i> *m = (TypedMessage<Vec2i>*)message;
        Vec2i screenCoordinates = m->GetValue();
        Vector2 click = MathUtil::ScreenToWorld(screenCoordinates);
        Vector2 position = GetPosition();
        Vector2 size = GetSize();
        if ((click.X < position.X + size.X/2.0) && (click.X > position.X - size.X/2.0) && (click.Y < position.Y + size.Y/2.0) && (click.Y > position.Y - size.Y/2.0)){
            level_up();
        }
    }
}

bool StandartTower::level_up(){
    bool res = Tower::level_up();
    if (res)circle->SetSize(MathUtil::PixelsToWorldUnits(Level::Radius(level)));
    return res;
}