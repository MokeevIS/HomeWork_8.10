#pragma once
#include <string>
#include <vector>
#include "Message.h"


class User
{
private:
	std::string name;
	std::string login;
	std::string password;
	std::vector< std::shared_ptr<Message> > vecSendMess;
	std::vector< std::shared_ptr<Message> > vecRecMess;

public:
	User(std::string name, std::string login, std::string password);
	~User();
	void setName(std::string name);
	std::string getName(void) const;
	std::string getLogin(void) const;
	bool checkPassword(std::string password);
	bool checkLogin(std::string login);
	bool checkName(std::string name);
	void saveRecMess(std::shared_ptr<Message> newMess);
	void saveSendMess(std::shared_ptr<Message> newMess);
	std::shared_ptr<Message> getSaveRecMess(int messageID);
	int getSizeRecMess();
	std::shared_ptr<Message> getSaveSendMess(int messageID);
	int getSizeSendMess();
};

