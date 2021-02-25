#include "framebuffer.h"

void kmain()
{
  init_terminal();
  write_char('A', terminal_color, 0, 0);
}
