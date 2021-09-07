#pragma once

#include <SDL.h>

namespace BCUtils
{
	//TODO: Rename this, don't know a good name for it but this is bad
	inline float TimeInSeconds()
	{
		float ticks = SDL_GetTicks();
		ticks *= 0.001f;

		return ticks;
	}
}