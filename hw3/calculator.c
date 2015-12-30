#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

#define MAX_EQU_LEN 100


/**
 * Param: operator - a character
 *
 * Return: A number corresponding to the arithmetic precedence 
 *         of the character. 
 *         Multiplication:  * => 5
 *         Division:        / => 4
 *         Modulus:         % => 3
 *         Addition:        + => 2
 *         Subtration:      - => 1
 *         NonOperator           0
 */
static char prec(char operator) {

	
	switch(operator){//swtich case
		
		case '*':
			return 5;
			break;
		
		case '/':
			return 4;
			break;
		
		case '%':
			return 3;
			break;
		
		case '+':
			return 2;
			break;
		
		case '-':
			return 1;
			break;
		
		default:
			return 0;
			break;
	}

}

/**
 * Param: num - A string
 *
 * Return: 1 if the string contains only contains numbers
 *         0 otherwise
 */
static int isNumeric(char *num) { //why a string?

	//int checkNum=*num;
	if(isdigit(*num)){	//try putting checkNum in isdigit
		return 1;
	//if string is number return 1
		}
	else{
		return 0;
		}

}

/**
 * Param: infix - A valid infix expression
 *
 * Return: The corresponding postfix expression
 *
 * To convert an expression from infix to postfix, 
 * use the following algorithm
 *
 * create an empty string called postfix
 * create an empty stack
 *
 * for each token in the string
 *      if the token is a number
 *          append it to the postfix string
 *      else if the token is a left paren
 *          push it onto the stack
 *    //  else if the next token is an operator (+, -, *, /, %)
 *          while the stack is not empty and the operator at the top of the stack has higher precedence than the token
 *              pop the top element off of the stack and append it to the postfix string
 *          push the current token onto the stack
 *      else if the next token is a right paren
 *          while the stack is not empty and the corresponding left paren is not at the top of the stack
 *              pop the next operator off of the stack
 *              append it to the postfix string
 * while there are elements remaining on the stack
 *      pop the top element off of the stack
 *      append it to the postfix string
 *
 * return the postfix string
 *
 *
 * Hint: Put spaces between numbers and operators so 
 *       that you can use strtok in eval 
 */
char* to_postfix(char* infix){

	char* to_postfix(char* infix);

        char* postfix = malloc(sizeof(infix));//malloc space
        stack* s = create_stack();//create a stack

        int i=0, j=0;//counters

        for(i=0; infix[i]!='\0'; i++)
        {
                if(isdigit(infix[i]))
                {
                        postfix[j]=infix[i];
                        j++;
                }
                else if(infix[i]=='(')
                {
                        push(s,(char)infix[i]);
                }
                else if(infix[i]==')')
                {
                        postfix[j]=' ';
                        j++;

                        while(!isEmpty(s) && top(s)!='(')
                        {
                        postfix[j]=(char)top(s);
                        j++;
                        pop(s);
                        }
                pop(s);
                }

                else
                {
                        postfix[j++]=' ';
                        if(isEmpty(s))
                        {
                                push(s,(char)infix[i]);
                        }
                        else
                        {
                                while(!isEmpty(s) && prec((char)top(s)) && prec(infix[i]))
                                {
                                        postfix[j++]=' ';
                                        postfix[j++]=(char)top(s);
                                        pop(s);//pop
                                }
                        push(s,(char)infix[i]); // push
                        }
                }
 }

        while(!isEmpty(s))
        {
                postfix[j++]= (char)top(s);
                pop(s);//pop
        }
        postfix[j]='\0';
        free(s);//free node
        return postfix;//return string

}

			
		

/**
 * Param: postfix - A valid postfix string
 *
 * Return: The value that the expression evaluates to
 *
 *
 * To evaluate a postfix string, use the following algorithm
 *
 * create an empty stack
 *
 * for each token in the string
 *      if the token is numeric
 *          convert it to an integer
 *          push it onto the stack
 *      else
 *          pop the top two elements off of the stack
 *          the first element goes into the right variable
 *          the second goes into the left variable
 *          appy the operation: 
 *              result = left op right
 *              ex: result left + right
 *          push the result onto the stack
 *
 * The final result will be the only element on the stack
 * pop it and return it. 
 */
int eval(char* postfix) {
    stack *s = create_stack();
    int result;
	//you guys did this already
    char* token = strtok(postfix, " \n");
    while(token != NULL) {
        if (isNumeric(token)) {
            push(s, atoi(token));
        } else {
            int x = top(s);
            pop(s);
            int y = top(s);
            pop(s);
	
            switch(token[0]) {
                case '*':
                    result = y * x;
                    break;
                case '/':
                    result = y / x;
                    break;
                case '%':
                    result = y % x;
                    break;
                case '+':
                    result = y + x;
                    break;
                case '-':
                    result = y - x;
                    break;
            }

            push(s, result);
        }

        token = strtok(NULL, " \n");
    }

    result = top(s);
    pop(s);
    free(s);

    return result;
}
