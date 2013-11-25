#include "Trap.h"
#include "Enemy.h"
#include "Deceleration.h" 
#include "Poisoning.h"
#include "Weakness.h"

const int dmg = 10;

Trap::Trap()
{
	rendered = false;
	circle = new Actor();
	circle->SetPosition(this->GetPosition());
	circle->SetColor(0.0f, 0.0f, 1.0f);
	circle->SetDrawShape(ADS_Circle);
	circle->SetSize(MathUtil::PixelsToWorldUnits(180.0));
	circle->SetAlpha(0.2);
	SetSprite("Resources/Images/trap.png");
	theSwitchboard.SubscribeTo(this, "MouseDown");
}

Trap::Trap(const Trap& orig)
{
}

Trap::~Trap()
{
}

void Trap::Render(){
	Tower::Render();
	if(!rendered){
		rendered = true;
		circle->SetPosition(this->GetPosition());	
		theWorld.Add(circle, 1);
	}
}

bool Trap::attack(){
	Vector2 pos = this->GetPosition();
	ActorSet enemies = theTagList.GetObjectsTagged("enemy");
	ActorSet::iterator it = enemies.begin();
	float min_dist = 1000.0;
	Enemy* for_dmg = NULL;
    while(it != enemies.end()){
        Vector2 en_pos = (*it)->GetPosition();
        float dist = Vector2::DistanceSquared(en_pos, pos);
        if (dist <= MathUtil::PixelsToWorldUnits(180.0)){
        	for_dmg = (Enemy*)(*it); 
        	for_dmg->get_damage(dmg);
        	int random_effect = MathUtil::RandomIntInRange(1, 3);
        	switch(random_effect){
        		case 1: { 
        					std::shared_ptr<Effect> ef(new Poisoning());
        					for_dmg->effect(ef);
        					break;
        				}
        		case 2: {
        					std::shared_ptr<Effect> ef(new Deceleration());
	        				for_dmg->effect(ef);
	        				break;
        				}
        		case 3: {
        					std::shared_ptr<Effect> ef(new Weakness());
	        				for_dmg->effect(ef);
	        				break;
        				}
        	}
        }
        it++;
    }
    theSwitchboard.UnsubscribeFrom(this, "PathPointReached");
    theWorld.Remove(circle);
    theWorld.Remove(this);
    Actor::Destroy();
}

void Trap::ReceiveMessage(Message *message){
    if (message->GetMessageName() == "MouseDown")
    {
        TypedMessage<Vec2i> *m = (TypedMessage<Vec2i>*)message;
        Vec2i screenCoordinates = m->GetValue();
        Vector2 click = MathUtil::ScreenToWorld(screenCoordinates);
        Vector2 position = GetPosition();
	    Vector2 size = GetSize();
	    if ((click.X < position.X + size.X/2.0) && (click.X > position.X - size.X/2.0) && (click.Y < position.Y + size.Y/2.0) && (click.Y > position.Y - size.Y/2.0)){
	    	attack();
	    }
    }
}