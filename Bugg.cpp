#include <stdio.h>
#include "Bugg.h"
#include <memory.h>
#include <stdlib.h>

#include "maptest.h"
#include "Logger.h"

const uint64_t FirstByte =  0x00000000000000FF;
const uint64_t SecondByte = 0x000000000000FF00;


Bugg::Bugg(int BrainSize):  m_Brain(BrainSize)
{
	for (int i=0; i < BrainSize; ++i)
	{
		m_Brain[i] = rand() % 256;	
	}
	m_BrainRead = 0;
}

void Bugg::RecieveUpdate(const MapEventData &eventData) 
{
	m_events.push_back(eventData);
}

void Bugg::Move(uint8_t Direction)
{
	Direction %= DIR_MAX;
	std::stringstream ssMsg; 
	ssMsg << "Bugg:Move dir: " << (int)Direction << '\n';
	getGlobalLogger().Log(CHANNEL_TRACE, ssMsg.str());
	getGlobalActionManager().Add(new MoveAction((enumDirection)Direction, *this));
	
}

uint64_t Bugg::Think()
{
  uint64_t retvalue;
  if (m_BrainRead > m_Brain.size()) m_BrainRead=0; 
  ::memcpy(&retvalue, &m_Brain[m_BrainRead], sizeof(retvalue));
  m_BrainRead += sizeof(retvalue);
  return retvalue;
}

void Bugg::TakeAction(uint64_t action)
{
	const uint8_t Max_action = 2;
		
	uint8_t curAction = (action&FirstByte) % Max_action;
	std::stringstream ssMsg;
	ssMsg << "Bugg::TakeAction() action: "<< curAction;
	switch (curAction)
	{
		case 1:
			ssMsg << "Move\n";
			Move(0x07&(action>>4));
			break;
		default:
			ssMsg << "Rest \n";
		break;
		//do nothing. Even buggs have to rest
	}
	getGlobalLogger().Log(CHANNEL_TRACE, ssMsg.str());
}

void Bugg::Tick(const Timespan& Delta)
{
  //iterate over events, add to sensory input bank 

  //think about what to do, decide goal.
  int64_t action = Think();
  //do it
  TakeAction(action);
}




