#pragma once
#include "Participant.h"
class Professional :
	public Participant
{
private:
	std::string m_Club;
	int m_nrOfSeasons;
public:
	Professional();
	Professional(std::string name, bool gender, std::string club, int nrOfSeasons);
	~Professional();

	/*get/set functions*/
	std::string getClub() const; 
	int getNrOfSeasons() const; 
	void setClub(const std::string club); 
	void setNrOfSeasons(const int nrOfSeasons); 

	/*the toString function returns all the information as a string*/
	virtual std::string toString() const;
};

