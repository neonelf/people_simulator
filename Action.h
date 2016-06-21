#ifndef __ACTION_H__
#define __ACTION_H__

#include <string>

class IAction
{
public:
	virtual void Execute()=0;
	virtual std::string GetDescription() const =0;
};





#endif //__ACTION_H__
