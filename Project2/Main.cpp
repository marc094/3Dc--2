#include "Triangle3D.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Mesh3D.h"
#include "EventManager.h"
#include "Mainloop.h"
#pragma comment( lib, "External/SDL2-2.0.5/lib/x86/SDL2.lib")
#pragma comment( lib, "External/SDL2-2.0.5/lib/x86/SDL2main.lib")
#pragma comment( lib, "External/SDL2_image-2.0.0/lib/x86/SDL2_image.lib")
#undef main
#define MAX_BULLETS 10

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
	Point3D _rotation(0, -M_PI / 1024, 0);
	Point3D rotation2(-M_PI / 2, 0, 0);

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
	mesh.rotate(rotation2);



	SDL_Surface* aux_surf = IMG_Load("Resources/texture.png");
	SDL_Texture* ship_texture = SDL_CreateTextureFromSurface(_window_renderer, aux_surf);

	SDL_Surface* aux_surf2 = IMG_Load("Resources/bg2.jpg");
	SDL_Texture* bg1 = SDL_CreateTextureFromSurface(_window_renderer, aux_surf2);
	SDL_Texture* bg2 = SDL_CreateTextureFromSurface(_window_renderer, aux_surf2);

	SDL_Rect _bg1{ 0, 0, 600, 337 };
	SDL_Rect _bg2{ 600, 0, 600, 337 };
	SDL_Rect _rect{ 200, 50, 200, 100 };
	SDL_Rect texture_rect_ship{ 0, 225, 968, 421 };
	SDL_Rect texture_rect_beam{ 0, 0, 414, 225 };


	//std::vector<SDL_Rect> bullets;
	SDL_Rect bullets[MAX_BULLETS];
	int bullet = 0;

	for (int i = 0; i < MAX_BULLETS; i++) {
		bullets[i] = SDL_Rect{ _rect.x + _rect.w / 2, _rect.y + _rect.h / 2 - 3, 20, 6 };
	}

	/*mesh.renderLines(_window_renderer);

	SDL_RenderPresent(_window_renderer);*/
	
	_main_loop->setMainFunc( [&](float dt) {
		//while (!_event_manager->getExitState()) {
			_event_manager->Update(0.0);
			bool shooting = false;
			if (_event_manager->isKeyboardPressed(KEY_a))
				_rect.x -= 1;
			if (_event_manager->isKeyboardPressed(KEY_w))
				_rect.y -= 1;
			if (_event_manager->isKeyboardPressed(KEY_s))
				_rect.y += 1;
			if (_event_manager->isKeyboardPressed(KEY_d))
				_rect.x += 1;
			if (_event_manager->isKeyboardPressed(KEY_SPACE))
				shooting = true;
			if (_event_manager->isKeyboardPressed(KEY_RIGHT)) {
				_bg1.x--;
				_bg2.x--;
			}

			if (_bg1.x < -600)
				_bg1.x = 0;
			if (_bg2.x < 0)
				_bg2.x = 600;

			if (shooting) {
				if (bullet >= MAX_BULLETS)
					bullet = 0;
				bullets[bullet].x = _rect.x + _rect.w / 2;
				bullets[bullet].y = _rect.y + _rect.h / 2 - bullets[bullet].h/2;
				bullet++;
				//bullets.push_back(SDL_Rect{ _rect.x + _rect.w/2, _rect.y + _rect.h/2 - 3, 20, 6 });
			}

			//SDL_RenderClear(_window_renderer);

			SDL_SetRenderDrawColor(_window_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(_window_renderer);
			SDL_SetRenderDrawColor(_window_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderCopy(_window_renderer, bg1, nullptr, &_bg1);
			SDL_RenderCopy(_window_renderer, bg2, nullptr, &_bg2);


			for (int i = 0; i < MAX_BULLETS; i++)
			{
				bullets[i].x++;
				SDL_RenderCopy(_window_renderer, ship_texture, &texture_rect_beam, &bullets[i]);
			}


			//Quadrat
			SDL_RenderCopy(_window_renderer, ship_texture, &texture_rect_ship, &_rect);
			//SDL_RenderFillRect(_window_renderer, &_rect);

			/*if (_event_manager->isKeyboardPressed(KEY_d))
				mesh.rotate(rotation);
			if (_event_manager->isKeyboardPressed(KEY_a))
				mesh.rotate(_rotation);*/
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

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0 && IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		ok = false;
	}
	else {
		_window = SDL_CreateWindow("Triangles", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 337, 0);
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