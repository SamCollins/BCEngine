#pragma once

#include <SDL.h>

#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>

#include "BCUtils.h"

#include "BCCore/GameWindow.h"
#include "BCCore/InputBuffer.h"
#include "BCCore/Entity.h"
#include "BCSim/Vector2.h"
#include "BCSim/Environment.h"

namespace Demos
{
	class EntityDemo
	{
	public:
		EntityDemo();
		void Start();

		void ToggleFpsInfo();
		void ToggleInputInfo();

		//void AddInputToBuffer(SDL_Keycode input);
		void PopulateInputBuffer();
		void ResolveInput();
	private:
		bool g_showFpsInfo;
		bool g_showInputInfo;
		int g_currentFrame;
		BCCore::InputBuffer g_inputBuffer;

		BCCore::Entity* g_playableEntity;
	};
}