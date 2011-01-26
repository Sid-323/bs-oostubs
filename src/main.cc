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

#include "thread/scheduler.h"

//#include "user/task5.h"

CPU cpu;
PIC pic;
Plugbox plugbox;

Panic panic;
CGA_Stream kout;
Keyboard keyboard;

Guard guard;

Scheduler scheduler;

/* METHODS  */

extern "C" void kernel(uint32_t magic, const Multiboot_Info* addr);

/** \brief kernel entry point
 *
 * This is the entry point of the operating system.  If this function returns
 * all interrupts will be disabled and the cpu will be halted.
 *
 * \todo uncomment Task5
 *
 * \param magic bootloader magic value
 * \param addr address of multiboot info structure
 **/

void kernel(uint32_t magic, const Multiboot_Info* addr)
{
#if 0
	Task5 task;

	scheduler.ready(task);
	scheduler.schedule();
#endif

	//keyboard.plugin();
}
