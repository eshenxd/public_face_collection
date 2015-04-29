#include "compareTime.h"


void updateConfig(GETTIME time, Config& config){

	config.year = time.fyear;
	config.month = time.fmonth;
	config.day = time.fday;

	config.hour = time.fhour;
	config.minute = time.fminute;
	config.second = time.fsecond;
}

void compareTime(GETTIME time, Config& config)
{
	if (time.fyear > config.year){

		updateConfig(time, config);
	}

	if (time.fyear == config.year&&time.fmonth > config.month){

		updateConfig(time, config);
	}

	if (time.fyear == config.year&&time.fmonth == config.month&&time.fday > config.day){

		updateConfig(time, config);
	}

	if (time.fyear == config.year&&time.fmonth == config.month&&time.fday == config.day
		&&time.fhour > config.hour){

		updateConfig(time, config);
	}

	if (time.fyear == config.year&&time.fmonth == config.month&&time.fday == config.day
		&&time.fhour == config.hour&&time.fminute > config.minute){

		updateConfig(time, config);
	}

	if (time.fyear == config.year&&time.fmonth == config.month&&time.fday == config.day
		&&time.fhour == config.hour&&time.fminute == config.minute&&time.fsecond > config.second){

		updateConfig(time, config);
	}

}