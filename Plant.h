#ifndef __PLANT_H__
#define __PLANT_H__


class Plant : public Tickable
{
	public:
		Plant();
		~Plant();

		Plant(const Plant& rhs) {operator=(rhs);}
		const Plant& operator=(const Plant& rhs);

		void Tick(size_t DeltaTimeSeconds);
	protected:
		unsigned int m_LightExposureAccumulator; //reset at transition from dark->light
		unsigned int m_LightExposurePrevious;
		bool m_bPrevReadWasDark;

};




#endif //__PLANT_H__
