#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main() {
	pid_t ret = fork();
	if (ret > 0) { //子进程

	}
	else if (ret == 0) {
		printf("hello...1");
		pid_t ret2 = fork();
		if (ret2 == 0) {
			//父进程
			printf("hello...2");
		}
		else if(ret2 > 0) {
			//子进程
		}
		else {
			perror("fork");
		}
	}
	else {
		perror("fork");
		return -1;
	}
	
#if 0
	char buf[128] = { 0 };

	scanf("%s", buf);
	printf("%s\n", buf);
	pid_t ret = fork();
	//pid_t ret = 20;
	if (ret < 0) {
		perror("fork:");
		return -1;
	}
	else if(ret == 0){
		int i = 0;
		for (; i < 10; i++) {
			printf("hello,Parent\n");
		}
	}
	else {
		int i = 0;
		for (; i < 10; i++) {
			printf("hello,Child\n");
		}
	}

	int arr[] = { 1,2,3,4,5,5,3,2,1 };
	int ret = 0;
	int i = 0;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		ret ^= arr[i];
	}
	printf("ret = %d\n", ret);

#endif
	return 0;
}