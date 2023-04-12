#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <deque>
# include <exception>
# include <algorithm>
# include <limits>

class Span
{

	public:
		class FullSpanException : public std::exception
		{
			const char* what() const throw();
		};

		class SpanNotFound : public std::exception
		{
			const char* what() const throw();
		};
		
	public:
		Span();
		Span(unsigned int n);
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );

		void addNumber(int n);
		void addNumberRange(std::deque<int> &temp);
		unsigned int shortestSpan();
		unsigned int longestSpan();

	private:

		unsigned int _n;
		std::deque<int> _deq;	

};

bool comp(int a, int b);
// std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */