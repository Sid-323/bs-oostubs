/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                G U A R D                                  *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "guard/guard.h"
#include "guard/secure.h"
#include "guard/gate.h"
#include "object/queue.h"

#include "machine/cpu.h"

extern CPU cpu;

Gate *
Guard::remove_epilogue()
{
	Gate *item;

	cpu.disable_int();
	item = (Gate *)epilogues.dequeue();
	cpu.enable_int();

	if (item)
		item->queued(false);
	return item;
}

void
Guard::leave()
{
	Gate *item;

	while ((item = remove_epilogue()))
		item->epilogue();

	retne(); /* NOTE: ensures that epilogues are secured against other epilogues */
}

void
Guard::relay(Gate *item)
{
	if (avail()) {
		Secure s; /* NOTE: ensures that epilogues are secured against other epilogues */

		cpu.enable_int();
		item->epilogue();
	} else if (!item->queued()) {
		epilogues.enqueue(item);
		item->queued(true);
	}
}
