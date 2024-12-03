#include <iostream>
#include "Chat.h"

using namespace std;

Chat chat;

//
static void Option_SendMessage()
{
	string choice;
	string input;
	string text;
	int receiverID = -1;

	while (1)
	{
		cout << ".............................................................." << endl;
		cout << "Выберите необходимый вариант: " << endl;
		cout << "1 - Отправить сообщение конкретному пользователю " << endl;
		cout << "2 - Отправить сообщение всем пользователям чата" << endl;
		cout << "0 - назад" << endl;
		getline(cin, choice);

		if (choice == "1")
		{
			cout << "Выберете пользователя из следующего списка:" << endl;
			chat.showListUsers();

			while (1)
			{				
				cout << "Введите ID пользователя:" << endl;
				getline(cin, input);

				try {
					receiverID = stoi(input) - 1;
				}
				catch (invalid_argument e) {
					cout << "Неверный ввод! Необходимо ввести целое неотрицательное число!" << endl;
					continue;
				}

				if ((receiverID <= chat.numberUsers() -1) && (receiverID >= 0))
				{
					while (1)
					{
						cout << "Введите сообщение для отправки выбранному пользователю:" << endl;
						getline(cin, text);
						if (text.empty())
						{
							cout << "Сообщение не может быть пустым! " << endl;
							continue;
						}
						else
						{							
							chat.sendMessage(receiverID, text);
							cout << "Сообщение отправленно! " << endl;
							break;
						}
					}
					break;
				}
				else
				{
					cout << "Такого пользователя нет!" << endl;
					continue;
				}	
			}
						
		}			
		else if (choice == "2")
		{
			while (1)
			{
				cout << "Введите сообщение для отправки всем пользователям:" << endl;
				getline(cin, text);
				if (text.empty())
				{
					cout << "Сообщение не может быть пустым! " << endl;
					continue;
				}
				else
				{
					chat.sendMessagesAll(text);
					cout << "Сообщение отправленно! " << endl;
					break;
				}
			}
		}
		else if (choice == "0")
			return;
		else
			cout << "Неверный ввод!" << endl;
	}
}	
//
static void Option_ShowRecMessage()
{
	cout << ".............................................................." << endl;		
	chat.showRecMessages();		
	cout << ".............................................................." << endl;
}
//
static void Option_ShowSendMessage()
{
	cout << ".............................................................." << endl;
	chat.showSendMessages();
	cout << ".............................................................." << endl;
}

// Регистрация пользователя 
static bool Option_RegisterAnAccount()
{
	string name;
	string login;
	string password;

	cout << "Введите логин" << endl;
	getline(cin, login);
	if (chat.findLogin(login) > -1)
	{
		cout << "Пользователь с таким именем уже зарегистрирован" << endl;
		return false;
	}

	cout << "Введите пароль" << endl;
	getline(cin, password);

	cout << "Введите имя" << endl;
	getline(cin, name);

	if (chat.makeNewUser(login, password, name))
	{
		cout << "Пользователь успешно зарегистрирован" << endl;
		return true;
	}
	else
	{
		cout << "Ошибка регистрации нового пользователя" << endl;
		return false;
	}

}

// Авторизация пользователя 
static bool Option_LogInToAccount()
{
	string login;
	string password;
	int userID = -1;

	cout << "Введите логин" << endl;
	getline(cin, login);
	userID = chat.findLogin(login);

	if (userID < 0)
	{
		cout << "Такого пользователя не существует ! ! !" << endl;
		return false;
	}

	for (int i = 3; i > 0; i--)
	{
		cout << "Введите пароль" << endl;
		getline(cin, password);
		if (chat.checkUserPassword(userID, password))
		{
			chat.setActiveUserID(userID);
			return true;
		}
		else
			cout << "Неверный пароль! Осталось попыток: " << i << endl;
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string choice;
	bool inAcc = 0;

	while (1)
	{
		cout << endl;
		cout << ".............................................................." << endl;
		cout << "Выберите необходимый вариант: " << endl;
		cout << "1 - Вход" << endl;
		cout << "2 - Регистрация" << endl;
		getline(cin, choice);

		if (choice == "1")
		{
			if (!Option_LogInToAccount())
				continue;
		}
		else if (choice == "2")
		{
			if (!Option_RegisterAnAccount())
				continue;
		}
		else
		{
			cout << "Неверный ввод!" << endl;
			continue;
		}
			


		while (1)
		{
			cout << "Выберите один вариант: " << endl;
			cout << "1 - Создать сообщение" << endl;
			cout << "2 - Входящие" << endl;
			cout << "3 - Отправленые" << endl;
			cout << "0 - Выйти" << endl;
			getline(cin, choice);
		
			if (choice == "1")
				Option_SendMessage();
			else if (choice == "2")
				Option_ShowRecMessage();
			else if (choice == "3")
				Option_ShowSendMessage();
			else if (choice == "0")
				break;
			else
				cout << "Неверный ввод!" << endl;
		}
			
	}
}