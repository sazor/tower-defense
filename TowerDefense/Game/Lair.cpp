#include "Lair.h"

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
	for(int i = 0; i < thePrefs.GetInt("LairSettings", "Waves"); ++i){
		std::this_thread::sleep_for(std::chrono::seconds(MathUtil::RandomIntInRange(2, thePrefs.GetInt("LairSettings", "TimeInterval"))));
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

void Lair::Render()
{
    Actor::Render();
    if(!rendered){
		rendered = true;
	}
}

void Lair::ReceiveMessage(Message *message){
}