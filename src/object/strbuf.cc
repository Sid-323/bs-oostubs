/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                       S T R I N G B U F F E R                             *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "object/strbuf.h"

Stringbuffer::Stringbuffer() : pBuffer(buffer)
{
	*buffer = '\0';
}

void
Stringbuffer::put(char c)
{
	*pBuffer++ = c;

	if (pBuffer == buffer + sizeof(buffer))
		flush(); /* flush resets pBuffer */
}

