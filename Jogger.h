#pragma once
#include "Participant.h"
class Jogger :
	public Participant
{
private:
	int m_Age;
public:
	Jogger();
	Jogger(std::string name, bool gender, int age);
	~Jogger();

	/*get/set functions*/
	int getAge() const; 
	void setAge(const int age); 

	/*the toString function returns all the information as a string*/
	virtual std::string toString() const;
};

