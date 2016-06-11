#ifndef __MAP_H__
#define __MAP_H__

#include "Registry.h"

enum EventDataType
{
  SMELL =  0x00,
  SOUND =  0x01,
  SIGHT =  0x02 
};

typedef struct _MapLocation 
{
	int x;
	int y;

} MapLocation;

struct MapEventData
{
//type How Sensed?
	int m_type;
//source Location?
};


class GameMap : public IRegistry
{
	public:
		void MapEvent(const struct MapEventData& evtData);

		
};


#endif //__MAP_H__
