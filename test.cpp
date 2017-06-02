#include<string>
#include<iostream>
#include "Registry.h"
#include "Menu.h"
int main2()											/*remove 2, to test*/
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	/*dynamically creating a Registry object*/
	Registry *reg = new Registry;

	/*adding participants*/
	reg->AddJogger("bertil", Registry::GENDER::FEMALE, 30);
	reg->AddProfessional("alex", Registry::GENDER::FEMALE, "HIF", 3);
	reg->AddJogger("adam", Registry::GENDER::MALE, 12);

	/*testing copy-constructor*/
	Registry reg2(*reg);

	/*testing editing, one with the wrong index and one with the right one.
	Because the object at index 0 is a jogger and joggers do not have seasons*/
	reg->EditNrOfSeasons(0, 20);
	reg->EditNrOfSeasons(1, 20);

	/*testing the overloaded assignement operator.
	First with itself, which will trigger filsafe.
	Then with another object, which will work.*/
	*reg = *reg;
	*reg = reg2;

	/*sorting all participants*/
	reg->SortParticipants();

	/*allocating a string array to be filled with registry information*/
	std::string applicantTest[10];

	/*gathering all the info from just the joggers*/
	reg->GatherInfoJoggers(applicantTest);

	/*printing all the information*/
	for (int i = 0; i < reg->getNrOfJoggers(); ++i)
	{
		std::cout << applicantTest[i];
	}

	/*testing the destructor*/
	delete reg;

	return 0;
}