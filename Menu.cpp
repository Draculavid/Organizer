#include "Menu.h"



int Menu::menuShow()
{
	bool menuChoice = false;
	std::cout << "0 Exit\n1 Add Jogger\n2 Add Professional\n3 Show all participants\n4 Show all joggers\n5 Show all professionals\n6 Remove participant\n7 change number of seasons of a professional\n8 sort all participants\n\nYour choice: ";
	std::cin >> this->m_Choice;
	menuChoice = checkChoice();
	while (!menuChoice)
	{
		std::cout << "invalid choice, please reenter: ";
		std::cin >> this->m_Choice;
		menuChoice = checkChoice();
	}
	return this->m_Choice;
}

bool Menu::checkChoice()
{
	bool result = true;
	if (this->m_Choice < 0 || this->m_Choice > 8)
	{
		result = false;
	}
	return result;
}

void Menu::showInfo(TYPE type)
{
	/*this function will interpret which info the user wants, gather it and show it*/
	std::string *info = nullptr;
	info = new std::string[this->m_Reg.getNrOfParticipants()];
	switch (type)
	{
	case Menu::ALL:
		this->m_Reg.GatherInfoAll(info);
		for (int i = 0; i < this->m_Reg.getNrOfParticipants(); ++i)
			std::cout << info[i];
		break;
	case Menu::JOGGER:
		this->m_Reg.GatherInfoJoggers(info);
		for (int i = 0; i < this->m_Reg.getNrOfJoggers(); ++i)
			std::cout << info[i];
		break;
	case Menu::PROFESSIONAL:
		this->m_Reg.GatherInfoProfessionals(info);
		for (int i = 0; i < this->m_Reg.getNrOfProfessionals(); ++i)
			std::cout << info[i];
		break;
	default:
		break;
	}
	delete[] info;
}

void Menu::addParticipant(TYPE type)
{
	/*This function will be used if the user wishes to add a participant*/
	std::string name; int gender;
	std::cout << "\nName of participant: ";
	std::cin >> name;
	std::cout << "Gender of participant (enter with numbers, 0 for female and 1 for male): ";
	std::cin >> gender;
	while (gender < 0 || gender > 1)
	{
		std::cout << "Invalid choice, please enter again: ";
		std::cin >> gender;
	}
	if (type == Menu::JOGGER)
	{
		int age;
		std::cout << "Age of the participant: ";
		std::cin >> age;
		m_Reg.AddJogger(name, (Registry::GENDER)gender, age);
	}
	else
	{
		std::string club; int nrSeasons;
		std::cout << "Name of club: ";
		std::cin >> club;
		std::cout << "Number of seasons the participant has been a member: ";
		std::cin >> nrSeasons;
		m_Reg.AddProfessional(name, (Registry::GENDER)gender, club, nrSeasons);
	}
}

void Menu::removeParticipant()
{
	/*This function is called when a user wishes to remove a participant.*/
	std::string choice;
	showInfo(Menu::ALL);
	std::cout << "\nwhich participant do you want to remove? (write the name) ";
	std::cin >> choice;
	int index = m_Reg.getIndex(choice);
	if (index != -1)
	{
		m_Reg.RemoveParticipant(index);
	}
}

void Menu::editSeasons()
{
	/*This function will let the user edit the number of seasons of an existing professional*/
	std::string choice;
	showInfo(Menu::PROFESSIONAL);
	std::cout << "\nwhich professional do you wish to edit? (write the name) ";
	std::cin >> choice;
	int index = m_Reg.getIndex(choice);
	if (index != -1)
	{
		int newValue;
		std::cout << "new value: ";
		std::cin >> newValue;
		m_Reg.EditNrOfSeasons(index, newValue);
	}
}

void Menu::sortParticipants()
{
	m_Reg.SortParticipants();
}

Menu::Menu()
{
}

Menu::~Menu()
{
}

int Menu::run()
{
	this->m_Choice = menuShow();
	while (this->m_Choice != 0)
	{
		switch (this->m_Choice)
		{
		case(1):
			/*add a jogger*/
			addParticipant(Menu::JOGGER);
			break;
		case(2):
			/*add a professional*/
			addParticipant(Menu::PROFESSIONAL);
			break;
		case(3):
			/*show all participants*/
			showInfo(Menu::ALL);
			break;
		case(4):
			/*show all joggers*/
			showInfo(Menu::JOGGER);
			break;
		case(5):
			/*show all professionals*/
			showInfo(Menu::PROFESSIONAL);
			break;
		case(6):
			/*remove a participant*/
			removeParticipant();
			break;
		case(7):
			/*change the seasons of a professional*/
			editSeasons();
			break;
		case(8):
			/*sort all the participants*/
			sortParticipants();
			break;

		default:
			break;
		}
		this->m_Choice = menuShow();
	}
	return 0;
}
