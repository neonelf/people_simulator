#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include "Enivronment.h"

class IContainer
{
	public:
	  IContainer();
	  virtual ~IContainer();

	  const Enivronment& getEnvironment() const;
	  size_t getSize() const;

	protected:
	  size_t m_size;
	  Environment m_ContainerEnv;


};




#endif //__CONTAINER_H__
