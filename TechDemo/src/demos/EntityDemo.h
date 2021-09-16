#pragma once

#include <SDL.h>

#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>

#include "BCUtils.h"

#include "RenderWindow.h"
#include "InputBuffer.h"
#include "Entity.h"
#include "Physics.h"

namespace Demos
{
	class EntityDemo
	{
	public:
		EntityDemo();
		void Start();
	};
}