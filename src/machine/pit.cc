/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                  P I T                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "machine/pit.h"
#include "machine/io_port.h"

void
PIT::interval(unsigned short us)
{
	interv = us;
	int c = interv*1000/838; /* timers have resolutions of 838ns */

	ctrl_port.outb(0 << 0 | /* 16-bit counting */
		       2 << 1 | /* mode 2 */
		       3 << 4 | /* lower order + higher order byte */
		       0 << 6); /* counter 0 */
	data_port.outb((c >> 0) & 0xFF);
	data_port.outb((c >> 8) & 0xFF);
}
