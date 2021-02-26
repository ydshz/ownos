#include "stdio.h"
#include "framebuffer.h"

void kmain()
{
  init_terminal();
  char test[] = "ti";
  kwrite(test, 2);
}
