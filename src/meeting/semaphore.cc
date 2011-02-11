#include "meeting/semaphore.h"
#include "thread/customer.h"
#include "syscall/guarded_scheduler.h"

extern Guarded_Scheduler scheduler;

void
Semaphore::p()
{
	if (cnt) {
		cnt--;
	} else {
		enqueue(scheduler.Organizer::active());
		scheduler.Organizer::block(*this);
	}
}

void
Semaphore::v()
{
	Customer *c;

	if ((c = (Customer *)dequeue()))
		scheduler.Organizer::wakeup(*c);
	else
		cnt++;
}
