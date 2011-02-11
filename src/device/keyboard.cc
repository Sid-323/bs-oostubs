/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            K E Y B O A R D                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

/* INCLUDES */
#include "device/keyboard.h"
#include "machine/keyctrl.h"
#include "guard/gate.h"
#include "machine/key.h"
#include "meeting/semaphore.h"

#include "machine/plugbox.h"
#include "machine/pic.h"

extern Plugbox plugbox;
extern PIC pic;

void
Keyboard::plugin()
{
	plugbox.assign(Plugbox::keyboard, *this);
	pic.allow(PIC::keyboard);
}

bool
Keyboard::prologue()
{
	Key key = key_hit();

	if (!key.valid())
		return false;

	if (key.ctrl() && key.alt() &&
	    key.scancode() == Key::scan::del)
		reboot();

	buffer = key;
	return true;
}

void
Keyboard::epilogue()
{
	if (buffer_read) {
		semaphore.signal();
		buffer_read = 0;
	}
}

Key
Keyboard::getkey()
{
	semaphore.wait();

	buffer_read = 1;
	return buffer;
}