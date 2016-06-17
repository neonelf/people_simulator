#include <stdio.h>
#include "ActionManager.h"

using namespace std;

void ActionManager::ExecuteActions()
{
	printf("ActionManager::ExecuteActions size:%lu\n", m_ActionList.size());
	for (vector<IAction*>::iterator itr = m_ActionList.begin();
		 itr != m_ActionList.end(); ++itr)
	{
		printf("Exectue : 0x%X\n", (*itr)); 
		(*itr)->Execute();
		delete (*itr);
	}
	m_ActionList.clear();
}


void ActionManager::Add(IAction* pNodeToAdd)
{
	m_ActionList.push_back(pNodeToAdd);
}
