#ifndef __TIMESPAN_H__
#define __TIMESPAN_H__

#include <cstdint>

class Timespan
{
public:
	static Timespan FromMiliseconds(int64_t Miliseconds); 
	
	Timespan(): m_MicroSeconds(0) {}
	Timespan(const Timespan& rhs) { operator=(rhs); } 
	const Timespan& operator=(const Timespan& rhs) {m_MicroSeconds=rhs.m_MicroSeconds; return *this;}
	const Timespan& operator+=(const Timespan& rhs) {m_MicroSeconds+=rhs.m_MicroSeconds; return *this;}
	Timespan operator+(const Timespan& rhs)const ;

	const Timespan& operator%=(const Timespan& rhs) {m_MicroSeconds%=rhs.m_MicroSeconds; return *this;}
	Timespan operator%(const Timespan& rhs) const;


	bool operator==(const Timespan& rhs)const { return m_MicroSeconds == rhs.m_MicroSeconds; } 
	bool operator>(const Timespan& rhs) const { return m_MicroSeconds > rhs.m_MicroSeconds; }
	bool operator<(const Timespan& rhs) const { return m_MicroSeconds < rhs.m_MicroSeconds; } 


	int64_t asSeconds()const  { return m_MicroSeconds/1000000;}
	int64_t asMinutes() const { return m_MicroSeconds/60000000;}


protected:
	int64_t m_MicroSeconds;	
};




#endif //__TIMESPAN_H__
