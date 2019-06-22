/* 
 * File:   MyStack.h
 * Author:
 */

#ifndef MYSTACK_H
#define	MYSTACK_H

#include <iostream>
#include <cstdlib>

class MyStack
{
private:
    int n; //plhthos stoixeiwn

    //sundedemenh lista gia thn ulopoihsh ths stoibas
    struct node
    {
        int num;

        struct node *next; //deikths gia na vroume to epomeno stoixeio

    } *top; //vriskei thn korufh ths stoivas

public:
    MyStack(); //constructor
    ~MyStack(); //destructor
    void Push(int x); //eisagwgh sthn korufh
    int Pop(); //diagrafh apo thn korufh
    int Read(); //anagnwsh ths korufhs
    int GetSize(); //plhthos apothkeumenwn stoixeiwn sth stoiva
};

#endif

