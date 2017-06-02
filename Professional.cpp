#include "Professional.h"



Professional::Professional()
{
}

Professional::Professional(std::string name, bool gender, std::string club, int nrOfSeasons)
	:Participant(name, gender)
{
	this->m_Club = club;
	this->m_nrOfSeasons = nrOfSeasons;
}

Professional::~Professional()
{
}

std::string Professional::getClub() const
{
	return this->m_Club;
}

int Professional::getNrOfSeasons() const
{
	return this->m_nrOfSeasons;
}

void Professional::setClub(const std::string club)
{
	this->m_Club = club;
}

void Professional::setNrOfSeasons(const int nrOfSeasons)
{
	this->m_nrOfSeasons = nrOfSeasons;
}

std::string Professional::toString() const
{
	/*This function returns a string with all the information of the current object*/
	std::string to;
	std::ostringstream convert;
	convert << this->m_nrOfSeasons;
	to = "\nClub: " + this->m_Club
		+ "\nNumber of seasons as a professional: "
		+ convert.str() + "\n";
	return Participant::toString() + to;
}
