#include <stdio.h>
#include <string.h>


void findTrack(char *trackArr[], char target[]){
	for(int i=0;i<5;i++){
		if (strstr(trackArr[i], target)){
			printf("Track %i: %s \n", i, trackArr[i]);
			return;
		}
	}
	puts("Could not find the track.");
	return;
}

int main(){

	char *tracks[] = {
		"I left my heart in Harvard Med School",
		"Newark, Newark - a wonderful town",
		"Dancing with a Dork",
		"From here to maternity",
		"The girl from Iwo Jima",
	};
	char targetTrack[80];
	puts("Please input a keyword from the track you would love to target!");
	//scanf("%s\n", targetTrack);
	fgets(targetTrack, 80, stdin);
	targetTrack[strcspn(targetTrack, "\n")] ='\0';  
	findTrack(tracks, targetTrack);

	return 0;
}
