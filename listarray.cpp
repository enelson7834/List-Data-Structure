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

    this->size = this->cursor = this->actual = 0;
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
            cursor = -1;
        }
        else if( this->cursor == this->actual ) // check if last element removed
        {
            this->cursor = 0;
        }
        else // all other cases
        {
            ;
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

ListArray<T>& operator = ( const ListArray<T>& )

friend ostream& operator << (ostream&, const ListArray<S>&);

private:
    T *data;
    int cursor;
    int actual;
    int size;
};