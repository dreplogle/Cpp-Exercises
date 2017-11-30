// Programming_Exercise_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h";
#include <iostream>;
#include <string>;
#include <list>;
#include <unordered_map>;
#define LRU_SIZE 1000
using namespace std;

int reverse_string() {
	string reversible;
	cout << "String to be reversed: ";
	getline(cin, reversible);

	int i = 0;
	int j = int(reversible.length() - 1);
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

/* Also need to make a linkedlist class as std::list is not robust enough */
template <typename T>
class Node {
	/* Singly linked list */
	Node * next;
	T data;
	public:
		Node(T thing, Node node) {
			data = thing;
			next = node&;
		}
};

template <typename T>
class LinkedList {
	
};

template <typename T>
class LRU_cache {
	list<T> myThings;
	unordered_map<T, int> thing_hash;
	public: 
		LRU_cache(int s, T first) {
			size = s;
			myThings.push_back(first);
		}
		void put_data(T data) {
			if (myThings.size == LRU_SIZE) {
				// Remove the LRU "thing" from both hash and linkedlist
			}
			else {
				/* Push onto linkedlist to maintain order, and add to hash */
				myThings.push_back(data);
			}
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

