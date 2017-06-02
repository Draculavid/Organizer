#pragma once
#include <string>
#include <sstream>
class Participant
{
public:
	bool operator< (const Participant& right) const;
private:
	/*this variable will hold the participants name*/
	std::string m_Name;
	/*For the gender, true will mean Female and false will mean Male*/
	bool m_Gender;
public:
	Participant();
	Participant(std::string name, bool gender);
	virtual ~Participant() = 0;

	/*get/set functions*/
	std::string getName() const; 
	bool getGender() const; 
	void setName(const std::string name); 
	void setGender(const bool gender);

	/*the toString function returns all the information as a string*/
	virtual std::string toString() const;
};

