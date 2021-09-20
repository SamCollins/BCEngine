#pragma once

#include <SDL.h>

#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>

#include "BCUtils.h"

#include "BCCore/RenderWindow.h"
#include "BCCore/InputBuffer.h"
#include "BCCore/Entity.h"
#include "BCSim/Physics.h"

namespace Demos
{
	class EntityDemo
	{
	public:
		EntityDemo();
		void Start();
	};
}