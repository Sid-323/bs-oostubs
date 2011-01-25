/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              M A I N                                      *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "machine/multiboot.h"

#include "machine/cpu.h"
#include "machine/plugbox.h"
#include "machine/pic.h"

#include "device/panic.h"
#include "device/cgastr.h"
#include "device/keyboard.h"

#include "guard/guard.h"

//#include "user/task4.h"

CPU cpu;
PIC pic;
Plugbox plugbox;

Panic panic;
CGA_Stream kout;
Keyboard keyboard;

Guard guard;

/* METHODS  */

extern "C" void kernel(uint32_t magic, const Multiboot_Info* addr);

/** \brief kernel entry point
 *
 * This is the entry point of the operating system.  If this function returns
 * all interrupts will be disabled and the cpu will be halted.
 *
 * \todo uncomment Task4
 *
 * \param magic bootloader magic value
 * \param addr address of multiboot info structure
 **/

}
//Task4 task;
//scheduler.ready(task);
//scheduler.schedule();

	//Task3 task;
	keyboard.plugin();
	//task.action();
}
