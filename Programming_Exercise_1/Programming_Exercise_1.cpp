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
			next = nullptr;
			prev = nullptr;
		}
		Node(T thing) {
			data = thing;
			next = nullptr;
			prev = nullptr;
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
	public:
		LinkedList(T thing) {
			rootPtr = new Node<T>(thing);
			endPtr = rootPtr;
		}

		/* Add node to end of list, using new data */
		Node<T> * add_data(T thing) {
			Node<T> * node = new Node<T>(thing);

			// add node to the end of the linked list
			endPtr->setNext(node);
            node->setPrev(endPtr);
			endPtr = node;
			return node;
		}

		void remove_data(T data) {

		}

		/* Add existing node to end of LinkedList */
		void add_node(Node<T> * node) {
			if (node != endPtr) {
				endPtr->setNext(node);
				node->setPrev(endPtr);
				endPtr = node;
			}
		}

		/* Remove node from its place and return it safely; the return is  */
		void remove_node(Node<T> * node) {
			Node<T> * prev_node = node->getPrev();
			Node<T> * next_node = node->getNext();
			if (prev_node != nullptr) {
				prev_node->setNext(next_node);
			}
			if (next_node != nullptr) {
				next_node->setPrev(prev_node);
			}
			if (rootPtr == node) {
				rootPtr = next_node;
			}
		}

		void set_root(Node<T> * node) {
			rootPtr = node;
		}
		/* Return root pointer */
		Node<T> * return_root() {
			return rootPtr;
		}

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


		private:
			Node<T> * rootPtr;
			Node<T> * endPtr;
};

template <typename T>
class LRU_cache {
	public: 
		LRU_cache() {
			size = 100;
			thing_hash = NULL;
		}
		LRU_cache(int s, T first) {
			size = s;
			myThings = new LinkedList<T>(first);
			hash[first] = myThings->return_root();
		}
		void put_data(string key, T data) {
			if (myThings.size == LRU_SIZE) {
				/* Remove the LRU "thing" from both hash and linkedlist. Get the root, remove it from the linkedlist, set a new root, 
				then delete old root from both the hash and linkedlist and add the new data at the end. */
				Node<T> * root = myThings->return_root();
				myThings->remove_node(root);
				myThings->set_root(root->getNext());
				hash.erase(key);
				delete root;
				hash[key] = myThings->add_data(data);
			}
			else {
				/* Check if the item exists; if so, move it to the end, otherwise add it anew */
				if (hash[key]) {
					/* Move "thing" to MRU */
					Node<T> * node = hash[key];
					myThings->remove_node(node);
					myThings->add_node(node);
				}
				else {
					/* Push onto linkedlist to maintain order, and add to hash */
					hash[key] = myThings->add_data(data);
				}
			}
		}
		void get_data(T key) {
			// remove node from in place and move it to the end of the linked-list
			Node<T> * node = hash[key];
			myThings->remove_node(node);
			myThings->add_node(node);
			return node->data;
		}

	private:
		int size;
		LinkedList<T> * myThings;
		unordered_map<T, Node<T> *> hash;

		//unordered_map<string, MyThing&>
		/*MyThing put_data() {

		}
		MyThing get_data() {

		}	*/
	
};

/* Small testbench for the doubly linked list class */
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

/* Small testbench for the LRU */
void LRUTestbench() {
	LRU_cache<int> cache(1000, 5);
	cache.put_data("1", 4);
	cache.put_data("2", 3);
	cache.put_data("3", 2);
	cache.put_data("4", 1);
	cache.put_data("5", 0);
	cache.put_data("6", 3);
}


int main()
{
	//reverse_string();
	//LRU_cache <int> cache(1000, 5);
	//LinkedListTestbench();
	LRUTestbench();

	return 0;
}

