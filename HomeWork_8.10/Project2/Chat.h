#pragma once
#include "User.h"
#include "Message.h"
#include <vector>
#include <iostream>
#include <string>

class Chat
{
private:
	std::vector< std::unique_ptr<User> > vecUsers;
	int activeUserID;
public:
	Chat();
	~Chat();
	int getActiveUserID();
	void setActiveUserID(int UserID);
	int numberUsers();
	int findLogin(std::string login);
	int findName(std::string name);
	bool makeNewUser(std::string login, std::string password, std::string name);
	bool checkUserPassword(int userID, std::string password);
	void showListUsers();
	void sendMessage(int recUsersID, std::string text);
	void sendMessagesAll(std::string text);
	void showRecMessages();
	void showSendMessages();
};

