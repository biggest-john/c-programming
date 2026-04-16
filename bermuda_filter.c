#include <stdlib.h>
#include <stdio.h>

int main (){
	float latitude;
	float longitude;
	char info[80];

	while(scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3){
		if (longitude > 26 && longitude< 34){
			if (latitude> -64 && latitude < -76){
				printf("%f, %f, %s\n", latitude, longitude, info);
			}
		}
	}
	return 0;
}
