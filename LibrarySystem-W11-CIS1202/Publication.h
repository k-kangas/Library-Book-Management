#ifndef Publication_H_
#define Publication_H_

#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

enum class PublicationType { BOOK, MAGAZINE, NEWSPAPER, AUDIO, VIDEO };


class Publication_C
{
private:
	string title;
	string publisher;
	double price;
	int year;
	PublicationType type;
	int stock;
	static float totalStock;

public:
	Publication_C();


	void Store_Publication(string itemTitle, string itemPublisher, double itemPrice,
		int itemYear, PublicationType itemType, int itemStock);		//Store the parameters in the Publication member variables.
	void displayInfo();																	//Display the contents of the Publication member variables.
	void checkOut();																	//Subtract 1 from stock, testing that the stock is not zero, and display an appropriate “check out” or “no stock” message.
	void checkIn();																		//Add 1 to the stock and display an appropriate “check in” message.

	string Get_Title() const;															// Getters member functions for the 6 variables.
	string Get_Publisher() const;
	double Get_Price() const;
	int Get_Year() const;
	PublicationType Get_Type() const;
	int Get_Stock();

	void Set_Title(string);															// Setters member functions for the 6 variables.
	void Set_Publisher(string);
	void Set_Price(double);
	void Set_Year(int);
	void Set_Type(PublicationType);
	void Set_Stock(int);




};
#endif

