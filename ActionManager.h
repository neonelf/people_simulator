#ifndef __ACTIONMANAGER_H__
#define __ACTIONMANAGER_H__

#include <vector>
#include "Action.h"

class ActionManager
{
public:
	void ExecuteActions();	
	void Add(IAction* pNodeToAdd);
protected:

	std::vector<IAction*> m_ActionList;	
};




#endif //__ACTIONMANAGER_H__
