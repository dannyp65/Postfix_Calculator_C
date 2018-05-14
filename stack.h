//
//  stack.h
//  postfix
//
//  Created by Daniel Pham on 11/17/15.
//  Copyright © 2015 Daniel Pham. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int info;
    struct stack *ptr;
};
struct stack *top, *top1, *temp;

int topelement();
void push(int data);
void pop();
void empty();
void display();
void destroy();
void stack_count();
void create();

#endif /* stack_h */
