#include <iostream>
#include <vector>
#include <iterator>
#include "iterator.hpp"
#include "utils.hpp"
#include "vector.hpp"
#include <chrono>

template <class Iter, class vect>
	void print_vec(vect v, std::string msg)
{
	std::cout << "vec " << msg << ": ";
	for (Iter it = v.begin(); it < v.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

int main()
{
	auto start_my = std::chrono::system_clock::now();
	ft::vector<int> my_v;
	std::cout << "empty my: " << my_v.empty() << std::endl;
	my_v.push_back(10);
	my_v.push_back(20);
	my_v.push_back(30);
	my_v.push_back(40);
	my_v.push_back(50);
	my_v.push_back(60);
	std::cout << "empty my: " << my_v.empty() << std::endl;
	std::cout << "size my: " << my_v.size() << std::endl;
	ft::vector<int>::iterator my_it_begin = my_v.begin();
	ft::vector<int>::iterator my_it_end = my_v.end();
	my_it_end--;
	ft::vector<int>::reverse_iterator rev_my_it_begin = my_v.rbegin();
	ft::vector<int>::reverse_iterator rev_my_it_end = my_v.rend();
	rev_my_it_begin++;
	print_vec<ft::vector<int>::iterator>(my_v, "my");
	ft::vector<int>::iterator my_erase_it = my_v.erase(my_v.begin() + 1);
	std::cout << "erase_it my: " << *my_erase_it << std::endl;
	print_vec<ft::vector<int>::iterator>(my_v, "my");
	ft::vector<int>::iterator my_erase_it_2 = my_v.erase(my_v.begin(), my_v.begin() + 2);
	std::cout << "range erase_it my: " << *my_erase_it_2 << std::endl;
	std::cout << "capacity my: " << my_v.capacity() << std::endl;
	print_vec<ft::vector<int>::iterator>(my_v, "my");
	my_v.resize(9,1);
	print_vec<ft::vector<int>::iterator>(my_v, "my");
	std::cout << "capacity my: " << my_v.capacity() << std::endl;
	print_vec<ft::vector<int>::iterator>(my_v, "my");
	std::cout << "capacity my: " << my_v.capacity() << std::endl;
	std::cout << "my_insert it: " << *my_v.insert(my_v.end() - 2, 25) << std::endl;
	my_v.insert(my_v.begin() + 1, 25);
	std::cout << "capacity my: " << my_v.capacity() << std::endl;
	print_vec<ft::vector<int>::iterator>(my_v, "my");
	ft::vector<int> copy_my_v;
	copy_my_v = my_v;
	std::cout << "capacity copy_my: " << copy_my_v.capacity() << std::endl;
	ft::vector<int> copy_2_my_v(my_v);
	std::cout << "capacity copy_2_my: " << copy_2_my_v.capacity() << std::endl;
	copy_2_my_v.insert(copy_2_my_v.end(), 30);
	print_vec<ft::vector<int>::iterator>(copy_my_v, "copy_my");
	print_vec<ft::vector<int>::iterator>(copy_2_my_v, "copy_2_my");
	std::cout << "capacity copy_2_my: " << copy_2_my_v.capacity() << std::endl;
	my_v.insert(my_v.end() - 5,14, 70);
	print_vec<ft::vector<int>::iterator>(my_v, "my");
	std::cout << "capacity my: " << my_v.capacity() << std::endl;
	std::cout << "size my: " << my_v.size() << std::endl;
	print_vec<ft::vector<int>::iterator>(copy_my_v, "copy_my");
	std::cout << "capacity copy_my: " << copy_my_v.capacity() << std::endl;
	std::cout << "size copy_my: " << copy_my_v.size() << std::endl;
	copy_my_v.insert(copy_my_v.begin(), my_v.begin(), my_v.end());
	print_vec<ft::vector<int>::iterator>(copy_my_v, "copy_my");
	std::cout << "capacity copy_my: " << copy_my_v.capacity() << std::endl;
	std::cout << "size copy_my: " << copy_my_v.size() << std::endl;
	copy_my_v.push_back(60);
	print_vec<ft::vector<int>::iterator>(copy_my_v, "copy_my");
	std::cout << "capacity copy_my: " << copy_my_v.capacity() << std::endl;
	std::cout << "size copy_my: " << copy_my_v.size() << std::endl;
	copy_my_v.insert(copy_my_v.begin(), copy_2_my_v.begin(), copy_2_my_v.end());
	print_vec<ft::vector<int>::iterator>(copy_my_v, "copy_my");
	std::cout << "capacity copy_my: " << copy_my_v.capacity() << std::endl;
	std::cout << "size copy_my: " << copy_my_v.size() << std::endl;
	copy_my_v.pop_back();
	print_vec<ft::vector<int>::iterator>(copy_my_v, "copy_my");
	std::cout << "capacity copy_my: " << copy_my_v.capacity() << std::endl;
	std::cout << "size copy_my: " << copy_my_v.size() << std::endl;
	print_vec<ft::vector<int>::iterator>(my_v, "my");
	std::cout << "capacity my: " << my_v.capacity() << std::endl;
	std::cout << "size my: " << my_v.size() << std::endl;
	print_vec<ft::vector<int>::iterator>(copy_my_v, "copy_my");
	std::cout << "capacity copy_my: " << copy_my_v.capacity() << std::endl;
	std::cout << "size copy_my: " << copy_my_v.size() << std::endl;
	my_v.swap(copy_my_v);
	print_vec<ft::vector<int>::iterator>(my_v, "my");
	std::cout << "capacity my: " << my_v.capacity() << std::endl;
	std::cout << "size my: " << my_v.size() << std::endl;
	print_vec<ft::vector<int>::iterator>(copy_my_v, "copy_my");
	std::cout << "capacity copy_my: " << copy_my_v.capacity() << std::endl;
	std::cout << "size copy_my: " << copy_my_v.size() << std::endl;

	copy_my_v.assign(26, 100);
	print_vec<ft::vector<int>::iterator>(copy_my_v, "copy_my");
	std::cout << "capacity copy_my: " << copy_my_v.capacity() << std::endl;
	std::cout << "size copy_my: " << copy_my_v.size() << std::endl;

	copy_my_v.assign(my_v.begin(), my_v.end());
	print_vec<ft::vector<int>::iterator>(copy_my_v, "copy_my");
	std::cout << "capacity copy_my: " << copy_my_v.capacity() << std::endl;
	std::cout << "size copy_my: " << copy_my_v.size() << std::endl;
	try {
		copy_my_v.at(100) = 100;      // vector::at throws an out-of-range
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
	std::cout << "front copy_my: " << copy_my_v.front() << std::endl;
	std::cout << "at copy_my: " << copy_my_v.at(20) << std::endl;
	std::cout << "[] copy_my: " << copy_my_v[7] << std::endl;
	std::cout << "back copy_my: " << copy_my_v.back() << std::endl;
	my_v = copy_my_v;
	my_v[23] = 2;
	print_vec<ft::vector<int>::iterator>(copy_my_v, "copy_my");
	print_vec<ft::vector<int>::iterator>(my_v, "my_v");
	std::cout << "operator== : " << (my_v == copy_my_v) << std::endl;
	std::cout << "operator== : " << (copy_my_v == copy_my_v) << std::endl;
	std::cout << "operator!= : " << (my_v != copy_my_v) << std::endl;
	std::cout << "operator!= : " << (copy_my_v != copy_my_v) << std::endl;
	std::cout << "operator<= : " << (my_v <= copy_my_v) << std::endl;
	std::cout << "operator<= : " << (copy_my_v <= copy_my_v) << std::endl;
	std::cout << "operator>= : " << (my_v >= copy_my_v) << std::endl;
	std::cout << "operator>= : " << (copy_my_v >= copy_my_v) << std::endl;
	std::cout << "operator<  : " << (my_v < copy_my_v) << std::endl;
	std::cout << "operator<  : " << (copy_my_v < copy_my_v) << std::endl;
	std::cout << "operator>  : " << (my_v > copy_my_v) << std::endl;
	std::cout << "operator>  : " << (copy_my_v > copy_my_v) << std::endl;
	auto end_my = std::chrono::system_clock::now();



	auto start_orig = std::chrono::system_clock::now();
	std::cout << std::endl;
	std::vector<int> orig_v;
	std::cout << "empty orig: " << orig_v.empty() << std::endl;
	orig_v.push_back(10);
	orig_v.push_back(20);
	orig_v.push_back(30);
	orig_v.push_back(40);
	orig_v.push_back(50);
	orig_v.push_back(60);
	std::cout << "empty orig: " << orig_v.empty() << std::endl;
	std::cout << "size orig: " << orig_v.size() << std::endl;
	std::vector<int>::iterator orig_it_begin = orig_v.begin();
	std::vector<int>::iterator orig_it_end = orig_v.end();
	(void)orig_it_begin;
	orig_it_end--;
	std::vector<int>::reverse_iterator rev_orig_it_begin = orig_v.rbegin();
	std::vector<int>::reverse_iterator rev_orig_it_end = orig_v.rend();
	(void)rev_orig_it_end;
	rev_orig_it_begin++;
	print_vec<std::vector<int>::iterator>(orig_v, "orig");
	std::vector<int>::iterator orig_erase_it = orig_v.erase(orig_v.begin() + 1);
	std::cout << "erase_it orig: " << *orig_erase_it << std::endl;
	print_vec<std::vector<int>::iterator>(orig_v, "orig");
	std::vector<int>::iterator orig_erase_it_2 = orig_v.erase(orig_v.begin(), orig_v.begin() + 2);
	std::cout << "range erase_it orig: " << *orig_erase_it_2 << std::endl;
	std::cout << "capacity orig: " << orig_v.capacity() << std::endl;
	print_vec<std::vector<int>::iterator>(orig_v, "orig");
	orig_v.resize(9,1);
	std::cout << "capacity orig: " << orig_v.capacity() << std::endl;
	print_vec<std::vector<int>::iterator>(orig_v, "orig");
	std::cout << "orig_insert it: " << *orig_v.insert(orig_v.end() - 2, 25) << std::endl;
	orig_v.insert(orig_v.begin() + 1, 25);
	std::cout << "capacity orig: " << orig_v.capacity() << std::endl;
	print_vec<std::vector<int>::iterator>(orig_v, "orig");
	std::vector<int> copy_orig_v;
	copy_orig_v = orig_v;
	std::cout << "capacity copy_orig: " << copy_orig_v.capacity() << std::endl;
	std::vector<int> copy_2_orig_v(orig_v);
	std::cout << "capacity copy_2_orig: " << copy_2_orig_v.capacity() << std::endl;
	copy_2_orig_v.insert(copy_2_orig_v.end(), 30);
	print_vec<std::vector<int>::iterator>(copy_orig_v, "copy_orig");
	print_vec<std::vector<int>::iterator>(copy_2_orig_v, "copy_2_orig");
	std::cout << "capacity copy_2_my: " << copy_2_orig_v.capacity() << std::endl;
	std::cout << "capacity orig: " << orig_v.capacity() << std::endl;
	orig_v.insert(orig_v.end() - 5,14, 70);
	print_vec<std::vector<int>::iterator>(orig_v, "orig");
	std::cout << "capacity orig: " << orig_v.capacity() << std::endl;
	std::cout << "size orig: " << orig_v.size() << std::endl;
	print_vec<std::vector<int>::iterator>(copy_orig_v, "copy_orig");
	std::cout << "capacity copy_orig_v: " << copy_orig_v.capacity() << std::endl;
	std::cout << "size copy_orig_v: " << copy_orig_v.size() << std::endl;
	copy_orig_v.insert(copy_orig_v.begin(), orig_v.begin(), orig_v.end());
	print_vec<std::vector<int>::iterator>(copy_orig_v, "copy_orig");
	std::cout << "capacity copy_orig_v: " << copy_orig_v.capacity() << std::endl;
	std::cout << "size copy_orig_v: " << copy_orig_v.size() << std::endl;
	copy_orig_v.push_back(60);
	print_vec<std::vector<int>::iterator>(copy_orig_v, "copy_orig");
	std::cout << "capacity copy_orig_v: " << copy_orig_v.capacity() << std::endl;
	std::cout << "size copy_orig_v: " << copy_orig_v.size() << std::endl;
	copy_orig_v.insert(copy_orig_v.begin(), copy_2_orig_v.begin(), copy_2_orig_v.end());
	print_vec<std::vector<int>::iterator>(copy_orig_v, "copy_orig");
	std::cout << "capacity copy_orig_v: " << copy_orig_v.capacity() << std::endl;
	std::cout << "size copy_orig_v: " << copy_orig_v.size() << std::endl;
	copy_orig_v.pop_back();
	print_vec<std::vector<int>::iterator>(copy_orig_v, "copy_orig_v");
	std::cout << "capacity copy_orig_v: " << copy_orig_v.capacity() << std::endl;
	std::cout << "size copy_orig_v: " << copy_orig_v.size() << std::endl;
	print_vec<std::vector<int>::iterator>(orig_v, "orig");
	std::cout << "capacity orig: " << orig_v.capacity() << std::endl;
	std::cout << "size orig: " << orig_v.size() << std::endl;
	print_vec<std::vector<int>::iterator>(copy_orig_v, "copy_orig_v");
	std::cout << "capacity copy_orig_v: " << copy_orig_v.capacity() << std::endl;
	std::cout << "size copy_orig_v: " << copy_orig_v.size() << std::endl;
	orig_v.swap(copy_orig_v);
	print_vec<std::vector<int>::iterator>(orig_v, "orig");
	std::cout << "capacity orig: " << orig_v.capacity() << std::endl;
	std::cout << "size orig: " << orig_v.size() << std::endl;
	print_vec<std::vector<int>::iterator>(copy_orig_v, "copy_orig_v");
	std::cout << "capacity copy_orig_v: " << copy_orig_v.capacity() << std::endl;
	std::cout << "size copy_orig_v: " << copy_orig_v.size() << std::endl;

	copy_orig_v.assign(26, 100);
	print_vec<std::vector<int>::iterator>(copy_orig_v, "copy_orig_v");
	std::cout << "capacity copy_orig_v: " << copy_orig_v.capacity() << std::endl;
	std::cout << "size copy_orig_v: " << copy_orig_v.size() << std::endl;
	copy_orig_v.assign(orig_v.begin(), orig_v.end());
	print_vec<std::vector<int>::iterator>(copy_orig_v, "copy_orig_v");
	std::cout << "capacity copy_orig_v: " << copy_orig_v.capacity() << std::endl;
	std::cout << "size copy_orig_v: " << copy_orig_v.size() << std::endl;

	try {
		copy_orig_v.at(100) = 100;      // vector::at throws an out-of-range
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
	std::cout << "front copy_orig_v: " << copy_orig_v.front() << std::endl;
	std::cout << "at copy_orig_v: " << copy_orig_v.at(20) << std::endl;
	std::cout << "[] copy_orig_v: " << copy_orig_v[7] << std::endl;
	std::cout << "back copy_orig_v: " << copy_orig_v.back() << std::endl;

	orig_v = copy_orig_v;
	orig_v[23] = 2;
	print_vec<std::vector<int>::iterator>(copy_orig_v, "copy_orig_v");
	print_vec<std::vector<int>::iterator>(orig_v, "orig_v");
	std::cout << "operator== : " << (orig_v == copy_orig_v) << std::endl;
	std::cout << "operator== : " << (copy_orig_v == copy_orig_v) << std::endl;
	std::cout << "operator!= : " << (orig_v != copy_orig_v) << std::endl;
	std::cout << "operator!= : " << (copy_orig_v != copy_orig_v) << std::endl;
	std::cout << "operator<= : " << (orig_v <= copy_orig_v) << std::endl;
	std::cout << "operator<= : " << (copy_orig_v <= copy_orig_v) << std::endl;
	std::cout << "operator>= : " << (orig_v >= copy_orig_v) << std::endl;
	std::cout << "operator>= : " << (copy_orig_v >= copy_orig_v) << std::endl;
	std::cout << "operator<  : " << (orig_v < copy_orig_v) << std::endl;
	std::cout << "operator<  : " << (copy_orig_v < copy_orig_v) << std::endl;
	std::cout << "operator>  : " << (orig_v > copy_orig_v) << std::endl;
	std::cout << "operator>  : " << (copy_orig_v > copy_orig_v) << std::endl;
	auto end_orig = std::chrono::system_clock::now();

	std::cout << "ORIG Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_orig - start_orig).count() << std::endl;
	std::cout << "MY Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_my - start_my).count() << std::endl;
	return 0;
}
