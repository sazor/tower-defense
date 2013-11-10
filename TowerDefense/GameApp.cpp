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

//#include "Game/AbstractObject.h"
#include "Game/Castle.h"
#include "Game/Characteristics.h"
#include "Game/Deceleration.h"
#include "Game/Effect.h"
#include "Game/EffectContainer.h"
#include "Game/Enemy.h"
#include "Game/Lair.h"
#include "Game/Landscape.h"
#include "Game/Level.h"
#include "Game/MagicTower.h"
#include "Game/Point.h"
#include "Game/Poisoning.h"
#include "Game/Square.h"
#include "Game/StandartTower.h"
#include "Game/Tower.h"
#include "Game/Trap.h"
#include "Game/Weakness.h" 
#include "stdafx.h"



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

void AppScreen::Update(float dt) {}
void AppScreen::Render() {}



GameApp* GameApp::s_GameApp = NULL;

GameApp::GameApp()
{	
	ConsoleLog *c = new ConsoleLog();
	theSound.SetSoundCallback(this, &GameManager::SoundEnded);
	screen = new AppScreen();
	sample = theSound.LoadSample("Resources/Sounds/click.ogg", false /*no stream*/);
	theWorld.NameLayer("foreground", 0);
	theWorld.NameLayer("units", 1);
	theWorld.LoadLevel("leveltest");
	ActorSet grass = theTagList.GetObjectsTagged("background");
	ActorSet::iterator it = grass.begin();
	while (it != grass.end())
	{
		_objects.push_back(*it);
		it++;
	}
	BoundingBox bounds(Vector2(-20, -20), Vector2(20, 20));
	theSpatialGraph.CreateGraph(0.25f, bounds);
	theSpatialGraph.EnableDrawGraph(true);
	Enemy* en = new Enemy();
	en->SetPosition(7.81f, 3.43f);
	theWorld.Add(en, 2);
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

AppScreen* GameApp::GetCurrentScreen()
{
	return screen;
}

void GameApp::ReceiveMessage(Message* message)
{

}

void GameApp::Render()
{
	
}

void GameApp::SoundEnded(AngelSoundHandle sound)
{	
	// Detect sounds that have ended here.
}
