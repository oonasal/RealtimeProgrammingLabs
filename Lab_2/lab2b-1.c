#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int fellow_desc;
    char chr_fellow;
    int result;

    fellow_desc = OpenChatFellow();

    while(1) {

        /*read input from the chat fellow file*/
        result = read(fellow_desc, &chr_fellow, 1);
        if(result == 1) {
            write(STDOUT_FILENO, &chr_fellow, 1);
        }

        /*check for termination*/
        if(chr_fellow == 'Q') {
            break;
        }
    }
    close(fellow_desc);
    return 0;
}
