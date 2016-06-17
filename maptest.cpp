#include <stdio.h>
#include <stdlib.h>
#include "maptest.h"
#include "Map.h"
#include "Bugg.h"
#include "Surface.h"

static ActionManager s_MyActionManager;

ActionManager& getGlobalActionManager() { return s_MyActionManager; } 


int main(int argc, char** argv)
{
	srand(100378);
	
	GameMap mainMap;
	Bugg bug1(300);
	MapLocation a;
	a.x = a.y =10;
	bug1.SetLocation(a);

	mainMap.RegisterListener(&bug1);
	struct MapEventData d;
	d.m_type = 10;
	mainMap.MapEvent(d);

	for(int i=0; i < 10; ++i)
	{
		bug1.Tick(Timespan::FromMiliseconds(100));

		s_MyActionManager.ExecuteActions();
	}

	

  return 0;
}
