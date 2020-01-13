/*************************************************************************************************************************************************************************************************
Filename:							Image.cpp
Version:							1
Author/Student Name:				Alexandre Dagher
Student Number:						040868750
Course Name and Number:				C++ CST8219 300
Lab Section:						301
Assignemnt Number:					Assignment 2
Assignment Name:					RasterGraphic in C++ using Container Classes and Overloaded Operators
Due Date:							November 10th @ 11:59
Submission Date:					November 10th
Professors Name:					Andrew Tyler
List of source files:				GraphicElement.cpp RasterGraphic.cpp Image.cpp
Purpose:							Create a console applicaion that holds Graphic elements using container Classes and Uses Overloaded Operators to manipulate Elements
**************************************************************************************************************************************************************************************************/
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <forward_list>
using namespace std;
#include "Image.h"
#include "GraphicElement.h"
#include "RasterGraphic.h"

/*************************************************************************************************************************************************************************************************
Function name:							Image() Constructor
Purpose:								Creating a Image
Function In parameters:					int x, int y, int duration, char* name
Function Out parameters:				Image object
Version :								1
Author/Student Name:					Alexandre Dagher
************************************************************************************************************************************************************************************************/
Image::Image(int x, int y, int duration, char * name) :pixel_x(x), pixel_y(y), duration(duration){
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name)+1 , name);
}

/*************************************************************************************************************************************************************************************************
Function name:							Image() Copy Constructor
Purpose:								Copying a Image object
Function In parameters:					const Image &image
Function Out parameters:				Image object
Version :								1
Author/Student Name:					Alexandre Dagher
************************************************************************************************************************************************************************************************/
Image::Image(const Image &image) : pixel_x(image.pixel_x), pixel_y(image.pixel_y), duration(image.duration){
	name = new char[strlen(image.name) + 1];
	strcpy_s(name, strlen(image.name)+1, image.name);
}

/*************************************************************************************************************************************************************************************************
Function name:							Image() Destructor
Purpose:								Deleting name data memeber
Function In parameters:					None
Function Out parameters:				Image object
Version :								1
Author/Student Name:					Alexandre Dagher
************************************************************************************************************************************************************************************************/
Image::~Image(){
	delete[] name;
}

/*************************************************************************************************************************************************************************************************
Function name:							operator<<
Purpose:								overloaded operator for printing objects
Function In parameters:					ostream &os, Image &image
Function Out parameters:				osteam object
Version :								1
Author/Student Name:					Alexandre Dagher
************************************************************************************************************************************************************************************************/
ostream & operator<<(ostream &os, Image &image)
{
	time_t startsec, oldsec = 0, newsec = 0;
	startsec = oldsec = time(NULL);

	cout << "name = " << image.name << "; " << "pixel_x = " << image.pixel_x << "; " << "pixel_y = " << image.pixel_y << "; " << "duration = " << image.duration << endl << "\tCounting the seconds for this image: ";

	while (newsec - startsec < image.duration){
		newsec = time(NULL);
		if (newsec > oldsec){
			cout << newsec - startsec << ", ";
			oldsec = newsec;
		}
	}
	cout << endl;
	return os;
}
