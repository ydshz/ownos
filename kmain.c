#include "stdio.h"
#include "framebuffer.h"

void kmain()
{
  init_terminal();
  //char test[] = "Hello Kernel";
  kwrite("Hello Kernel", 12);
}
