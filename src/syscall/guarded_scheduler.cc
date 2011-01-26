
#include "syscall/guarded_scheduler.h"
#include "syscall/thread.h"

#include "guard/secure.h"

void
Guarded_Scheduler::schedule()
{
	Secure s;
	Scheduler::schedule();
}

void
Guarded_Scheduler::ready(Thread& that)
{
	Secure s;
	Scheduler::ready(that);
}

void
Guarded_Scheduler::exit()
{
	Secure s;
	Scheduler::exit();
}

void
Guarded_Scheduler::kill(Thread* that)
{
	Secure s;
	Scheduler::kill(that);
}

void
Guarded_Scheduler::resume()
{
	Secure s;
	Scheduler::resume();
}
