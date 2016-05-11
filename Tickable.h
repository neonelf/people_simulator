#ifndef __TICKABLE_H__
#define __TICKABLE_H__

#include <cstddef>

class ITickable
{
	public:
	  ITickable() {}
	  virtual ~ITickable() {}
	  virtual void Tick(size_t DeltaTimeSeconds)=0;
}; 



#endif //__TICKABLE_H__
