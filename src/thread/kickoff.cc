#include "thread/kickoff.h"
#include "thread/coroutine.h"

void
kickoff(Coroutine *co)
{
	co->action();
	co->exit();

	/* shouldn't be reached */
	while (42);
}
