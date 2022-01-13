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
	//origmap.insert ( std::pair<int,int>(10,300) );
	//origmap.insert ( std::pair<int,int>(20,300) );
	//origmap.insert ( std::pair<int,int>(60,300) );
	std::map<int,int>::iterator origit=origmap.begin();
	//for (; origit!=origmap.end(); ++origit)
		std::cout << origit->first << " => " << origit->second << '\n';

	std::cout << std::endl;
	std::cout << std::endl;

	ft::map<int,int> mymap;
	mymap.insert ( ft::pair<int,int>(50,300) );
	ft::map<int,int>::iterator myit;
	myit = mymap.begin();
	//std::cout << myit->first << " => " << myit->second << '\n';
	return 0;
}