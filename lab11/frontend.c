//MArk Madden
//mcmpw6
//lab 11
//14182986
//lab code: 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#define MAX_LINE 250


int main(int argc, char* argv[]){

	int token[MAX_LINE];
	char buffer[MAX_LINE];
	if(argc<2){ // error check
		printf("Not enough inputs");
		return 0;
		}
	
	FILE* file=fopen(argv[1],"r");	// open file
	if(file==NULL){
		printf("File could not be open\n");
	}
	
	while(fgets(token,MAX_LINE,file)!=NULL){
		if(buffer[strlen(buffer)-1]=='\n')
			buffer[strlen(buffer)-1] ='\0';
			
		
	
	