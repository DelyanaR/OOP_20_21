#pragma once
#include<string>
#include <vector>
#include "Message.hpp"


class Subscriber{
public:
	Subscriber(std::string new_id);
	virtual ~Subscriber()=default;

	virtual void signal(Message) = 0;
	virtual int read()const = 0;
	virtual Subscriber* clone() = 0;

	const std::string id;

protected:
	std::vector<Message> mes;
};

