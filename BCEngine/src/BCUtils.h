#pragma once

#include <SDL.h>

namespace BCUtils
{
	//TODO: Rename this, don't know a good name for it but this is bad
	inline double TimeInSeconds()
	{
		double ticks = static_cast<double>(SDL_GetTicks());
		ticks *= 0.001;

		return ticks;
	}
}