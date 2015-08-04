//
//  Movie.cpp
//  CppTest
//
//  Created by meng zhang on 29/03/2015.
//  Copyright (c) 2015 meng zhang. All rights reserved.
//

#include "Movie.h"
/*
 recursively get all the similiar movies and erase duplicated items
 use stl list to remove item/append sublist
 complexity should be O(n2)
 */
void Movie::getAllSimilarMovies(Movie* m, list<Movie*> &allSimList)
{
	list<Movie*> sublist;
	vector<Movie *> sim_list = m->getSimilarMovies();
	vector<Movie *>::iterator iter;
	for (iter = sim_list.begin(); iter != sim_list.end(); iter ++) {
		sublist.push_back(*iter);
	}
	
	list<Movie *>::iterator iter1;
	list<Movie *>::iterator iter2;
	for (iter1 = allSimList.begin(); iter1 != allSimList.end(); iter1 ++) {
		for(iter2 = sublist.begin(); iter2 != sublist.end(); ) {
			if(*iter1 == *iter2)
				iter2 = sublist.erase(iter2);
			else
				iter2++;
		}
	}

	if (sublist.empty())
		return;
	
	allSimList.insert(allSimList.end(), sublist.begin(), sublist.end());
	
	for (iter1 = sublist.begin(); iter1 != sublist.end(); iter1 ++) {
		Movie* m = *iter1;
		getAllSimilarMovies(m, allSimList);
	}
}
