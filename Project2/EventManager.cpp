#include "EventManager.h"

EventManager* EventManager::_instance = nullptr;

EventManager::EventManager()
{
	Init();
}

void EventManager::Init() {
	for (int i = 0; i <= Key::KEY_RIGHT; i++) {
		keys[i] = false;
	}
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
	keys[KEY_SPACE] = false;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				quit = true;
				break;
			case SDLK_a:
				keys[KEY_a] = true;
				break;
			case SDLK_w:
				keys[KEY_w] = true;
				break;
			case SDLK_s:
				keys[KEY_s] = true;
				break;
			case SDLK_d:
				keys[KEY_d] = true;
				break;
			case SDLK_SPACE:
				keys[KEY_SPACE] = true;
				break;
			case SDLK_RIGHT:
				keys[KEY_RIGHT] = true;
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_a:
				keys[KEY_a] = false;
				break;
			case SDLK_w:
				keys[KEY_w] = false;
				break;
			case SDLK_s:
				keys[KEY_s] = false;
				break;
			case SDLK_d:
				keys[KEY_d] = false;
				break;
			case SDLK_RIGHT:
				keys[KEY_RIGHT] = false;
				break;
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

bool EventManager::isKeyboardPressed(Key k) {
	return keys[k];
}