#ifndef __WILDERNESS_H__
#define __WILDERNESS_H__

#include "Container.h"
#include "Environment.h"

class Wilderness : public IContainer, public Environment
{
  public:
    Wilderness();
	virtual ~Wilderness();

};



#endif //__WILDERNESS_H__
