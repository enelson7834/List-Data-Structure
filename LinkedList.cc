/** LinkedList ADT implamentation file.
@file LinkedList.cc
@author Eugene Nelson
@date 9/17/17
@version 1.0 (Eugene Nelson 9/17/17)

Implamentation file for the LinkedList ADT. Defines the memeber functions of the LinkedList ADT.*/

#include "LinkedList.hh"
#include <iostream>

template <class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& copyList)
{
        for(int position = 0; position < copyList->aItemCount; ++position)
        {
                this->InsertEntry(position, copyList->GetEntry(position));
        }
}
template <class ItemType>
LinkedList<ItemType>::~LinkedList()     { this->Clear(); }

template <class ItemType>
bool LinkedList<ItemType>::InsertEntry(int newPosition, 
                                        const ItemType& newEntry)
{
        if(newPosition > aItemCount || newPosition < 0) return false;

        if(this->IsEmpty())
        {
                apHead = new Node<ItemType>(newEntry, NULL);
                ++aItemCount;
                return true;
        }

        Node<ItemType>* cursor = apHead;
        for(int i = 0; i < newPosition - 1; ++i)
        {
                cursor = cursor->GetNext();
        }

        Node<ItemType>* temp = new Node<ItemType>(newEntry, cursor->GetNext());
        cursor->SetNext(temp);
        ++aItemCount;

        return true;
}

template <class ItemType>
bool LinkedList<ItemType>::RemoveEntry(int position)
{
        if(this->IsEmpty()) return false;
        if(position >= aItemCount || position < 0) return false;

        Node<ItemType>* cursor = apHead;

        if(position == 0)
        {
                apHead = cursor->GetNext();
                delete cursor;
                --aItemCount;
                return true;
        }

        for(int i = 0; i < position - 1; ++i)
        {
                cursor = cursor->GetNext();
        }

        Node<ItemType>* temp = cursor->GetNext();

        cursor->SetNext(temp->GetNext());
        delete temp;
        --aItemCount;
        temp = NULL;
        cursor = NULL;
        return true;
}

template <class ItemType>
void LinkedList<ItemType>::Clear()
{
        while(!this->IsEmpty())
        {
                this->RemoveEntry(0);
        }
}

template <class ItemType>
ItemType LinkedList<ItemType>::GetEntry(int position)
{
        if(this->IsEmpty()) return ItemType();
        if(position >= aItemCount || position < 0) return ItemType();
        
        Node<ItemType>* cursor = apHead;
        for(int i = 0; i < position; ++i)
        {
                cursor = cursor->GetNext();
        }

        return cursor->GetEntry();
}

template <class ItemType>
bool LinkedList<ItemType>::SetEntry(int position, const ItemType& newEntry)
{
        if(this->IsEmpty()) return false;
        if(position >= aItemCount || position < 0) return false;
        
        Node<ItemType>* cursor = apHead;
        for(int i = 0; i < position; ++i)
        {
                cursor = cursor->GetNext();
        }

        cursor->SetEntry(newEntry);

        return true;
}