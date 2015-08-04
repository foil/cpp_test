//
//  Movie.h
//  CppTest
//
//  Created by meng zhang on 29/03/2015.
//  Copyright (c) 2015 meng zhang. All rights reserved.
//

#ifndef __CppTest__Movie__
#define __CppTest__Movie__

#include <stdio.h>
#include <vector>
#include <list>

using std::vector;
using std::list;

class Movie {
private:
	int movieId;
	float rating;
	vector<Movie*> similarMovies; // Similarity is bidirectional
	static void getAllSimilarMovies(Movie* m, list<Movie*> &allSimList);
public:
	Movie(int movieId, float rating) {
		this->movieId = movieId;
		this->rating = rating;
	}
 
	int getId() {
		return movieId;
	}
 
	float getRating() {
		return rating;
	}
 
	void addSimilarMovie(Movie* movie) {
		similarMovies.push_back(movie);
		movie->similarMovies.push_back(this);
	}
 
	vector<Movie *>& getSimilarMovies() {
		return similarMovies;
	}
 
	/*
	 * Implement a function to return top rated movies in the network of movies
	 * reachable from the current movie
	 * eg:            A(Rating 1.2)
	 *               /   \
	 *            B(2.4)  C(3.6)
	 *              \     /
	 *               D(4.8)
	 * In the above example edges represent similarity and the number is rating.
	 * getMovieRecommendations(A,2) should return C and D (sorting order doesn't matter so it can also return D and C)
	 * getMovieRecommendations(A,4) should return A, B, C, D (it can also return these in any order eg: B,C,D,A)
	 * getMovieRecommendations(A,1) should return D. Note distance from A to D doesn't matter,
	 *                             return the highest rated.
	 *
	 *     @param movie
	 *     @param numTopRatedSimilarMovies
	 *                      number of movies we want to return
	 *     @return List of top rated similar movies
	 */
	
	// A's recommendation movies should not include A itself
	static void getMovieRecommendations(Movie& movie, int numTopRatedSimilarMovies, vector<Movie *>& recommendedMovies) {
		// Implement me
		recommendedMovies.clear();
		list<Movie*> allsimlist;
		getAllSimilarMovies(&movie, allsimlist);
		list<Movie*>::iterator iter = allsimlist.begin();
		for (int i = 0; i < numTopRatedSimilarMovies; i ++) {
			recommendedMovies.push_back(*iter);
			iter ++;
			if (iter == allsimlist.end())
				return;
		}
		while (iter != allsimlist.end()) {
			Movie* m = *iter;
			for (int i = 0; i < numTopRatedSimilarMovies; i ++) {
				if (m->getRating() > recommendedMovies[i]->getRating()) {
					recommendedMovies[i] = m;
					break;
				}
			}
			iter ++;
		}
		return;
	}
};

#endif /* defined(__CppTest__Movie__) */
