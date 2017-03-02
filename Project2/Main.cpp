#include "Triangle3D.h"
#include "SDL.h"
#include "Mesh3D.h"
#include "EventManager.h"
#include "Mainloop.h"
#pragma comment( lib, "External/SDL2-2.0.5/lib/x64/SDL2.lib")
#pragma comment( lib, "External/SDL2-2.0.5/lib/x64/SDL2main.lib")
#pragma comment( lib, "External/SDL2_image-2.0.0/lib/x64/SDL2_image.lib")


SDL_Window* _window = NULL;

SDL_Surface* _window_surface = NULL;

SDL_Renderer* _window_renderer = NULL;

bool init();
void close();

int main(int argc, char *args[]) {

	init();

	EventManager* _event_manager = EventManager::getInstance();
	MainLoop* _main_loop = MainLoop::getInstance();

	Point3D p1(-150, -150, -150);
	Point3D p2(150, -150, -150);
	Point3D p3(0, 150, -150);
	Point3D p4(0, 0, 150);
	Point3D center(600, 550, 75);
	Point3D rotation(0, M_PI / 1024, 0);

	Triangle3D triangle(p1, p2, p3);
	Triangle3D triangle2(p1, p2, p4);
	Triangle3D triangle3(p1, p3, p4);
	Triangle3D triangle4(p2, p3, p4);
	Transform t;

	std::vector<Triangle3D> triangles;
	triangles.push_back(triangle);
	triangles.push_back(triangle2);
	triangles.push_back(triangle3);
	triangles.push_back(triangle4);


	Mesh3D mesh(center, triangles);

	SDL_Rect _rect{ 200, 50, 100, 100 };


	/*mesh.renderLines(_window_renderer);

	SDL_RenderPresent(_window_renderer);*/
	
	_main_loop->setMainFunc( [&](float dt) {
		//while (!_event_manager->getExitState()) {
			_event_manager->Update(0.0);

			if (_event_manager->isKeyboardPressed(KEY_a))
				_rect.x -= 1;
			if (_event_manager->isKeyboardPressed(KEY_w))
				_rect.y -= 1;
			if (_event_manager->isKeyboardPressed(KEY_s))
				_rect.y += 1;
			if (_event_manager->isKeyboardPressed(KEY_d))
				_rect.x += 1;

			SDL_RenderClear(_window_renderer);

			//Quadrat
			SDL_SetRenderDrawColor(_window_renderer, 0xFF, 0x00, 0x00, 0xFF);
			SDL_RenderClear(_window_renderer);
			SDL_SetRenderDrawColor(_window_renderer, 0x00, 0x00, 0xFF, 0xFF);
			SDL_RenderFillRect(_window_renderer, &_rect);

			mesh.rotate(rotation);
			mesh.renderLines(_window_renderer);

			SDL_RenderPresent(_window_renderer);
		}

	//}
	);

	_main_loop->Run();

	close();
	return 0;
}

bool init() {

	bool ok = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		ok = false;
	}
	else {
		_window = SDL_CreateWindow("Triangles", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1236, 720, 0);
		if (_window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			ok = false;
		}
		else {
			_window_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
			SDL_RenderClear(_window_renderer);
			SDL_RenderPresent(_window_renderer);
		}
	}

	return ok;
}

void close() {
	SDL_DestroyRenderer(_window_renderer);
	SDL_DestroyWindow(_window);
	_window = NULL;

	SDL_Quit();
}