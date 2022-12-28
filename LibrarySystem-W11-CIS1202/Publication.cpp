#include "Publication.h"


Publication_C::Publication_C()
{
	title = "";
	publisher = "";
	price = 0;
	year = 0;
	type = PublicationType::BOOK;
	stock = 0;
}


void Publication_C::Store_Publication(string itemTitle, string itemPublisher, double itemPrice, int itemYear, PublicationType itemTypeWord, int itemStock)
{
	title = itemTitle;
	publisher = itemPublisher;
	price = itemPrice;
	year = itemYear;
	type = itemTypeWord;
	stock = itemStock;
}

void Publication_C::displayInfo()
{
	string itemTypeWord = "";
	int itemTypeNum = 0;

	if (Publication_C::type == PublicationType::BOOK)
	{
		itemTypeWord = "Book";
		itemTypeNum = 1;
	}
	else if (Publication_C::type == PublicationType::MAGAZINE)
	{
		itemTypeWord = "Magazine";
		itemTypeNum = 2;
	}
	else if (Publication_C::type == PublicationType::NEWSPAPER)
	{
		itemTypeWord = "Newspaper";
		itemTypeNum = 3;
	}
	else if (Publication_C::type == PublicationType::AUDIO)
	{
		itemTypeWord = "Audio";
		itemTypeNum = 4;
	}
	else {
		itemTypeWord = "Video";
		itemTypeNum = 5;
	}
	cout << fixed << setprecision(2);
	cout << "\nTitle: " << title << endl;
	cout << "Publisher: " << publisher << endl;
	cout << "Price: $" << price << endl;
	cout << "Year: " << year << endl;
	cout << "Type: " << itemTypeNum << endl;
	//cout << "Type: " << itemTypeWord << endl;
	cout << "Stock: " << stock << endl;

}

void Publication_C::checkOut()
{
	if (stock > 0)
	{
		stock -= 1;
		cout << "\n\nBook checked out\n";
	}
	else {
		cout << "no stock" << endl;
	}
}

void Publication_C::checkIn()
{
	stock += 1;
	cout << "\n\nBook checked in\n";
}

string Publication_C::Get_Title() const
{
	return title;
}

string Publication_C::Get_Publisher() const
{
	return publisher;
}

double Publication_C::Get_Price() const
{
	return price;
}

int Publication_C::Get_Year() const
{
	return year;
}

PublicationType Publication_C::Get_Type() const
{

	return type;
}

int Publication_C::Get_Stock()
{
	return stock;
}

void Publication_C::Set_Title(string ti)
{
	title = ti;
}

void Publication_C::Set_Publisher(string pu)
{
	publisher = pu;
}

void Publication_C::Set_Price(double pr)
{
	price = pr;
}

void Publication_C::Set_Year(int ye)
{
	year = ye;
}

void Publication_C::Set_Type(PublicationType ty)
{

	type = ty;
}
void Publication_C::Set_Stock(int st)
{
	stock = st;
}
