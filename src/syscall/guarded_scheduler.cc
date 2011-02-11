#include "syscall/guarded_scheduler.h"
#include "syscall/thread.h"
#include "thread/organizer.h"

#include "guard/secure.h"

void
Guarded_Scheduler::schedule()
{
	Secure s;
	Organizer::schedule();
}

void
Guarded_Scheduler::ready(Thread& that)
{
	Secure s;
	Organizer::ready(that);
}

void
Guarded_Scheduler::exit()
{
	Secure s;
	Organizer::exit();
}

void
Guarded_Scheduler::kill(Thread* that)
{
	Secure s;
	Organizer::kill(*that);
}

void
Guarded_Scheduler::resume()
{
	Secure s;
	Organizer::resume();
}
