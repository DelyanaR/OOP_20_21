#pragma once
#include <iostream>
#include <string>
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"

class TeamLead;

class Developer{
public:
	Developer();
	Developer(const std::string& name);
	std::string getName()const;
	double getSalary()const;
	TeamLead* getTeamLead()const;
	void setInitialSalary(double amount);
	void sendLeavingRequest();
	void sendPromotionRequest(double amount);
	void setLead(TeamLead* new_lead);
	void setName(const std::string& new_name);
	void setSalary(double salary);
private:
	std::string name;
	double salary;
	TeamLead* lead;
};

