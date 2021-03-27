#include "stdio.h"
#include "framebuffer.h"
#include "security/stacksmash.h"
void kmain()
{
    init_terminal();
    kprintln("Hello Kernel");
}
