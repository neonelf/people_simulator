#ifndef __PERSON_H__
#define __PERSON_H__

class Person
{
	public:
	Person();
	~Person();
	 
	Person(const Person& rhs) { operator=(rhs); }
	const Person& operator=(const Person& rhs);
	
	//person will have needs which translate to Goals
	//person will have known operations (some basic, some recipes)
	//person will have current goal, and next step?
	//person will have personality that will order all goals, and be used to evaluate all steps to a goal.

	protected:
		unsigned int m_Hunger;

};



#endif //__PERSON_H__
