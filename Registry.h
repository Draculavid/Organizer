#pragma once
#include "Participant.h"
#include "Jogger.h"
#include "Professional.h"
class Registry
{
public:
	/*enums for simpler use*/
	enum GENDER
	{
		MALE = 0,
		FEMALE = 1,
	};
	
	/*overloaded operator*/
	Registry& operator=(const Registry& other);
private:
	int m_NrOfParticipants;
	Participant** m_Participants;

	/*private function for allocating one memory space*/
	Participant** AllocateOneParticipant();
public:																						   
	Registry();
	~Registry();
	Registry(const Registry &other);														  
											
	/*General functions*/
	void AddJogger(std::string name, GENDER gender, int age);								  
	void AddProfessional(std::string name, GENDER gender, std::string club, int nrOfSeasons); 
	void RemoveParticipant(int which);														  
	bool EditNrOfSeasons(int which, int newAmount);											  
	void SortParticipants();																  

	/*get functions*/
	int getNrOfParticipants() const;
	int getNrOfProfessionals() const;														  
	int getNrOfJoggers() const;																  
	int getIndex(std::string name) const;

	/*Fills a string array with the information of all participants*/
	void GatherInfoAll(std::string information[]) const;									  
	void GatherInfoJoggers(std::string information[]) const;								  
	void GatherInfoProfessionals(std::string information[]) const;							  

	
};

