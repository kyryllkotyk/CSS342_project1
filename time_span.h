#include <math.h>

using namespace std;

class TimeSpan
{
private:
	int hour = 0, minute = 0, second = 0;

	TimeSpan normalize(double hours, double minutes, double seconds) {
		int hoursInt = int(hours),
			minutesInt = int(minutes),
			secondsInt = round(seconds);

		//Dealing with negatives
		if (hours < 0) {
			minutes -= hours * 60;
		}
		if (minutes < 0) {
			seconds -= minutes * 60;
		}

		//Converting doubles into ints
		if (hoursInt != hours) {
			minutes += (hours - hoursInt) * 60;
			hours = hoursInt;
		}
		if (minutesInt != minutes) {
			seconds += (minutes - minutesInt) * 60;
		}

		minutes += seconds / 60;
		secondsInt = seconds;
		secondsInt %= 60;
		hours += minutes / 60;
		minutesInt = minutes;
		minutesInt %= 60;

		TimeSpan normalizedTime(hoursInt, minutesInt, secondsInt);
		return normalizedTime;
	}

public:
	TimeSpan(double hours, double minutes, double seconds) {
		set_time(hours, minutes, seconds);
	}

	TimeSpan(double minutes, double seconds) {
		set_time(0, minutes, seconds);
	}

	TimeSpan(double seconds) {
		set_time(0, 0, seconds);
	}

	void set_time(int hours, int minutes, int seconds) {
		this->normalize(hours, minutes, seconds);
	}

	int hours() const {
		return hour;
	}

	int minutes() const {
		return minute;
	}

	int seconds() const {
		return second;
	}

	/*bool operator==(const TimeSpan& timeToCompare) const {
		return (this->hours() == timeToCompare.hours()
			or this->minutes() == timeToCompare.minutes()
			or this->seconds() == timeToCompare.seconds());
	}



	void operator+(const TimeSpan& timeToAdd) {
		set_time(timeToAdd.hours() + this->hours(),
			timeToAdd.minutes() + this->minutes(),
			timeToAdd.seconds() + this->seconds());
	}*/


	//OVERLOAD
	// +, -, ==, !=, <, <=, >, >=, =, +=, -=

		//void operator=(const TimeSpan& timeToEquate)  {
	//	set_time(timeToEquate.hours(), timeToEquate.minutes(), timeToEquate.seconds());
	//}
};

