#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[])
{

	SDL_Surface *imageSurface = NULL;
	SDL_Surface *windowSurface = NULL;

	std::string s(argv[1]);
	std::string file = "BMP Loaded: " + s;
	const char *final = file.c_str();

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL couldn't init..." << SDL_GetError() << std::endl;
	} // One line init error check
	SDL_Window *window = SDL_CreateWindow(final, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

	windowSurface = SDL_GetWindowSurface(window);

	if (window == NULL)
	{
		std::cout << "Window not created... " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	SDL_Event windowEvent;

	imageSurface = SDL_LoadBMP(argv[1]);

	if (imageSurface == NULL)
	{
		std::cout << "SDL Couldn't Init image... " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	while (true)
	{
		if (SDL_PollEvent(&windowEvent))
		{
			if (SDL_QUIT == windowEvent.type)
			{
				break;
			}
		}

		SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
		SDL_UpdateWindowSurface(window);
	}

	SDL_FreeSurface(windowSurface);
	SDL_FreeSurface(imageSurface);

	imageSurface = NULL;
	windowSurface = NULL;

	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
