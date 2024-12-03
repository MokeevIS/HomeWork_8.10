#include "User.h"

using namespace std;

User::User(string name, string login, string password)
{
	this->name = name;
	this->login = login;
	this->password = password;
}

User::~User()
{
}

void User::setName(string name)
{
	this->name = name;
}

string User::getName(void) const
{
	return name;
}

string User::getLogin(void) const
{
	return login;
}

bool User::checkPassword(string password)
{
	return (this->password == password);
}
bool User::checkLogin(string login)
{
	return (this->login == login);
}
bool User::checkName(string name)
{
	return (this->name == name);
}

void User::saveRecMess(shared_ptr<Message> newMess)
{
	vecRecMess.emplace_back(newMess);
}

void User::saveSendMess(shared_ptr<Message> newMess)
{
	vecSendMess.emplace_back(newMess);
}

shared_ptr<Message> User::getSaveRecMess(int messageID)
{
	return vecRecMess[messageID];
}

int User::getSizeRecMess()
{
	if (vecRecMess.empty())
		return 0;
	else
		return vecRecMess.size();
}

shared_ptr<Message> User::getSaveSendMess(int messageID)
{
	return vecSendMess[messageID];
}

int User::getSizeSendMess()
{
	if (vecSendMess.empty())
		return 0;
	else
		return vecSendMess.size();
}
