#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

    int fellow_desc;
    char chr_fellow;
    char chr_user;
    int result, result2;

    fellow_desc = OpenChatFellow();

    int file_flags;
	file_flags = fcntl(fellow_desc, F_GETFL);
	file_flags = file_flags | O_NONBLOCK;
	fcntl(fellow_desc, F_SETFL, file_flags);

    int file_flags2;
	file_flags2 = fcntl(STDOUT_FILENO, F_GETFL);
	file_flags2 = file_flags2 | O_NONBLOCK;
	fcntl(STDOUT_FILENO, F_SETFL, file_flags2);

    int file_flags3;
	file_flags3 = fcntl(STDIN_FILENO, F_GETFL);
	file_flags3 = file_flags3 | O_NONBLOCK;
	fcntl(STDIN_FILENO, F_SETFL, file_flags3);

    while(1) {

        /*read input from the chat fellow file*/
        result = read(fellow_desc, &chr_fellow, 1);
        if(result == 1) {
            write(STDOUT_FILENO, &chr_fellow, 1);
        }

        /*read input from the keyboard*/
        result2 = read(STDIN_FILENO, &chr_user, 1);
        if(result2 == 1) {
            write(STDOUT_FILENO, &chr_user, 1);
        }

        /*check for termination*/
        if(chr_fellow == 'Q' || chr_user == 'Q') {
            break;
        }
    }
    close(fellow_desc);
    return 0;
}
