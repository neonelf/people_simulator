#include <stdio.h>
#include "Environment.h"
#include <inttypes.h>

static const Timespan scDaySpan = Timespan::FromMiliseconds(86400000);

Environment::Environment()
{
	m_LightLevel = 0;
	m_secondsOfLightMax = 0;
	//food, water?
}

void Environment::Tick(const Timespan& Delta)
{
	m_TotalElapsedTime = Delta;
}

void Environment::SetLightLevel(int Level, int length_hours)
{
	m_LightLevel = Level;
	m_secondsOfLightMax = length_hours *60 *60;
}

uint8_t Environment::GetCurLightLevel()
{
	if ( (m_TotalElapsedTime % scDaySpan).asSeconds() <= m_secondsOfLightMax)
		return m_LightLevel;
	else
		return 0;
}

void Environment::DebugPrint()
{
	printf("Environment time: %" PRId64 ", curLight: %d\n",m_TotalElapsedTime.asSeconds(), GetCurLightLevel());
}
