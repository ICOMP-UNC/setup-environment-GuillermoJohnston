#include <stdio.h>
#include <greetings.h>

#include "static.h"
#include "shared.h"

int main(int argc, char* argv[]){
    printf("Hello, OS II. Welcome to 2024 course!\n");
    greetings();
    printf("Calling shared lib form main program. I get '%ld'\n", shared_lib_function("Hello, SO II dynamically"));
    printf("Calling static lib form main program. I get '%ld'\n", static_lib_function("Hello, SO II statically"));
    return 0;
}