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
		void RemoveFromBuffer(SDL_Keycode input);
		SDL_Keycode GetInputFromBuffer();
		bool HasInput(SDL_Keycode input) const;
		bool HasInputs() const;
		void ClearBuffer();
		void PrintBufferContents() const;
	private:
		std::queue<SDL_Keycode> m_buffer;
	};
}