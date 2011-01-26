/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                 T O C                                     *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "machine/toc.h"

void
toc_settle(struct toc* regs, void* tos, void (*kickoff)(void*), void* object)
{
	void **t = tos;

	*--t = object;
	--t; /* will be SP after "return" to kickoff so this has to be reserved as kickoffs "return address" */
	*--t = kickoff;

	regs->esp = t;
}
