#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
	char * name;
	int age;
	int height;
} Student;

Student * student_constructor(char * n, int a, int h){

	Student * s = malloc(sizeof(Student));
	
	if(s == NULL){
		return NULL;
	}
	
	s->name = malloc(sizeof(char) * strlen(n)+1);	

	strcpy(s->name, n);

	s->age = a;
	
	s->height = h;

	return s;

}

void student_deconstructor(Student * s){

	free(s->name);
	free(s);
}

Student * student_deep_copy(Student * s)
{
	return student_constructor(s->name,s->age,s->height);


}

Student * student_shallow_copy(Student * s)
{
	return s; 


}

Student * student_assign(Student * s1,Student * s1_shallow)
{
	free(s1->name);
	s1->name = strdup(s1_shallow->name);

	s1->age = s1_shallow->age;

	s1->height = s1_shallow->height;

	return s1;	

}

int main(int argc, char ** argv)
{
	Student * s1 = student_constructor("Patty",20,60);

	Student * s1_shallow = student_shallow_copy(s1);

	Student * s1_deep = student_deep_copy(s1);


	s1->age = 30;

	printf("s1_shallow's age is %d\n",s1_shallow->age);
	printf("s1_deep's age is %d\n",s1_deep->age);

	


	return EXIT_SUCCESS;
}
