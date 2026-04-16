#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	float latitude;
	float longitude;
	char info[80];
	int started = 0;
	
	puts("data = \n[");
	while(scanf("%f, %f, %79[^\n]", &latitude, &longitude, info) == 3){
		if(started){
			puts(",");
		}
		else{
			started = 1;
		}
		if(latitude>90.0 || latitude < -90){
			fprintf(stderr, "invalid latitude !\nlatitude must be between -90.0 and 90.0\n");
			return 2; //this mean the code in main encountered an error.
		}
		if(longitude > 180.0 || longitude < -180.0){
			fprintf(stderr,"invalid longitude!\nlongitude must be between -180.0 and 180.0\n");
			return 2; 
		}
		printf("{latitude: %f, longitude: %f, info: '%s'}\n", latitude, longitude, info);
	}
	puts("\n]");

	return 0;
}

