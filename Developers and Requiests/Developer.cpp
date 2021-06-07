#include "Developer.hpp"
#include "TeamLead.hpp"

Developer::Developer(): name(""), salary(0), lead(nullptr) {
}

Developer::Developer(const std::string& name): name(name), salary(0), lead(nullptr) {
}

std::string Developer::getName()const {
	return this->name;
}

double Developer::getSalary()const {
	return this->salary;
}

TeamLead* Developer::getTeamLead()const {
	return this->lead;
}

void Developer::setInitialSalary(double amount) {
	if (this->salary == 0) {
		this->salary = amount;
	}
}

void Developer::sendLeavingRequest() {
	if (this->lead != nullptr) {
		this->lead->addLeavingRequest(LeavingRequest(this->name));
	}
}

void Developer::sendPromotionRequest(double amount) {
	if (this->lead != nullptr) {
		this->lead->addPromotionRequest(PromotionRequest(this->name, amount));
	}
}

void Developer::setName(const std::string& new_name) {
	this->name = new_name;
}

void Developer::setSalary(double salary) {
	this->salary = salary;
}

void Developer::setLead(TeamLead* new_lead) {
	this->lead = new_lead;
}
