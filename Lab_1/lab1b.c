#include <stdio.h>
#include <unistd.h>

int main() {
	while(1) {
		char one = '1';
		write(STDOUT_FILENO, &one, 1);
	}
}
