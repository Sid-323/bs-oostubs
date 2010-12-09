/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                 P A N I C                                 *
 *                                                                           *
 *---------------------------------------------------------------------------*/

/* INCLUDES */
#include "device/panic.h"

#include "machine/cpu.h"
#include "device/cgastr.h"

extern CPU cpu;
extern CGA_Stream kout;

bool
Panic::prologue()
{
        //kout << "Error: Unhandled interrupt" << endl;
        cpu.halt();

        return false;
}

void
Panic::epilogue()
{
	/* never reached */
}
