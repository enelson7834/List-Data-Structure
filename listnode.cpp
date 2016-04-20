#include <iostream>
using namespace std;


Node::Node( int value, Node* nxt )
{
    this->data = value;
    this->next = nxt;
}

ListNode::ListNode( int a )
{
    this->head = this->cursor = NULL;
}

ListNode::ListNode( const ListNode& copy )
{

}

ListNode::~ListNode( )
{

}

bool ListNode::insertAfter( int a )
{

}

bool insertBefore(int);
bool get(int&) const;
bool remove(int&);

void clear();

bool goToBeginning( )
{
	if( this->isEmpty( ) )
	{
		return false;
	}
	else
	{
		this->cursor = this->head;
	}
}

bool goToEnd();

bool goToNext();
bool goToPrior();

bool isEmpty() const;
bool isFull() const;

ListNode& operator = (const ListNode&);

friend ostream& operator << (ostream&, const ListNode&);

private:
    Node *head;
    Node *cursor;
};
