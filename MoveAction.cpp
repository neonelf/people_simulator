
#include "MoveAction.h"


void MoveAction::Execute()
{
	//move this bastard
	MapLocation tmpLoc = m_ObjToMove.GetCurrentLocation();
	printf("MoveAction::Execute ");
	switch (m_Dir)
	{
		case DIR_EAST: tmpLoc.x++;
		    printf("East\n");
		break;
		case DIR_SOUTH: tmpLoc.y++;
            printf("South\n");
        break;
        case DIR_WEST: tmpLoc.x--;
            printf("West\n");
        break;
        case DIR_NORTH: tmpLoc.y--;
            printf("North\n");
        break;
		default:
			printf("Unknown dir\n");
		break;
	}
	m_ObjToMove.SetLocation(tmpLoc);
	

}
