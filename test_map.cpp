#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "utils.hpp"
#include <map>
#include "map.hpp"

int main ()
{
	std::map<int,int> origmap;
	origmap.insert ( std::pair<int,int>(50,300) );
	origmap.insert ( std::pair<int,int>(10,300) );
	origmap.insert ( std::pair<int,int>(20,300) );
	origmap.insert ( std::pair<int,int>(60,300) );
	std::map<int,int>::iterator origit = origmap.begin();
	//for (; origit!=origmap.end(); ++origit)
		std::cout << origit->first << " => " << origit->second << '\n';

	std::cout << std::endl;
	std::cout << std::endl;

	ft::map<int,int> mymap;
	ft::pair<ft::map<int,int>::iterator,bool> ret_insert;
	ret_insert = mymap.insert( ft::pair<int,int>(50,500) );
	ret_insert = mymap.insert( ft::pair<int,int>(20,200) );
	ret_insert = mymap.insert( ft::pair<int,int>(40,400) );
	ret_insert = mymap.insert( ft::pair<int,int>(40,300) );
	ret_insert = mymap.insert( ft::pair<int,int>(10,100) );
	ret_insert = mymap.insert( ft::pair<int,int>(80,100) );
	ft::map<int,int>::iterator myit;
	myit = mymap.find(10);
	std::cout << myit->first << '\n';
	std::cout << myit->second << '\n';
	return 0;
}