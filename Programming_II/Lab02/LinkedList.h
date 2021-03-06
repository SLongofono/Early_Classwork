/*	Name: Stephen Longofono - 2776831
*	File name: LinkedList.h
*	Date: 02-04-2015
*	Description: This class is in control of generating a list composed of Node objects and
*	performing operations on said list.  Note: everything comes down to m_size being accurate and the last
*	Node in any list pointing to nullptr.  If these two conditions are not met, all operations will fail.
*/

#ifndef LINKED_H
#define LINKED_H

class LinkedList{

	public:

		/* This is a constructor
		* @pre - none
		* @post - creates a LinkedList in stack memory, initializes m_size to zero and m_next to nullptr
		* @return - none
		*/
		LinkedList();

		/* This is a deconstructor - don't do anything silly like try method calls after it executes.
		* @pre - A LinkedList exists with an accurate size and the last Node pointing to nullptr.
		* 	The coolest part about this is that we already have the code written to do the 
		* 	housekeeping for us.  It's a one-liner
		* @post - calls the removeFront() method until the list is empty (false return). 
		* 	sets m_front to nullptr.
		* @return - none
		*/
		~LinkedList();
		
		/* This is a getter of sorts to determine if a list is empty
		* @pre - This function depends entirely on the size of the LinkedList.  If the size is not
		*	accurate then it will not behave correctly.
		* @post - checks the size of this LinkedList
		* @return - true if m_size is zero, false otherwise
		*/
		bool isEmpty() const;
		
		/* This is a getter for the number of Nodes in a LinkedList
		* @pre - Assumes that size is accurate
		* @post - Accesses m_size
		* @return - Returns the integer m_size of this LinkedList
		*/
		int size() const;
		
		/* This creates a Node object and attaches it to the front of a list.
		* @pre - Assumes a LinkedList exists, with an accurate size and properly initialized if the LinkedList
		* is empty
		* @post - Creates a Node, sets the Node's m_value to the value argument, sets the Node's pointer to
		* m_front, sets m_front to point to the new node, increments the size of the LinkedList.
		* @return - void
		*/
		void addFront(int value);

		/* This creates a Node object and attaches it to the back of a list.
		* @pre - Assumes a LinkedList exists, with only the end Node's pointer set to null.  Assumes
		* 	The Node has m_next initialized to nullptr
		* @post - Creates a Node, sets the Node's m_value to the value argument, finds the end of the list by
		* checking the Node pointers, sets the last node to point at the new Node, increments the size.
		* @return - void
		*/
		void addBack(int value);
		
		/* This removes the front Node of the list
		* @pre - Assumes the m_front pointer is pointing at the correct Node
		* @post - Assigns a temp. pointer to point at the front node's m_next.  Changes m_front to
		*	 point to m_next of the front node.  Deletes the original front Node the m_front is
		*	 looking at.  Assigns m_front to look at the new front where n is looking. Decrements
		*	 the size.
		* @return - true if node was removed, false if the LinkedList is empty
		*/
		bool removeFront();
		
		/* This removes the rear Node of the list
		* @pre - Assumes that only the rear node has m_next set to nullptr.
		* @post - Finds the end of the list by checking the Node pointers, while keeping a temporary
		*	 pointer set to the node before the one being checked.  Upon finding the end, the end
		*	 Node is deleted, and m_next of the Node before it is set to nullptr.  Decrements size.
		* @return - true if node was removed, false if the LinkedList is empty.
		*/
		bool removeBack();
	
		/* This is a getter of sorts that prints the value stored at each Node
		* @pre - A linked list exists with accurate m_size value
		* @post - Checks if the list is empty, otherwise prints each Node's m_value
		* @return - if the list is empty, prints "List Empty", otherwise prints the values.
		*/
		void printList() const;

		/* This is a getter of sorts that determines if the list has a Node with the value passed
		* @pre - A linked list exists with accurate size and initialized values
		* @post - Checks if the list is empty, otherwise steps through and compares each node's m_value to the
		*	 value passed in.
		* @return - If the list has a Node with the given value, returns true, otherwise returns false.
		*/
		bool search(int value) const;
		

	private:

		Node* m_front;	// leading object in list - crucial that this remains valid
		int m_size;	// size of list - crucial that this remains valid for nearly all methods

		/* This method is a minion that finds the rear entry of the list.
		* ::::NOTE::::: if this returns the value of nullptr, something is wrong with the m_size of the 
		* LinkedList.  This method is used to compare the first and last Nodes, so if it returns nullptr
		* (indicating failure), then the isEmpty method got a bad value for m_size
		* @pre - Assumes a LinkedList exists, with an accurate size
		* @post - checks to see if the LinkedList is empty. If not, steps through each Node until it
		*	 finds with m_next pointing to nullptr (this is the last Node in the list).  
		* @return - Returns nullptr if the list is empty or by default, otherwise returns a pointer to
		* the last Node
		*/
		Node* getBack() const;

};//end class


#endif
