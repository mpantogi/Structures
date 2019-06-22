/*
 * File:   MyStack.cpp
 * Author: 
 */

#include "MyStack.h"

using namespace std;

MyStack::MyStack() //constructor
{
    n=0;
    top=NULL; //arxikopoihsh me NULL
}

MyStack::~MyStack() //destructor
{
    
    while (top!=NULL)
    {
        struct node *temp=top;  //dhlwsh prosorinou komvou temp
        top=top->next;  
        delete temp; 
    }
    delete top; 
}

void MyStack::Push(int x) 
{
    struct node *temp;  //dhmiourgia neou komvou
    temp=new node;  
    temp->num=x;    //kataxwrhsh stoixeiou x
    temp->next=top; 
    top=temp;   
    n++;
}
	
int MyStack::Pop() 
{
    
    if (top==NULL)
    {
        return 0;
    }
    else
    {
        int new_temp; //dhlwsh arxeiou gia na apothkeusoume ton komvo pros diagrafh
        struct node *temp;  
        temp=top;
        new_temp=temp->num;
        top=top->next; //metatinhsh tou deikth sto epomeno stoixeio
        delete temp; 
        n--;   
        return new_temp;  
    }
}

int MyStack::Read() 
{
    if (top!=NULL) 
        return top->num; //epistrofh timhs
    else
        return 0;
}

int MyStack::GetSize() //plhthos apothkeumenwn stoixeiwn
{
    return n;
}
