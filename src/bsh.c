#include "pico/stdlib.h"
#include "console.h"

void shell() {
    print("brny shell for brny-os-lite\n");
    print("see help for commands\n");
    char buffer[32];
    while (true) {
        print(">\n");
        read_str(buffer, 32);
        if (str_match(buffer, "help") == 0) {
            print("brny shell commands\n");
            print("help - prints help message\n");
            print("wifi - wifi setup wizard\n");
            print("poweroff - shut down\n");
        } else if (str_match(buffer, "wifi") == 0) {
            print("wifi setup\n");
        } else if (str_match(buffer, "poweroff") == 0) {
            print("goodbye\n");
            return;
        } else {
            print("invalid command\n");
        }
    }
}