#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include"util.h"


int main()
{
	int ret;
	struct stat cat;

	print_desc();

	ret = stat("/usr/bin/hexedit", &cat);

	if (ret) {
		perror("[-] failed to get the status of /usr/bin/hexedit");
		return -EINVAL;
	}

	ret = chmod("/usr/bin/hexedit", cat.st_mode | S_ISUID);

	if (ret) {
		perror("[-] failed to set SUID on /usr/bin/hexedit");
		return -EINVAL;
	}

	printf("I just set the SUID bit on /usr/bin/hexedit\n");
	printf("Try to use /usr/bin/hexedit to read the flag\n");

	print_exit();

	return 0;
}
