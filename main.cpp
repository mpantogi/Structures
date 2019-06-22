/*
 * File:   main.cpp
 * Author:
 */

#include "MyQueue.h"
#include "MyStack.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string.h>

#define MAX 100
#define NUMBER 10

using namespace std;

//briskei to id_struct sto id_array
int find(int id_array[],int id_struct)
{
    int i=0;
    do
    {
        if(id_array[i]==id_struct)
        {
            return i;
        }
        i++;
    } while(i<NUMBER);
    return -1;
}

//epistrefh thn prwth eleuterh thesh ston pinaka id_array
int free(int id_array[])
{
    int i=0;
    do
    {
        if(id_array[i]==0)
        {
            return i;
        }
        i++;
    } while(i<NUMBER);
    return -1;
}

int main(int argc, char** argv) {

    //anoigma arxoiwn gia anagnwsh kai eggrafh
    ifstream infile;
    ofstream outfile;

    infile.open("input.txt",ios::in);
    outfile.open("output.txt", ios::out);

     /* command[MAX] - pinakas gia apothkeush xarakthrwn entwlwn
     * num[MAX] - pinakas apothkeushs gia aritmous ouras kai stoibas
     * elem[MAX] - pinakas apothkeushs gia ta stoixeia pros eisagwgh
     */
    char buffer[MAX], command[MAX], num[MAX], elem[MAX];
    

    //pinakas seiktwn gia tis oures
    MyQueue *QueuePointers[NUMBER];
    //pinakas deiktwn gia tis stoibes
    MyStack *StackPointers[NUMBER];
    
    /* i, j, k - metrhtes
	 * id_struct - aritmos ouras kai stoibas
     * id_element - stoixeio gia eisagwgh
     * temp_num - antigrafh ths id_struct h ths id_element
     * nums - plhthos pshfiwn ths id_struct h ths id_element
     * size -plhthos stoixeiwn twn pinakwn num h elem
     */
    int i, j, k, id_struct, id_element, temp_num, nums, size;

    /* id_queue[NUMBER] - kwdikoi ourwn pou dhmiourghthkan
     * num_queue - plhthos ourwn pou dhmiourghthkan
     * id_stack[NUMBER] - kwdikoi stoibwn pou dhmiourghthkan
     * num_stack - plhthos stoibwn pou dhmiourghthkan
     */
    int id_queue[NUMBER], num_queue=0, id_stack[NUMBER], number_stack=0;

    /* fail1 - anagnwrhsh kenwn grammwn sto arxeio
     * fail2 - anagnwrhsh esfalmenhs entwlh
	 */
    bool fail1,fail2;

    //arxikopoihsh  pinakwn
    for(i=0;i<NUMBER;i++)
    {
        id_queue[i]=0;
        id_stack[i]=0;
    }
    //apothkeush kathe grammhs tou arxeiou
    while(infile.getline(buffer,MAX))
    {
        i=0, j=0, temp_num=0, nums=0, size=0;
        fail1=0;
        fail2=1;
        k=0; //metrhths kenwn thesewn
        while ( (buffer[k] == ' ') || (buffer[k] == '\t') )
        {
            k++;
        }
        if (buffer[k] == '\0')
        {
            fail1=1;
        }
        //euresh ths entolhs
        if(fail1==0)
        {
            i=k;
            for (j = 0; buffer[i] != ' ' && buffer[i] != ',' && buffer[k] != '\t' && buffer[i] != '\n' && buffer[i] != '\0'; i++, j++)
            {
                command[j] = buffer[i];
            }
            command[j] = '\0'; //dhmiourgia sumvoloseiras
            //sunthkh gia otan meta thn entolh uparxei keno
            if (buffer[i] == ' ')
            {
                i++;
                for (j = 0; buffer[i] != ' ' && buffer[i] != ',' && buffer[k] != '\t' && buffer[i] != '\n' && buffer[i] != '\0'; i++, j++)
                {
                    //epanafora tou deikth i sthn katalhlh thesh
                    size++;
                    num[j] = buffer[i];
                }
                if (j!=0) //elegxos
                {
                    num[j] = '\0';
                    //metatroph sumvoloseiras se akeraio
                    id_struct = atoi(num);
                    //epanafora  i sthn katallhlh thesh
                    temp_num=id_struct;
                    do
                    {
                        temp_num=temp_num/10;
                        nums++;
                    } while (temp_num!=0);

                    //sunthkh otan meta thn entolh uparxei ','
                    if (buffer[i] == ',')
                    {
                        i++; 
                        //pratw opws prohgoumenos
                        for (j = 0; buffer[i] != ' ' && buffer[i] != ',' && buffer[k] != '\t' && buffer[i] != '\n' && buffer[i] != '\0'; i++, j++)
                        {
                            size++;
                            elem[j] = buffer[i];
                        }
                        if (j!=0) //elegxos
                        {
                            elem[j] = '\0';
                            id_element = atoi(elem);
                            temp_num=id_element;
                            do
                            {
                                temp_num=temp_num/10;
                                nums++;
                            } while (temp_num!=0);
                            //egxwrw thesh sto i
                            i=i-size+nums;
                            //elegxos gia adeia grammh
                            while ( (buffer[i] == ' ') || (buffer[i] == '\t') )
                            {
                                i++;
                            }
                            if (buffer[i] == '\0')
                            {
                                fail2=0;
                            }
                        }
                        else
                        {
                            fail2=1;
                        }
                    }
                    else
                    {
                        if ( ( strcmp(command,"QUEUE_INSERT")==0 ) || ( strcmp(command,"STACK_PUSH")==0 ) )
                        {
                            fail2=1;
                        }
                        else
                        {
                            //egxwrhsh theshs sto i
                            i=i-size+nums;
                            //elegxos gia adeia grammh
                            while ( (buffer[i] == ' ') || (buffer[i] == '\t') )
                            {
                                i++;
                            }
                            if (buffer[i] == '\0')
                            {
                                fail2=0;
                            }
                        }
                    }
                }
                else
                {
                    fail2=1;
                }
            }
            if (fail2==0)
            {
                //elegxos egkhrhs timhs
                if ( (id_struct>0) && (id_struct<11) )
                {
				
                    //ulopoihsh ouras
					
                    if (strcmp(command,"QUEUE_CREATE")==0)
                    {
                        //kataxwrhsh timhs
                        QueuePointers[id_struct-1] = new MyQueue;
                        outfile << "< " << command << " " << id_struct << " >\t< OK >" << endl;
                        //kataxwrhsh tou id_struct sto id_queue
                        if( ( find(id_queue,id_struct) ) == -1 )
                        {
                            if( ( free(id_queue) )!= -1 )
                            {
                                id_queue[free(id_queue)]=id_struct;
                                num_queue++;
                            }
                        }
                    }
                    else if (strcmp(command,"QUEUE_DESTROY")==0)
                    {
                        //periptwsh uparktou kwdika
                        if ( ( find(id_queue,id_struct) ) != -1 )
                        {
                            QueuePointers[id_struct-1]->~MyQueue();
                            outfile << "< " << command << " " << id_struct << " >\t< OK >" << endl;
                            id_queue[find(id_queue,id_struct)]=0; 
                            num_queue--;
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t";
                            outfile << "< ERROR: No Queue with code=" << id_struct << " is found >" << endl;
                        }
                    }
                    else if (strcmp(command,"QUEUE_INSERT")==0)
                    {
                        if ( ( find(id_queue,id_struct) ) != -1 )
                        {
                            if (id_element>0)
                            {
                                QueuePointers[id_struct-1]->Insert(id_element);
                                outfile << "< " << command << " " << id_struct << "," << id_element << " >\t< OK >" << endl;
                            }
                            else
                            {
                                //elegxos gia thn swsth ektupwsh tou id_element
                                if (id_element==0)
                                {
                                    outfile << "< " << command << " " << id_struct << "," << elem[0] << " >\t";
                                }
                                else
                                {
                                    outfile << "< " << command << " " << id_struct << "," << id_element << " >\t";
                                }
                                outfile << "< ERROR: wrong value, insert only positive numbers >" << endl;
                            }
                        }
                        else
                        {
                            if (id_element==0)
                            {
                                outfile << "< " << command << " " << id_struct << "," << elem[0] << " >\t";
                            }
                            else
                            {
                                outfile << "< " << command << " " << id_struct << "," << id_element << " >\t";
                            }
                            outfile << "< ERROR: No Queue with code=" << id_struct << " is found >" << endl;
                        }
                    } 
                    else if (strcmp(command,"QUEUE_DELETE")==0)
                    {
                        if ( ( find(id_queue,id_struct) ) != -1 )
                        {
                            if(QueuePointers[id_struct-1]->GetSize()==0)
                            {
                                outfile << "< " << command << " " << id_struct << " >\t< ERROR: can't delete from an empty Queue >" << endl;
                            }
                            else
                            {
                                QueuePointers[id_struct-1]->Delete() ;
                                outfile << "< " << command << " " << id_struct << " >\t< OK >" << endl;
                            }
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t";
                            outfile << "< ERROR: No Queue with code=" << id_struct << " is found >" << endl;
                        }
                    }
                    else if (strcmp(command,"QUEUE_READ")==0)
                    {
                        if ( ( find(id_queue,id_struct) ) != -1 )
                        {
                            if(QueuePointers[id_struct-1]->Read()==0)
                            {
                                outfile << "< " << command << " " << id_struct << " >\t\t< ERROR: can't read from an empty QUEUE >" << endl;
                            }
                            else
                            {
                                outfile << "< " << command << " " << id_struct << " >\t\t< " << QueuePointers[id_struct-1]->Read() << " >" << endl;
                            }
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t\t";
                            outfile << "< ERROR: No Queue with code=" << id_struct << " is found >" << endl;
                        }
                    }
                    else if (strcmp(command,"QUEUE_GETSIZE")==0)
                    {
                        if ( ( find(id_queue,id_struct) ) != -1 )
                        {
                            outfile << "< " << command << " " << id_struct << " >\t< " << QueuePointers[id_struct-1]->GetSize() << " >" << endl;
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t";
                            outfile << "< ERROR: No Queue with code=" << id_struct << " is found >" << endl;
                        }
                    }

                    //ulopoihsh stoibas

                    else if (strcmp(command,"STACK_CREATE")==0)
                    {
                        //kataxwrhsh timhs
                        StackPointers[id_struct-1] = new MyStack;
                        outfile << "< " << command << " " << id_struct << " >\t< OK >" << endl;
                        //kataxwrhsh tou id_struct sto id_stack
                        if( ( find(id_stack,id_struct) ) == -1 )
                        {
                            if( ( free(id_stack) )!= -1 )
                            {
                                id_stack[free(id_stack)]=id_struct;
                                number_stack++;
                            }
                        }
                    }
                    else if (strcmp(command,"STACK_DESTROY")==0)
                    {
                        //periptwsh uparktou kwdika
                        if ( ( find(id_stack,id_struct) ) != -1 )
                        {
                            StackPointers[id_struct-1]->~MyStack();
                            outfile << "< " << command << " " << id_struct << " >\t< OK >" << endl;
                            id_stack[find(id_stack,id_struct)]=0; 
                            number_stack--;
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t";
                            outfile << "< ERROR: No Stack with code=" << id_struct << " is found >" << endl;
                        }
                    }
                    else if (strcmp(command,"STACK_PUSH")==0)
                    {
                        if ( ( find(id_stack,id_struct) ) != -1 )
                        {
                            if (id_element>0)
                            {
                                StackPointers[id_struct-1]->Push(id_element);
                                outfile << "< " << command << " " << id_struct << ","<< id_element << " >\t< OK >" << endl;
                            }
                            else
                            {
                                if (id_element==0)
                                {
                                    outfile << "< " << command << " " << id_struct << "," << elem[0] << " >\t";
                                }
                                else
                                {
                                    outfile << "< " << command << " " << id_struct << "," << id_element << " >\t";
                                }
                                outfile << "< ERROR: wrong value, enter only positive numbers to push >" << endl;
                            }
                        }
                        else
                        {
                            if (id_element==0)
                            {
                                outfile << "< " << command << " " << id_struct << "," << elem[0] << " >\t";
                            }
                            else
                            {
                                outfile << "< " << command << " " << id_struct << "," << id_element << " >\t";
                            }
                            outfile << "< ERROR: No Stack with code=" << id_struct << " is found >" << endl;
                        }
                    }
                    else if (strcmp(command,"STACK_POP")==0)
                    {
                        if ( ( find(id_stack,id_struct) ) != -1 )
                        {
                            if(StackPointers[id_struct-1]->GetSize()==0)
                            {
                                outfile << "< " << command << " " << id_struct << " >\t\t< ERROR: can't pop from an empty Stack >" << endl;
                            }
                            else
                            {
                                outfile << "< " << command << " " << id_struct << " >\t\t< " << StackPointers[id_struct-1]->Pop() << " >" << endl;
                            }
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t\t";
                            outfile << "< ERROR: No Stack with code=" << id_struct << " is found >" << endl;
                        }
                    }
                    else if (strcmp(command,"STACK_READ")==0)
                    {
                        if ( ( find(id_stack,id_struct) ) != -1 )
                        {
                            if(StackPointers[id_struct-1]->Read()==0)
                            {
                                outfile << "< " << command << " " << id_struct << " >\t\t< ERROR: can't read from an empty Stack >" << endl;
                            }
                            else
                            {
                                outfile << "< " << command << " " << id_struct << " >\t\t< " << StackPointers[id_struct-1]->Read() << " >" << endl;
                            }
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t\t";
                            outfile << "< ERROR: No Stack with code=" << id_struct << " is found >" << endl;
                        }
                    }
                    else if (strcmp(command,"STACK_GETSIZE")==0)
                    {
                        if ( ( find(id_stack,id_struct) ) != -1 )
                        {
                            outfile << "< " << command << " " << id_struct << " >\t< " << StackPointers[id_struct-1]->GetSize() << " >" << endl;
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t";
                            outfile << "< ERROR: No Stack with code=" << id_struct << " is found >" << endl;
                        }
                    }
                    else
                    {
                        outfile << "< ERROR: Unknown command >" << endl;
                    }
                } 
                else
                {
                    if (strcmp(command,"QUEUE_CREATE")==0)
                    {
                        if (id_struct==0)
                        {
                            outfile << "< " << command << " " << num[0] << " >\t";
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t";
                        }
                        outfile << "< ERROR: no valid Queue_code, enter value 0 to 9 >" << endl;
                    }
                    else if (strcmp(command,"QUEUE_DESTROY")==0)
                    {
                        if (id_struct==0)
                        {
                            outfile << "< " << command << " " << num[0] << " >\t";
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t";
                        }
                        outfile << "< ERROR: no valid Queue_code, enter value 0 to 9 >" << endl;
                    }
                    else if (strcmp(command,"QUEUE_INSERT")==0)
                    {
                        if (id_struct==0)
                        {
                            if (id_element==0)
                            {
                                outfile << "< " << command << " " << num[0] << "," << elem[0] << " >\t";
                            }
                            else
                            {
                                outfile << "< " << command << " " << num[0] << "," << id_element << " >\t";
                            }
                        }
                        else
                        {
                            if (id_element==0)
                            {
                                outfile << "< " << command << " " << id_struct << "," << elem[0] << " >\t";
                            }
                            else
                            {
                                outfile << "< " << command << " " << id_struct << "," << id_element << " >\t";
                            }
                        }
                        outfile << "< ERROR: no valid Queue_code, enter value 0 to 9 >" << endl;
                    }
                    else if (strcmp(command,"QUEUE_DELETE")==0)
                    {
                        if (id_struct==0)
                        {
                            outfile << "< " << command << " " << num[0] << " >\t";
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t";
                        }
                        outfile << "< ERROR: no valid Queue_code, enter value 0 to 9 >" << endl;
                    }
                    else if (strcmp(command,"QUEUE_READ")==0)
                    {
                        if (id_struct==0)
                        {
                            outfile << "< " << command << " " << num[0] << " >\t\t";
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t\t";
                        }
                        outfile << "< ERROR: no valid Queue_code, enter value 0 to 9 >" << endl;
                    }
                    else if (strcmp(command,"QUEUE_GETSIZE")==0)
                    {
                        if (id_struct==0)
                        {
                            outfile << "< " << command << " " << num[0] << " >\t";
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t";
                        }
                        outfile << "< ERROR: no valid Queue_code, enter value 0 to 9 >" << endl;
                    }
                    else if (strcmp(command,"STACK_CREATE")==0)
                    {
                        if (id_struct==0)
                        {
                            outfile << "< " << command << " " << num[0] << " >\t";
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t";
                        }
                        outfile << "< ERROR: no valid Stack_code, enter value 0 to 9 >" << endl;
                    }
                    else if (strcmp(command,"STACK_DESTROY")==0)
                    {
                        if (id_struct==0)
                        {
                            outfile << "< " << command << " " << num[0] << " >\t";
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t";
                        }
                        outfile << "< ERROR: no valid Stack_code, enter value 0 to 9 >" << endl;
                    }
                    else if (strcmp(command,"STACK_PUSH")==0)
                    {
                        if (id_struct==0)
                        {
                            if (id_element==0)
                            {
                                outfile << "< " << command << " " << num[0] << "," << elem[0] << " >\t";
                            }
                            else
                            {
                                outfile << "< " << command << " " << num[0] << "," << id_element << " >\t";
                            }
                        }
                        else
                        {
                            if (id_element==0)
                            {
                                outfile << "< " << command << " " << id_struct << "," << elem[0] << " >\t";
                            }
                            else
                            {
                                outfile << "< " << command << " " << id_struct << "," << id_element << " >\t";
                            }
                        }
                        outfile << "< ERROR: no valid Stack_code, enter value 0 to 9 >" << endl;
                    }
                    else if (strcmp(command,"STACK_POP")==0)
                    {
                        if (id_struct==0)
                        {
                            outfile << "< " << command << " " << num[0] << " >\t\t";
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t\t";
                        }
                        outfile << "< ERROR: no valid Stack_code, enter value 0 to 9 >" << endl;
                    }
                    else if (strcmp(command,"STACK_READ")==0)
                    {
                        if (id_struct==0)
                        {
                            outfile << "< " << command << " " << num[0] << " >\t\t";
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t\t";
                        }
                        outfile << "< ERROR: no valid Stack_code, enter value 0 to 9 >" << endl;
                    }
                    else if (strcmp(command,"STACK_GETSIZE")==0)
                    {
                        if (id_struct==0)
                        {
                            outfile << "< " << command << " " << num[0] << " >\t";
                        }
                        else
                        {
                            outfile << "< " << command << " " << id_struct << " >\t";
                        }
                        outfile << "< ERROR: no valid Stack_code, enter value 0 to 9 >" << endl;
                    }
                    else
                    {
                        outfile << "< ERROR: Unknown command >" << endl;
                    }
                } 

            } //telos if gia fail

            else
            {
                outfile << "< ERROR: Unknown command or syntax >" << endl;
            } 

        } //telos if gia fail

    } //telos while

    //kleisimo arxeiwn
    infile.close();
    outfile.close();
    return 0;
}
