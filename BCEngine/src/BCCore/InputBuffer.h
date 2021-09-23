#pragma once

#include <SDL.h>

#include <iostream>
#include <queue>

namespace BCCore
{
	class InputBuffer
	{
	public:
		InputBuffer();
		void AddToBuffer(SDL_Keycode input);
		SDL_Keycode GetInput();
		bool HasInputs();
		void ClearBuffer();
		void PrintBufferContents();
	private:
		std::queue<SDL_Keycode> m_buffer;
	};
}