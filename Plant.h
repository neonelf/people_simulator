#ifndef __PLANT_H__
#define __PLANT_H__

#include "Tickable.h"

//forward decel
class Environment;

class Plant : public ITickable
{
	public:
		Plant();
		~Plant();


		//inherited from ITickable
		virtual void Tick(size_t DeltaTimeSeconds);

		void Put(Environment &WhereIAm);

		//Debug
		void DebugPrint();

	protected:
		unsigned int m_LightExposureAccumulator; //reset at transition from dark->light
		unsigned int m_LightExposurePrevious;
		bool m_bPrevReadWasDark;

		Environment *m_pCurEnvironment;

};




#endif //__PLANT_H__
