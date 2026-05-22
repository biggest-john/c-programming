#include <stdio.h>
#include <stdlib.h>

/*typedef struct parent{
	const char *name;
	const char *state_of_origin;
	const char *phone_number;
} parent;

typedef struct student {
	const char *name;
	const char *dept;
	int age;
	struct parent stud_parent;
} student;



void student_det(student person){
	printf(
			"Name: %s;\nDepartment: %s;\nAge: %i;\nFather_Name: %s;\nState_of_origin: %s;\nPhone_number: %s;\n",
			person.name, person.dept, person.age, person.stud_parent.name, person.stud_parent.state_of_origin,  person.stud_parent.phone_number
			);
}

int main (){
	student john = {"John Martins", "Computer Science", 19, {"Martins Asuku", "Kogi", "08158194186"}};

	student_det(john);

	return 0;
}*/

typedef struct{
	const char *name;
	const char *specie;
	int age;
} turtle;

void happy_birthday(turtle *t){
	t->age++;
	printf("Happy birthday %s, you are now %i years old.\n",
			t->name, t->age);
}

int main(){
	turtle myrtle = {"myrtle", "leather back", 69};
	happy_birthday(&myrtle);
	printf("%s's age is now %i\n", myrtle.name, myrtle.age);

	return 0;
}
