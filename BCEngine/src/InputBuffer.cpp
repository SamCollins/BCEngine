#include "InputBuffer.h"

namespace BCEngine
{
	InputBuffer::InputBuffer()
		:m_buffer()
	{

	}

	void InputBuffer::AddToBuffer(SDL_EventType input)
	{
		m_buffer.push(input);
	}

	SDL_EventType InputBuffer::GetInput()
	{
		SDL_EventType queuedInput = m_buffer.front();
		m_buffer.pop();
		return queuedInput;
	}

	void InputBuffer::ClearBuffer()
	{
		while (!m_buffer.empty())
		{
			m_buffer.pop();
		}
	}

	void InputBuffer::PrintBufferContents()
	{
		std::queue tempQueue(m_buffer);

		std::cout << "Buffer Contents:" << std::endl;
		while (!tempQueue.empty())
		{
			std::cout << tempQueue.front() << ", ";
			tempQueue.pop();
		}
		std::cout << std::endl;
	}
}