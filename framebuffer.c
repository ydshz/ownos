#include "colorvalues.h"

char *fb = (char *) 0x000B8000;

unsigned char terminal_row;
unsigned char terminal_column;
unsigned char terminal_color;

/**
 * Calculates the colorcode based on foreground and background value.
 */
unsigned char calculate_colorcode(unsigned char fg, unsigned char bg)
{
  //return fg | bg <<4;
  return ((fg & 0x0F) << 4) | (bg & 0x0F);
}

/** fb_write_cell:
*  Writes a character with the given foreground and background to position i
*  in the framebuffer.
*
*  @param i  The location in the framebuffer
*  @param c  The character
*  @param fg The foreground color
*  @param bg The background color
*/
void write_char(char c, unsigned char color, unsigned char x, unsigned char y)
{
  const unsigned int index = y * 25 + x;
	fb[index] = c;
  fb[index+1] = color;
}

/**
 * Initializes the terminal
 */
void init_terminal()
{
  terminal_row = 0;
  terminal_column = 0;
  terminal_color = calculate_colorcode(0, 7);
}
