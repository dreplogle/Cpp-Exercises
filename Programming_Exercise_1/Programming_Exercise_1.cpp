// Programming_Exercise_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h";
#include <iostream>;
#include <string>;
#include <list>;
using namespace std;

int reverse_string() {
	string reversible;
	cout << "String to be reversed: ";
	getline(cin, reversible);

	int i = 0;
	int j = reversible.length() - 1;
	char temp = NULL;
	while (i < j) {
		temp = reversible[i];
		reversible[i++] = reversible[j];
		reversible[j--] = temp;
	}
	cout << "\nReversed line: " << reversible << "\n";
	system("pause");
	return 0;
}

template <typename T>
class LRU_cache {
	list<T> myThings;
	public: 
		LRU_cache(int s, T first) {
			size = s;
			myThings.push_back(first);
		}

	private:
		int size;
		
		//unordered_map<string, MyThing&>
		/*MyThing put_data() {

		}
		MyThing get_data() {

		}	*/
	
};

int main()
{
	//reverse_string();
	LRU_cache <int> cache(1000, 5);
	return 0;
}

