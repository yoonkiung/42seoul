#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <deque>
# include <list>
# include <sstream>
# include <ctime>

class PmergeMe
{

	public:

		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );
		void printTimeDeque(int ac);
		void printTimeList(int ac);
		void printSequence(std::string buffer);
		int	setContainers(int ac, char **av);
		int	setContainer(std::string av);
		void	mergeList(int left, int mid, int right);
		void	insertionSortList(int n, int start);
		void	mergeSortList(int left, int right);
		void	mergeDeque(int left, int mid, int right);
		void	insertionSortDeque(int n, int start);
		void	mergeSortDeque(int left, int right);
		void	sorting(int ac);
		
		std::deque<int> getDeque() const;
		std::list<int> getList() const;

	private:
		std::deque<int> _deque;
		std::list<int> _list;
		double	_durationDeque;
		double	_durationList;
};


#endif /* ******************************************************** PMERGEME_H */

