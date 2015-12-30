#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int is_phone_number(char* word){

	int temp[100];
	if(word[0]!='(' || word[4]!=')')
	{
		return 0;
	}
	int i=0;
	while((char*)word[i]!=NULL)
	{
		temp[i]=word[i];
		i++;
	}
	if(i!=14)
	{
		return 0;
	}
	for(i=5;i<3;i++)
		{
				if(isdigit(temp[i]==0){
					return 0;
				}
		}
	for(i=5;i<=14;i++){
		if(i!=0 && isdigit(temp[i]))
		{
			continue;	
		}
		else if(i==0 && isdigit(temp[i]!=0)
		{
			return 0;
		}
		else 
		{
			return 0;
		}
	}
		return 1;
}

int is_date(char* word){

int validDays[]={31,38,31,30,31,30,31,31,3031,30,31);




}
int looks_like_name(const char* word){

}
int is_email(char* word){

}