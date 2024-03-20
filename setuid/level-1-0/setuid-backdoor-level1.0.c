#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include"util.h"


int main()
{
	FILE *fp;
	ssize_t ret;
	size_t count;
	char *flag = NULL;

	print_desc();

	fp = fopen("/flag", "r");

	if (!fp) {
		perror("[-] fopen failed");
		return -EINVAL;
	}

	ret = getline(&flag, &count, fp);
	if (ret < 0) {
		perror("[-] fgets failed");
		fclose(fp);
		return -EINVAL;
	}
	
	printf("%s", flag);

	free(flag);
	flag = NULL;
	fclose(fp);

	print_exit();

	return 0;
}
