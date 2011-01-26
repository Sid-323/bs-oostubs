#include "syscall/thread.h"
#include "syscall/guarded_scheduler.h"

extern Guarded_Scheduler scheduler;

void
resume()
{
	scheduler.resume();
}

void
exit()
{
	scheduler.exit();
}
