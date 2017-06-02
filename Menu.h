#pragma once
#include<iostream>
#include"Registry.h"
class Menu
{
private:
	/*enums for simpler use*/
	enum TYPE
	{
		ALL = 0,
		JOGGER = 1,
		PROFESSIONAL = 2,
	};

	/*Private variables*/
	int m_Choice;
	Registry m_Reg;

	/*Private functions*/
	int menuShow();
	bool checkChoice();
	void showInfo(TYPE type);
	void addParticipant(TYPE type);
	void removeParticipant();
	void editSeasons();
	void sortParticipants();
public:
	Menu();
	~Menu();

	/*run will handle choices*/
	int run();

	/*get/set functions*/
	int GetChoice() { return this->m_Choice; }
	void SetChoice(int choice) { this->m_Choice = choice; }
};

