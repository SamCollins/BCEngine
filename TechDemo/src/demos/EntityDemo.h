#pragma once

#include <SDL.h>

#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>

#include "BCUtils.h"

#include "Engine.h"
#include "Physics.h"
#include "RenderWindow.h"
#include "Entity.h"

namespace Demos
{
	class EntityDemo
	{
	public:
		EntityDemo();
		void Start();
	};
}