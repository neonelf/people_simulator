#include <stdio.h>
#include "ActionManager.h"
#include "Logger.h"

using namespace std;

void ActionManager::ExecuteActions()
{
	stringstream ssMsg;
	ssMsg << "ActionManager::ExecuteActions size: " <<  m_ActionList.size() << '\n';
	getGlobalLogger().Log(CHANNEL_TRACE, ssMsg.str());

	for (vector<IAction*>::iterator itr = m_ActionList.begin();
		 itr != m_ActionList.end(); ++itr)
	{
		ssMsg.str(std::string()); //clear it out
		ssMsg << "Exectue Action: " << (*itr)->GetDescription() << '\n'; 
		getGlobalLogger().Log(CHANNEL_TRACE, ssMsg.str());

		(*itr)->Execute();
		delete (*itr);
	}
	m_ActionList.clear();
}


void ActionManager::Add(IAction* pNodeToAdd)
{
	m_ActionList.push_back(pNodeToAdd);
}
