/** LinkedList ADT header file.
@file LinkedList.hh
@author Eugene Nelson
@date 9/17/17
@version 1.0 (Eugene Nelson 9/17/17)

Header file for the LinkedList ADT. Describes the memeber functions of the LinkedList ADT and their paramaters/functions.*/

#ifndef linked_list_h
#define linked_list_h

#include <iostream>
#include "Node.hh"

template <class ItemType>
class LinkedList
{
	public:
		/** Default constructor, copy constructor, and deconstructor.*/
		LinkedList()	{ apHead = NULL; aItemCount = 0; }
		LinkedList(const LinkedList<ItemType>& copyList);
		~LinkedList();

	    /** Checks to see if the list is empty.
        @return True if list is empty. False otherwise.*/
        bool IsEmpty() const { if(aItemCount <= 0) return true; return false; }
        
        /** Gets the number of entries currently in the list.
        @return The integer number of entries in the list.*/
        int GetLenth() { return aItemCount; }
        
        /** Insert entry into list at the a given position.
        @pre None.
        @post New entry will be inserted into the list at the given position, moving the current entry at that position and all following entries forward in the list.
        @param newPosition The position where the new entry will be inserted.
        @param newEntry The new entry to be inserted into the list.
        @return True if entry was successfully added. False otherwise.*/
        bool InsertEntry(int newPosition, const ItemType& newEntry);
        
        /** Removes the entry at the given position from the list.
        @pre None.
        @post Removes node at given position and relinks the list. If the entry to be removed was the first entry, then the head pointer is adjusted.
        @param position The position in the list where the removal will occur.
        @return True if the removal was successful. False otherwise.*/
        bool RemoveEntry(int position);
        
        /** Removes all of the entries in the list.
        @post The list will be emptied and private values are adjusted as necessary.*/
        void Clear();
        
        /** Gets value of entry at a given position in the list.
        @pre 0 < position <= getLength()
        @post The entry at postition will be returned.
        @param position The position of the entry to be returned.
        @return The entry at the given position.*/
        ItemType GetEntry(int position);

        /** Replaces an entry at given position.
        @pre 0 < position <= getLength():
        @post The entry at the given position will be replaced.
        @param position The position of the element to be replaced.
        @param newEntry The replacement entry.
        @return True if the entry has been replaced. False otherwise.*/
        bool SetEntry(int position, const ItemType& newEntry);

	private:
	    Node<ItemType>* 	apHead;
	    int 				aItemCount;
};
#include "LinkedList.cc"

#endif