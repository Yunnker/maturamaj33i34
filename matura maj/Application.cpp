#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#define ILE_CYFR_PI 100

int digitToInt(std::string string)
{
	
	return int(string[0] - 48);
}

int main()
{

	std::fstream file;
	file.open("pi_przyklad.txt");
	if (!file.good())
	{
		std::cout << "Problem z otwarciem pliku" << std::endl;
		return 1;
	}

	//vector
	std::vector<std::string> Ciagi;
	std::vector<int> Ciag;

	//int
	int tablica[ILE_CYFR_PI];
	int ileCiagow = 0;
	int poprzednia = 0;

	//bool
	bool rise = true;
	bool first = true;

	//strings
	std::string ciag;
	std::string linia;

	for (int i = 0; i < ILE_CYFR_PI; i++)
	{	
		std::getline(file, linia);
		if (rise)
		{
			if (digitToInt(linia) > poprzednia)
			{
				if (first)
				{
					ciag.push_back(poprzednia);
					first = false;
				}					
				ciag.push_back(digitToInt(linia));
				poprzednia = digitToInt(linia);
			}
			else if(digitToInt(linia) == poprzednia)
			{
				if (first)
				{
					ciag.push_back(poprzednia + 48);
					first = false;
				}
				ciag.push_back(digitToInt(linia));
				rise = false;
			}
			else
			{
				poprzednia = digitToInt(linia);
				ciag.erase();
				first = true;
				rise = true;
			}
		}
		else
		{
			if (digitToInt(linia) > poprzednia)
			{
				if (first)
				{
					ciag.push_back(poprzednia + 48);
					first = false;
				}
				ciag.push_back(digitToInt(linia));
				poprzednia = digitToInt(linia);
			}
			else if (digitToInt(linia) == poprzednia)
			{
				if (first)
				{
					ciag.push_back(poprzednia);
					first = false;
				}
				ciag += linia[0];
			}
			else
			{
				poprzednia = digitToInt(linia);
				Ciagi.push_back(ciag);
				ciag = "";
				first = true;
				rise = true;
				ileCiagow++;
			}
		}
	}

	std::cout << ileCiagow << std::endl;
	for (auto& elem : Ciagi)
	{
		std::cout << elem << std::endl;
	}


}