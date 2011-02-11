/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            K E Y B O A R D                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "machine/keyctrl.h"
#include "guard/gate.h"
#include "machine/key.h"
#include "meeting/semaphore.h"

/** \brief %Keyboard driver with interrupt support
 *
 * This class is a subclass of Gate and implements the interrupt routine used
 * for the keyboard. It also contains a semaphore based one elementary key
 * buffer to store pressed keys.
 **/
class Keyboard : public Keyboard_Controller, public Gate  {
private:
	Semaphore semaphore;

	/** \brief storage for fetched keys
	 *
	 **/
	Key buffer;
	int buffer_read;

public:
  Keyboard() : semaphore(0), buffer_read(1) {}

  /** \brief enable the interrupt mechanism of the keyboard
   *
   * Method plugin() enables all keyboard interrupts. After calling plugin()
   * interrupts activated by the keyboard are recognised.
   **/
  void plugin();

  /** \brief fetch the key from the controller
   *
   * \return true if epilogue must be executed afterwards, false otherwise
   **/
  virtual bool prologue();

   /** \brief print the fetched key to the screen
    *
    **/
  virtual void epilogue();

  /** \brief get the next Key or block current Thread
   *
   **/
  Key getkey();
};

#endif
