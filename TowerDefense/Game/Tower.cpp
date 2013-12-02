#include "Tower.h"
#include "Enemy.h"

bool Tower::nearest_tower(Enemy* first, Enemy* second){
	Vector2 pos = this->GetPosition();
	Vector2 f_pos = first->GetPosition();
	Vector2 s_pos = second->GetPosition();
	float dist_f = Vector2::DistanceSquared(f_pos, pos);
	float dist_s = Vector2::DistanceSquared(s_pos, pos);
	return (dist_f < dist_s);
}
bool Tower::nearest_castle(Enemy* first, Enemy* second){
	Vector2 pos = GameApp::getCastlePosition();
	Vector2 f_pos = first->GetPosition();
	Vector2 s_pos = second->GetPosition();
	float dist_f = Vector2::DistanceSquared(f_pos, pos);
	float dist_s = Vector2::DistanceSquared(s_pos, pos);
	return (dist_f < dist_s);
}
bool Tower::weakest(Enemy* first, Enemy* second){
	return (first->getHealth() < second->getHealth());
}
bool Tower::strongest(Enemy* first, Enemy* second){
	return (first->getHealth() > second->getHealth());
}
bool Tower::fastest(Enemy* first, Enemy* second){
	return (first->getSpeed() > second->getSpeed());
}
bool Tower::slowest(Enemy* first, Enemy* second){
	return (first->getSpeed() < second->getSpeed());
}

void Tower::Render()
{
    Actor::Render();
}

void Tower::ReceiveMessage(Message *message){
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


Tower::Tower(){
	level = 1;
	theSwitchboard.SubscribeTo(this, "MouseDown");
}

Tower::Tower(const Tower& orig){
}

bool Tower::level_up(){
	Castle* castle = (Castle*)Actor::GetNamed("Castle");
	if(level != Level::MaxLevel() && castle->buy_level(Level::Cost(level + 1))){
		level++;
		return true;
	}
	return false;
}