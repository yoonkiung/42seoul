#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs )
	{
		this->_deque = rhs.getDeque();
		this->_list = rhs.getList();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
typedef std::numeric_limits< double > dbl;

void PmergeMe::printTimeDeque(int ac)
{
	std::cout.precision(7);
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << _durationDeque << " us" << std::endl;	
}

void PmergeMe::printTimeList(int ac)
{
	std::cout.precision(7);
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::list : " << _durationList << " us" << std::endl;
}

void PmergeMe::printSequence(std::string buffer)
{
	std::deque<int>::iterator iterDeque;
	std::list<int>::iterator iterList;

	std::cout << buffer << ":\t";
	for (iterDeque = _deque.begin(); iterDeque != _deque.end(); iterDeque++)
	{
		std::cout << *iterDeque << " ";
	}
	std::cout << std::endl;
}

int	PmergeMe::setContainers(int ac, char **av)
{
	for (int i = 0; i < ac; i++)
	{
		if (!setContainer(av[i]))
			return (0);
	}
	return (1);
}

int	PmergeMe::setContainer(std::string av)
{
	std::string token;
	std::stringstream iss(av);
	long long temp;

	while (iss >> temp)
	{
		if (temp > INT_MAX || temp <= 0)
			return (0);
		_deque.push_back(static_cast<int>(temp));
		_list.push_back(static_cast<int>(temp));
	}
	return (1);
}

void	PmergeMe::mergeList(int left, int mid, int right)
{
	std::list<int>::iterator iterList, iterL, iterR;
	int	i, j;
	int n1 = mid - left + 1;
    int n2 = right - mid;
	std::list<int> L, R;
	
	iterList = _list.begin();
	for (j = 0; j < left; j++)
		iterList++;

	for (i = 0; i < n1; i++, iterList++)
		L.push_back(*iterList);
	
	for (i = 0; i < n2; i++, iterList++)
		R.push_back(*iterList);

	i = 0;
	j = 0;
	iterList = _list.begin();
	iterL = L.begin();
	iterR = R.begin();
	while (i < n1 && j < n2)
	{
		if (*iterL <= *iterR)
		{
			*iterList = *iterL;
			iterList++;
			iterL++;
			i++;
		}
		else
		{
			*iterList = *iterR;
			iterList++;
			iterR++;
			j++;
		}
	}
	while (i < n1)
	{
		*iterList = *iterL;
		iterList++;
		iterL++;
		i++;
	}
	while (j < n2)
	{
		*iterList = *iterR;
		iterList++;
		iterR++;
		j++;
	}
}

void	PmergeMe::insertionSortList(int n, int start)
{
	std::list<int>::iterator	iterI;
	std::list<int>::iterator	iterJ;
	std::list<int>::iterator	iterNextJ;
	int	i, j, key;
	
	for (iterI = _list.begin(), i = 0; i < start + 1; i++)
		iterI++;

	for (i = 1; i < n; i++, iterI++)
	{
		key = *iterI;

		iterJ = --iterI;
		iterI++;
		j = i - 1;
		while (j >= 0 && *iterJ > key)
		{
			iterNextJ = ++iterJ;
			iterJ--;
			*iterNextJ = *iterJ;
			j -= 1;
			iterJ--;
		}
		iterNextJ = ++iterJ;
		iterJ--;
		*iterNextJ = key;
	}
}

void	PmergeMe::mergeSortList(int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;

		mergeSortList(left, mid);

		mergeSortList(mid + 1, right);

		if (right - left + 1 < 8)
			insertionSortList(right - left + 1, left);
		else
			mergeList(left, mid, right);
	}
}

void	PmergeMe::mergeDeque(int left, int mid, int right)
{
	int	i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	std::deque<int> L, R;

	for (i = 0; i < n1; i++)
		L.push_back(_deque[left + i]);
	for (j = 0; j < n2; j++)
		R.push_back(_deque[mid + 1 + j]);
	
	i = 0; j = 0; k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			_deque[k++] = L[i++];
		else
			_deque[k++] = R[j++];
	}

	while (i < n1)
		_deque[k++] = L[i++];
	while (j < n2)
		_deque[k++] = R[j++];
}

void	PmergeMe::insertionSortDeque(int n, int start)
{
	int i, j, key;

	for (i = 1; i < n; i++)
	{
		key = _deque[start + i];
		j = i - 1;

		while (j >= 0 && _deque[start + j] > key)
		{
			_deque[start + j + 1] = _deque[start + j];
			j--;
		}

		_deque[start + j + 1] = key;
	}
}

void	PmergeMe::mergeSortDeque(int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;

		mergeSortDeque(left, mid);
		mergeSortDeque(mid + 1, right);

		if (right - left + 1 < 8)
			insertionSortDeque(right - left + 1, left);
		else
			mergeDeque(left, mid, right);	
	}
}

void	PmergeMe::sorting(int ac)
{
	clock_t	start;
	clock_t	end;
	


	start = clock();
	mergeSortDeque(0, ac - 2);
	end = clock();
	_durationDeque = static_cast<double>(end - start) / 1000;
	std::cout << "start " << start << std::endl;
	std::cout << "end : " << end << std::endl;
	start = clock();
	mergeSortList(0, ac - 2);
	end = clock();
	_durationList = static_cast<double>(end - start) / 1000;

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::deque<int> PmergeMe::getDeque() const
{
	return (this->_deque);
}

std::list<int> PmergeMe::getList() const
{
	return (this->_list);
}


/* ************************************************************************** */