/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                         C G A _ S T R E A M                               *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "device/cgastr.h"

		/* this would be easier if CGA_Screen::print would be more powerful */
void
CGA_Stream::flush()
{
	unsigned short	x, y;
	char		*s = buffer;

	getpos(x, y);
	int offset = GETOFFSET(x, y);
	uint16_t *p = sptr + offset;

	for (int n = pBuffer - buffer; n; n--, s++) {
		switch (*s) {
		case '\n':
			offset = GETOFFSET(0, GETY(offset)+1);
			p = sptr + offset;
			break;

		default:
			*p++ = (uint16_t)*s | (uint16_t)STD_ATTR << 8;
			offset++;
			break;
		}

		if (offset > GETOFFSET(width-1, height-1)) {
			scrollup();
			offset -= width;
			p -= width;
		}
	}

	pBuffer = buffer;
	setpos(GETX(offset), GETY(offset));
}
