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


class LRU_cache {
	//int size;
	public: 
		LRU_cache(int s) {
			size = s;
		}

	private:
		int size;
		template <class MyThing> 
		list<MyThing> myThings;
		//unordered_map<string, MyThing&>
		/*MyThing put_data() {

		}
		MyThing get_data() {

		}	*/
	
};

int main()
{
	//reverse_string();
	LRU_cache* cache = new LRU_cache(1000);
	return 0;
}

