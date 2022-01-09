#include <iostream>
#include <stack>
#include "stack.hpp"

int main()
{
	std::stack<int> orig_s;
	std::cout << "empty orig_s: " << orig_s.empty() << std::endl;
	orig_s.push(20);
	orig_s.push(30);
	orig_s.push(40);
	std::cout << "empty orig_s: " << orig_s.empty() << std::endl;
	std::cout << "top orig_s: " << orig_s.top() << std::endl;
	std::cout << "size orig_s: " << orig_s.size() << std::endl;
	std::stack<int> copy_orig_s(orig_s);

	std::cout << "operator== : " << (orig_s == copy_orig_s) << std::endl;
	std::cout << "operator== : " << (copy_orig_s == copy_orig_s) << std::endl;
	std::cout << "operator!= : " << (orig_s != copy_orig_s) << std::endl;
	std::cout << "operator!= : " << (copy_orig_s != copy_orig_s) << std::endl;
	std::cout << "operator<= : " << (orig_s <= copy_orig_s) << std::endl;
	std::cout << "operator<= : " << (copy_orig_s <= copy_orig_s) << std::endl;
	std::cout << "operator>= : " << (orig_s >= copy_orig_s) << std::endl;
	std::cout << "operator>= : " << (copy_orig_s >= copy_orig_s) << std::endl;
	std::cout << "operator<  : " << (orig_s < copy_orig_s) << std::endl;
	std::cout << "operator<  : " << (copy_orig_s < copy_orig_s) << std::endl;
	std::cout << "operator>  : " << (orig_s > copy_orig_s) << std::endl;
	std::cout << "operator>  : " << (copy_orig_s > copy_orig_s) << std::endl;
	orig_s.pop();
	std::cout << "size orig_s: " << orig_s.size() << std::endl;
	std::cout << "top orig_s: " << orig_s.top() << std::endl;


	std::cout << std::endl;
	std::cout << std::endl;


	ft::stack<int> my_s;
	std::cout << "empty my_s: " << my_s.empty() << std::endl;
	my_s.push(20);
	my_s.push(30);
	my_s.push(40);
	std::cout << "empty my_s: " << my_s.empty() << std::endl;
	std::cout << "top my_s: " << my_s.top() << std::endl;
	std::cout << "size my_s: " << my_s.size() << std::endl;
	ft::stack<int> copy_my_s(my_s);

	std::cout << "operator== : " << (my_s == copy_my_s) << std::endl;
	std::cout << "operator== : " << (copy_my_s == copy_my_s) << std::endl;
	std::cout << "operator!= : " << (my_s != copy_my_s) << std::endl;
	std::cout << "operator!= : " << (copy_my_s != copy_my_s) << std::endl;
	std::cout << "operator<= : " << (my_s <= copy_my_s) << std::endl;
	std::cout << "operator<= : " << (copy_my_s <= copy_my_s) << std::endl;
	std::cout << "operator>= : " << (my_s >= copy_my_s) << std::endl;
	std::cout << "operator>= : " << (copy_my_s >= copy_my_s) << std::endl;
	std::cout << "operator<  : " << (my_s < copy_my_s) << std::endl;
	std::cout << "operator<  : " << (copy_my_s < copy_my_s) << std::endl;
	std::cout << "operator>  : " << (my_s > copy_my_s) << std::endl;
	std::cout << "operator>  : " << (copy_my_s > copy_my_s) << std::endl;
	my_s.pop();
	std::cout << "size my_s: " << my_s.size() << std::endl;
	std::cout << "top my_s: " << my_s.top() << std::endl;
}
