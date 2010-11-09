/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                             C G A _ S C R E E N                           *
 *                                                                           *
 *---------------------------------------------------------------------------*/
#include <stdint.h>

#include "machine/cgascr.h"
#include "machine/io_port.h"

uint16_t *CGA_Screen::sptr = (uint16_t *)0xB8000;

IO_Port CGA_Screen::index_port(0x3D4);
IO_Port CGA_Screen::data_port(0x3D5);

void
CGA_Screen::setpos(unsigned short x, unsigned short y)
{
	uint16_t offset = GETOFFSET(x, y);

	index_port.outb(high_index);
	data_port.outb(offset >> 8);
	index_port.outb(low_index);
	data_port.outb(offset);
}

void
CGA_Screen::getpos(unsigned short &x, unsigned short &y)
{
	uint16_t offset;

	index_port.outb(high_index);
	offset = (uint16_t)(unsigned char)data_port.inb() << 8;
	index_port.outb(low_index);
	offset |= (unsigned char)data_port.inb();

	x = GETX(offset);
	y = GETY(offset);
}

void
CGA_Screen::show(unsigned short x, unsigned short y, char character, unsigned char attrib)
{
	sptr[GETOFFSET(x, y)] = (uint16_t)character | (uint16_t)attrib << 8;
}

	/* very simple, thus CGA_Stream::flush has to do all the work */
void
CGA_Screen::print(const char *string, unsigned int n, unsigned char attrib)
{
	uint16_t att = (uint16_t)attrib << 8;
	unsigned short x, y;

	getpos(x, y);

	for (uint16_t *p = sptr + GETOFFSET(x, y); n; n--, string++, p++)
		*p = (uint16_t)*string | att;
}

void
CGA_Screen::scrollup(void)
{
	uint16_t *p = sptr;

	for (int i = (height-1)*width; i; i--, p++)
		*p = p[width];
	/* p at beginning of last line */

	for (int i = width; i; i--)
		*p++ = (uint16_t)' ' | (uint16_t)STD_ATTR << 8;
}

void
CGA_Screen::clear(void)
{
	uint16_t *p = sptr;

	for (int i = height*width; i; i--)
		*p++ = (uint16_t)' ' | (uint16_t)STD_ATTR << 8;
}
