#if 1
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//从键盘读取数据，写入管道，读取管道，写到屏幕
int main(int argc, char *argv[]) {
	int fds[2];
	char buf[100] = { 0 };
	size_t len;
	ssize_t r_len;
	

	if (pipe(fds) == -1) {
		perror("make pipe");
		exit(1);
	}

	//read from stdin
	while (fgets(buf, 100, stdin)) {
		len = strlen(buf);
		//write to pipe
		if (write(fds[1], buf, len) != len) {
			perror("write to pipe");
			break;
		}
		memset(buf, 0, 100);

		//read from pipe
		if ((r_len = read(fds[0], buf, (size_t)100)) == -1) {
			perror("read form pipe");
			break;
		}

		//write to stdout
		if (write(1, buf, len) != len) {
			perror("write to stdout");
			break;
		}
	}
		
	return 0;
}
#endif