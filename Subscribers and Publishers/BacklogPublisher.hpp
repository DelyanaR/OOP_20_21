#pragma once
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "Publisher.hpp"

// BacklogPublisher is a Publisher, which can have one
// or more subscribers and upon receiving a message
// via `signal()`, it replays that message to all the
// subscribers
// Also it keeps a backlog of previous messages so when a new
// Subscriber subscribes, the Publisher replays all
// backlogged messages to the new Subscriber
class BacklogPublisher: public Publisher {
public:
	BacklogPublisher()=default;
	
	// subscribe registers a Subscriber to start receiving messages
	// The new subscriber should receive all previous messages
	void subscribe(Averager*)override;
	void subscribe(MovingAverager*)override;
	void subscribe(PeriodicSampler*)override;

	// signal receives a message from an external source
	// and replays that message to all the current subscribers
	void signal(Message mes)override;

private:
	std::vector<Message> allMes;
};
