#include "Plant.h"


Plant::Plant()
{
	m_LightExposure = 0;
	m_bPrevReadWasDark = true;
}

Plant::~Plant() {}

const Plant& operator=(const PLant& rhs)
{
	m_LightExposure = rhs.m_LightExposure;
	m_bPrevReadWasDark = rhs.m_bPrevReadWasDark;
	

	return *this;

}

void Plant::Tick(size_t DeltaTimeSeconds)
{
	//get light reading from leaf container 
	//if (is currently light)
		//if Prev read was dark  
		//reset to 0
	  //_add Delta time to m_LightExposure


}
 
