#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    char chr_user;
    int result;

    while(1) {

        /*read input from the keyboard*/
        result = read(STDIN_FILENO, &chr_user, 1);
        if(result == 1) {
            write(STDOUT_FILENO, &chr_user, 1);
        }

        /*check for termination*/
        if(chr_user == 'Q') {
            break;
        }
    }
    return 0;
}
