#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include "P9-heap.h"
using namespace std;

int cmpKey(void* arg1, void* arg2);
int main () 
{
	srand(time(NULL));
	
	HEAP* heap100  = heapCreate (100,cmpKey);
	HEAP* heap200  = heapCreate (200,cmpKey);
	HEAP* heap500  = heapCreate (500,cmpKey);
	HEAP* heap1000 = heapCreate (1000,cmpKey);
	HEAP* heap2000 = heapCreate (2000,cmpKey);
	//cout << "Random numbers in range 1 to 100" << endl;
	
	cout << "Table reheapUp:" << "\n" << "-------------------------------------------------------------------------------------------" << endl;
	//size 100
	while(heap100->size<100)
	{
		int randNum= rand() % 100 + 1;
		int* randP = new int(randNum);
		//cout << randNum << endl;
		//cout << *randP << endl;
		heapInsert(heap100,(void*)randP);
	}
	cout << "| Heap of size 100" << endl;
	cout << "| Total moves: " << heap100->movesAdd << endl;
	double movesAvg = ((double)heap100->movesAdd)/(double)100;
	cout << "| Average moves per user (moves/totalUsers): " << setprecision(6) << movesAvg << endl;
	
	
	//size 200
	while(heap200->size<200)
	{
		int randNum= rand() % 100 + 1;
		int* randP = new int(randNum);
		//cout << randNum << endl;
		//cout << *randP << endl;
		heapInsert(heap200,(void*)randP);
	}
	cout << "| Heap of size 200" << endl;
	cout << "| Total moves: " << heap200->movesAdd << endl;
	movesAvg = ((double)heap200->movesAdd)/(double)200;
	cout << "| Average moves per user (moves/totalUsers): " << setprecision(6) << movesAvg << endl;
	
	
	//size 500
	while(heap500->size<500)
	{
		int randNum= rand() % 100 + 1;
		int* randP = new int(randNum);
		//cout << randNum << endl;
		//cout << *randP << endl;
		heapInsert(heap500,(void*)randP);
	}
	cout << "| Heap of size 500" << endl;
	cout << "| Total moves: " << heap500->movesAdd << endl;
	movesAvg = ((double)heap500->movesAdd)/(double)500;
	cout << "| Average moves per user (moves/totalUsers): " << setprecision(6) << movesAvg << endl;
	
	
	//size 1000
	while(heap1000->size<1000)
	{
		int randNum= rand() % 100 + 1;
		int* randP = new int(randNum);
		//cout << randNum << endl;
		//cout << *randP << endl;
		heapInsert(heap1000,(void*)randP);
	}
	cout << "| Heap of size 1000" << endl;
	cout << "| Total moves: " << heap1000->movesAdd << endl;
	movesAvg = ((double)heap1000->movesAdd)/(double)1000;
	cout << "| Average moves per user (moves/totalUsers): " << setprecision(6) << movesAvg << endl;
	
	
	//size 2000
	while(heap2000->size<2000)
	{
		int randNum= rand();
		int* randP = new int(randNum);
		//cout << randNum << endl;
		//cout << *randP << endl;
		heapInsert(heap2000,(void*)randP);
	}
	cout << "| Heap of size 2000" << endl;
	cout << "| Total moves: " << heap2000->movesAdd << endl;
	movesAvg = ((double)heap2000->movesAdd)/(double)2000;
	cout << "| Average moves per user (moves/totalUsers): " << setprecision(6) << movesAvg << endl;
	cout << "| \n" << "| Each input of size n gives a total moves of c*n , for 0<c<logn; thus reheapUp == O(cn) =>O(nlogn)" << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
	
	cout << "Table reheapDown:" << "\n" << "-------------------------------------------------------------------------------------------" << endl;
	while(heap100->size>0)
	{
		int* temp=(int*)malloc(sizeof(int*));
		heapDelete(heap100,(void**)&temp);
		//cout << *temp << endl;
	}
	cout << "| Heap of size 100" << endl;
	cout << "| Total moves: " << heap100->movesDel << endl;
	movesAvg = ((double)heap100->movesDel)/(double)100;
	cout << "| Average moves per user (moves/totalUsers): " << setprecision(6) << movesAvg << endl;

	while(heap200->size>0)
	{
		int* temp=(int*)malloc(sizeof(int*));
		heapDelete(heap200,(void**)&temp);
		//cout << *temp << endl;
	}
	cout << "| Heap of size 200" << endl;
	cout << "| Total moves: " << heap200->movesDel << endl;
	movesAvg = ((double)heap200->movesDel)/(double)200;
	cout << "| Average moves per user (moves/totalUsers): " << setprecision(6) << movesAvg << endl;	//cout << "Printing" << endl;
	
	while(heap500->size>0)
	{
		int* temp=(int*)malloc(sizeof(int*));
		heapDelete(heap500,(void**)&temp);
		//cout << *temp << endl;
	}
	cout << "| Heap of size 500" << endl;
	cout << "| Total moves: " << heap500->movesDel << endl;
	movesAvg = ((double)heap500->movesDel)/(double)500;
	cout << "| Average moves per user (moves/totalUsers): " << setprecision(6) << movesAvg << endl;
	
	while(heap1000->size>0)
	{
		int* temp=(int*)malloc(sizeof(int*));
		heapDelete(heap1000,(void**)&temp);
		//cout << *temp << endl;
	}
	cout << "| Heap of size 1000" << endl;
	cout << "| Total moves: " << heap1000->movesDel << endl;
	movesAvg = ((double)heap1000->movesDel)/(double)1000;
	cout << "| Average moves per user (moves/totalUsers): " << setprecision(6) << movesAvg << endl;
	while(heap2000->size>0)
	{
		int* temp=(int*)malloc(sizeof(int*));
		heapDelete(heap2000,(void**)&temp);
		//cout << *temp << endl;
	}
	cout << "| Heap of size 2000" << endl;
	cout << "| Total moves: " << heap2000->movesDel << endl;
	movesAvg = ((double)heap2000->movesDel)/(double)2000;
	cout << "| Average moves per user (moves/totalUsers): " << setprecision(6) << movesAvg << endl;
	cout << "| \n" << "| Each input of size n gives a total moves of at least 4*n , for 4<c<n; thus reheapUp == lower bound of nlogn and upperbound/O(n^2) " << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
	//Want to print heap100
	/*for(int i=0;i<100;i++)
	{
		cout << *(int*)heap100->heapAry[i] << endl;
	}*/
	
	return 0;
}

int cmpKey(void* arg1, void* arg2)
{
	int* nOne = (int*)arg1;
	int* nTwo = (int*)arg2;
	//cout << *nOne << " " << *nTwo << endl;
	int result = ((*nOne>*nTwo)?+1:-1);
	if(*nOne==*nTwo) result = 0;
	//cout << result << endl;
	return result;
}
