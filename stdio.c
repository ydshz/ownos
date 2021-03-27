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
        if(buffer[i] == '\n'){
            terminal_row++;
            terminal_column = 0;
        }
        else{
            write_char(buffer[i], terminal_color, terminal_column, terminal_row);
            terminal_column++;
        }
    }
}
void kprintln(char buffer[])
{
  int size = 0;
  while(buffer[size] != '\0'){
    size++;
  }
  kwrite(buffer, size);
  kwrite("\n", 1);
}
