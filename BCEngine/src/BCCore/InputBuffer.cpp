#include "InputBuffer.h"

namespace BCCore
{
	InputBuffer::InputBuffer()
		:m_buffer(), m_maxBufferLength(10)
	{

	}

	void InputBuffer::AddToBuffer(SDL_Keycode input)
	{
		if (m_buffer.size() < m_maxBufferLength)
			m_buffer.push(input);
	}

	void InputBuffer::RemoveFromBuffer(SDL_Keycode input)
	{
		std::queue<SDL_Keycode> tempQueue;
		while (!m_buffer.empty())
		{
			if (m_buffer.front() == input)
			{
				m_buffer.pop();
			}
			else
			{
				tempQueue.push(m_buffer.front());
				m_buffer.pop();
			}
		}

		m_buffer = tempQueue;
	}

	SDL_Keycode InputBuffer::GetInputFromBuffer()
	{
		SDL_Keycode queuedInput = m_buffer.front();
		m_buffer.pop();
		return queuedInput;
	}

	bool InputBuffer::HasInput(SDL_Keycode input) const
	{
		std::queue tempQueue(m_buffer);

		while (!m_buffer.empty())
		{
			if (m_buffer.front() == input)
				return true;
		}

		return false;
	}

	bool InputBuffer::HasInputs() const
	{
		return !m_buffer.empty();
	}

	void InputBuffer::ClearBuffer()
	{
		while (!m_buffer.empty())
		{
			m_buffer.pop();
		}
	}

	void InputBuffer::PrintBufferContents() const
	{
		std::queue tempQueue(m_buffer);

		std::cout << "Buffer Contents:" << std::endl;
		while (!tempQueue.empty())
		{
			std::cout << SDL_GetKeyName(tempQueue.front()) << " ";
			tempQueue.pop();
		}
		std::cout << std::endl;
	}
}