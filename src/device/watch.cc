/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              W A T C H                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "device/watch.h"

#include "guard/guard.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "syscall/guarded_scheduler.h"

extern Plugbox plugbox;
extern PIC pic;

extern Guarded_Scheduler scheduler;

void
Watch::windup()
{
	plugbox.assign(Plugbox::timer, *this);
	pic.allow(PIC::timer);
}

void
Watch::epilogue()
{
	scheduler.Scheduler::resume();
}
