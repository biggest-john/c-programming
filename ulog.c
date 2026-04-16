#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	int opt;
	char *in_file = "defalt_log.txt"; // setting it to a default value incase user does not pass it in.
	char *mode = "w"; //setting to  a default to avoid segmentation fault.
	int verbose = 0;
	
	while((opt = getopt(argc, argv, "f:av")) != -1){
		switch (opt){
		case 'f': 
			in_file = optarg;
			break;

		case 'a':
			mode = "a";
			break;
		case 'v':
			verbose = 1;
			break;
		case '?': 
			printf("this is an invalid argument:  %c\n", optopt);
			break;
		default:
			puts("This programme needs atleast one option to run. please do the needful");
			return 2;
		}
	} 
	// in C, you can not make a variable declaration within the the if-condition.
	FILE *input;
	if ((input = fopen(in_file, mode)) == 0){
		fprintf(stderr, "Error while trying to open the file: %s\n", in_file);
		return 2;
	}
	
	for(int i=optind; i<argc; i++){
		fprintf(input, "%s", argv[i]);	
	}
	fprintf(input, "\n");
	
	if (verbose){
		puts("your log has successfully been enterred into the file.");
	}
	fclose(input);
	return 0;
}
