/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                          D I S P A T C H E R                              *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "thread/dispatch.h"
#include "thread/entrant.h"
#include "machine/toc.h"

void
Dispatcher::go(Entrant& first)
{
	life = &first;
	toc_go(&first.regs);
}

void
Dispatcher::dispatch(Entrant& next)
{
	Entrant *co = life;

	life = &next;
	toc_switch(&co->regs, &next.regs);
}

Entrant*
Dispatcher::active()
{
	return life;
}
