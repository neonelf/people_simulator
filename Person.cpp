#include "Person.h"


Person::Person() 
{
	m_Hunger = 0;
}

Person::~Person() {}

const Person& Person::operator=(const Person& rhs)
{
	
	m_Hunger = rhs.m_Hunger;
}
