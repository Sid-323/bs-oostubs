#include "thread/kickoff.h"
#include "thread/coroutine.h"
#include "guard/guard.h"

extern Guard guard;

void
kickoff(Coroutine *co)
{
	guard.leave();
	co->action();
	co->exit();

	/* shouldn't be reached */
	while (42);
}
