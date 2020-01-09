/*************************************************************************************************************************************************************************************************
Filename:							GraphicElement.cpp
Version:							1
Author/Student Name:				Alexandre Dagher
Student Number:						040868750
Course Name and Number:				C++ CST8219 300
Lab Section:						301
Assignemnt Number:					Assignment 2
Assignment Name:					RasterGraphic in C++ using Container Classes and Overloaded Operators
Due Date:							November 10th @ 11:59pm
Submission Date:					November 10th
Professors Name:					Andrew Tyler
List of source files:				GraphicElement.cpp RasterGraphic.cpp Image.cpp
Purpose:							Create a console applicaion that holds Graphic elements using container Classes and Uses Overloaded Operators to manipulate Elements
**************************************************************************************************************************************************************************************************/
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;
#include "Image.h"
#include "GraphicElement.h"
#include "RasterGraphic.h"

/*************************************************************************************************************************************************************************************************
Function name:							operator<<
Purpose:								overloaded operator for printing objects
Function In parameters:					ostream &os, GraphicElement &image
Function Out parameters:				osteam object
Version :								1
Author/Student Name:					Alexandre Dagher
************************************************************************************************************************************************************************************************/
ostream & operator<<(ostream &os, GraphicElement &image){
	
	for (int i = 0; i < image.Images.size(); i++) {
		if (i == 0)
			cout << "\tfileName = " << image.fileName << endl;
		cout << "\tImage #" << i << ":\t" << image.Images[i];
	}
	return os;
}

/*************************************************************************************************************************************************************************************************
Function name:							operator+
Purpose:								overloaded operator for printing objects
Function In parameters:					GraphicElement &image
Function Out parameters:				GraphicElement
Version :								1
Author/Student Name:					Alexandre Dagher
************************************************************************************************************************************************************************************************/
GraphicElement GraphicElement::operator+(GraphicElement &image)
{
	vector<Image> tempImages;

	for (int i = 0; i < Images.size(); i++) 
		tempImages.push_back(Images[i]);

	for (int i = 0; i < image.Images.size(); i++)
		tempImages.push_back(image.Images[i]);

	return GraphicElement(fileName+"_"+image.fileName, tempImages);
}
