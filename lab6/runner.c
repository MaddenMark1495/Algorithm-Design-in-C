#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"


int main(int argc, char* argv[]) {
   //TODO:
   //check for correct arguments
   //read in the files
   //logically assemble the code to match the output on the homework document
   
   int i=0;
   char citytext [argc-1][10];
   char city[argc-1][10];
   Seat* seat=NULL;
   
   char fName[20];
   char lName[20];
   char origin[20];
   char destination[20];
   int  seatNumber[20];
   
   if(argc<2){
   		printf("Not Enough Inputs");
   		return 0;
   		}
   		
   		for(i=0;i<argc;i++){
   			
   			strcpy(citytext[i],argv[i+1]);
   			//city[i]=strtok(citytext[i],".");
   			
 			//check for land 
 			FILE* file = fopen(citytext[i],"r"); 
 			if(file==NULL)
   			{	
   				return 0;
   			}
 			
 			while(!feof(file)){
   				fscanf(file,"%s %s %s %d",fName,lName,origin,destination,&seatNumber);
   				printf("Made here\n");
   				seat=create_seat(fName,lName,origin,destination,seatNumber);
   				//head= checkin(head,seat);
   		}
   	
	}
}