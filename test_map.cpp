#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "utils.hpp"
#include <map>
#include "map.hpp"

int main ()
{
	std::map<int,int> orig_map;
	std::cout << "orig_map: " << "size = " << orig_map.size() << std::endl;
	std::cout << "orig_map: " << "empty = " << orig_map.empty() << std::endl;
	std::pair<std::map<int,int>::iterator,bool> ret_insert_orig;
	ret_insert_orig = orig_map.insert( std::pair<int,int>(50,500) );
	ret_insert_orig = orig_map.insert( std::pair<int,int>(20,200) );
	ret_insert_orig = orig_map.insert( std::pair<int,int>(40,400) );
	ret_insert_orig = orig_map.insert( std::pair<int,int>(40,300) );
	ret_insert_orig = orig_map.insert( std::pair<int,int>(10,100) );
	ret_insert_orig = orig_map.insert( std::pair<int,int>(80,800) );
	ret_insert_orig = orig_map.insert( std::pair<int,int>(15,150) );
	ret_insert_orig = orig_map.insert( std::pair<int,int>(70,700) );
	ret_insert_orig = orig_map.insert( std::pair<int,int>(16,160) );
	ret_insert_orig = orig_map.insert( std::pair<int,int>(13,130) );
	ret_insert_orig = orig_map.insert( std::pair<int,int>(12,150) );
	ret_insert_orig = orig_map.insert( std::pair<int,int>(14,150) );
	std::map<int,int>::iterator origit;

	origit = orig_map.begin();
	for (; origit!=orig_map.end(); ++origit)
		std::cout << "orig_map: " << origit->first << " => " << origit->second << '\n';
	--origit;
	std::cout << std::endl;
	for (; origit!=orig_map.begin(); --origit)
		std::cout << "orig_map: " << origit->first << " => " << origit->second << '\n';
	std::cout << "orig_map: " << origit->first << " => " << origit->second << '\n';
	std::cout << "orig_map: " << "size = " << orig_map.size() << std::endl;
	std::cout << "orig_map: " << "empty = " << orig_map.empty() << std::endl;
	std::cout << "orig_map: " << "count = " << orig_map.count(50) << std::endl;
	std::cout << "orig_map: " << "count = " << orig_map.count(16) << std::endl;
	std::cout << "orig_map: " << "count = " << orig_map.count(100) << std::endl;
	std::cout << "orig_map: " << "lower_bound = " << orig_map.lower_bound(20)->first << std::endl;
	std::cout << "orig_map: " << "upper_bound = " << orig_map.upper_bound(40)->first << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	ft::map<int,int> my_map;
	std::cout << "my_map: " << "size = " << my_map.size() << std::endl;
	std::cout << "my_map: " << "empty = " << my_map.empty() << std::endl;
	ft::pair<ft::map<int,int>::iterator,bool> ret_insert;
	ret_insert = my_map.insert( ft::pair<int,int>(50,500) );
	ret_insert = my_map.insert( ft::pair<int,int>(20,200) );
	ret_insert = my_map.insert( ft::pair<int,int>(40,400) );
	ret_insert = my_map.insert( ft::pair<int,int>(40,300) );
	ret_insert = my_map.insert( ft::pair<int,int>(10,100) );
	ret_insert = my_map.insert( ft::pair<int,int>(80,800) );
	ret_insert = my_map.insert( ft::pair<int,int>(15,150) );
	ret_insert = my_map.insert( ft::pair<int,int>(70,700) );
	ret_insert = my_map.insert( ft::pair<int,int>(16,160) );
	ret_insert = my_map.insert( ft::pair<int,int>(13,130) );
	ret_insert = my_map.insert( ft::pair<int,int>(12,150) );
	ret_insert = my_map.insert( ft::pair<int,int>(14,150) );
	ft::map<int,int>::iterator myit;
	myit = my_map.begin();
	for (; myit != my_map.end(); ++myit)
		std::cout << "my_map: " << myit->first << " => " << myit->second << '\n';
	--myit;
	std::cout << std::endl;
	for (; myit != my_map.begin(); --myit)
		std::cout << "my_map: " << myit->first << " => " << myit->second << '\n';
	std::cout << "my_map: " << myit->first << " => " << myit->second << '\n';
	std::cout << "my_map: " << "size = " << my_map.size() << std::endl;
	std::cout << "my_map: " << "empty = " << my_map.empty() << std::endl;
	std::cout << "my_map: " << "count = " << my_map.count(50) << std::endl;
	std::cout << "my_map: " << "count = " << my_map.count(16) << std::endl;
	std::cout << "my_map: " << "count = " << my_map.count(100) << std::endl;
	std::cout << "my_map: " << "lower_bound = " << my_map.lower_bound(20)->first << std::endl;
	std::cout << "my_map: " << "upper_bound = " << my_map.upper_bound(40)->first << std::endl;
	return 0;
}