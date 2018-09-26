#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main(){

	int fd[2];
	char string[] = "Hello, world!\n";
	char buffer[100];

	pipe(fd);

  write(fd[1], string, (strlen(string) + 1));
	close(fd[1]);
	read(fd[0], buffer, sizeof(buffer));
	close(fd[0]);
	printf("Received string: %s", buffer);


	return 0;
}
