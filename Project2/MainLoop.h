#pragma once
#include <functional>
#include "SDL.h"
#include "EventManager.h"
class MainLoop
{
private:
	static MainLoop* _instance;
	MainLoop();

	int start_time,
		end_time,
		delta_time,
		prev_delta_time,
		start_time_render,
		end_time_render,
		render_time,
		prev_render_time,
		start_time_logic,
		end_time_logic,
		logic_time,
		prev_logic_time;

	std::function <void(int)> mainFunction;
public:
	static MainLoop* getInstance();
	void Loop();
	void Run();
	void setMainFunc(std::function<void(int)> func);
	~MainLoop();
};

