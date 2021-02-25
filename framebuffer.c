#include "colorvalues.h"
#include "io.h"

/* IO-Port Macros */
#define CURSOR_COMMAND_PORT 0x3D4
#define CURSOR_DATA_PORT 0x3D5

/*IO-Command Macros*/
#define CURSOR_HIGH_BYTE_COMMAND 14
#define CURSOR_LOW_BYTE_COMMAND 15

char *fb = (char *) 0x000B8000;

unsigned char terminal_row;
unsigned char terminal_column;
unsigned char terminal_color;


/** fb_move_cursor:
*  Moves the cursor of the framebuffer to the given position
*
*  @param pos The new position of the cursor
*/
void move_cursor(unsigned short pos)
{
    outb(CURSOR_COMMAND_PORT, CURSOR_HIGH_BYTE_COMMAND);
    outb(CURSOR_DATA_PORT,    ((pos >> 8) & 0x00FF));
    outb(CURSOR_COMMAND_PORT, CURSOR_LOW_BYTE_COMMAND);
    outb(CURSOR_DATA_PORT,    pos & 0x00FF);
}

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
  move_cursor((unsigned short) index);
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

