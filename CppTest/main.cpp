//
//  main.cpp
//  CppTest
//
//  Created by meng zhang on 5/08/2014.
//  Copyright (c) 2014 meng zhang. All rights reserved.
//


#include "Movie.h"

void test_Movie()
{
	Movie A(0, 4.3), B(1, 3.6), C(2, 4.3), D(4, 8.3), E(5, 9.12), F(6, 2.4), G(7, 3.6), \
	H(8, 0.3), I(9, 9.4), J(10, 4.9), K(11, 5), L(12, 7.70), M(13, 3.5), N(14, 6), O(15, 8.2);
	A.addSimilarMovie(&C);
	A.addSimilarMovie(&E);
	A.addSimilarMovie(&D);
	A.addSimilarMovie(&B);
	B.addSimilarMovie(&A);
	B.addSimilarMovie(&C);
	B.addSimilarMovie(&D);
	B.addSimilarMovie(&E);
	C.addSimilarMovie(&E);
	C.addSimilarMovie(&F);
	C.addSimilarMovie(&G);
	D.addSimilarMovie(&H);
	D.addSimilarMovie(&I);
	D.addSimilarMovie(&J);
	D.addSimilarMovie(&K);
	D.addSimilarMovie(&L);
	D.addSimilarMovie(&M);
	D.addSimilarMovie(&N);
	D.addSimilarMovie(&O);
	K.addSimilarMovie(&A);
	K.addSimilarMovie(&B);
	K.addSimilarMovie(&C);
	K.addSimilarMovie(&D);
	K.addSimilarMovie(&E);
	
	vector<Movie *> recommendedMovies;
	Movie::getMovieRecommendations(A, 5, recommendedMovies);
	vector<Movie*>::iterator iter;
	for (iter = recommendedMovies.begin();
		 iter != recommendedMovies.end();
		 iter ++) {
		std::cout << (*iter)->getId() << ":" << (*iter)->getRating() << std::endl;
	}
}

int main(int argc, const char * argv[])
{
	test_Movie();
	return 0;
}

