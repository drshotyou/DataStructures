#include <iostream>
#include "stacksADT.h"
 using namespace std;

 int main () {
     int num;
     int *numP;
     int total;
     STACK *stack;

     stack=createStack();
     while(cin>>num && num!=EOF)
     {
         if(num<0)
         {
             if((total=stackCount(stack))<5)
             {
                 cout << "There are only " << total << " numbers in the stack" << endl;
             }
             else
             {
                cout << "The last 5 numbers are: ";
                for(int i=0;i<5;i++)
                {
                    num=*(int*)popStack(stack);
                    cout <<" "<< num << " ";
                }
                cout << endl;
             }
         }
         else
         {
             numP=(int*)malloc(sizeof(int));
             *numP=num;
             if(!pushStack(stack,numP))
             {
                 cout << "Stack is full" << endl;
             }
         }
         cout << "Input next in integer" << endl;
     }

     total=stackCount(stack);
     if(total==0)
     {
         cout << "Stack is empty" << endl;
     }
     else
     {
         cout << "The remaining " << total << " numbers are: ";
         while(!emptyStack(stack))
         {
             num = *(int*)popStack(stack);
             cout << " " << num << " ";
         }
     }
     return 0;
 }
