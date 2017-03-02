#pragma once
#include "SDL.h"

enum Key
{
	KEY_a,
	KEY_w,
	KEY_s,
	KEY_d
};

class EventManager
{
private:
	static EventManager* _instance;
	bool quit = false;
	bool keys[4];
	EventManager();
public:
	static EventManager* getInstance();
	bool getExitState();
	bool isKeyboardPressed(Key k);
	void Update(float dt);
	void Init();
	~EventManager();
};

