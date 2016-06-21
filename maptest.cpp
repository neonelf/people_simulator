#include <stdio.h>
#include <stdlib.h>
#include "maptest.h"
#include "Map.h"
#include "Bugg.h"
#include "Surface.h"
#include "UrlListener.h"
#include "Logger.h"

static ActionManager s_MyActionManager;
static Logger s_MyLogger;

ActionManager& getGlobalActionManager() { return s_MyActionManager; } 
Logger& getGlobalLogger() { return s_MyLogger; } 

int main(int argc, char** argv)
{
	srand(100378);

	UrlListener server;
	server.StartListening(7813);
	GameMap mainMap;
	Bugg bug1(300);
	MapLocation a;
	a.x = a.y =10;
	bug1.SetLocation(a);

	mainMap.RegisterListener(&bug1);
	struct MapEventData d;
	d.m_type = 10;
	mainMap.MapEvent(d);
	
	while (1)
	{
		if (server.AcceptAnyNewConnections())
		{
			//read new connection?
			//handle data?
			//respond to ne request?
			//close new connection?
		}
		bug1.Tick(Timespan::FromMiliseconds(100));

		s_MyActionManager.ExecuteActions();
	}

	

  return 0;
}
