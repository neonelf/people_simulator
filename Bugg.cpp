#include <stdio.h>
#include "Bugg.h"
#include <memory.h>


const uint64_t FirstByte =  0x00000000000000FF;
const uint64_t SecondByte = 0x000000000000FF00;


void Bugg::RecieveUpdate(const MapEventData &eventData) 
{
	m_events.push_back(eventData);
}

void Bugg::Move(uint8_t Direction)
{
	switch (Direction)
	{
		case 1:	m_curLocation.x++;
			break;
		case 2: m_curLocation.y++;
			break;
		case 3: m_curLocation.x--;
			break;
		case 4: m_curLocation.y--;
			break;
	}

}

uint64_t Think()
{
  uint64_t retvalue;
  void* pbuf = malloc(sizeof(retvalue));	
  memcpy (&retvalue, pbuf, sizeof(retvalue));
  free(pbuf);

  return retvalue;
}

void Bugg::TakeAction(uint64_t action)
{
	const uint8_t Max_action = 1;
	
	uint8_t curAction = (action|FirstByte) % Max_action;
	switch (curAction)
	{
		case 1:
			Move(FirstByte|(action>>4));
			break;

		default:
		break;
		//do nothing. Even buggs have to rest
	}
}

void Bugg::Tick(const Timespan& Delta)
{
  //iterate over events, add to sensory input bank 

  //think about what to do, decide goal.
  int64_t action = Think();
  //do it
  TakeAction(action);
}




