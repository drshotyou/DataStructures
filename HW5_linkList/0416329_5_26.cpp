#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include "linkListADT.h"


using namespace std;

int cmpNames (void* nameOne, void* nameTwo);
int cmpGrades (void* nameOne, void* nameTwo);
//int cmpNmaes (void* nameOne, void* nameTwo);

int main()
{
	ifstream input;
	string studentName;
	studentName=(char*)malloc(sizeof(char*));
	int grades,total=0;
	LIST * studentNames;
	LIST * gradesList;
	studentNames 	= createList(cmpNames);
	gradesList 		= createList(cmpGrades);
	//cout << "created list" << endl;
	input.open("StudentName.txt");
	while(!input.eof())
	{
		input >> studentName;
		cout << studentName << endl;
		NODE* studentNode = new NODE;
		studentNode->dataPtr=(void*)studentName;
		int success = addNode(studentNames,studentNode);
		cout << success << endl;
		if(success!=0)
		{
			cout << "Error inserting, exiting program" << endl;
			break;
		}
		
		//NODE temp2;
		//NODE* temp3;
		//temp3=(NODE*)malloc(sizeof(NODE*));
		//temp2.dataPtr = studentName;
		//bool found = searchList(studentNames,&temp2,(void**)&temp3);
		//cout << found << endl;
		//cout << temp3->dataPtr << endl;
		for(int i=0;i<3;i++)
		{
			cin >> grades;
			cout << grades << endl;
			NODE* gradeNode = new NODE;
			gradeNode->dataPtr=(int*)grades;
			int success2 = addNode(gradesList,gradeNode);
			//cout << "here" << endl;
			//cout << *gradePtr << endl;
			//total+=grades[i];
			// calculate avergae here???
			if(grades<0)
			{
				//total/=i+1;
				//cout << "Student name: " << studentName << endl;
				//cout << ""
				break;
			}
			/*else if(i==2)
			{
				total/=i+1;
			}*/
			//studentNames->pos=studentNames->pos->link;
		}
	}
	int j=0;
	for(int i=0;i<studentNames->count;i++)
	{
		
		char * temp;
		bool found;
		temp=(char*)malloc(sizeof(char*));
		found=traverse(studentNames,i,(void**)temp);
		cout << temp << endl;
		int count=1;
		for(j;j<gradesList->count;j++)
		{
			bool found2;
			int * temp2;
			temp2=(int*)malloc(sizeof(int*));
			found2=traverse(gradesList,j,(void**)temp2);
			if(*temp2==1)
			{
				j++;
				cout << "Average: " << total/count << endl;
				break;
			}
			cout << temp2 << endl;
			count++;
		}
		
	}
	return 0;
}



int cmpNames(void* nameOne, void* nameTwo)
{
	int result;
	char* nOne;
	char* nTwo;
	
	nOne = (char*)((NODE*)nameOne)->dataPtr;
	nTwo = (char*)((NODE*)nameTwo)->dataPtr;
	
	result=strcmp(nOne,nTwo);
	return result;
}

int cmpGrades(void* nameOne, void* nameTwo)
{
	int result;
	int* nOne;
	int* nTwo;
	
	nOne = (int*)((NODE*)nameOne)->dataPtr;
	nTwo = (int*)((NODE*)nameTwo)->dataPtr;
	
	result=(nOne>nTwo?+1:-1);
	if(nOne==nTwo) result =0;
	return result;
}
