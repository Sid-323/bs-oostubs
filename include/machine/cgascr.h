/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                             C G A _ S C R E E N                           *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __screen_include__
#define __screen_include__

#include <stdint.h>

#include "machine/io_port.h"

/** \brief CGA-Dispaly driver
 *
 * CGA_Screen enables the basic control of the screen of a computer by accessing
 * the screen memory and I/O ports directly.
 */
class CGA_Screen {
private:
	static IO_Port index_port, data_port;
	static const unsigned char high_index = 14, low_index = 15;

public:
	static const unsigned short width = 80, height = 25;

	static uint16_t *sptr; /* lower order byte is first on 386 */

	static const unsigned char STD_ATTR = 15; /* white on black */
	static const unsigned char ANNOY_ATTR = 11 | 5 << 4 | 1 << 7; /* cyan on magenta, blinking ;-) */

  /** \brief Constructor
   *
   **/
  /* CGA_Screen(); */

  /** \brief Destructor
   *
   **/
  /* ~CGA_Screen(); */

  /** \brief set the cursor position
   *
   * \param x column number of new position 
   * \param y row number of new position
   */
  void setpos(unsigned short x, unsigned short y);

  /** \brief get the cursor position
   *
   * \param x reference for column number of current position
   * \param y reference for row number of curent position
   */
  void getpos(unsigned short& x, unsigned short& y) /* const */;

  /** \brief print a character to a specific position
   *
   * \param x column number of display position
   * \param y row number of display position
   * \param c character to be displayed
   * \param attrib display attributs
   */
  void show(unsigned short x, unsigned short y, char c, unsigned char attrib);

  /** \brief print a string to the current position
   * 
   * \param string string of characters to be displayed
   * \param n number auf characters in string
   * \param attrib display attributs
   */
  void print(const char* string, unsigned int n, unsigned char attrib);

  /** \brief scroll the display one line upwards
   *
   * The new row at the bottom of the screen is filled with spaces.
   **/
  void scrollup();

  /** \brief clear the screen
   *
   **/
  void clear();
};

		/* MACROS */

#define GETOFFSET(X, Y)	((Y)*width + (X))
#define GETX(O)		((O) % width)
#define GETY(O)		((O) / width)

#endif
