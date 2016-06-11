#ifndef __TICKABLE_H__
#define __TICKABLE_H__

#include "Timespan.h"

class ITickable
{
	public:
	  ITickable() {}
	  virtual ~ITickable() {}
	  virtual void Tick(const Timespan& Delta)=0;
}; 



#endif //__TICKABLE_H__
