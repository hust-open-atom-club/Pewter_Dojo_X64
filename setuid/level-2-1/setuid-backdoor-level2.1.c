#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include"util.h"


int main()
{
	int ret;
	struct stat cat;

	print_desc();

	ret = stat("/usr/bin/gzip", &cat);

	if (ret) {
		perror("[-] failed to get the status of /usr/bin/gzip");
		return -EINVAL;
	}

	ret = chmod("/usr/bin/gzip", cat.st_mode | S_ISUID);

	if (ret) {
		perror("[-] failed to set SUID on /usr/bin/gzip");
		return -EINVAL;
	}

	printf("I just set the SUID bit on /usr/bin/gzip\n");
	printf("Try to understand /usr/bin/gzip and elaborately obtain the flag\n");

	print_exit();

	return 0;
}
