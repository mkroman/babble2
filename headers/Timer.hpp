#pragma once
#include <stdint.h>
#include <SDL/SDL.h>

class Timer
{
public:
	/*!
	 * Construct a new timer.
	 */
	Timer();

	/*!
	 * Clean up our mess.
	 */
	~Timer();

	/*!
	 * \brief Check whether or not the timer is active.
	 */
	bool active() const
	{
		return m_active;
	}

	/*!
	 * \brief Get the number of ticks since m_time.
	 */
	int ticks();

	/*!
	 * \brief Start the timer.
	 */
	void start();

	/*!
	 * \brief Stop the timer.
	 */
	void stop();

private:
	bool     m_active;
	uint32_t m_time;
};
