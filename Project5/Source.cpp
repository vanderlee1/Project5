#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

float meanFunction(int, int,int,int);
float stdFunction(int,int,int,int, float);


int main()
{

	//input variables
	int value1;
	int value2;
	int value3;
	int value4;
	ifstream inputFileName;
	ofstream outputFileName;


	//local variables
	inputFileName.open("inMeanStd.dat");
	outputFileName.open("outMeanStd.dat");

	

	//read values
	inputFileName >> value1 >> value2 >> value3 >> value4;

	//calculate values

	outputFileName << "This is mean: "<< meanFunction(value1, value2, value3, value4) << endl;
	outputFileName << "This is standard: " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << endl;

	//output values on the screen
	cout << "This is mean:  " << meanFunction(value1, value2, value3, value4) << endl;
	cout << "This is standard:  " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << endl<<endl;


	cout << "put in 4 integers\n"; 
	cin >> value1 >> value2 >> value3 >> value4;
	outputFileName << "This is mean: " << meanFunction(value1, value2, value3, value4) << endl;
	outputFileName << "This is standard: " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << endl;
	cout << "This is mean:  " << meanFunction(value1, value2, value3, value4) << endl;
	cout << "This is standard:  " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << endl;


	inputFileName.close();
	outputFileName.close();


	return 0;
}

float meanFunction(int value1, int value2, int value3, int value4)
{
	return (float(value1 + value2 + value3 + value4) / float(4));
}

float stdFunction(int value1, int value2, int value3, int value4, float average)
{
	return sqrt((float(pow((value1 - average), 2) + pow((value2 - average), 2) + pow((value3 - average), 2)) + pow((value4 - average), 2)) / 4);
}