#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include "functions.h"

int main(int argc, char* argv[]) {
	Seed();
	
	int x = 0;
	int xv = 2;
	int y = 0;
	int yv = 2;
	int coll = 0;
	int r = Random();
	int g = Random();
	int b = Random();

	SDL_Window* window;
	SDL_Renderer* renderer;
	
	SDL_Rect rect = { 0, 0, 100, 100 };

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Untitled", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	bool isRunning = true;

	while (isRunning) {
		
		
		SDL_Event event;

		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				isRunning = false;
			}
		}
	
		SDL_SetRenderDrawColor(renderer, 64, 64, 64, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, r, g, b, 255);
		SDL_RenderFillRect(renderer, &rect);

		rect.x = x;
		rect.y = y;

		Move(&x, xv, &y, yv);
		Update(x, &xv, y, &yv, &coll);
		Collusion(&coll, &r, &g, &b);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
