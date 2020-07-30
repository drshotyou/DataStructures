#include <iostream>
#include "stacksADT.h"

using namespace std;

int main () {
	int entranceX,entranceY;
	int* numY;
	int* numX;
	numY=(int*)malloc(sizeof(int));
	numX=(int*)malloc(sizeof(int));
	int maze[10][12]={ //0  1  2  3  4  5  6  7  8  9  10  11
					   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, // 0
					   
					   //0  1  2  3  4  5  6  7  8  9  10  11
					   { 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1 }, // 1
					   
					   //0  1  2  3  4  5  6  7  8  9  10  11
					   { 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1 }, // 2
					   
					   //0  1  2  3  4  5  6  7  8  9  10  11
					   { 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1 }, // 3
					   
					   //0  1  2  3  4  5  6  7  8  9  10  11
					   { 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 }, // 4
					   
					   //0  1  2  3  4  5  6  7  8  9  10  11
					   { 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1 }, // 5
					   
					   //0  1  2  3  4  5  6  7  8  9  10  11
					   { 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 }, // 6
					   
					   //0  1  2  3  4  5  6  7  8  9  10  11
					   { 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1 }, // 7
					   
					   //0  1  2  3  4  5  6  7  8  9  10  11
					   { 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 }, // 8 
					   
					   //0  1  2  3  4  5  6  7  8  9  10  11
					   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } // 9
					   
					   
					  };
	STACK* xVis;
	STACK* yVis;
	xVis=createStack();
	yVis=createStack();
	bool cheeseDinner=false;
	cout << "Please input the entrance coordinates (x,y): ";
	cin >> entranceX >> entranceY;
	while(maze[entranceY][entranceX]!=0)
	{
		cout << "Position " << entranceX << " " << entranceY << " is not an open spot" << endl;
		cout << "Input a valid position:  ";
		cin >> entranceX >> entranceY;
	}
	while(!cheeseDinner)
	{
		if(entranceY==4 && entranceX==11)
		{
			cout << "Reached the cheese at: " << entranceX << " " << entranceY << endl;
			cheeseDinner=true;
			break;
		}
		if(maze[entranceY][entranceX+1]==0)
		{
			cout << "Right" << endl;
			*numY=entranceY;
			pushStack(yVis,numY);
			*numX=entranceX;
			pushStack(xVis,numX);
			maze[entranceY][entranceX]=3;
			cout << entranceX << " " << entranceY << endl;
			entranceX++;
			continue;
		} 
		if(maze[entranceY+1][entranceX]==0)
		{
			cout << "Down" << endl;
			*numY=entranceY;
			pushStack(yVis,numY);
			*numX=entranceX;
			pushStack(xVis,numX);
			maze[entranceY][entranceX]=3;
			cout << entranceX << " " << entranceY << endl;
			entranceY++;
			continue;
		}
		if(maze[entranceY][entranceX-1]==0)
		{
			cout << "Left" << endl;
			*numY=entranceY;
			//cout << *numP << endl;
			pushStack(yVis,numY);
			*numX=entranceX;
			//cout << *numP << endl;
			pushStack(xVis,numX);
			maze[entranceY][entranceX]=3;
			cout << entranceX << " " << entranceY << endl;
			entranceX--;
			continue;
		}
		if (maze[entranceY-1][entranceX]==0)
		{
			cout << "Up" << endl;
			*numY=entranceY;
			pushStack(yVis,numY);
			*numX=entranceX;
			pushStack(xVis,numX);
			maze[entranceY][entranceX]=3;
			cout << entranceX << " " << entranceY << endl;
			entranceY--;
			continue;
		}
		if(!emptyStack(yVis))
		{
			cout << "Dead" << endl;
			maze[entranceY][entranceX]=4;
			cout << entranceX << " " << entranceY << endl;
			entranceY=*(int*)popStack(yVis);
			//cout << entranceY << endl;
			
			entranceX=*(int*)popStack(xVis);
			//cout << entranceX << endl;
			//popStack(yVis);
			//popStack(xVis);
			cout << entranceX << " " << entranceY << endl;
			continue;
		}
		//cout << emptyStack(yVis) << endl;
		
	}
	
	return 0;
}
