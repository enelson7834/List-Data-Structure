#include <iostream>
using namespace std;

template <typename T>
class ListArray {
public:
    ListArray(int=10);
    ListArray(const ListArray<T>&);
    ~ListArray();

    bool insertBefore(const T&);
    bool insertAfter(const T&);
    bool get(T&) const;
    bool remove(T&);

    void clear();

    bool goToBeginning();
    bool goToEnd();

    bool goToNext();
    bool goToPrior();

    bool isEmpty() const;
    bool isFull() const;

    ListArray<T>& operator = (const ListArray<T>&);

    template <typename S>
    friend ostream& operator << (ostream&, const ListArray<S>&);

private:
    T *data;
    int cursor;
    int actual;
    int size;
};

template <typename T>
ListArray<T>::ListArray( int a )
{
    this->size = a;
    this->cursor = -1;
    this->actual = 0;

    this->data = new T[ this->size ];
}

template <typename T>
ListArray<T>::ListArray( const ListArray<T>& copy )
{
    this->size = copy.size;
    this->cursor = copy.cursor;
    this->actual = copy.actual;

    this->data = new T[ this->size ];

    for( int i= 0; i < this->actual; i++ )
        this->data[ i ] = copy.data[ i ];
}

template <typename T>
ListArray<T>::~ListArray( )
{
    delete[] this->data;
    this->data  = NULL;
}

template <typename T>
bool ListArray<T>::insertBefore( const T& value )
{
    if( this->isFull( ) )
        return false;

    if( this->isEmpty() )
    {
        this->cursor = 0;
    }
    else
    {
        for( int i = this->actual; i > this->cursor; i-- )
            this->data[ i ] = this->data[ i - 1 ];
    }

    this->actual++;
    this->data[ this->cursor ] = value;

    return true;
}

template <typename T>
bool ListArray<T>::insertAfter( const T& value )
{
    if( this->isFull( ) )
        return false;

    if( this->isEmpty() )
    {
        ;
    }
    else
    {
        for( int i = this->actual; i > this->cursor; i-- )
            this->data[ i ] = this->data[ i - 1 ];
    }

    this->actual++;
    this->cursor++;
    this->data[ this->cursor ] = value;

    return true;
}

template <typename T>
bool ListArray<T>::get( T& value ) const
{
    if( this->isEmpty( ) )
    {
        return false;
    }
    else
    {
        value = this->data[ this->cursor ];
        return true;
    }
}

template <typename T>
bool ListArray<T>::remove( T& value )
{
    if( this->isEmpty( ) )
    {
        return false;
    }
    else
    {
        value = this->data[ this->cursor ];

        this->actual--;

        // shuffle data members down
        for( int i = this->cursor; i < this->actual; i++ )
            this->data[ i ] = this->data[ i + 1 ];

        if( this->actual == 0 ) // check if empty
        {
            cursor = -1; // set cursor to 'empty' state
        }
        else if( this->cursor == this->actual ) // check if last element removed
        {
            this->cursor = 0; // set cursor to front
        }
        else // all other cases
        {
            ; // cursor should be in the same position
        }
        return true;
    }

}

template <typename T>
void ListArray<T>::clear( )
{
    this->actual = 0;
    this->cursor = -1;

    return true;
}

template <typename T>
bool ListArray<T>::goToBeginning( )
{
    if( this->isEmpty( ) )
    {
        return false;
    }
    else
    {
        this->cursor = 0;
        return true;
    }
}

template <typename T>
bool ListArray<T>::goToEnd( )
{
    if( this->isEmpty( ) )
    {
        return false;
    }
    else
    {
        this->cursor = this->actual - 1;
        return true;
    }
}

template <typename T>
bool ListArray<T>::goToNext( )
{
    if( this->isEmpty( ) )
    {
        return false;
    }
    else if( this->cursor == this->actual - 1 )
    {
        return false;
    }
    else
    {
        this->cursor++;
        return true;
    }
}

template <typename T>
bool ListArray<T>::goToPrior( )
{
    if( this->isEmpty( ) )
    {
        return false;
    }
    else if( this->cursor == 0 )
    {
        return false;
    }
    else
    {
        this->cursor--;
        return true;
    }
}

template <typename T>
bool ListArray<T>::isEmpty( ) const
{
    if( this->actual == 0 && this->cursor == -1 )
    {
        return true;
    }
    else 
    {
        return false;
    }
}

template <typename T>
bool ListArray<T>::isFull( ) const
{
    if( this->actual == this->size )
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
ListArray<T>& ListArray<T>::operator = ( const ListArray<T>& copy )
{
    if( this == &copy )
    {
        ;
    }
    else 
    {
        if( this->size != copy.size )
        {
            delete[] this->data;
            this->size = copy.size;
            this->data = new T[ this->size ];
        }
        this->cursor = copy.cursor;
        this->actual = copy.actual;

        this->data = new T[ this->size ];

        for( int i= 0; i < this->actual; i++ )
            this->data[ i ] = copy.data[ i ];
    }

    return *this;
}

template <typename T>
ostream& operator << ( ostream& out, const ListArray<T>& source )
{
    if( source.isEmpty( ) )
    {
        ;
    }
    else
    {
        for( int i = 0; i < source.actual; i++ )
        {
            out << source.data[ i ];
            out << " ";
        }
    }

    return out;
}