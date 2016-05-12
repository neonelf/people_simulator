#include <stdlib.h>
#include <stdio.h>

#include "Plant.h"
#include "Environment.h"


Plant::Plant()
{
	m_pCurEnvironment = NULL;
	m_LightExposureAccumulator = 0;
	m_LightExposurePrevious = 0;
	m_bPrevReadWasDark = true;
}

Plant::~Plant() {}


void Plant::Tick(size_t DeltaTimeSeconds)
{
	uint8_t LightReading = 0;
	//get light reading from leaf container 
	if (m_pCurEnvironment)
	{
		LightReading = m_pCurEnvironment->GetCurLightLevel();
		if (LightReading > 0)
		{
			if (m_bPrevReadWasDark)
			{
			  m_LightExposurePrevious = m_LightExposureAccumulator;
			  m_LightExposureAccumulator = 0; //reset for a new day
			}
			m_LightExposureAccumulator += LightReading * DeltaTimeSeconds;
			m_bPrevReadWasDark = false;
		}
		else
		{
			//reading was 0 remember that.
			m_bPrevReadWasDark = true;
		}
	}
}

void Plant::Put(Environment &WhereIAm)
{
	m_pCurEnvironment = &WhereIAm;
}
 
void Plant::DebugPrint()
{
	printf("Plant Light Exp: %d | PrevLight: %d\n", m_LightExposureAccumulator, m_LightExposurePrevious);
}
