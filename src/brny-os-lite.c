#include "console.h"
#include "pico/stdlib.h"
#include "init.h"
#include "os_utils.h"


int main()
{
    stdio_init_all();
    sleep_ms(5000);
    print("brnyos kernel v0.1\n");
    print("starting init\n");
    init();
    print("init process died, powering off\n");
    poweroff();
}
