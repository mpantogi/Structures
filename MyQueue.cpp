/*
 * File:   MyQueue.cpp
 * Author: 
 */

#include "MyQueue.h"

using namespace std;

MyQueue::MyQueue() //Constructor
{
    n=0;
    front=rear=NULL; //arxikopoiw se NULL
}

MyQueue::~MyQueue() //Destructor
{
    while(front!=rear)
    {
        Delete();
    }
    delete front; 
    delete rear;
}

void MyQueue::Insert(int x)
{
    if(front==NULL) 
    {
        front=rear=new node; //desmeush mnhmhs gia to prwto stoixeio
        rear->num=x; 
    }
    else
    {
        rear->next=new node; //desmeush mnhmhs ga neo stoixeio
        rear->next->num=x;
        rear=rear->next;
    }
    n++;
    rear->next=NULL; //arxikopoihsh deikth
}

int MyQueue::Read()
{
    if (front!=NULL)
    {
        return front->num; //epistrofh timhs
    }
    return 0;
}

void MyQueue::Delete()
{
    if(front!=NULL) 
    {
        node *temp; //dhlwsh neou deikth
        temp=front;
        if(rear==temp){ //gia ena stoixeio
            rear=NULL;
        }
        front=front->next; //h arxh einai to epomeno stoixeio
        delete temp;
        n--; 
    }
}

int MyQueue::GetSize() //epistrofh plhtous stoixeiwn
{
   return n;
}
