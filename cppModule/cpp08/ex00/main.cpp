#include "easyfind.hpp"

int main()
{
	std::cout << "*******Test 1*********" << std::endl;
    {
		std::vector<int> vec(5, 5);
		for (int i = 0; i < 5; i++)
			vec[i] = i;
		std::vector<int>::iterator found = easyfind(vec, 2);
		if (found == vec.end())
			std::cout << "cannot find 2 in vector" << std::endl;
		else
			std::cout << "found 2 in vector " << *found << std::endl;
		if (easyfind(vec, 99) == vec.end())
			std::cout << "not found in vector" << std::endl;
	}
	std::cout << "*******Test 2*********" << std::endl;
	{
		std::list<int> lis(5);
		for (int i = 0; i < 5; i++)
			lis.push_back(i);
		std::list<int>::iterator found = easyfind(lis, 4);
		if (found == lis.end())
			std::cout << "cannot find 2 in list" << std::endl;
		else
			std::cout << "found 4 in list " << *found << std::endl;
		if (easyfind(lis, 99) == lis.end())
			std::cout << "not found in vector" << std::endl;			
	}
	std::cout << "*******Test 3*********" << std::endl;
	{
		std::deque<int> deq;
		for (int i = 0; i < 5; i++)
			deq.push_back(i);
		std::deque<int>::iterator found = easyfind(deq, 4);
		if (found == deq.end())
			std::cout << "cannot find 2 in deq" << std::endl;
		else
			std::cout << "found 4 in list " << *found << std::endl;
		if (easyfind(deq, 99) == deq.end())
			std::cout << "not found in vector" << std::endl;			
	}
}