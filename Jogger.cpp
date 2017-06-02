#include "Jogger.h"



Jogger::Jogger()
{
}

Jogger::Jogger(std::string name, bool gender, int age)
	:Participant(name, gender)
{
	this->m_Age = age;
}

Jogger::~Jogger()
{
}

int Jogger::getAge() const
{
	return this->m_Age;
}

void Jogger::setAge(const int age)
{ 
	this->m_Age = age; 
}

std::string Jogger::toString() const
{
	/*This function returns a string with all the information of the current object*/
	std::string to;
	std::ostringstream convert;
	convert << this->m_Age;
	to = "\nAge: " + convert.str() + "\n";
	return Participant::toString() + to;
}
