#include "encrypt.h"
#include <stdio.h>
void encrypt(char message[]){
	int i = 0;
	while(message[i]){
		message[i] = message[i] ^ 31;
		i++;
	}
}
