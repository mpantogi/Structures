/*
 * File:   MyQueue.h
 * Author: 
 */

#ifndef MYQUEUE_H
#define	MYQUEUE_H

#include <iostream>
#include <cstdlib>

class MyQueue
{
private:
    int n; //plhthos stoixeiwn

    //sundedemenh lista gia thn ulopoihsh ths ouras
    struct node
    {
        int num;

        struct node *next; //deikths gia na vroume to epomeno stoixeio

    } *front, *rear; //deiktes gia thn euresh ths arxhs kai tou telous ths ouras

public:
    MyQueue(); //constructor
    ~MyQueue(); //destructor
    int Insert(int x); //eisagwgh sto telos ths ouras
    int Delete(); //diagrafh apo thn arxh
    int Read(); //anagnwsh tou stoixeiou korufhs
    int GetSize(); //plhthos apothkeumenwn stoixeiwn sthn oura

};

#endif
