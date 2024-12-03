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
		cout << "�������� ����������� �������: " << endl;
		cout << "1 - ��������� ��������� ����������� ������������ " << endl;
		cout << "2 - ��������� ��������� ���� ������������� ����" << endl;
		cout << "0 - �����" << endl;
		getline(cin, choice);

		if (choice == "1")
		{
			cout << "�������� ������������ �� ���������� ������:" << endl;
			chat.showListUsers();

			while (1)
			{				
				cout << "������� ID ������������:" << endl;
				getline(cin, input);

				try {
					receiverID = stoi(input) - 1;
				}
				catch (invalid_argument e) {
					cout << "�������� ����! ���������� ������ ����� ��������������� �����!" << endl;
					continue;
				}

				if ((receiverID <= chat.numberUsers() -1) && (receiverID >= 0))
				{
					while (1)
					{
						cout << "������� ��������� ��� �������� ���������� ������������:" << endl;
						getline(cin, text);
						if (text.empty())
						{
							cout << "��������� �� ����� ���� ������! " << endl;
							continue;
						}
						else
						{							
							chat.sendMessage(receiverID, text);
							cout << "��������� �����������! " << endl;
							break;
						}
					}
					break;
				}
				else
				{
					cout << "������ ������������ ���!" << endl;
					continue;
				}	
			}
						
		}			
		else if (choice == "2")
		{
			while (1)
			{
				cout << "������� ��������� ��� �������� ���� �������������:" << endl;
				getline(cin, text);
				if (text.empty())
				{
					cout << "��������� �� ����� ���� ������! " << endl;
					continue;
				}
				else
				{
					chat.sendMessagesAll(text);
					cout << "��������� �����������! " << endl;
					break;
				}
			}
		}
		else if (choice == "0")
			return;
		else
			cout << "�������� ����!" << endl;
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

// ����������� ������������ 
static bool Option_RegisterAnAccount()
{
	string name;
	string login;
	string password;

	cout << "������� �����" << endl;
	getline(cin, login);
	if (chat.findLogin(login) > -1)
	{
		cout << "������������ � ����� ������ ��� ���������������" << endl;
		return false;
	}

	cout << "������� ������" << endl;
	getline(cin, password);

	cout << "������� ���" << endl;
	getline(cin, name);

	if (chat.makeNewUser(login, password, name))
	{
		cout << "������������ ������� ���������������" << endl;
		return true;
	}
	else
	{
		cout << "������ ����������� ������ ������������" << endl;
		return false;
	}

}

// ����������� ������������ 
static bool Option_LogInToAccount()
{
	string login;
	string password;
	int userID = -1;

	cout << "������� �����" << endl;
	getline(cin, login);
	userID = chat.findLogin(login);

	if (userID < 0)
	{
		cout << "������ ������������ �� ���������� ! ! !" << endl;
		return false;
	}

	for (int i = 3; i > 0; i--)
	{
		cout << "������� ������" << endl;
		getline(cin, password);
		if (chat.checkUserPassword(userID, password))
		{
			chat.setActiveUserID(userID);
			return true;
		}
		else
			cout << "�������� ������! �������� �������: " << i << endl;
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
		cout << "�������� ����������� �������: " << endl;
		cout << "1 - ����" << endl;
		cout << "2 - �����������" << endl;
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
			cout << "�������� ����!" << endl;
			continue;
		}
			


		while (1)
		{
			cout << "�������� ���� �������: " << endl;
			cout << "1 - ������� ���������" << endl;
			cout << "2 - ��������" << endl;
			cout << "3 - �����������" << endl;
			cout << "0 - �����" << endl;
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
				cout << "�������� ����!" << endl;
		}
			
	}
}