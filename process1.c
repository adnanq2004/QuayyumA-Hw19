#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define READ 0
#define WRITE 1

int main() {

  mkfifo("parent_pipe", 0666);
  mkfifo("child_pipe", 0666);
	char line[100];

	while (1) {
    int file = open("parent_pipe", O_WRONLY);
    int file2 = open("child_pipe", O_RDONLY);
    printf("please give a string: ");
    fgets(line, sizeof(line), stdin);
    write(file, line, sizeof(line));
    read(file2, line, sizeof(line));
    printf("this is the altered string: %s\n", line);
	}

  return 0;
}
