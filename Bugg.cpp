#include <stdio.h>
#include "Bugg.h"

void Bugg::RecieveUpdate(const MapEventData &eventData) const
{
	printf("Bugg recievedUpdate %d\n", eventData.m_type);
}

