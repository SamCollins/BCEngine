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
		void AddToBuffer(SDL_EventType input);
		SDL_EventType GetInput();
		void ClearBuffer();
		void PrintBufferContents();
	private:
		std::queue<SDL_EventType> m_buffer;
	};
}