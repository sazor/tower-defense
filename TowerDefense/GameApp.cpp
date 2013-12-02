//////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2008-2013, Shane Liesegang
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright 
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright 
//       notice, this list of conditions and the following disclaimer in the 
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the copyright holder nor the names of any 
//       contributors may be used to endorse or promote products derived from 
//       this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.
//////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GameApp.h"

#include "Game/Castle.h"
#include "Game/Container.h" 
#include "Game/Deceleration.h"
#include "Game/Effect.h"
#include "Game/Enemy.h"
#include "Game/Lair.h"
#include "Game/Level.h"
#include "Game/MagicTower.h"
#include "Game/Poisoning.h"
#include "Game/StandartTower.h"
#include "Game/Tower.h"
#include "Game/Trap.h"
#include "Game/Weakness.h" 
#include "stdafx.h"
#include <fstream>

void ChoiceMade(int choice)
{
	ConsoleLog *c = new ConsoleLog();
	c->Printf("Change tactics to %d. ", choice);
	thePrefs.SetInt("PlayerSettings", "Tactics", choice);
}

void ButtonPress(){
	StringList labels;
	labels.push_back("Nearest to tower");
	labels.push_back("Nearest to castle");
	labels.push_back("Weakest");
	labels.push_back("Strongest");
	labels.push_back("Fastest");
	labels.push_back("Slowest");
	GameApp::_choiceBox = theUI.ShowChoiceBox("Choose your tactics:", labels, ChoiceMade);
}


AppScreen::AppScreen() {}

void AppScreen::Start(){}

void AppScreen::Stop()
{
	std::vector<Renderable*>::iterator it = _objects.begin();
	while(_objects.end() != it)
	{
		// we're pre-destroying physics bodies here because it 
		//  can mess with the pathfinding regeneration.
		PhysicsActor* pa = dynamic_cast<PhysicsActor*> (*it);
		if (pa != NULL)
		{
			if (pa->GetBody() != NULL)
			{
				pa->GetBody()->SetUserData(NULL);
				theWorld.GetPhysicsWorld().DestroyBody(pa->GetBody());
				pa->ResetBody();
			}
		}
		(*it)->Destroy();
		it++;
	}
	_objects.clear();
}

void AppScreen::Update(float dt) {
}
void AppScreen::Render() {
}



GameApp* GameApp::s_GameApp = NULL;
int GameApp::tower;
TextActor * GameApp::castle_health;
TextActor * GameApp::castle_cash;
AngelUIHandle GameApp::_choiceBox = NULL;
AngelUIHandle GameApp::_button = NULL;

GameApp::GameApp()
{	
	load_prefs();
	theSound.SetSoundCallback(this, &GameManager::SoundEnded);
	screen = new AppScreen();
	sample = theSound.LoadSample("Resources/Sounds/click.ogg", false /*no stream*/);
	theWorld.NameLayer("background", 0);
	theWorld.NameLayer("objects", 1);
	theWorld.NameLayer("units", 2);
	theWorld.LoadLevel("level");
	BoundingBox bounds(Vector2(-20, -20), Vector2(20, 20));
	theSpatialGraph.CreateGraph(0.6f, bounds);
	Castle* castle = (Castle*)Actor::GetNamed("Castle");
	castle_health = new TextActor("Console", "Castle health: " + IntToString(castle->getHealth()), TXT_Center);
	castle_health->SetPosition(Vector2(-4.5f, 4.5f));
	theWorld.Add(castle_health);
	castle_cash = new TextActor("Console", "Castle cash: " + IntToString(castle->getCash()), TXT_Center);
	castle_cash->SetPosition(Vector2(-4.5f, 3.5f));
	theWorld.Add(castle_cash);
	std::thread interval(&GameApp::timer, this);
	interval.detach();
	_button = theUI.AddButton("Change tactics", Vec2i(90, 700), ButtonPress, true);
}

void GameApp::MouseDownEvent(Vec2i screenCoordinates, MouseButtonInput button)
{
	TypedMessage<Vec2i> *m = new TypedMessage<Vec2i>("MouseDown", screenCoordinates);
	theSwitchboard.Broadcast(m);
}

GameApp& GameApp::GetInstance()
{
	if (s_GameApp == NULL)
	{
		s_GameApp = new GameApp();
	}
	return *s_GameApp;
}

Vector2 GameApp::getCastlePosition(){
	Castle* castle = castle = (Castle*)Actor::GetNamed("Castle");
	Vector2 aim = castle->GetPosition();
	aim.Y -= 1.43;
	return aim;
}

AppScreen* GameApp::GetCurrentScreen()
{
	return screen;
}

