/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                  P I T                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __pit_include__
#define __pit_include__

#include "machine/io_port.h"

/** \brief Programmable Interval Timer driver
 *
 * This driver provides discrete time interval notifications needed to
 * implement clocks and timer.
 **/
class PIT { 
private:
  const IO_Port ctrl_port;
  const IO_Port data_port;

  unsigned short interv;

public:
  /** \brief Default Constructor
   * 
   * Initialising the PIT with a specific configurations containing timer interval and mode of operation.
   *
   * \param us timer intervall in microseconds
   **/
  PIT(unsigned short us) : ctrl_port(0x43), data_port(0x40) {
	  interval(us);
  }
  
  /** \brief get the current timer intervall
   *
   * \return the current timer interval of the PIT.
   */
  unsigned short interval()
  {
  	  return interv;
  }
  
  /** \brief reprogram the PIT with a new timer interval
   *
   * \param us the new timer interval
   */
  void interval(unsigned short us); 
};

#endif
