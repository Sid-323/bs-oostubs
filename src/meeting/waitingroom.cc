#include "meeting/waitingroom.h"
#include "thread/customer.h"
#include "syscall/guarded_scheduler.h"

extern Guarded_Scheduler scheduler;

Waitingroom::~Waitingroom()
{
	Customer *c;

	while ((c = (Customer *)dequeue()))
		scheduler.Organizer::wakeup(*c);
}

void
Waitingroom::remove(Customer &customer)
{
	Queue::remove(&customer);
}
