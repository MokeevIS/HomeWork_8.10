#include "Chat.h"
#include <memory>

using namespace std;

Chat::Chat()
{
	activeUserID = -1; // нет активного пользователя
}

Chat::~Chat()
{
}

int Chat::getActiveUserID()
{
	return activeUserID;
}

void Chat::setActiveUserID(int UserID)
{
	activeUserID = UserID;
}

bool Chat::makeNewUser(string login, string password, string name)
{	
	vecUsers.emplace_back( make_unique<User>(login, password, name));
	activeUserID = vecUsers.size() - 1;
	return true;	
}

int Chat::numberUsers()
{
	return vecUsers.size();
}

int Chat::findLogin(string login)
{
	for (int i = 0; i < numberUsers(); i++)
		if (vecUsers[i]->checkLogin(login))
			return i;
	return -1;
}
int Chat::findName(string name)
{
	for (int i = 0; i < numberUsers(); i++)
		if (vecUsers[i]->checkName(name))
			return i;
	return -1;
}

bool Chat::checkUserPassword(int userID, string password)
{
	return (vecUsers[userID]->checkPassword(password));
}

// Отображение списка пользователей
void Chat::showListUsers()
{	
	for (int i = 0; i < numberUsers(); i++)
		cout << "ID: " << i+1 << ", Имя - " << vecUsers[i]->getName() << endl;
}

// Отправка сообщения 
void Chat::sendMessage(int recUsersID, string text)
{
	shared_ptr<Message> mess_ptr = make_shared<Message>(activeUserID, recUsersID, text);
	
	vecUsers[activeUserID]->saveSendMess(mess_ptr);
	vecUsers[recUsersID]->saveRecMess(mess_ptr);
	
}

// Отправка сообщения всем пользователям 
void Chat::sendMessagesAll(string text)
{
	shared_ptr<Message> mess_ptr = make_shared<Message>(activeUserID, text);

	vecUsers[activeUserID]->saveSendMess(mess_ptr);
	for (int i = 0; i < numberUsers(); i++)
	{
		if (activeUserID != i)
			vecUsers[i]->saveRecMess(mess_ptr);
	}
		
}


// Показать список полученных сообщений  
 void Chat::showRecMessages()
{
	int size = vecUsers[activeUserID]->getSizeRecMess();
			
	for (int i = 0; i < size; i++)
	{
		shared_ptr<Message> mess_ptr = vecUsers[activeUserID]->getSaveRecMess(i);
		int senderID = mess_ptr->getSenderID();

		cout << "Oт: " << vecUsers[senderID]->getName() << ", (ID:" << senderID << "), ";
		
		if (mess_ptr->getStatusRead())
			cout << "Прочитанное" << endl;
		else
			cout << "Непрочитанное" << endl;

		cout << "	Текст: "<< mess_ptr->getText() << endl;
				
	}
}

// Показать список отправленных сообщений  
void Chat::showSendMessages()
{
	int size = vecUsers[activeUserID]->getSizeSendMess();

	for (int i = 0; i < size; i++)
	{
		shared_ptr<Message> mess_ptr = vecUsers[activeUserID]->getSaveSendMess(i);
		int recipientID = mess_ptr->getRecipientID();

		if (mess_ptr->getRecipientID() == -1)
			cout << "Кому: Всем пользователям, ";
		else
			cout << "Кому: " << vecUsers[recipientID]->getName() << ", (ID:" << recipientID << "), ";

		if (mess_ptr->getStatusRead())
			cout << "Прочитанное" << endl;
		else
			cout << "Непрочитанное" << endl;

		cout << "	Текст: " << mess_ptr->getText() << endl;

	}
}
