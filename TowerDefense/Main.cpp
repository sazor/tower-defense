#include "stdafx.h"

#include "GameApp.h"

int main(int argc, char* argv[])
{
	theWorld.Initialize(896, 896, "Tower Defense", false, false);

	//we're going to be using the built-in physics
	theWorld.SetupPhysics();
	
	//theDemoGame is our DemoGameManager singleton
	// all the cool stuff happens there -- check it out. 
	theWorld.SetGameManager(&theGame);
	
	// do all your setup first, because this function won't return until you're exiting
	theWorld.StartGame();
	
	// any cleanup can go here
	theWorld.Destroy();
	
	return 0;
}