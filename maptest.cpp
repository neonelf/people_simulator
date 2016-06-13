#include <stdio.h>
#include <stdlib.h>
#include "Map.h"
#include "Bugg.h"
#include "Surface.h"

int main(int argc, char** argv)
{
	srand(100378);
	Surface DrawPortal(161, 51);
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
		mainMap.Draw(DrawPortal);
	
		DrawPortal.Refresh();
		bug1.Tick(Timespan::FromMiliseconds(100));
		getchar();
	}

	

  return 0;
}
