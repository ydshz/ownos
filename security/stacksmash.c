#include "../panic.h"
#define STACK_CHK_GUARD 0x595e9fbd94fda766

long long __stack_chk_guard = STACK_CHK_GUARD;

void __stack_chk_fail(void)
{
  panic("Stacksmashing detected");
}
