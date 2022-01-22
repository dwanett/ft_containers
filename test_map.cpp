#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "utils.hpp"
#include <map>
#include "map.hpp"

/*
int main ()
{
	std::map<int,int> orig_map;
	std::map<int,int> orig_map_2;
	std::cout << "orig_map: " << "size = " << orig_map.size() << std::endl;
	std::cout << "orig_map: " << "empty = " << orig_map.empty() << std::endl;
	std::pair<std::map<int,int>::iterator,bool> ret_insert_orig;
	ret_insert_orig = orig_map_2.insert(std::pair<int,int>(120,700) );
	ret_insert_orig = orig_map_2.insert(std::pair<int,int>(140,160) );
	ret_insert_orig = orig_map_2.insert(std::pair<int,int>(130,130) );
	ret_insert_orig = orig_map_2.insert(std::pair<int,int>(150,150) );
	ret_insert_orig = orig_map_2.insert(std::pair<int,int>(160,150) );
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
	std::pair<std::map<int,int>::iterator, std::map<int,int>::iterator> orig_equal_it;
	orig_equal_it = orig_map.equal_range(40);
	std::cout << "orig_map: " << "equal_range_first = " << orig_equal_it.first->first << std::endl;
	std::cout << "orig_map: " << "equal_range_second = " << orig_equal_it.second->first << std::endl;
	origit = orig_map.begin();
	origit++;
	origit++;
	orig_map.insert(origit, std::pair<int,int>(30,300) );
	orig_map.insert(orig_map_2.begin(),  orig_map_2.end());
	std::cout << "orig_map: " << "size = " << orig_map.size() << std::endl;
	origit = orig_map.begin();
	for (; origit != orig_map.end(); ++origit)
		std::cout << "orig_map: " << origit->first << " => " << origit->second << '\n';

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "orig_map < orig_map: " << (orig_map < orig_map) << '\n';
	std::cout << "orig_map < orig_map_2: " << (orig_map < orig_map_2) << '\n';
	std::cout << std::endl;
	std::cout << "orig_map <= orig_map: " << (orig_map <= orig_map) << '\n';
	std::cout << "orig_map <= orig_map_2: " << (orig_map <= orig_map_2) << '\n';
	std::cout << std::endl;
	std::cout << "orig_map > orig_map: " << (orig_map > orig_map) << '\n';
	std::cout << "orig_map > orig_map_2: " << (orig_map > orig_map_2) << '\n';
	std::cout << std::endl;
	std::cout << "orig_map >= orig_map: " << (orig_map >= orig_map) << '\n';
	std::cout << "orig_map >= orig_map_2: " << (orig_map >= orig_map_2) << '\n';
	std::cout << std::endl;
	std::cout << "orig_map == orig_map: " << (orig_map == orig_map) << '\n';
	std::cout << "orig_map == orig_map_2: " << (orig_map == orig_map_2) << '\n';

	orig_map.clear();
	std::cout << "orig_map: " << "size = " << orig_map.size() << std::endl;

	std::cout << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	ft::map<int,int> my_map;
	ft::map<int,int> my_map_2;
	std::cout << "my_map: " << "size = " << my_map.size() << std::endl;
	std::cout << "my_map: " << "empty = " << my_map.empty() << std::endl;
	ft::pair<ft::map<int,int>::iterator,bool> ret_insert;
	ret_insert = my_map_2.insert( ft::pair<int,int>(120,700) );
	ret_insert = my_map_2.insert( ft::pair<int,int>(140,160) );
	ret_insert = my_map_2.insert( ft::pair<int,int>(130,130) );
	ret_insert = my_map_2.insert( ft::pair<int,int>(150,150) );
	ret_insert = my_map_2.insert( ft::pair<int,int>(160,150) );

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
	ft::pair<ft::map<int,int>::iterator, ft::map<int,int>::iterator> my_equal_it;
	my_equal_it = my_map.equal_range(40);
	std::cout << "my_map: " << "equal_range_first = " << my_equal_it.first->first << std::endl;
	std::cout << "my_map: " << "equal_range_second = " << my_equal_it.second->first << std::endl;
	myit = my_map.begin();
	myit++;
	myit++;
	my_map.insert(myit, ft::pair<int,int>(30,300) );
	my_map.insert(my_map_2.begin(),  my_map_2.end());
	std::cout << "my_map: " << "size = " << my_map.size() << std::endl;
	myit = my_map.begin();
	for (; myit != my_map.end(); ++myit)
		std::cout << "my_map: " << myit->first << " => " << myit->second << '\n';

	std::cout << std::endl;
	std::cout << "my_map < my_map: " << (my_map < my_map) << '\n';
	std::cout << "my_map < my_map_2: " << (my_map < my_map_2) << '\n';
	std::cout << std::endl;
	std::cout << "my_map <= my_map: " << (my_map <= my_map) << '\n';
	std::cout << "my_map <= my_map_2: " << (my_map <= my_map_2) << '\n';
	std::cout << std::endl;
	std::cout << "my_map > my_map: " << (my_map > my_map) << '\n';
	std::cout << "my_map > my_map_2: " << (my_map > my_map_2) << '\n';
	std::cout << std::endl;
	std::cout << "my_map >= my_map: " << (my_map >= my_map) << '\n';
	std::cout << "my_map >= my_map_2: " << (my_map >= my_map_2) << '\n';
	std::cout << std::endl;
	std::cout << "my_map == my_map: " << (my_map == my_map) << '\n';
	std::cout << "my_map == my_map_2: " << (my_map == my_map_2) << '\n';
	std::cout << std::endl;
	std::cout << std::endl;

	myit = my_map.begin();
	for (; myit != my_map.end(); ++myit)
		std::cout << "my_map: " << myit->first << " => " << myit->second << '\n';
	myit = my_map_2.begin();
	std::cout << std::endl;
	for (; myit != my_map_2.end(); ++myit)
		std::cout << "my_map_2: " << myit->first << " => " << myit->second << '\n';
	my_map.swap(my_map_2);
	std::cout << std::endl;
	std::cout << std::endl;
	myit = my_map.begin();
	for (; myit != my_map.end(); ++myit)
		std::cout << "my_map: " << myit->first << " => " << myit->second << '\n';
	myit = my_map_2.begin();
	std::cout << std::endl;
	for (; myit != my_map_2.end(); ++myit)
		std::cout << "my_map_2: " << myit->first << " => " << myit->second << '\n';

	ft::map<int,int> my_map_3(my_map.begin(), my_map.end());
	myit = my_map_3.begin();
	std::cout << std::endl;
	for (; myit != my_map_3.end(); ++myit)
		std::cout << "my_map_3: " << myit->first << " => " << myit->second << '\n';
	std::cout << "my_map_3: " << "size = " << my_map_3.size() << std::endl;
	ft::map<int,int> my_map_4(my_map_2);
	myit = my_map_4.begin();
	std::cout << std::endl;
	for (; myit != my_map_4.end(); ++myit)
		std::cout << "my_map_4: " << myit->first << " => " << myit->second << '\n';
	std::cout << "my_map_4: " << "size = " << my_map_4.size() << std::endl;

	my_map_4 = my_map_3;

	myit = my_map_4.begin();
	std::cout << std::endl;
	for (; myit != my_map_4.end(); ++myit)
		std::cout << "my_map_4: " << myit->first << " => " << myit->second << '\n';
	std::cout << "my_map_4: " << "size = " << my_map_4.size() << std::endl;
	my_map.clear();
	std::cout << "my_map: " << "size = " << my_map.size() << std::endl;
	return 0;
}*/

