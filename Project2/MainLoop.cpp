#include "MainLoop.h"

MainLoop* MainLoop::_instance = nullptr;


MainLoop::MainLoop()
{
	start_time = 0;
	end_time = 0;
	delta_time = 0;
	render_time = 0;
	logic_time = 0;
	prev_delta_time = 0;
	prev_logic_time = 0;
	prev_render_time = 0;
}


MainLoop::~MainLoop()
{
}


void MainLoop::Loop() {
	while (!EventManager::getInstance()->getExitState()) {
		start_time = SDL_GetTicks();

		if (mainFunction != nullptr) {
			mainFunction(delta_time);
		}

		end_time = SDL_GetTicks();
		delta_time = end_time - start_time;
		printf("Delta time: %d\n", delta_time);
	}
}

MainLoop* MainLoop::getInstance() {
	if (_instance == nullptr)
		_instance = new MainLoop();
	return _instance;
}

void MainLoop::Run() {
	Loop();
}

void MainLoop::setMainFunc(std::function<void(int)> func) {
	mainFunction = func;
}