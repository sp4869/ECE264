#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	int roomNumber;
	int roomCapacity;

}Room;

Room * roomAssign(Room * r1, Room * r2){
	r1->roomNumber = r2->roomNumber;
	r1->roomCapacity = r2->roomCapacity;

	return r1;
}

typedef struct{
	
	char * buildingName;
	int numRooms;
	Room * buildingRooms;

}Building;

Building * building_constructor(char * n, int nR, Room * bR)
{
	Building * b1 = malloc(sizeof(Building));
	b1->buildingName = malloc(sizeof(char)*(strlen(n)+1));
	strcpy(b1->buildingName,n);

	b1->numRooms = nR;
	int i;
	b1->buildingRooms = malloc(sizeof(Room)*(b1->numRooms));

	

	for(i=0; i<b1->numRooms; i++)
	{	
		roomAssign(b1->buildingRooms+i,bR+i); 		

	}
	return b1;

}

void building_deconstructor(Building * b1)
{
	free(b1->buildingRooms);
	free(b1->buildingName);
	free(b1);


}

void printBuilding(Building * b1)
{
	printf("The building name is %s\n",b1->buildingName);

	printf("There are %d rooms in the building\n", b1->numRooms);

	printf("Here is a description of the rooms:\n");

	int i;
	for(i=0; i<b1->numRooms; i++){
		printf("Room %d can hold %d students\n",b1->buildingRooms[i].roomNumber,b1->buildingRooms[i].roomCapacity);
	}

}


int main(int argc, char ** argv)
{
	
	
	Room arrRoom[3];
	arrRoom[0].roomNumber = 101;
	arrRoom[0].roomCapacity = 50;
	arrRoom[1].roomNumber = 102;
	arrRoom[1].roomCapacity = 200;
	arrRoom[2].roomNumber = 103;
	arrRoom[2].roomCapacity = 20;

	Building * b1 = building_constructor("MSEE",3,arrRoom);

	printBuilding(b1);

	building_deconstructor(b1);
	return EXIT_SUCCESS;
}


