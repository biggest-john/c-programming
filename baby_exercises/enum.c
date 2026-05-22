#include <stdlib.h>
#include <stdio.h>

typedef enum{
	COUNT,
	POUND, 
	PINT
}unit_of_measure;

typedef union{
	short count;
	float weight;
	float volume;
}quantity;

typedef struct{
	const char *name;
	const char *country;
	quantity amount;
	unit_of_measure units;
}fruit_order;

void display(fruit_order order){
	puts("This order contains");

	if (order.units == PINT){
		printf("%2.2f pints of %s\n", order.amount.volume, order.name);
	}
	else if(order.units == POUND){
		printf("%2.2f lbs of %s\n", order.amount.weight, order.name);
	}
	else{
		printf("%i %s\n", order.amount.count, order.name );
	}
}

int main () {
	fruit_order apples = {"apples", "England", .amount.count = 144, .units=COUNT};
	fruit_order strawberries = {"strawberries", "Spain", .amount.weight=17.9, .units = POUND};
	fruit_order oj = {"Orange juice", "USA", .amount.volume = 10.5, .units = PINT};

	display(apples);
	display(strawberries);
	display(oj);
}
