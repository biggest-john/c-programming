#include <stdio.h>
#include <stdlib.h>


int y = 75;
void go_south_east(int *lon, int *lat){
	*lon = *lon + 1;
	*lat = *lat - 1;
}

int main(){
	int longitude = 34;
	int latitude = -64;

	go_south_east(&longitude,&latitude);
	printf("the ship is now at [%i, %i]", longitude, latitude);
}

