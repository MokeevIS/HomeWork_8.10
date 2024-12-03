#pragma once
#include <string>
#include <memory>
#include <iostream>


class Message : public std::enable_shared_from_this<Message>
{
private:
	std::string text;
	int senderID;
	int recipientID;
	bool statusRead;
public:
	Message(int senderID, int recipientID, std::string text);
	Message(int senderID, std::string text);
	~Message();
	std::shared_ptr<Message> getPtr();
	std::string getText();
	int getSenderID();
	int getRecipientID();
	bool getStatusRead();
};

