#pragma once
#include <iostream>

class Time
{
	unsigned short hours;
	unsigned short minutes;
	unsigned short seconds;

public:
	Time(int hour, int minutes, int seconds) : hours{ unsigned short(hour) }, minutes{ unsigned short(minutes) }, seconds{ unsigned short(seconds) } {};
	Time() :Time(0, 0, 0) {};

	Time operator+(Time time)
	{
		int seconds = this->seconds + this->minutes * 60 + this->hours * 60 * 60;
		seconds += time.seconds + time.minutes * 60 + time.hours * 60 * 60;


		Time temp(seconds / 3600, seconds / 60 - seconds / 3600 * 60, seconds % 60);

		return temp;
	}
	Time operator-(Time time)
	{
		int seconds = this->seconds + this->minutes * 60 + this->hours * 60 * 60;
		seconds -= time.seconds + time.minutes * 60 + time.hours * 60 * 60;
		if (seconds < 0)  seconds += 24 * 60 * 60;

		Time temp(seconds / 3600, seconds / 60 - seconds / 3600 * 60, seconds % 60);
		

		return temp;
	}
	template <typename T>
	Time operator-(T sec)
	{
		int seconds = this->seconds + this->minutes * 60 + this->hours * 60 * 60;
		seconds -= sec;
		if (seconds < 0)  seconds += 24 * 60 * 60;

		Time temp(seconds / 3600, seconds / 60 - seconds / 3600 * 60, seconds % 60);

		return temp;
	}
	friend std::ostream& operator<<(std::ostream& o, const Time time);
};

inline std::ostream& operator<<(std::ostream& o, const Time time)
{
	o << time.hours << ":" << time.minutes << ":" << time.seconds << std::endl;
	return o;
}

