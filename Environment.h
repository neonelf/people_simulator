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
		virtual void Tick(size_t DeltaTimeSeconds);
		
		void SetLightLevel(int Level, int length_hours);
		uint8_t GetCurLightLevel();

		//debug
		void DebugPrint();
	
	protected:
		int m_LightLevel;
		int m_secondsOfLightMax;
		int m_secondsTotalElapsed;
};




#endif //__ENVIRONMENT_H__
