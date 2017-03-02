#pragma once
#include "SDL.h"
class EventManager
{
private:
	static EventManager* _instance;
	bool quit = false;
	EventManager();
public:
	static EventManager* getInstance();
	bool getExitState();
	void Update(float dt);
	~EventManager();
};

