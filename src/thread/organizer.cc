#include "thread/organizer.h"
#include "thread/customer.h"
#include "thread/scheduler.h"
#include "meeting/waitingroom.h"

void
Organizer::block(Waitingroom& waitingroom)
{
	Customer *c = active();

	c->waiting_in(&waitingroom);
	exit();
}

void
Organizer::wakeup(Customer& customer)
{
	customer.waiting_in(0x0);
	ready(customer);
}

/* NOTE: all other kill's use pointers to the thread object */
void
Organizer::kill(Customer& that)
{
	Waitingroom *w;

	if ((w = that.waiting_in()))
		w->remove(that);
	else
		Scheduler::kill(&that);
}
