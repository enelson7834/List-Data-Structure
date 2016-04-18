#include <iostream>
using namespace std;

ListArray<T>::ListArray( int = a )
{
    this->size = a;
    this->cursor = -1;
    this->actual = 0;

    this->data = new T[ this->size ];
}

ListArray<T>::ListArray( const ListArray<T>& copy )
{
    this->size = copy.size;
    this->cursor = copy.cursor;
    this->actual = copy.actual;

    this->data = new T[ this->size ];

    for( int i= 0; i < this->actual; i++ )
        this->data[ i ] = copy.data[ i ];
}

ListArray<T>::~ListArray( )
{
    delete[] this->data;
    this->data  = NULL;
}

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

        if( this->actual == 0; ) // check if empty
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

void ListArray<T>::clear( )
{
    this->actual = 0;
    this->cursor = -1;

    return true;
}

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

bool isEmpty( ) const
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

bool isFull( ) const
{
    if( this->actual == this-size )
    {
        return true;
    }
    else
    {
        return false;
    }
}

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

ostream& operator << ( ostream& out, const ListArray<S>& source )
{
    if( source.isEmpty( ) )
    {
        ;
    }
    else
    {
        for( int i = 0; i < this->actual; i++ )
            out << this->data[ i ];
    }

    return out;
}
