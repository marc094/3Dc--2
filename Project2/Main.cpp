#include "Triangle3D.h"
#include "SDL.h"
#include "Mesh3D.h"
#pragma comment( lib, "External/SDL2-2.0.5/lib/x64/SDL2.lib")
#pragma comment( lib, "External/SDL2-2.0.5/lib/x64/SDL2main.lib")
#pragma comment( lib, "External/SDL2_image-2.0.0/lib/x64/SDL2_image.lib")

#undef main

SDL_Window* _window = NULL;

SDL_Surface* _window_surface = NULL;

SDL_Renderer* _window_renderer = NULL;

bool init();
void close();

void main(int argc, char *args[]) {

	init();

	/*Point3D p1(-150, -150, -150);
	Point3D p2(150, -150, -150);
	Point3D p3(0, 150, -150);
	Point3D p4(0, 0, 150);
	Point3D center(600, 550, 75);
	Point3D rotation(M_PI / 1024, M_PI / 1024, M_PI / 1024);

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

	/*for (int i = 0; i < 10; i++) {
		Point3D p1(500*i*0.1, 500/(0.1*i+1), 0);
		Point3D p2(500/(0.1*i+1), 750*i*0.1, 0);
		Point3D p3(750*i*0.1, 500*i*0.1, 0);
		Triangle3D triangle(p1, p2, p3);
		triangles.push_back(triangle);
	}*/

	SDL_SetRenderDrawColor(_window_renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderClear(_window_renderer);
	SDL_Rect _rect{ 200, 50, 100, 100 };
	SDL_SetRenderDrawColor(_window_renderer, 0x00, 0x00, 0xFF, 0xFF);
	SDL_RenderFillRect(_window_renderer, &_rect);

	/*for (int i = 0; i < 1; i++) {
		triangles[i].renderLines(_window_renderer);
	}*/

	//mesh.renderLines(_window_renderer);

	/*SDL_RenderPresent(_window_renderer);
	//SDL_UpdateWindowSurface(_window);
	SDL_Delay(1000);

	for (int t = 0; t < 10000; t++) {
		SDL_RenderClear(_window_renderer);

		/*for (int i = 0; i < 1; i++) {
			//Point3D rotation(0, 0, (M_PI) / 64);
			triangles[i].rotate(rotation);
			triangles[i].renderLines(_window_renderer);
		}*/

		//mesh.rotate(rotation);
		//mesh.renderLines(_window_renderer);

		SDL_RenderPresent(_window_renderer);
		SDL_Delay(15);
	//}

	//SDL_UpdateWindowSurface(_window);
	SDL_Delay(5000);

	close();

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

			/*_window_surface = SDL_GetWindowSurface(_window);
			SDL_FillRect(_window_surface, NULL, 0x000000);
			SDL_UpdateWindowSurface(_window);*/
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