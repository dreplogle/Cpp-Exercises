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
	T data;
	public:
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
		void setNext(Node node) {
			next = &node;
		}
		void setPrev(Node node) {
			prev = &node;
		}
		Node getNext() {
			return next;
		}
		Node getPrev() {
			return prev;
		}
	private:
		// next goes into newer nodes, prev goes into older nodes
		Node * next;
		Node * prev;
};

template <typename T>
class LinkedList {
	/* Doubly linkedlist */
	Node<T> root;
	Node<T> end;
	public:
		LinkedList(T thing) {
			Node<T> root(thing);
			end = root;
		}
		void add_data(T thing) {
			Node<T> node(thing);
			// add node to the end of the linked list
			end.setNext(node);
			node.setPrev(end);
			end = node;
		}
		/*void removeNode(T thing) {

		}*/
		void print_list() {
			Node temp;
			temp = root;
			do {
				cout << temp.data + " ";
			} while (temp != NULL);
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
	LinkedList<int> temp(1);
	temp.add_data(5);
	//Node<int> temp(5);

}

int main()
{
	//reverse_string();
	//LRU_cache <int> cache(1000, 5);




	return 0;
}

