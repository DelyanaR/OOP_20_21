#pragma once
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "Publisher.hpp"

// SimplePublisher is a Publisher, which can have one
// or more subscribers and upon receiving a message
// via `signal()`, it replays that message to all the
// subscribers
class SimplePublisher: public Publisher {
public:
	SimplePublisher() = default;

	// subscribe registers a Subscriber to start receiving messages
	void subscribe(Averager*)override;
	void subscribe(MovingAverager*)override;
	void subscribe(PeriodicSampler*)override;

	// signal receives a message from an external source
	// and replays that message to all the current subscribers
	void signal(Message mes) override;
};
