#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include"util.h"

void print_desc()
{
	printf("###\n");
	printf("### If you feel hard to beat this pokemon, please read and study the description.\n");
	printf("### Or just skip and try other pokemons.\n");
	printf("### Have fun :)\n");
	printf("###\n");
}

int main()
{
	int ret;
	struct stat cat;

	print_desc();

	ret = stat("/usr/bin/ruby", &cat);

	if (ret) {
		perror("[-] failed to get the status of /usr/bin/ruby");
		return -EINVAL;
	}

	ret = chmod("/usr/bin/ruby", cat.st_mode | S_ISUID);

	if (ret) {
		perror("[-] failed to set SUID on /usr/bin/ruby");
		return -EINVAL;
	}

	printf("I just set the SUID bit on /usr/bin/ruby\n");
	printf("Try to learn programming in ruby and read the flag\n");

	return 0;
}
