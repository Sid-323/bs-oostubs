/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                          C O R O U T I N E                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "thread/coroutine.h"
#include "thread/kickoff.h"
#include "machine/toc.h"

#include "thread/scheduler.h"

extern Scheduler scheduler;

/* to be compatible with C the signature of the kickoff function need to be changed to do this, one can cast the kickoff function using the fallowing line:
 * void(*kickoffC)(void*) = reinterpret_cast<void(*)(void*)>(&kickoff);
 *
 * kickoffC can then be passed to toc_settle
 */

Coroutine::Coroutine(void* tos)
{
	toc_settle(&regs, tos, reinterpret_cast<void(*)(void*)>(&kickoff), this);
}

void
Coroutine::resume()
{
	scheduler.resume();
}

void
Coroutine::exit()
{
	scheduler.exit();
}
