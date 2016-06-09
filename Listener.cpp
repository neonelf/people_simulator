#include "Listener.h"

void IRegistry::RegisterListener(IListener* pListener)
{
	m_listenerRegistry.insert(pListener);
	pListener->AddRegistry(this);
}

void IRegistry::DeregisterListener(IListener* pListener)
{
	m_listenerRegistry.erase(pListener);
}

IListener::~IListener()
{
	for (RegistryContainerType::const_iterator itr = m_registryToUnregisterFrom.begin();
	     itr != m_registryToUnregisterFrom.end();
		 ++itr)
	{
		(*itr)->DeregisterListener(this);
	}
}


