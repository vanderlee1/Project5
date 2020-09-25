#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

float meanFunction(int, int,int,int); //prototype for the mean functinon
float stdFunction(int,int,int,int, float); // prototype for the population standard deviation  function


int main()
{

	//input variables
	int value1;
	int value2;
	int value3;
	int value4;
	ifstream inputFileName;
	ofstream outputFileName;


	//open files
	inputFileName.open("inMeanStd.dat");
	outputFileName.open("outMeanStd.dat");

	

	//read values
	inputFileName >> value1 >> value2 >> value3 >> value4;

	//prompt for the user
	cout << "This program is going to caluculate the mean and the population standard deviation. \n";
	cout << "First, the program is going to calculate the mean and the population standard deviation of 4 integers from a document \n";
	cout << "Second, the program is gonna ask you to put in 4 integers. The program will calculate the mean and the \nstandard deviation of those integers."<< endl << endl << endl;
	
	//calculate values
	outputFileName << "This is the mean of the integers in the document: "<< meanFunction(value1, value2, value3, value4) << endl;
	outputFileName << "This is the population standard deviation of the integers in the document: " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << endl << endl<<endl;

	//output values on the screen
	cout << "This is the mean of the integers in the document:  " << meanFunction(value1, value2, value3, value4) << endl;
	cout << "This is the population standard deviation of the integers in the document:  " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << endl<<endl;

	//promt for the user
	cout << "Put in 4 integers. Afer you put in one integer you have to press enter"<< endl ; 
	cin >> value1 >> value2 >> value3 >> value4;
	
	//puts the calculated values in the document
	cout << endl;
	outputFileName << "This is the mean of the integers you filled in:  " << meanFunction(value1, value2, value3, value4) << endl; 
	outputFileName << "This is the population standard deviation of the integers you filled in: " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << endl;
	
	//Outputs the calculated values on the screen
	cout << "This is the mean of the integers you filled in: " << meanFunction(value1, value2, value3, value4)<< endl;
	cout << "This is the population standard deviation of the integers you filled in: " << stdFunction(value1, value2, value3, value4, meanFunction(value1, value2, value3, value4)) << endl;

	//close the files
	inputFileName.close();
	outputFileName.close();
	
	return 0;
}
 
float meanFunction(int value1, int value2, int value3, int value4) //Function defintion of the mean function
{
	return (float(value1 + value2 + value3 + value4) / float(4));
}

float stdFunction(int value1, int value2, int value3, int value4, float average) //Function defintion of the population standard deviation
{
	return sqrt((float(pow((value1 - average), 2) + pow((value2 - average), 2) + pow((value3 - average), 2)) + pow((value4 - average), 2)) / 4);
}