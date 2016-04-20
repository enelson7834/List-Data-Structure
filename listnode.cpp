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
	Node* temp = new Node( a, NULL );

	if( this->isEmpty( ) )
	{
		this->head = this->cursor = temp;

		return true;
	}
	else
	{
		temp->next = this->cursor->next;

		this->cursor->next = temp;
		this->cursor = temp;

		return true;
	}
}

bool ListNode::insertBefore( int a )
{
	Node* temp = new Node( a, this->cursor );

	if( this->isEmpty( ) )
	{
		this->head = this->cursor = temp;
		return true;
	}
	else
	{
		temp = this->cursor->data;

		this->cursor->data = a;
		if( this->cursor == this->head )
		{
			this->head = temp;
		}

		this->cursor = temp;

		return true;
	}

}

bool ListNode::get( int& a ) const
{
	if( this->isEmpty( ) )
	{
		return false;
	}
	else
	{
		a = this->cursor->data;
		return true;
	}
}

bool ListNode::remove( int& a )
{
	if( this->isEmpty( ) )
	{
		return false;
	}
	else
	{
		a = this->cursor->data;

		Node* temp1 = this->cursor->next;
		Node* temp2 = this->cursor;
		this->goToPrior( );

		delete temp2;
		temp2 = NULL;

		this->cursor->next = temp1;
		temp1 = NULL;

		if( this->cursor->next == NULL )
		{
			this->cursor = this->head;
		}
		else
		{
			this->cursor = this->cursor->next;
		}

		return true;
	}
}

void ListNode::clear();

bool ListNode::goToBeginning( )
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

bool ListNode::goToEnd( )
{
	if( this->isEmpty( ) )
	{
		return false;
	}
	else
	{
		while( this->cursor->next != NULL )
			this->cursor = this->cursor->next;
		return true;
	}
}

bool ListNode::goToNext( )
{
	if( this->isEmpty( ) )
	{
		return false;
	}
	else if( this->cursor->next == NULL )
	{
		return false;
	}
	else
	{
		this->cursor = this->cursor->next;
		return true;
	}
}

bool ListNode::goToPrior( )
{
	if( this->isEmpty( ) )
	{
		return false;
	}
	else if( this->cursor == this->head )
	{
		return false;
	}
	else
	{
		Node* temp = this->head;
		while( temp->next != this->cursor )
			temp = temp->next;

		this->cursor = temp;

		return true;
	}
}

bool ListNode::isEmpty( ) const
{
	if( this->head == NULL && this->cursor == NULL )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ListNode::isFull() const;

ListNode& operator = (const ListNode&);

friend ostream& operator << (ostream&, const ListNode&);

private:
    Node *head;
    Node *cursor;
};
