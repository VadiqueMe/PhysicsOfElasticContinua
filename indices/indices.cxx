#include <string>
#include <vector>
#include <set>
#include <algorithm>

#include <iostream>

typedef unsigned short  ushort ;

template < typename Type >
class four
{
	public:
		Type  first ;
		Type  second ;
		Type  third ;
		Type  fourth ;

		four ( Type the1st, Type the2nd, Type the3rd, Type the4th )
			: first( the1st )
			, second( the2nd )
			, third( the3rd )
			, fourth( the4th ) { }

		bool operator < ( const four & that ) const
		{
			if ( first < that.first ) return true ;
			else if ( first == that.first ) {
				if ( second < that.second ) return true ;
				else if ( second == that.second ) {
					if ( third < that.third ) return true ;
					else if ( third == that.third ) {
						if ( fourth < that.fourth ) return true ;
			}	}	}

			return false ;
		}

		bool operator == ( const four & that ) const
		{
			return ( first == that.first && second == that.second && third == that.third && fourth == that.fourth ) ;
		}
} ;

template < typename Type >
std::ostream & operator << ( std::ostream & out, const four< Type > & thiz )
{
	out << thiz.first << thiz.second << thiz.third << thiz.fourth ;
	return out ;
}

template < typename Type >
class pairofours
{
	public:
		four< Type >  first ;
		four< Type >  second ;

		pairofours ( four< Type > one, four< Type > two )
			: first( one )
			, second( two ) { }
} ;

template < typename Type >
void vectorOfPairsToVectorOfSets ( const std::vector< pairofours< Type > > & pairs,
					std::vector< std::set< four< Type > > > & sets )
{
	sets.clear (); // fresh it

	for ( size_t i = 0 ; i < pairs.size () ; ++ i )
	{
		std::set< four< Type > > newentry ;
		newentry.insert( pairs[ i ].first );
		newentry.insert( pairs[ i ].second );

		sets.push_back( newentry );
	}
}

