#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

//Parameters:
//fName : The first name of a passenger
//lName : The last name of a passengerw
//origin: A passengers origin
//dest  : A passengers destination
//
//Return: A seat struct populated with the specified information
//
//Each of the strings malloced inside of the struct should be the exact size
//of the string that it holds. So, if a passengers first name is Seth then 
//seat->fName should point to exactly 5 characters; one for each letter in
//the name plus the null terminater. 
//
Seat* create_seat(char* fName, char* lName, char* origin, char* dest, int num) {

//	printf("error check1\n");
	Seat* newseat=malloc(sizeof(Seat));
//	printf("error check2\n");
	newseat->fName=(char*)malloc((strlen(fName)+1));
//	printf("error check3\n");
	newseat->lName=(char*)malloc((strlen(lName)+1));
//	printf("error check4\n");
	newseat->origin=(char*)malloc((strlen(origin)+1));
//	printf("error check5\n");
	newseat->destination=(char*)malloc((strlen(dest)+1));
//	printf("error check6\n");
//	printf("error check7\n");
	strcpy(newseat->fName,fName);
//	printf("error check8\n");
	strcpy(newseat->lName,lName);
//	printf("error check9\n");
	strcpy(newseat->origin,origin);
//	printf("error check10\n");
	strcpy(newseat->destination,dest);
//	printf("error check11\n");
	newseat->seatNumber=num;
	
	printf("%s %s got in the plane at %s\n",newseat->fName,newseat->lName,newseat->origin);
	
	
	return newseat;
	


}

//Parameters:
//seat : A double pointer to a seat struct
//
//Return : Nothing
//
//This function should properly free all the memory inside of a seat and
//set the seat equal to NULL so it may not be referenced by other 
//functions
void  empty_seat(Seat** seat) {

  	printf("%s %s got off the plane at %s\n",(*seat)->fName,(*seat)->lName,(*seat)->destination);
  	free((*seat)->fName);
  	free((*seat)->lName);
  	free((*seat)->origin);
  	free((*seat)->destination);
  	free(*seat);

	seat = NULL; //maybe

}

//Parameters: 
//plane : the head of a linked list
//seat  : a pointer to a seat
//
//Return: The possibly updated head of the linked list
//
//This function should insert the seat into the plane list in sorted order
//by seat number recursively 
Seat* check_in(Seat* plane, Seat* seat) {

	if(plane==NULL)
	{

		return seat;
	}
	if(plane->seatNumber>seat->seatNumber){
		
		seat->next=plane;
		return seat;
		}
		plane->next=check_in(plane->next,seat);
		return plane;

}


//Parameters:
//plane : the head of a linked list
//location: the current location of the plane
//
//Return : The possibly updated head of the plane list
//
//This method should recursively remove each seat from the plane
//that has the current location as its destination and pass it to 1
//empty seat
Seat* land(Seat* plane, char* location) {

	if(plane==NULL){
		return NULL;
	
	}
	if(strcmp(plane->destination,location)==0){
			Seat* next=plane->next;
			empty_seat(&plane);
			return land(next,location);
			
			}
		plane->next=land(plane->next,location);
		return plane;
		}
		
	
		
	
	
	
	


