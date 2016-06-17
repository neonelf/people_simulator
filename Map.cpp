#include "Map.h"
#include "Listener.h"
#include "Surface.h"


void GameMap::MapEvent(const struct MapEventData& evtData)
{
	//send to all registered listeners
	for (ListenerRegistryContainerType::const_iterator itr = m_listenerRegistry.begin();
	     itr != m_listenerRegistry.end();
		 ++itr)
	 {
	   (*itr)->RecieveUpdate(evtData);
	 }
}

void GameMap::Draw(Surface& visual)
{
	//iterate listeners and getLoc?
	 for (ListenerRegistryContainerType::const_iterator itr = m_listenerRegistry.begin();
	      itr != m_listenerRegistry.end();
	      ++itr)
	 {
	 	//visual.DrawAt((*itr)->GetCurrentLocation(), '@');
	 }
}


