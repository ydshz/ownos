#include "../panic.h"

unsigned int __stack_chk_guard = 0x00000aff;

void __stack_chk_fail(void)
{
  panic("Stacksmashing detected");
}
