//  ECE2534 - Intro to unix
//  Project 2
//  postfix notation calculator
//
//  Created by Nhan Pham on 11/17/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

//Create a truct for stack
typedef struct node
{
    double info;
    struct node *ptr;
}stack;

stack *top,*top1,*temp;

// declare functions for the stuck and gobal variable
double peek();
void push(double data);
void pop();
int empty();
void display();
void destroy();
void create();
int isOp(char input);
int count = 0;


int main(int argc, const char * argv[]) {
    
    // declare and initialize variables
    char input;
    int in_count = 0, op_count = 0, compare = 0;
    double lVal = 0, rVal =0, result =0 ;
    
    // print welcome message
    printf("\n Welcome to postfix calculator \n");
    
    // destruct then construct a new stack
    destroy();
    create();
    
        
    while (1)
    {
        // get input
        scanf("%s", &input);
        
        if (input == 'n') {
            destroy();
            create();
            op_count=0;
            in_count = 0;
        }
        else if (isOp(input)) // check if input is an operator
        {
            
            if (empty() || count < 2 ) // check if there are enough operands
            {
                printf("\n There is not enough value in the stack");
                op_count++;
            }
            else
            {
                //take values from the stack
                op_count++;
                rVal = peek();
                pop();
                lVal = peek();
                pop();
                
                switch (input) //calculate base on the operator
                {
                    case '+':
                        result = lVal + rVal;
                        
                        break;
                    
                    case '/':
                        result = lVal / rVal;
                       
                        break;
                    
                    case '*':
                        result = lVal * rVal;
                        
                        break;
                    
                    case '-':
                        result = lVal - rVal;
                       
                        break;
                        
                    default:
                        printf("\n Error!!");
                        break;
                }
                push(result);
                
            }
        }
        else
        {
            if (isnumber(input)) // if the input is a number then push it in the stack
            {
                in_count++;
                long double numericalInput = atof(&input); // convert char to double
                push(numericalInput);
               
            }
            else if ( input == EOF)
            {
                printf("\n Result: %lf", result);
               
            }
            else
                printf("\n Error!!");
                
        }
        
        compare = in_count - op_count;

        // print of the result
        if ( count == 1 && op_count != 0 && compare != 0)
        {
            result = peek();
            printf("\n Result: %lf", result);
            printf("\n Enter another value to continue with previous result or 'n' for new calculation\n");
        }
        
    }
    
   
    return 0;
}

/* checking if the input is an operator*/
int isOp(char input)
{
    if(input == '*' || input == '/' || input == '-' || input == '+')
    {
        return TRUE;
    }
    else
        return FALSE;
}


/* Create empty stack */
void create()
{
    top = NULL;
}

/* Push data into stack */
void push(double data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}

/* Display stack elements */
void display()
{
    top1 = top;
    
    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
        
    }
    
    while (top1 != NULL)
    {
        printf("%lf ", top1->info);
        top1 = top1->ptr;
    }

}

/* Pop menber on stack */
void pop()
{
    top1 = top;
    
    if (top1 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return;
    }
    else
        top1 = top1->ptr;
    free(top);
    top = top1;
    count--;
}

/* Return top element */
double peek()
{
    return(top->info);
}

/* Check if stack is empty or not */
int empty()
{
    if (top == NULL)
        return TRUE;
    else
        return FALSE;
}

/* Destroy entire stack */
void destroy()
{
    top1 = top;
    
    while (top1 != NULL)
    {
        top1 = top->ptr;
        free(top);
        top = top1;
       // top1 = top1->ptr;
    }
    free(top1);
    top = NULL;
    count = 0;
}
