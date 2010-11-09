/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            O _ S T R E A M                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "object/strbuf.h"
#include "object/o_stream.h"

O_Stream&
O_Stream::operator << (const char *value)
{
	for (; *value; value++)
		put(*value); /* may be done with the char version if char should be an ASCII char */
	return *this;
}

O_Stream&
O_Stream::operator << (char *value)
{
	return *this << (const char *)value;
}

O_Stream&
O_Stream::operator << (unsigned long value)
{
	/* NOTE: had to add -fno-stack-protector */

	char buf[32+1]; /* long should be 32-bit, binary is largest */
	char *p = buf + sizeof(buf) - 1;

	*p = '\0';
	do {
		*--p = '0' + value % base;
		if (*p > '9') /* hexadecimal fix */
			*p += 'A'-'9'-1;
	} while (value /= base);

	return *this << p;
}

O_Stream&
O_Stream::operator << (long value)
{
	if (value < 0) {
		*this << "-"; /* may be done with a char if char should be an ASCII */
		value *= -1;
	}

	return *this << (unsigned long)value;
}

O_Stream&
O_Stream::operator << (int value)
{
	return *this << (long)value;
}

O_Stream&
O_Stream::operator << (unsigned int value)
{
	return *this << (unsigned long)value;
}

O_Stream&
O_Stream::operator << (short value)
{
	return *this << (long)value;
}

O_Stream&
O_Stream::operator << (unsigned short value)
{
	return *this << (unsigned long)value;
}

		/* supposing that a char shall be interpreted as a number */

O_Stream&
O_Stream::operator << (char value)
{
	return *this << (long)value;
}

O_Stream&
O_Stream::operator << (unsigned char value)
{
	return *this << (unsigned long)value;
}

		/* supposing that the pointer shall be interpreted as a number */

O_Stream&
O_Stream::operator << (void *value)
{
	enum Base old = base;
	*this << "0x" << hex << (unsigned long)value;
	base = old;
	return *this;
}

O_Stream&
O_Stream::operator << (O_Stream& (*f) (O_Stream&))
{
	return f(*this);
}

		/* MANIPULATORS */

O_Stream&
endl(O_Stream &os)
{
	os << "\n"; /* may be done with char, etc. */
	os.flush();

	return os;
}

O_Stream&
bin(O_Stream &os)
{
	os.base = O_Stream::bin;
	return os;
}
 
O_Stream&
oct(O_Stream &os)
{
	os.base = O_Stream::oct;
	return os;
}

O_Stream&
dec(O_Stream &os)
{
	os.base = O_Stream::dec;
	return os;
}
 
O_Stream&
hex(O_Stream &os)
{
	os.base = O_Stream::hex;
	return os;
}

