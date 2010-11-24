/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              G U A R D I A N                              *
 *                                                                           *
 *---------------------------------------------------------------------------*/

/* INCLUDES */
#include "machine/plugbox.h"
#include "machine/pic.h"

#include "guard/gate.h"

extern PIC pic;
extern Plugbox plugbox;

/* METHODS  */
extern "C" void guardian(unsigned short slot);

/** \brief Entry point for interrupts
 *
 * @param slot number of occurred interrupt
 */
void
guardian(unsigned short slot)
{
	Gate &gate = plugbox.report(slot);

	pic.ack();
	gate.trigger();
}
