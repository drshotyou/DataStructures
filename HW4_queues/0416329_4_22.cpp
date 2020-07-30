#include <iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>
#include "queues.h"
using namespace std;

struct Client{
	int clockTime;
	int callNum;
	int arrivalTime;
	int startTime;
	int serviceTime;
	int waitTime;
	int queueSize;
};



Client* newClient(int currentTime, int size);
int     clientNumber     = 0;
int 	idleTime         = 0;
int 	totalWaitTime    = 0;
int 	totalCalls       = 0;
int 	totalServiceTime = 0;
int 	maxQueueSize     = 0;
int 	averageWaitTime  = 0;
int 	avgServiceTime   = 0;
bool    timerReached     = true;

int main() {
	
	QUEUE*  exClient = createQueue();
	QUEUE*  line     = createQueue();
	Client* inLine   = NULL;
	srand(time(NULL));
	
	int runTime=120,timer=2;
	
	for(int i=0;i<runTime;i++)
	{
		
		int call=rand()%10+1;
		bool callInHold=false;
		if (call<5)
		{
			callInHold=true;
		}
		else
		{
			callInHold=false;
		}
		
		if(callInHold)
		{
			inLine = newClient(i,queueCount(line));
			enqueue(line,inLine);
			idleTime=0;	
		}
		else
		{
			idleTime++;
		}	
		int ended=rand()%2;
		if(ended && inLine!=NULL && timerReached)
		{
			
			if((++(inLine->serviceTime)) == timer )
			{
				timerReached=false;
			}
		}
		else if(queueCount(line)!=0)
		{
			if(queueCount(line)>maxQueueSize)
			{
				maxQueueSize=queueCount(line);
			}
				inLine->waitTime++;
				totalWaitTime+=inLine->waitTime;
			
			if(inLine!=NULL)
			{
				enqueue(exClient,inLine);
				
				cout << "Clock time: "     << i                   << endl;
				cout << "Call number: "    << inLine->callNum     << endl;
				cout << "Arrival time: "   << inLine->arrivalTime << endl;
				cout << "Wait time: "      << inLine->waitTime    << endl;
				cout << "Service time: "   << inLine->serviceTime << endl;
				cout << "Queue size at time of request: " << inLine->queueSize << endl;
				cout << endl;
				totalCalls=inLine->callNum;
			}
			dequeue(line,(void**)&inLine);
			inLine->startTime = i;
			inLine->serviceTime++;
			totalServiceTime++;
			timerReached=true;
		}
	}	
	cout << "Total Calls: "    			<< totalCalls    				<< endl;
	cout << "Idle time: "      			<< idleTime      				<< endl;
	cout << "Total wait time: "			<< totalWaitTime 				<< endl;
	cout << "Total service time: " 		<< totalServiceTime 			<< endl;
	cout << "Max queue size: "			<< maxQueueSize 		        << endl;
	cout << "Average wait time: "		<< totalWaitTime/totalCalls 	<< endl;	
	cout << "Average service time: "	<< totalServiceTime/totalCalls  << endl;
	
	return 0;
}


Client* newClient(int simTime, int queueSize)
{
	struct Client* newInLine= (Client*)malloc(sizeof(Client));
	newInLine->clockTime=-1;
	newInLine->callNum = clientNumber++;
	newInLine->arrivalTime = simTime;
	newInLine->waitTime = 0;
	newInLine->serviceTime = 0;
	newInLine->queueSize = queueSize;
	
	return newInLine;
}

