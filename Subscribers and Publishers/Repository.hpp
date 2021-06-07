#pragma once
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include <vector>

// Repository is the single place where Subscribers will
// be stored. A Repository has ownership of the Subscribers
// stored inside it.
// The only way to access the available Subscribers in the
// repository is via the Subscriber's unique id.
// id's are guaranteed to be unique
class Repository {
public:
	// add registers a new Subscriber in the Repository
	void add(Subscriber*);

	Repository()=default;
	virtual ~Repository() = default;
	Repository& operator=(const Repository& rhs);
	Repository(const Repository& rhs);

	//get returns a Subscriber in the Repository if a
	// Subscriber with the given id exists.
	// Returns nullptr otherwise
	Subscriber* get(std::string id);

private:
	std::vector<Subscriber*> subscribers;
};

