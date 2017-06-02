#include "Registry.h"




Registry::Registry()
{
	this->m_Participants = new Participant*[0];
}

Participant** Registry::AllocateOneParticipant() 
{
	/*This function will allocate memory for one participant*/
	Participant** temp;
	temp = new Participant*[this->m_NrOfParticipants + 1];
	for (int i = 0; i < this->m_NrOfParticipants; ++i)
		temp[i] = this->m_Participants[i];
	delete[] this->m_Participants;
	return temp;
}

Registry::~Registry()
{
	for (int i = 0; i < this->m_NrOfParticipants; ++i)
		delete m_Participants[i];
	delete[] m_Participants;
}

Registry& Registry::operator=(const Registry& other)
{
	if (this != &other)
	{
		/*cleaning the allocated memory*/
		for (int i = 0; i < this->m_NrOfParticipants; ++i)
			delete m_Participants[i];
		delete[] m_Participants;

		/*copying the information*/
		this->m_NrOfParticipants = other.m_NrOfParticipants;
		this->m_Participants = new Participant*[this->m_NrOfParticipants];
		for (int i = 0; i < this->m_NrOfParticipants; ++i)
		{
			Professional* p = dynamic_cast<Professional*>(other.m_Participants[i]);
			if (p != nullptr)
			{
				this->m_Participants[i] = new Professional(p->getName(), p->getGender(), p->getClub(), p->getNrOfSeasons());
			}
			else
			{
				Jogger* temp = (Jogger*)other.m_Participants[i];
				this->m_Participants[i] = new Jogger(temp->getName(), temp->getGender(), temp->getAge());
			}
		}
	}
	return *this;
}

Registry::Registry(const Registry & other)
{
	this->m_NrOfParticipants = other.m_NrOfParticipants;
	this->m_Participants = new Participant*[this->m_NrOfParticipants];
	for (int i = 0; i < this->m_NrOfParticipants; ++i)
	{
		Professional* p = dynamic_cast<Professional*>(other.m_Participants[i]);
		if (p != nullptr)
		{
			this->m_Participants[i] = new Professional(p->getName(), p->getGender(), p->getClub(), p->getNrOfSeasons());
		}
		else
		{
			Jogger* temp = (Jogger*)other.m_Participants[i];
			this->m_Participants[i] = new Jogger(temp->getName(), temp->getGender(), temp->getAge());
		}
	}
}

void Registry::AddJogger(std::string name, GENDER gender, int age)
{
	Participant** temp = this->AllocateOneParticipant();
	temp[this->m_NrOfParticipants] = new Jogger(name, (gender==FEMALE?true:false), age); 
	this->m_Participants = temp;
	this->m_NrOfParticipants++;
}

void Registry::AddProfessional(std::string name, GENDER gender, std::string club, int nrOfSeasons)
{
	Participant** temp = this->AllocateOneParticipant();
	temp[this->m_NrOfParticipants] = new Professional(name, (gender==FEMALE?true:false), club, nrOfSeasons);
	this->m_Participants = temp;
	this->m_NrOfParticipants++;
}

void Registry::RemoveParticipant(int which)
{
	/*This function will delete the paticipant decided by the parameter and
	sort the array so that the "dead" position ends up last.*/
	delete this->m_Participants[which];
	this->m_NrOfParticipants--;
	
	/*swapping the participants so that the deleted one is put last*/
	Participant* temp = this->m_Participants[which];
	this->m_Participants[which] = this->m_Participants[this->m_NrOfParticipants];
	this->m_Participants[this->m_NrOfParticipants] = temp;
}

bool Registry::EditNrOfSeasons(int which, int newAmount)
{
	/*This function will edit the number of seasons of an existing professional based on
	the parameters if the current object is indeed a professional.*/
	bool result = false;
	Professional* p = dynamic_cast<Professional*>(this->m_Participants[which]);
	if (p != nullptr)
	{
		((Professional*)this->m_Participants[which])->setNrOfSeasons(newAmount);
		result = true;
	}
	return result;
}

void Registry::SortParticipants()
{
	/*This function will sort all the participants in alphabetical formation*/
	for (int i = 0; i < this->m_NrOfParticipants; ++i)
	{
		for (int j = i+1; j < this->m_NrOfParticipants; ++j)
		{
			if (*this->m_Participants[j] < *this->m_Participants[i])
			{
				Participant* temp = this->m_Participants[i];
				this->m_Participants[i] = this->m_Participants[j];
				this->m_Participants[j] = temp;
			}
		}
	}
}

int Registry::getNrOfParticipants() const
{
	return this->m_NrOfParticipants;
}

int Registry::getNrOfProfessionals() const
{
	/*This function will check if the participants are professional or not and return the
	number of professionals*/
	int nrOfProf = 0;
	for (int i = 0; i < this->m_NrOfParticipants; ++i)
	{
		Professional* p = dynamic_cast<Professional*>(this->m_Participants[i]);
		if (p != nullptr)
			nrOfProf++;
	}
	return nrOfProf;
}

int Registry::getNrOfJoggers() const
{
	/*This function will check if the participants are joggers or not and return the
	number of professionals*/
	int nrOfJog = 0;
	for (int i = 0; i < this->m_NrOfParticipants; ++i)
	{
		Jogger* p = dynamic_cast<Jogger*>(this->m_Participants[i]);
		if (p != nullptr)
			nrOfJog++;
	}
	return nrOfJog;
}

int Registry::getIndex(std::string name) const
{
	/*This function will loop all of the existing participants and find the
	index number of the participant with the same name as the parameter. If no
	name is found, this function returns -1*/
	int index = -1;
	for (int i = 0; i < this->m_NrOfParticipants; ++i)
	{
		if (name == this->m_Participants[i]->getName())
		{
			index = i;
			i = this->m_NrOfParticipants;
		}
	}
	return index;
}

void Registry::GatherInfoAll(std::string information[]) const
{
	/*loop through all of the participants toString function*/
	for (int i = 0;	i < this->m_NrOfParticipants; ++i)
	{
		information[i] = this->m_Participants[i]->toString();
	}
}

void Registry::GatherInfoJoggers(std::string information[]) const
{
	/*loop through all of the Joggers toString function*/
	int stringCtrl = 0;
	for (int i = 0; i < this->m_NrOfParticipants; ++i)
	{
		Jogger* p = dynamic_cast<Jogger*>(this->m_Participants[i]);
		if (p != nullptr)
		{
			information[stringCtrl] = this->m_Participants[i]->toString();
			stringCtrl++;
		}
	}
}

void Registry::GatherInfoProfessionals(std::string information[]) const
{
	/*loop through all of the professionals toString function*/
	int stringCtrl = 0;
	for (int i = 0; i < this->m_NrOfParticipants; ++i)
	{
		Professional* p = dynamic_cast<Professional*>(this->m_Participants[i]);
		if (p != nullptr)
		{
			information[stringCtrl] = this->m_Participants[i]->toString();
			stringCtrl++;
		}
	}
}

