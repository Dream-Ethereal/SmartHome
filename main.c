#include <stdio.h>
#include "server.h"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s port \n", argv[0]);
		return 1;
	}
	//
	server_init(argv[1]);
	server_run();
	return 0;
}






