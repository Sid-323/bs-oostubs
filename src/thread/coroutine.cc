/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                          C O R O U T I N E                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "thread/coroutine.h"

/* to be compatible with C the signature of the kickoff function need to be changed to do this, one can cast the kickoff function using the fallowing line:
 * void(*kickoffC)(void*) = reinterpret_cast<void(*)(void*)>(&kickoff);
 *
 * kickoffC can then be passed to toc_settle
 */

Coroutine::Coroutine(void* tos){

}
