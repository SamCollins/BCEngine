#pragma once

#include <SDL.h>

#include <iostream>
#include <queue>

namespace BCEngine
{
	class InputBuffer
	{
	public:
		InputBuffer();
		void AddToBuffer(SDL_Keycode input);
		SDL_Keycode GetInput();
		void ClearBuffer();
		void PrintBufferContents();
	private:
		std::queue<SDL_Keycode> m_buffer;
	};
}