int main ( void )
{
	std::vector< four< ushort > > indices ;

	for ( size_t i = 1 ; i <= 3 ; ++ i )
		for ( size_t j = 1 ; j <= 3 ; ++ j )
			for ( size_t k = 1 ; k <= 3 ; ++ k )
				for ( size_t l = 1 ; l <= 3 ; ++ l )
					indices.push_back( four< ushort > ( i, j, k, l ) );

	std::cout << indices.size () << " entries" << std::endl ;

	for ( size_t position = 0 ; position < indices.size () ; ++ position )
	{
		std::cout << indices[ position ] << std::endl ;
	}

	bool doneWithThat = false ;

	std::vector< pairofours< ushort > > symmetryAbcdCdab ;

	for ( size_t iThis = 0 ; iThis < indices.size () ; ++ iThis )
	{
		doneWithThat = false ;
		for ( size_t iThat = iThis + 1 ; iThat < indices.size () && ! doneWithThat ; ++ iThat )
		{
			four< ushort > thisOne = indices[ iThis ];
			four< ushort > thatOne = indices[ iThat ];
	
			if ( thisOne.first == thatOne.third && thisOne.second == thatOne.fourth &&
				 thisOne.third == thatOne.first && thisOne.fourth == thatOne.second )
			{
				symmetryAbcdCdab.push_back( pairofours< ushort >( thisOne, thatOne ) );
				doneWithThat = true ;
			}
		}
	}

	std::cout << symmetryAbcdCdab.size () << " entries with abcd=cdab symmetry" << std::endl ;

	std::cout << "\\begin{array}{c}" << std::endl ;
	for ( size_t index = 0 ; index < symmetryAbcdCdab.size () ; ++ index )
	{
		four< ushort > thisfour = symmetryAbcdCdab[ index ].first;
		four< ushort > thatfour = symmetryAbcdCdab[ index ].second;

		std::cout <<
			"A^{" << thisfour << "}" << " = " << "A^{" << thatfour << "}"
				<< " \\\\" << std::endl ;
	}
	std::cout << "\\end{array}" << std::endl ;

	std::vector< std::set< four< ushort > > > allSymmetries ;
	vectorOfPairsToVectorOfSets( symmetryAbcdCdab, allSymmetries );

/*
	std::vector< std::set< four< ushort > > > symmetryAbcdBadc ;

	for ( size_t iThis = 0 ; iThis < indices.size () ; ++ iThis )
	{
		doneWithThat = false ;
		for ( size_t iThat = iThis + 1 ; iThat < indices.size () && ! doneWithThat ; ++ iThat )
		{
			four< ushort > thisOne = indices[ iThis ];
			four< ushort > thatOne = indices[ iThat ];
	
			if ( thisOne.first == thatOne.second && thisOne.second == thatOne.first &&
				 thisOne.third == thatOne.fourth && thisOne.fourth == thatOne.third )
			{
				symmetryAbcdBadc.push_back( std::set< four< ushort > > { thisOne, thatOne } );
				doneWithThat = true ;
			}
		}
	}

	std::cout << symmetryAbcdBadc.size () << " entries with abcd=badc symmetry" << std::endl ;

	for ( size_t indexofset = 0 ; indexofset < symmetryAbcdBadc.size () ; ++ indexofset )
	{
		bool first = true ;
		for ( auto item : symmetryAbcdBadc[ indexofset ] )
		{
			if ( ! first ) std::cout << "=" ;
			std::cout << item ;
			first = false ;
		}
		std::cout << std::endl ;
	}
*/

	std::vector< std::set< four< ushort > > > symmetryAbcdBacd ;

	for ( size_t iThis = 0 ; iThis < indices.size () ; ++ iThis )
	{
		doneWithThat = false ;
		for ( size_t iThat = iThis + 1 ; iThat < indices.size () && ! doneWithThat ; ++ iThat )
		{
			four< ushort > thisOne = indices[ iThis ];
			four< ushort > thatOne = indices[ iThat ];
	
			if ( thisOne.first == thatOne.second && thisOne.second == thatOne.first &&
				 thisOne.third == thatOne.third && thisOne.fourth == thatOne.fourth )
			{
				symmetryAbcdBacd.push_back( std::set< four< ushort > > { thisOne, thatOne } );
				doneWithThat = true ;
			}
		}
	}

	std::cout << symmetryAbcdBacd.size () << " entries with abcd=bacd symmetry" << std::endl ;

	for ( size_t indexofset = 0 ; indexofset < symmetryAbcdBacd.size () ; ++ indexofset )
	{
		bool first = true ;
		for ( auto item : symmetryAbcdBacd[ indexofset ] )
		{
			if ( ! first ) std::cout << "=" ;
			std::cout << item ;
			first = false ;
		}
		std::cout << std::endl ;
	}

	std::vector< std::set< four< ushort > > > symmetryAbcdAbdc ;

	for ( size_t iThis = 0 ; iThis < indices.size () ; ++ iThis )
	{
		doneWithThat = false ;
		for ( size_t iThat = iThis + 1 ; iThat < indices.size () && ! doneWithThat ; ++ iThat )
		{
			four< ushort > thisOne = indices[ iThis ];
			four< ushort > thatOne = indices[ iThat ];
	
			if ( thisOne.first == thatOne.first && thisOne.second == thatOne.second &&
				 thisOne.third == thatOne.fourth && thisOne.fourth == thatOne.third )
			{
				symmetryAbcdAbdc.push_back( std::set< four< ushort > > { thisOne, thatOne } );
				doneWithThat = true ;
			}
		}
	}

	std::cout << symmetryAbcdAbdc.size () << " entries with abcd=abdc symmetry" << std::endl ;

	for ( size_t indexofset = 0 ; indexofset < symmetryAbcdAbdc.size () ; ++ indexofset )
	{
		bool first = true ;
		for ( auto item : symmetryAbcdAbdc[ indexofset ] )
		{
			if ( ! first ) std::cout << "=" ;
			std::cout << item ;
			first = false ;
		}
		std::cout << std::endl ;
	}

	// join these sets

	std::set< size_t > mergedIndices ;
	std::vector< std::set< four< ushort > > > mergedItems ;
	std::vector< std::set< four< ushort > > > nonmergedItems ;

	for ( size_t thatindex = 0 ; thatindex < symmetryAbcdBacd.size () ; ++ thatindex )
	{
		bool merged = false ;

		for ( size_t indexinall = 0 ; indexinall < allSymmetries.size () ; ++ indexinall )
		{
			for ( auto thatItem : symmetryAbcdBacd[ thatindex ] )
			{
				if ( merged ) break ;

				for ( auto itemInAll : allSymmetries[ indexinall ] )
					if ( thatItem == itemInAll )
					{
						allSymmetries[ indexinall ].merge( std::move( symmetryAbcdBacd[ thatindex ] ) );
						mergedIndices.insert( indexinall );
						merged = true ;
						break ;
					}
			}
		}

		if ( ! merged )
			nonmergedItems.push_back( symmetryAbcdBacd[ thatindex ] );
	}

	for ( size_t thatindex = 0 ; thatindex < symmetryAbcdAbdc.size () ; ++ thatindex )
	{
		bool merged = false ;

		for ( size_t indexinall = 0 ; indexinall < allSymmetries.size () ; ++ indexinall )
		{
			for ( auto thatItem : symmetryAbcdAbdc[ thatindex ] )
			{
				if ( merged ) break ;

				for ( auto itemInAll : allSymmetries[ indexinall ] )
					if ( thatItem == itemInAll )
					{
						allSymmetries[ indexinall ].merge( std::move( symmetryAbcdAbdc[ thatindex ] ) );
						mergedIndices.insert( indexinall );
						merged = true ;
						break ;
					}
			}
		}

		if ( ! merged )
			nonmergedItems.push_back( symmetryAbcdAbdc[ thatindex ] );
	}

	for ( auto it = mergedIndices.begin () ; it != mergedIndices.end () ; )
	{
		bool unique = true ;
		bool hasMoreItems = false ;

		for ( size_t ii = 0 ; ii < allSymmetries.size () ; ++ ii )
		{
			if ( ii == *it ) continue ;
			if ( ! unique ) break ;

			for ( auto thisItem : allSymmetries[ *it ] )
			{
				if ( ! unique ) break ;

				for ( auto thatItem : allSymmetries[ ii ] )
					if ( thisItem == thatItem )
					{
						if ( allSymmetries[ *it ].size () > allSymmetries[ ii ].size () )
							hasMoreItems = true ;

						unique = false ;
						break ;
					}
			}
		}

		if ( unique || hasMoreItems )
			++ it ;
		else
			it = mergedIndices.erase( it );
	}

	for ( auto index : mergedIndices )
		mergedItems.push_back( allSymmetries[ index ] );

	for ( size_t indexinall = 0 ; indexinall < allSymmetries.size () ; ++ indexinall )
	{
		bool duplicated = false ;

		for ( size_t thatindex = 0 ; thatindex < mergedItems.size () ; ++ thatindex )
		{
			if ( duplicated ) break ;

			for ( auto itemInAll : allSymmetries[ indexinall ] )
			{
				if ( duplicated ) break ;

				for ( auto thatItem : mergedItems[ thatindex ] )
					if ( itemInAll == thatItem )
						{  duplicated = true ;  break ;  }
			}
		}

		if ( ! duplicated )
			nonmergedItems.push_back( allSymmetries[ indexinall ] );
	}

	allSymmetries.clear ();

	for ( auto addme : mergedItems )
		allSymmetries.push_back( addme );

	for ( auto andme : nonmergedItems )
		allSymmetries.push_back( andme );

	std::sort( allSymmetries.begin (), allSymmetries.end () );

	std::cout << "abcd=cdab, abcd=bacd & abcd=abdc symmetry: " << allSymmetries.size () << " entries" << std::endl ;

	for ( size_t indexofset = 0 ; indexofset < allSymmetries.size () ; ++ indexofset )
	{
		bool first = true ;
		for ( auto item : allSymmetries[ indexofset ] )
		{
			if ( ! first ) std::cout << "=" ;
			std::cout << item ;
			first = false ;
		}
		std::cout << std::endl ;
	}

	std::cout << "unique components are" ;

	std::set< four< ushort > > uniqueOnes ;

	for ( size_t position = 0 ; position < indices.size () ; ++ position )
	{
		bool found = false ;
		for ( size_t ii = 0 ; ii < allSymmetries.size () && ! found ; ++ ii )
			for ( auto symmItem : allSymmetries[ ii ] )
				if ( indices[ position ] == symmItem ) {  found = true ;  break ;  }

		if ( ! found )
			uniqueOnes.insert( indices[ position ] );
	}

	std::cout << " " << uniqueOnes.size () << " entries" << std::endl ;

	for ( auto item : uniqueOnes )
		std::cout << item << std::endl ;

	for ( auto item : uniqueOnes )
		allSymmetries.push_back( std::set< four< ushort > > { item } );

	std::sort( allSymmetries.begin (), allSymmetries.end () );

	std::cout << "for LaTeX" << std::endl ;

	std::cout << "\\begin{array}{l}" << std::endl ;
	std::cout << "A^{abcd} = A^{cdab} = A^{bacd} = A^{abdc} \\\\" << std::endl ;
	std::cout << "%" << std::endl ;

	for ( size_t indexofset = 0 ; indexofset < allSymmetries.size () ; ++ indexofset )
	{
		bool first = true ;
		for ( auto item : allSymmetries[ indexofset ] )
		{
			if ( ! first ) std::cout << " = " ;
			std::cout << "A^{" << item << "}" ;
			first = false ;
		}
		std::cout << " \\\\" << std::endl ;
	}

	std::cout << "\\end{array}" << std::endl ;

	return EXIT_SUCCESS ;
}

