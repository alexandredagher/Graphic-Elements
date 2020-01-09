/*************************************************************************************************************************************************************************************************
Filename:							RasterGraphic.cpp
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
Function name:							InsertGraphicElement
Purpose:								Adding elements to the raster Graphic
Function In parameters:					None
Function Out parameters:				None
Version :								1
Author/Student Name:					Alexandre Dagher
************************************************************************************************************************************************************************************************/
void RasterGraphic::InsertGraphicElement()
{
	string graphicElementfileName;
	char imageName[256];
	int numbOfImages, x, y, duration, count = 0, i = 0, position, geCount = 0, numbOfElements = 0;
	vector<Image> tempImages;

	cout << "Insert a GraphicElement in the RasterGraphic\n" << "Pease enter the GraphicElement filename: ";
	cin >> graphicElementfileName;
	cout << "Entering the GraphicElement Images(the sets of dimensions and durations)\n" << "Please enter the number of Images: ";
	cin >> numbOfImages;

	while (count < numbOfImages) {

		cout << "Please enter pixel x for Image #" << count << " pixel_x: ";
		cin >> x;

		while (!cin)
		{
			cout << "Invalid pixel x value, Please enter pixel x for Image #" << count << " pixel_x: ";
			cin.clear();
			cin.ignore();
			cin >> x;
		}

		cout << "Please enter pixel y for Image #" << count << " pixel_y: ";
		cin >> y;

		while (!cin)
		{
			cout << "Invalid pixel y value, Please enter pixel y for Image #" << count << " pixel_y: ";
			cin.clear();
			cin.ignore();
			cin >> y;
		}

		cout << "Please enter the duration sec for this Image: ";
		cin >> duration;

		while (!cin)
		{
			cout << "Invalid duration value, please enter the duration sec for this Image: ";
			cin.clear();
			cin.ignore();
			cin >> duration;
		}

		cout << "Please enter the name for this Image: ";		
		cin >> imageName;
		
		Image nImage(x, y, duration, imageName);
		tempImages.push_back(nImage);
		count++;
	}

	GraphicElement newElement(graphicElementfileName, tempImages);

	forward_list<GraphicElement>::iterator checkIt;
	for (checkIt = GraphicElements.begin(); checkIt != GraphicElements.end(); checkIt++)
		geCount++;


	if (GraphicElements.empty() == true) {
		cout << "This is the first GraphicElement in the list" << endl << endl;
		GraphicElements.push_front(newElement);
	}
	else if (geCount == 1) {
		GraphicElements.insert_after(GraphicElements.begin(), newElement);
		cout << endl;
	}
	else {

		cout << "There are " << geCount << " GraphicElement(s) in the list" << endl;
		
		cout << "Please specify the posistion between 0 and " << (geCount-1) << " to insert after: ";
		cin >> position;

		while (position < 0 || position > geCount) {
			cout << "That value is not is not a possible index" << endl << "Please specify the posistion between 0 and " << geCount << " to insert after: ";
			cin >> position;
		}

		auto beginIt = GraphicElements.begin();

		while (i < position) {
			beginIt++;
			i++;
			numbOfElements++;
		}

		GraphicElements.emplace_after(beginIt, newElement);

		cout << endl;
	}
}


/*************************************************************************************************************************************************************************************************
Function name:							Delete Graphic Element
Purpose:								Deleting Graphic from head of RasterGraphic
Function In parameters:					None
Function Out parameters:				None
Version :								1
Author/Student Name:					Alexandre Dagher
************************************************************************************************************************************************************************************************/
void RasterGraphic::DeleteGraphicElement() {

	cout << "Delete the first GraphicElement from the RasterGraphic" << endl;

	if (GraphicElements.empty()) {
		cout << "There are no Graphic Elements in the list" << endl << endl;
		return;
	}
	else {
		cout << "GraphicElement deleted" << endl << endl;
		GraphicElements.pop_front();
	}
}

/*************************************************************************************************************************************************************************************************
Function name:							operator<<
Purpose:								Printing Elements
Function In parameters:					ostream &os, RasterGraphic &image
Function Out parameters:				ostream
Version :								1
Author/Student Name:					Alexandre Dagher
************************************************************************************************************************************************************************************************/
ostream & operator<<(ostream &os, RasterGraphic &image)
{
	int graphicCount = 0;
	forward_list<GraphicElement>::iterator IFL;

	cout << "RasterGraphic A" << endl << "Run the RasterGraphic" << endl;

	for (IFL = image.GraphicElements.begin(); IFL != image.GraphicElements.end(); IFL++){
		cout << "Graphic Element #" << graphicCount << ":" << endl;
		cout << *IFL;
		graphicCount++;
	}
	cout << "\nOutput finished" << endl;
	return os;
}

/*************************************************************************************************************************************************************************************************
Function name:							operator+=
Purpose:								Adding a element to itself
Function In parameters:					Graphicelement &image
Function Out parameters:				None
Version :								1
Author/Student Name:					Alexandre Dagher
************************************************************************************************************************************************************************************************/
void RasterGraphic::operator+=(GraphicElement& image) {
	GraphicElements.push_front(image);
}

/*************************************************************************************************************************************************************************************************
Function name:							operator[]
Purpose:								Retrieving a element
Function In parameters:					unsigned int position
Function Out parameters:				Graphicelement&
Version :								1
Author/Student Name:					Alexandre Dagher
************************************************************************************************************************************************************************************************/
GraphicElement& RasterGraphic::operator[](unsigned int position) {

	int i = 0;
	forward_list<GraphicElement>::iterator IFL = GraphicElements.begin();

	while (i < position) {
		IFL++;
		i++;
	}
	return *IFL;
}
