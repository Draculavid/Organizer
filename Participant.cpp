#include "Participant.h"



Participant::Participant()
{
}

Participant::Participant(std::string name, bool gender)
{
	this->m_Name = name;
	this->m_Gender = gender;
}

Participant::~Participant()
{
}

bool Participant::operator< (const Participant& right) const
{
	/*This overloaded operator compares the names of the parametres and
	return true or false based on which name is alphabetically higher or
	lower in the alphabet*/

	bool value = false;
	/*getting the smallest length of both names*/
	unsigned int size = this->m_Name.size();
	if (size > right.m_Name.size())
		size = right.m_Name.size();

	for (unsigned int i = 0; i < size; ++i)
	{
		if ((char)this->m_Name[i] != (char)right.m_Name[i])
		{
			if ((char)this->m_Name[i] < (char)right.m_Name[i])
			{
				value = true;
			}
			i = size;
		}
	}
	return value;
}

std::string Participant::getName() const
{
	return this->m_Name;
}

bool Participant::getGender() const
{
	return this->m_Gender;
}

void Participant::setName(const std::string name)
{
	this->m_Name = name;
}

void Participant::setGender(const bool gender)
{
	this->m_Gender = gender;
}

std::string Participant::toString() const
{
	/*This function returns a string with all the information of the current object*/
	std::string to;
	to = "Name of participant: " + this->m_Name
		+ "\nGender: " + (this->m_Gender ? "Female" : "Male");
	return to;
}
