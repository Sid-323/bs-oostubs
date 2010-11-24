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

#include "machine/plugbox.h"
#include "machine/pic.h"

extern Plugbox plugbox;
extern PIC pic;

/***AUFGABE 2***/
#include "device/cgastr.h"
extern CGA_Stream kout;

void
Keyboard::plugin()
{
	plugbox.assign(Plugbox::keyboard, *this);
	pic.allow(PIC::keyboard);
}

void
Keyboard::trigger()
{
	Key key = key_hit();

	if (key.valid()) {
		if (key.ctrl() && key.alt() &&
		    key.scancode() == Key::scan::del)
			reboot();

		/***AUFGABE 2***/
		char buf[2] = {key.ascii(), 0};

		kout.setpos(0, 6);
		kout << "Keyboard test: " << buf << endl;
	}
}