#define T1 int
#define T2 std::string

ft::map<T1, T2> mp;
ft::map<T1, T2>::iterator it = mp.end();

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

void	ft_find(T1 const &k)
{
	ft::map<T1, T2>::iterator ret = mp.find(k);

	if (ret != it)
		printPair(ret);
	else
		std::cout << "map::find(" << k << ") returned end()" << std::endl;
}

void	ft_count(T1 const &k)
{
	std::cout << "map::count(" << k << ")\treturned [" << mp.count(k) << "]" << std::endl;
}

int		main(void)
{
	mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";
	printSize(mp);

	std::cout << "\t-- FIND --" << std::endl;
	ft_find(12);
	ft_find(3);
	ft_find(35);
	ft_find(90);
	ft_find(100);

	std::cout << "\t-- COUNT --" << std::endl;
	ft_count(-3);
	ft_count(12);
	ft_count(3);
	ft_count(35);
	ft_count(90);
	ft_count(100);

	mp.find(27)->second = "newly inserted mapped_value";

	printSize(mp);

	ft::map<T1, T2> const c_map(mp.begin(), mp.end());
	std::cout << "const map.find(" << 42 << ")->second: [" << c_map.find(42)->second << "]" << std::endl;
	std::cout << "const map.count(" << 80 << "): [" << c_map.count(80) << "]" << std::endl;
	return (0);
}