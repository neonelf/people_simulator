#ifndef __ENVIRONMENT_H__
#define __ENVIRONMENT_H__

#include "Tickable.h"
#include <cstdint>

class Environment : public ITickable
{
	public:
		Environment();
		~Environment() {}
		
		//inherited 
		virtual void Tick(const Timespan&  Delta);
		
		void SetLightLevel(int Level, int length_hours);
		uint8_t GetCurLightLevel();

		//debug
		void DebugPrint();
	
	protected:
		int m_LightLevel;
		int m_secondsOfLightMax;
		Timespan  m_TotalElapsedTime;
};




#endif //__ENVIRONMENT_H__
