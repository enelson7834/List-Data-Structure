#include <iostream>
using namespace std;


Node( int value, Node* nxt )
{
    this->data = value;
    this->next = nxt;
}

ListNode( int a )
{
    this->head = this->cursor = NULL;
}
ListNode( const ListNode& );
~ListNode();

bool insertAfter(int);
bool insertBefore(int);
bool get(int&) const;
bool remove(int&);

void clear();

bool goToBeginning();
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
