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

/***AUFGABE 3***/
#include "device/cgastr.h"
extern CGA_Stream kout;

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
	/***AUFGABE 3***/
	char buf[2] = {buffer.ascii(), 0};

	kout.setpos(0, 6);
	kout << "Keyboard test: " << buf << endl;
}