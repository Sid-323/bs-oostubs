/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                  P I C                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "machine/pic.h"
#include "machine/io_port.h"

PIC::PIC() : ctrl_1(0x20) /* master/service */,
	     ctrl_2(0xa0) /* slave/service */,
	     mask_1(0x21) /* master/IMR */,
	     mask_2(0xa1) /* slave/IMR */,
	     master_mask(0xFB), slave_mask(0xFF)
{
	ctrl_1.outb(0x11);
	ctrl_2.outb(0x11);

	mask_1.outb(32);
	mask_2.outb(40);

	mask_1.outb(4);
	mask_2.outb(2);

	mask_1.outb(3);
	mask_2.outb(3);

	mask_1.outb(0xFB);
	mask_2.outb(0xFF);
}

void
PIC::forbid(Interrupts interrupt_device)
{
	if (interrupt_device < 8) {
		master_mask |= 1 << interrupt_device;
		mask_1.outb(master_mask);
	} else {
		slave_mask |= 1 << (interrupt_device - 8);
		mask_2.outb(slave_mask);
	}
}

void
PIC::allow(Interrupts interrupt_device)
{
	if (interrupt_device < 8) {
		master_mask &= ~(1 << interrupt_device);
		mask_1.outb(master_mask);
	} else {
		slave_mask &= ~(1 << (interrupt_device - 8));
		mask_2.outb(slave_mask);
	}
}

void
PIC::ack(void)
{
	ctrl_1.outb(0x20 /* OCW2 */);
	ctrl_2.outb(0x20 /* OCW2 */);
}
