#ifndef LINK_LIST
#define LINK_LIST

#include <iostream>
using namespace std;

template<typename T>
struct Int_Node
{
	T value;
	Int_Node<T> *pre;
	Int_Node<T> *next;

	Int_Node();
	Int_Node(T);
};

template<typename T>
class Link_List
{
	// friend ostream &operator<<(ostream &, const Link_List<T> &);  	// print all integers in the list
	// friend istream &operator>>(istream &, Link_List<T> &);			// input a value at the back of the list, like insert_node(val);

public:
	/*----- construct &destruct -----*/
	Link_List();										// default constructor
	Link_List(const Link_List<T> &);						// copy constructor
	~Link_List();

	/*----- function -----*/
	int getSize() const;

	const Link_List<T> &operator=(const Link_List<T> &);		// assignment operator
	bool operator==(const Link_List<T> &) const;			// equality operator
	bool operator!=(const Link_List<T> &right) const		// inequality operator
	{
		return !(*this == right);
	}

	T &operator[](int index);							// subscript operator for non-const objects
	T operator[](int index) const;					// subscript operator for const objects

	bool insert_node(T value);						// insert an integer at the back of link list
	bool insert_node(int index, T value);				// insert an integer after the i_th position
	bool delete_node();									// delete the last node
	bool delete_node(int index);						// delete the i_th node

	// bool clear_list();

private:
	int size;
	Int_Node<T> *head, *tail;								// pointer to the first and the last element of Link_List
};

#include "Link_List.cpp"
#endif // LINK_LIST
