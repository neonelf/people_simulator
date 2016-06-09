#ifndef __BUGG_H__
#define __BUGG_H__

#include "Map.h"
#include "Listener.h"

class Bugg : public IListener
{
public:
	//from IListener
	virtual void RecieveUpdate(const MapEventData &eventData) const;
	virtual MapLocation GetCurrentLocation() const {return m_curLocation;}

	void SetLocation(const MapLocation& NewLocation) { m_curLocation = NewLocation;}


protected:
	MapLocation m_curLocation;

};


#endif //__BUGG_H__
