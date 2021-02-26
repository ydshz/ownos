#include "framebuffer.h"
/**
 * This  function provides functionality to write to the framebuffer
 *
 * @param buffer The buffer to print
 * @param buffer_len The lengthof the buffer
 */
void kwrite(char buffer[], int buffer_len)
{
  for(int i=0; i<buffer_len; i++){
    write_char(buffer[i], terminal_color, terminal_row, terminal_column);
    terminal_row+=1;
  }
}
