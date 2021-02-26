#include "stdio.h"
#include "framebuffer.h"

void kmain()
{
  init_terminal();
  kwrite("Hello Kernel\n", 13);
}
