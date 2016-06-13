#include "Timespan.h"
 
Timespan Timespan::FromMiliseconds(int64_t Miliseconds)
{
	Timespan retval;
	retval.m_MicroSeconds = Miliseconds*1000;	
	return retval;
}

Timespan Timespan::operator+(const Timespan& rhs) const
{
	Timespan retval;
	retval.m_MicroSeconds = (m_MicroSeconds + rhs.m_MicroSeconds);
	return retval;
}

Timespan Timespan::operator%(const Timespan& rhs) const
{
    Timespan retval;
    retval.m_MicroSeconds = (m_MicroSeconds % rhs.m_MicroSeconds);
    return retval;
}

