#include <iostream>
#include <vector>
#include <string>   
#include <array>
#include <list>
#include <map>

using namespace std;

int main()
{
	array<string, 7> days = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
   
	for (int i = 0; i < days.size(); i++)
	{
		cout << days[i] << endl;
	}
	cout << "------------------------" << endl;
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	cout << numbers[0] << endl;
	cout << numbers[1] << endl;
	numbers.pop_back();
	cout << numbers[0] << endl;
	cout << "------------------------" << endl;
	list<string> fruits = { "Apple", "Banana", "Orange" };
	fruits.push_front("Blueberry");
	fruits.remove("Orange");
	for (const auto& fruit : fruits)
	{
		cout << fruit << endl;
	}
	cout << "------------------------" << endl;
	map<string,int>stock;
	stock["Apple"] = 10;
	stock["Banana"] = 5;
	stock["Orange"] = 8;
	for (const auto& item : stock)
	{
		cout << item.first << ": " << item.second << endl;
	}
}

