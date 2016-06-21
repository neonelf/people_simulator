
#include "MoveAction.h"
#include "Logger.h"

void MoveAction::Execute()
{
	//move this bastard
	MapLocation tmpLoc = m_ObjToMove.GetCurrentLocation();
	std::stringstream ssMsg;
	ssMsg << "MoveAction::Execute ";
	switch (m_Dir)
	{
		case DIR_EAST: tmpLoc.x++;
		    ssMsg << "East\n";
		break;
		case DIR_SOUTH: tmpLoc.y++;
            ssMsg << "South\n";
        break;
        case DIR_WEST: tmpLoc.x--;
            ssMsg << "West\n";
        break;
        case DIR_NORTH: tmpLoc.y--;
            ssMsg << "North\n";
        break;
		default:
			ssMsg << "Unknown dir\n";
		break;
	}
	getGlobalLogger().Log(CHANNEL_TRACE, ssMsg.str());
	m_ObjToMove.SetLocation(tmpLoc);
	

}
