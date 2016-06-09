#ifndef __REGISTRY_H__
#define __REGISTRY_H__

#include <unordered_set>

//forward decl
class IListener;

typedef std::unordered_set<IListener*> ListenerRegistryContainerType;

class IRegistry
{
	public:
		void RegisterListener(IListener* pListener);
		void DeregisterListener(IListener*  pListener);
	protected:
		ListenerRegistryContainerType  m_listenerRegistry;
};




#endif //__REGISTR_H__
