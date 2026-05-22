#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]){
	char *delivery = "";
	int thick = 0; /* to eval to bool type if should be thick or not*/
	int count = 0;
	char ch;

	while ((ch = getopt(argc, argv, "d:t")) != EOF){
		switch(ch){
			case 'd':
				delivery = optarg;
				break;
			case 't':
				thick = 1;
				break;
			default:
				fprintf(stderr, "Unknown option: '%s'\n ", optarg);

				return 1;
		}
	}
	argc -= optind;
	argv += optind;

	printf("argc: %i, argv pointing %s\n", argc, argv[0]);

	if (thick){
		puts("Thick crust.");
	}

	if (delivery[0])  /*note we did not just use delivery as delivery is pointing to an empty string which is true, but is there something in it? that's why we had to use delivery[0]*/{
		printf("To be delivered: %s\n", delivery);
	}
	puts("ingredients:");

	for(count=0; count<argc;count++){
		puts(argv[count]);
	}
	return 0;
}
