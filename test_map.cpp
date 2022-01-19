#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "utils.hpp"
#include <map>
#include "map.hpp"

int main ()
{
	std::map<int,int> origmap;
	std::pair<std::map<int,int>::iterator,bool> ret_insert_orig;
	ret_insert_orig = origmap.insert( std::pair<int,int>(50,500) );
	ret_insert_orig = origmap.insert( std::pair<int,int>(20,200) );
	ret_insert_orig = origmap.insert( std::pair<int,int>(40,400) );
	ret_insert_orig = origmap.insert( std::pair<int,int>(40,300) );
	ret_insert_orig = origmap.insert( std::pair<int,int>(10,100) );
	ret_insert_orig = origmap.insert( std::pair<int,int>(80,800) );
	ret_insert_orig = origmap.insert( std::pair<int,int>(15,150) );
	ret_insert_orig = origmap.insert( std::pair<int,int>(70,700) );
	ret_insert_orig = origmap.insert( std::pair<int,int>(16,160) );
	ret_insert_orig = origmap.insert( std::pair<int,int>(13,130) );
	ret_insert_orig = origmap.insert( std::pair<int,int>(12,150) );
	ret_insert_orig = origmap.insert( std::pair<int,int>(14,150) );
	std::map<int,int>::iterator origit;

	origit = origmap.end();
	--origit;
	for (; origit!=origmap.begin(); --origit)
			std::cout << origit->first << " => " << origit->second << '\n';


	//origit = origmap.begin();
	//for (; origit!=origmap.end(); ++origit)
	//	std::cout << origit->first << " => " << origit->second << '\n';
	//--origit;
	//std::cout << std::endl;
	//for (; origit!=origmap.begin(); --origit)
	//	std::cout << origit->first << " => " << origit->second << '\n';


	std::cout << std::endl;
	std::cout << std::endl;

	ft::map<int,int> mymap;
	ft::pair<ft::map<int,int>::iterator,bool> ret_insert;
	ret_insert = mymap.insert( ft::pair<int,int>(50,500) );
	ret_insert = mymap.insert( ft::pair<int,int>(20,200) );
	ret_insert = mymap.insert( ft::pair<int,int>(40,400) );
	ret_insert = mymap.insert( ft::pair<int,int>(40,300) );
	ret_insert = mymap.insert( ft::pair<int,int>(10,100) );
	ret_insert = mymap.insert( ft::pair<int,int>(80,800) );
	ret_insert = mymap.insert( ft::pair<int,int>(15,150) );
	ret_insert = mymap.insert( ft::pair<int,int>(70,700) );
	ret_insert = mymap.insert( ft::pair<int,int>(16,160) );
	ret_insert = mymap.insert( ft::pair<int,int>(13,130) );
	ret_insert = mymap.insert( ft::pair<int,int>(12,150) );
	ret_insert = mymap.insert( ft::pair<int,int>(14,150) );
	ft::map<int,int>::iterator myit;

	myit = mymap.end();
	--myit;
	for (; myit != mymap.begin(); --myit)
		std::cout << myit->first << " => " << myit->second << '\n';


	//myit = mymap.begin();
	//for (; myit != mymap.end(); ++myit)
	//	std::cout << myit->first << " => " << myit->second << '\n';
	//--myit;
	//std::cout << std::endl;
	//for (; myit != mymap.begin(); --myit)
	//	std::cout << myit->first << " => " << myit->second << '\n';
	return 0;
}