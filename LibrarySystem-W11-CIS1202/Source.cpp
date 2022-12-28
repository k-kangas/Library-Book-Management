/*
* Kurt Kangas
* CIS 1202 C++ Programming II
* Week 13 Project
* Library Book Management System
*/

#include "Publication.h"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void getPublications(Publication_C[], const int SZ, int& counter);
void showPublications(Publication_C[], int);
void showTitles(Publication_C[], int);
int findPublication(Publication_C[], int, string);
int getMenuChoice();

int main()
{
	string title = "";
	string publisher = "";
	double price = 0;
	int year = 0;
	PublicationType type = PublicationType::BOOK;
	int stock = 0;
	int input = 0;


	const int SIZE = 20;
	Publication_C pub[SIZE];
	int counter;
	int count = 0;
	int choice = 0;

	cout << "\tLibrary Book Management System";

	getPublications(pub, SIZE, counter);

	choice = getMenuChoice();
	do
	{
		switch (choice)
		{
		case 1:
			cout << "\nDisplaying all publications... ";
			showPublications(pub, counter);
			choice = getMenuChoice();
			break;
		case 2:
			cout << "\nDisplay publication titles... ";
			showTitles(pub, counter);
			choice = getMenuChoice();
			break;
		case 3:
			cout << "\nFinding a publication... ";
			count = findPublication(pub, counter, title);
			choice = getMenuChoice();
			break;
		case 4:

			cout << "Book " << pub[count].Get_Title() << endl;
			cout << "In stock: " << pub[count].Get_Stock();
			pub[count].checkOut();
			cout << "Now in stock: " << pub[count].Get_Stock();
			cout << endl;
			choice = getMenuChoice();
			break;
		case 5:
			cout << "Book " << pub[count].Get_Title() << endl;
			cout << "In stock: " << pub[count].Get_Stock();
			pub[count].checkIn();
			cout << "Now in stock: " << pub[count].Get_Stock();
			cout << endl;
			choice = getMenuChoice();
			break;
		case 6:
			cout << "\nExiting the program...";
			system("pause");
			return 0;
		}
	} while (choice != 6);


	cout << endl << endl;
	system("pause");
	return 0;
}
void getPublications(Publication_C pub[], const int SZ, int& counter)
{
	string title = "";
	string publisher = "";
	double price = 0;
	int year = 0;
	PublicationType type = PublicationType::BOOK;
	int stock = 0;
	int input = 0;
	counter = 0;


	fstream myFile;
	myFile.open("11publications.txt", ios::in);
	if (!myFile)
	{
		cout << "\nInvalid; cannot open file." << endl;
		exit(0);
	}
	while (myFile)
	{
		for (int i = 0; i < SZ; i++)
		{
			getline(myFile, title);
			myFile.clear();
			getline(myFile, publisher);
			myFile.clear();
			myFile >> price;
			myFile >> year;
			myFile >> input;
			myFile >> stock;

			if (input == 1)
			{
				PublicationType type = PublicationType::BOOK;
			}
			else if (input == 2)
			{
				PublicationType type = PublicationType::MAGAZINE;
			}
			else if (input == 3)
			{
				PublicationType type = PublicationType::MAGAZINE;
			}
			else if (input == 4)
			{
				PublicationType type = PublicationType::AUDIO;
			}
			else {
				PublicationType type = PublicationType::VIDEO;
			}
			pub[i].Set_Title(title);
			pub[i].Set_Publisher(publisher);
			pub[i].Set_Price(price);
			pub[i].Set_Year(year);
			pub[i].Set_Type(type);
			pub[i].Set_Stock(stock);

			pub[i].Store_Publication(title, publisher, price, year, type, stock);

			counter++;

			if (myFile.eof())
			{
				i = SZ;
			}
			myFile.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	myFile.close();
}
void showPublications(Publication_C pub[], int counter)
{
	cout << setprecision(2) << fixed;
	for (int i = 0; i < counter; i++)
	{
		cout << "\nTitle: " << pub[i].Get_Title();
		cout << "\nPublisher: " << pub[i].Get_Publisher();
		cout << "\nPrice: " << pub[i].Get_Price();
		cout << "\nYear: " << pub[i].Get_Year();
		//cout << "Type: " << pub[i].Get_Type();
		cout << "\nStock: " << pub[i].Get_Stock();
	}
}
int getMenuChoice()
{
	bool notValid = true;
	while (notValid)
	{
		notValid = false;
		int choice = 0;

		cout << "\n1. Display all publications";
		cout << "\n2. Display publication titles";
		cout << "\n3. Find a publication";
		cout << "\n4. Check out";
		cout << "\n5. Check in";
		cout << "\n6. Exit";
		cout << endl;
		cin >> choice;
		if (choice < 0 || choice > 6)
		{
			cout << "Not a valid choice. Try again.\n";
			notValid = true;
		}
		else {
			return choice;
		}
	}

}
int findPublication(Publication_C pub[], int counter, string title)
{
	int count = 0;
	cout << "What is the name of the title you are looking for?> ";
	cin.ignore();
	getline(cin, title);
	for (int i = 0; i < counter; i++)
	{
		if (pub[i].Get_Title() == title)
		{
			cout << "Element found at index " << i;
			count = i;
		}
		if (i == counter)
		{
			cout << "Element not present in array\n";
			count = 0;
		}
	}
	counter = count;
	return counter;
}
void showTitles(Publication_C pub[], int counter)
{
	for (int i = 0; i < counter; i++)
	{
		cout << "\nTitle: " << pub[i].Get_Title();
	}
}