#include "RectDemo.h"

namespace Demos
{
	RectDemo::RectDemo()
	{}

	void RectDemo::Start()
	{
		SDL_Init(SDL_INIT_EVERYTHING);

		BCCore::RenderWindow renderWindow("Rect Demo", 600, 600, "");

		bool gameRunning = true;
		SDL_Event event;

		renderWindow.InitRect(200, 200, 200, 200);

		int x_pos = 0, y_pos = 0;
		int moveSpeed = 10;

		while (gameRunning)
		{
			renderWindow.DrawBackground();
			renderWindow.MoveRect(x_pos, y_pos);
			renderWindow.DrawRect();

			//x_pos++;

			if (x_pos == 600) x_pos = 0;
			if (y_pos == 600) y_pos = 0;

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					gameRunning = false;

				if (event.type == SDL_KEYDOWN)
				{
					switch (event.key.keysym.sym)
					{
					case SDLK_UP:
						y_pos -= moveSpeed;
						break;
					case SDLK_DOWN:
						y_pos += moveSpeed;
						break;
					case SDLK_LEFT:
						x_pos -= moveSpeed;
						break;
					case SDLK_RIGHT:
						x_pos += moveSpeed;
						break;
					default:
						break;
					}
				}
			}

			std::cout << "x:" << x_pos << "y:" << y_pos << std::endl;
		}

		renderWindow.CleanUp();
	}
}