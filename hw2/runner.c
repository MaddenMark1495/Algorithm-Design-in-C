#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"


int main(int argc, char* argv[]) {
   //TODO:
   //check for correct arguments
   //read in the filesw
   //logically assemble the code to match the output on the homework documentq
   
   int i=0;
   Seat* seat=NULL;
   Seat* plane=NULL;
   char token[100];
   char* fName;
   char* lName;
   char* destination;
   int Number=0;
   char* chnum;
   
   
   if(argc<2){
   		printf("Not Enough Inputs");
   		return 0;
   		}
   //		printf("error check");
   		for(i=1;i<argc;i++){
   			
 			//check for land 
 			FILE* file = fopen(argv[i],"r"); 
 			if(file==NULL)
   			{	
   				return 0;
   			}
 			argv[i][strlen(argv[i])-4]= '\0';
 			plane = land(plane, argv[i]);
 			while(fgets(token,100,file)!=NULL){ //loading file
				if(argv==NULL){
					return 0;
				}
 				fName=strtok(token," ");
 				lName=strtok(NULL," ");
 				destination=strtok(NULL," ");
 				chnum=strtok(NULL," \0");
 			//	printf("%s",fName);
			//	printf("%s",chnum);
				
   		
   				seat=create_seat(fName,lName,argv[i],destination,atoi(chnum));
   			//	plane=check_in(plane,seat);
   				
   			}
   			fclose(file);
   		}
		
		return 0;
}
