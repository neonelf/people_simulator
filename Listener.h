#ifndef __LISTENER_H__
#define __LISTENER_H__

#include <unordered_set>
#include "Map.h"


//forward decl
class IRegistry;

typedef std::unordered_set<IRegistry*>  RegistryContainerType;
class IListener
{
	public:
		virtual void RecieveUpdate(const MapEventData &eventData) =0;	
		virtual MapLocation GetCurrentLocation() const = 0;
		void AddRegistry(IRegistry* pRegistry) {m_registryToUnregisterFrom.insert(pRegistry);}
		virtual ~IListener();
	private:
		RegistryContainerType m_registryToUnregisterFrom;
};








#endif // __LISTENER_H__
