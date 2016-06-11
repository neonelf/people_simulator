#ifndef __BUGG_H__
#define __BUGG_H__

#include "Map.h"
#include "Listener.h"
#include "Tickable.h"
#include <vector>

class Bugg : public IListener, public ITickable
{
public:
	//from IListener
	virtual void RecieveUpdate(const MapEventData &eventData);
	virtual MapLocation GetCurrentLocation() const {return m_curLocation;}

	void SetLocation(const MapLocation& NewLocation) { m_curLocation = NewLocation;}
	
	void Tick(const Timespan& Delta);
	void TakeAction(uint64_t action); 
	void Move(uint8_t direction);


protected:
	MapLocation m_curLocation;

	std::vector<MapEventData> m_events;

};


#endif //__BUGG_H__
