#include "framebuffer.h"
#include "stdio.h"

void panic(char buffer[])
{
  init_terminal();
  kprintln("Kernel Panic!");
  kprintln(buffer);
  for(;;){
    ;
  }
}
