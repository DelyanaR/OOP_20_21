#include "TeamLead.hpp"

TeamLead::TeamLead(const std::string& name, double salary) {
	setName(name);
	setSalary(salary);
	setLead(this);
}

std::vector<Developer*> TeamLead::getTeam()const {
	return this->team;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary) {
	if (developer != nullptr) {
		developer->setInitialSalary(salary);
		developer->setLead(this);
		this->team.push_back(developer);
	}
}

void TeamLead::removeDeveloperFromTeam(const std::string& name) {
	for (int i = this->team.size() - 1; i >=0; i--) {
		if (this->team[i]->getName() == name) {
			this->team[i]->setLead(nullptr);
			this->team.erase(this->team.begin() + i);
			return;
		}
	}
}

void TeamLead::increaseTeamSalariesBy(double amount) {
	for (size_t i = 0; i < this->team.size(); i++) {
		double slr = this->team[i]->getSalary() + amount;
		this->team[i]->setSalary(slr);
	}
}

void TeamLead::decreaseTeamSalariesBy(double amount) {
	for (size_t i = 0; i < this->team.size(); i++) {
		double slr = this->team[i]->getSalary() - amount;
		this->team[i]->setSalary(slr);
	}
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest) {
	this->leaveRequests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest) {
	this->promotionRequests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests() {
	while(!this->leaveRequests.empty()){
		for (size_t j = 0; j < this->team.size(); j++) {
			if (this->leaveRequests[0].getSender() == this->team[j]->getName()) {
				this->team[j]->setLead(nullptr);
				this->team.erase(this->team.begin() + j);
				this->leaveRequests.erase(this->leaveRequests.begin());
			}
		}
	}
}

void TeamLead::fulfillPromotionRequests() {
	while (!this->promotionRequests.empty()) {
		for (size_t j = 0; j < this->team.size(); j++) {
			if (this->promotionRequests[0].getSender() == this->team[j]->getName()) {
				this->team[j]->setSalary(this->team[j]->getSalary()+this->promotionRequests[0].getAmount());
				this->promotionRequests.erase(this->promotionRequests.begin());
			}
		}
	}
}