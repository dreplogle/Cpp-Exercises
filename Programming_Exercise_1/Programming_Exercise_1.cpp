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
	/* Doubly linked list Node */
	public:
		T data;
		Node() {
			data = NULL;
			next = NULL;
			prev = NULL;
		}
		Node(T thing) {
			data = thing;
			next = NULL;
			prev = NULL;
		}
		void setNext(Node * node) {
			next = node;
		}
		void setPrev(Node * node) {
			prev = node;
		}
		Node * getNext() {
			return next;
		}
		Node * getPrev() {
			return prev;
		}
	private:
		// next goes into newer nodes, prev goes into older nodes
		Node<T> * next;
		Node<T> * prev;
};

template <typename T>
class LinkedList {
	/* Doubly linkedlist */
	Node<T> * rootPtr;
	Node<T> * endPtr;
	public:
		LinkedList(T thing) {
			rootPtr = new Node<T>(thing);
			endPtr = rootPtr;
		}
		void add_data(T thing) {
			Node<T> * node = new Node<T>(thing);
			Node<T> * end = endPtr;
			// add node to the end of the linked list
			end->setNext(node);
            node->setPrev(end);
			endPtr = node;
		}
		/*void removeNode(T thing) {

		}*/
		void print_list() {
			Node<T> * tempPtr;
			tempPtr = rootPtr;
			do {
				cout << tempPtr->data << " and ";
				tempPtr = tempPtr->getNext();
			} while (tempPtr->getNext() != nullptr);
			cout << tempPtr->data << "\n";
			system("pause");
		}
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

void LinkedListTestbench() {
	LinkedList<int> temp(5);
	for (int i = 0; i < 5; i++) {
		int j = rand() % 100;
		cout << j << " is the number \n\n";
		temp.add_data(j);
	}
	system("pause");
	temp.print_list();
}

int main()
{
	//reverse_string();
	//LRU_cache <int> cache(1000, 5);

	LinkedListTestbench();


	return 0;
}

