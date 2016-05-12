#include <stdio.h>
#include "Environment.h"

static const int scSecondsPerDay = 86400;

Environment::Environment()
{
	m_LightLevel = 0;
	m_secondsOfLightMax = 0;
	m_secondsTotalElapsed = 0;
	//food, water?
}

void Environment::Tick(size_t DeltaTimeSeconds)
{
	m_secondsTotalElapsed += DeltaTimeSeconds;
	if (m_secondsTotalElapsed > scSecondsPerDay)
	{
		//reset
		m_secondsTotalElapsed %= scSecondsPerDay;
	}
}

void Environment::SetLightLevel(int Level, int length_hours)
{
	m_LightLevel = Level;
	m_secondsOfLightMax = length_hours *60 *60;
}

uint8_t Environment::GetCurLightLevel()
{
	if (m_secondsTotalElapsed <= m_secondsOfLightMax)
		return m_LightLevel;
	else
		return 0;
}

void Environment::DebugPrint()
{
	printf("Environment time: %d, curLight: %d\n",m_secondsTotalElapsed, GetCurLightLevel());
}
