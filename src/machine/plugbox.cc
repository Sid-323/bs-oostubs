/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              P L U G B O X                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

/* INCLUDES */
#include "machine/plugbox.h"

#include "guard/gate.h"
#include "device/panic.h"

extern Panic panic;

Plugbox::Plugbox()
{
	for (unsigned short i = 64; i;)
		assign(--i, panic);	/* does slot 0 exist? */
}

void
Plugbox::assign(unsigned short slot, Gate &gate)
{
	map[slot] = &gate;
}

Gate &
Plugbox::report(unsigned short slot)
{
	return *map[slot];
}
