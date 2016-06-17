#ifndef __BUGG_H__
#define __BUGG_H__

#include "Map.h"
#include "Listener.h"
#include "Tickable.h"
#include "MoveAction.h"

#include <vector>

class Bugg : public IListener, public ITickable, public IMovable
{
public:
	Bugg(int BrainSize);
	//from IListener
	virtual void RecieveUpdate(const MapEventData &eventData);

	
	void Tick(const Timespan& Delta);
	void TakeAction(uint64_t action); 
	void Move(uint8_t direction);
	uint64_t Think();


protected:

	std::vector<MapEventData> m_events;
	std::vector<char> m_Brain;
	int m_BrainRead;
private:
	Bugg();

};


#endif //__BUGG_H__
