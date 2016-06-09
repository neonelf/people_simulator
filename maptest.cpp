#include <stdio.h>
#include "Map.h"
#include "Bugg.h"

int main(int argc, char** argv)
{
	GameMap mainMap;
	Bugg bug1;

	mainMap.RegisterListener(&bug1);
	struct MapEventData d;
	d.m_type = 10;
	mainMap.MapEvent(d);

  return 0;
}
