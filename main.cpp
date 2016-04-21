#include <iostream>
#include "listarray.h"

using namespace std;

int main()
{
	int w;
	ListArray<int> l1;

	l1.insertBefore( 100 );
	l1.insertAfter( 200 );
	l1.insertBefore( 300 );

	for( int i = 0; i < 13; i++ )
	{
		l1.insertBefore( i );
		l1.insertAfter( i );
	}

	l1.goToEnd( ); 
	l1.goToNext( );
	l1.goToBeginning( );
	l1.goToPrior( );
	l1.goToEnd( ); 
	l1.goToPrior( );
	l1.insertAfter( 2 );

	cout << l1 << endl;

	l1.get( w );
	cout << w << endl;

	ListArray<int> l2( l1 );

	l1.get( w );
	cout << w << endl;

	cout << l2 << endl;

	cout << endl;

	l1.goToPrior( );
	l1.remove( w );
	l1.get( w );

	l1.goToPrior( );

	cout << l1 << endl;
	cout << l2 << endl;
	cout << endl;

	l2 = l1;

	cout << l1 << endl;
	cout << l2 << endl;
	cout << endl;

	l1.get( w );
	cout << w << endl;

	for( int i = 0; i < 17; i++ )
	{
		l1.remove( w );
		cout << l1 << endl;
	}

	cout << l1 << endl;
	cout << l2 << endl;
	cout << endl;
	

	return 0;
}