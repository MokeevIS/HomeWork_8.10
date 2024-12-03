#include "Message.h"

using namespace std;

Message::Message(int senderID, int recipientID, string text)
{
	this->senderID = senderID;
	this->recipientID = recipientID;
	this->text = text;
	statusRead = false;
}

Message::Message(int senderID, string text)
{
	this->senderID = senderID;
	this->recipientID = -1;
	this->text = text;
	statusRead = false;
}

Message::~Message()
{
}

shared_ptr<Message> Message::getPtr() 
{ 
	return shared_from_this();
}

string Message::getText()
{
	statusRead = true;
	return text;
}

int Message::getSenderID()
{
	return senderID;
}

int Message::getRecipientID()
{
	return recipientID;
}

bool Message::getStatusRead()
{
	return statusRead;
}