void GameApp::ReceiveMessage(Message* message)
{
	if (message->GetMessageName() == "MouseDown")
    {
    	Castle* castle = (Castle*)Actor::GetNamed("Castle");
    	TypedMessage<Vec2i> *m = (TypedMessage<Vec2i>*)message;
        Vec2i screenCoordinates = m->GetValue();
        Vector2 click = MathUtil::ScreenToWorld(screenCoordinates);
        if(tower != 3){
	        ActorSet background = theTagList.GetObjectsTagged("grass");
			ActorSet::iterator it = background.begin();
	        while(it != background.end()){
	        	Vector2 position = (*it)->GetPosition();
	        	Vector2 size = (*it)->GetSize();
	        	if ((click.X < position.X + size.X/2.0) && (click.X > position.X - size.X/2.0) && (click.Y < position.Y + size.Y/2.0) && (click.Y > position.Y - size.Y/2.0)){
	        		if(!(castle->buy_tower(tower))) return;
	        		if(tower == 1){
	        			StandartTower* new_tower = (StandartTower*)Actor::Create("standart_tower");
	        			new_tower->SetPosition(click);
	        			theWorld.Add(new_tower, 2);
	        		}
	        		if(tower == 2){
	        			MagicTower* new_tower = (MagicTower*)Actor::Create("magic_tower");
	        			new_tower->SetPosition(click);
	        			theWorld.Add(new_tower, 2);
	        		}
	        		break;
	        	}
	        	it++;
	        }
	    }
	    else{
	    	ActorSet background = theTagList.GetObjectsTagged("road");
			ActorSet::iterator it = background.begin();
	        while(it != background.end()){
	        	Vector2 position = (*it)->GetPosition();
	        	Vector2 size = (*it)->GetSize();
	        	if ((click.X < position.X + size.X/2.0) && (click.X > position.X - size.X/2.0) && (click.Y < position.Y + size.Y/2.0) && (click.Y > position.Y - size.Y/2.0)){
	        		if(!(castle->buy_tower(tower))) return;
	        		Trap* new_trap = (Trap*)Actor::Create("trap");
	        		new_trap->SetPosition(click);
	        		theWorld.Add(new_trap, 1);
	        		break;
	        	}
	        	it++;
	        }
	    }
        theSwitchboard.UnsubscribeFrom(this, "MouseDown");
    }
}

void GameApp::Render()
{

}

void GameApp::SoundEnded(AngelSoundHandle sound)
{	
	// Detect sounds that have ended here.
}

void GameApp::Update(float dt)
{
	if (theInput.IsKeyDown('s'))
	{
		tower = 1;
		theSwitchboard.SubscribeTo(this, "MouseDown");
	}
	if (theInput.IsKeyDown('m'))
	{
		tower = 2;
		theSwitchboard.SubscribeTo(this, "MouseDown");
	}
	if (theInput.IsKeyDown('t'))
	{
		tower = 3;
		theSwitchboard.SubscribeTo(this, "MouseDown");
	}
}

void GameApp::timer(){
	for(;;){
		std::this_thread::sleep_for(std::chrono::seconds(1));
		theSwitchboard.Broadcast(new Message("Tick", this));
	}
}

void GameApp::load_prefs(){
	//default tactics
	thePrefs.SetInt("PlayerSettings", "Tactics", 0);
	//load tower levels
	std::ifstream fin("Data/levels.dat");
	while(!fin.eof()){
		float radius;
		int cost;
		fin >> cost >> radius;
		Level::addLevel(radius, cost);
	}
	fin.close();
	//Time_intervals & dmg of towers
	thePrefs.SetFloat("TowerSettings", "MagicTime", 3.0);
	thePrefs.SetFloat("TowerSettings", "StandartTime", 1.0);
	thePrefs.SetFloat("TowerSettings", "MagicDmg", 10.0);
	thePrefs.SetFloat("TowerSettings", "StandartDmg", 40.0);
	thePrefs.SetFloat("TowerSettings", "TrapDmg", 15.0);
	//Enemy settings
	thePrefs.SetFloat("EnemySettings", "Cost", 100.0);
	thePrefs.SetFloat("EnemySettings", "MaxHealth", 100.0);
	thePrefs.SetFloat("EnemySettings", "Speed", 2.0);
	//Castle settings
	thePrefs.SetFloat("CastleSettings", "Cash", 500.0);
	thePrefs.SetFloat("CastleSettings", "MaxHealth", 100.0);
	//Lair settings
	thePrefs.SetInt("LairSettings", "Waves", 15);
	thePrefs.SetInt("LairSettings", "TimeInterval", 5);
	//Effect settings
	thePrefs.SetInt("EffectSettings", "PoisoningTime", 6);
	thePrefs.SetInt("EffectSettings", "PoisoningValue", 2);
	thePrefs.SetFloat("EffectSettings", "PoisoningDmg", 50.0);
	thePrefs.SetInt("EffectSettings", "WeaknessTime", 5);
	thePrefs.SetInt("EffectSettings", "WeaknessValue", 2);
	thePrefs.SetInt("EffectSettings", "DecelerationTime", 4);
	thePrefs.SetInt("EffectSettings", "DecelerationValue", 1);
}

void GameApp::Stop(){

}