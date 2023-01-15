// Copyright (c) 2020 vadique
// Distributed under the WTFPLv2 software license http://www.wtfpl.net

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double compute_beta( double ratio, size_t * jlast )
{
	const double pi5 = M_PI * M_PI * M_PI * M_PI * M_PI ;

	double sumbeta = 0 ;
	for ( size_t j = 1 ; j < 100000000 ; j += 2 )
	{
		double j_m5 = (double)1 / ( j * j * j * j * j ) ;
		double tanharg = ( ratio * M_PI * j / (double)2 ) ;
		double toadd = j_m5 * tanh( tanharg ) ;

		if ( toadd < 1e-15 ) {
			if ( jlast ) *jlast = j ;
			break ;
		}
		else {
			sumbeta += toadd ;
			//if ( toadd > 1e-6 ) printf( "computing beta: j = %lu, toadd = %e, sumbeta = %.12f\n", j, toadd, sumbeta ) ;
		}
	}

	return ( ( (double)1 / (double)3 ) - ( (double)64 / pi5 ) * ( (double)1 / ratio ) * sumbeta ) ;
}

double compute_alpha( double ratio, double beta, size_t * jlast )
{
	const double pi2 = M_PI * M_PI ;

	double sumalpha = 0 ;
	for ( size_t j = 1 ; j < 10000000000 ; j += 2 )
	{
		double j_m2 = (double)1 / ( j * j ) ;
		double cosharg = ( ratio * M_PI * j / (double)2 ) ;
		double toadd = j_m2 * ( (double)1 - ( (double)1 / cosh( cosharg ) ) ) ;
		if ( toadd < 1e-15 ) {
			if ( jlast ) *jlast = j ;
			break ;
		}
		else {
			sumalpha += toadd ;
			//if ( toadd > 1e-6 ) printf( "computing alpha: j = %lu, toadd = %e, sumalpha = %.12f\n", j, toadd, sumalpha ) ;
		}
	}

	return ( beta * pi2 ) / ( (double)8 * sumalpha ) ;
}

int main()
{
	printf( "for ratio = 1 :\n" ) ;
	size_t jlastbetaeq = 0 ;
	size_t jlastalphaeq = 0 ;
	double betaeq = compute_beta( 1.0, &jlastbetaeq ) ;
	double alphaeq = compute_alpha( 1.0, betaeq, &jlastalphaeq ) ;
	printf( "betaeq = %.14f (computed at j = %lu)\n", betaeq, jlastbetaeq ) ;
	printf( "alphaeq = %.14f (computed at j = %lu)\n", alphaeq, jlastalphaeq ) ;

	const double ratio = (double)2 ;

	printf( "for ratio = %f :\n", ratio ) ;
	size_t jlastbeta = 0 ;
	size_t jlastalpha = 0 ;
	double beta = compute_beta( ratio, &jlastbeta ) ;
	double alpha = compute_alpha( ratio, beta, &jlastalpha ) ;
	printf( "beta = %.14f (computed at j = %lu)\n", beta, jlastbeta ) ;
	printf( "alpha = %.14f (computed at j = %lu)\n", alpha, jlastalpha ) ;

	return EXIT_SUCCESS ;
}

