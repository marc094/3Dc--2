#include "EventManager.h"

EventManager* EventManager::_instance = nullptr;

EventManager::EventManager()
{
}


EventManager::~EventManager()
{
}


EventManager* EventManager::getInstance() {
	if (_instance == nullptr) {
		_instance = new EventManager();
	}
	return _instance;
}

void EventManager::Update(float dt) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.scancode) {
			case SDL_SCANCODE_ESCAPE:
				quit = true;
			}
			break;
		case SDL_QUIT:
			quit = true;
			break;
		}
	}
}

bool EventManager::getExitState() {
	return quit;
}