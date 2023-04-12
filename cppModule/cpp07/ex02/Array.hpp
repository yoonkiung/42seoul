#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array
{

	public:

		Array() : _n(0)
		{
			_arr = new T[0];
		}
		Array(unsigned int n) : _n(n)
		{
			_arr = new T[n];
		}
		Array( const Array & src )
		{
			*this = src;
		}

		~Array()
		{
			delete[] _arr;
		}

		Array &		operator=( Array const & rhs )
		{
			if ( this != &rhs )
			{
				this->_n = rhs._n;
				this->_arr = new T[_n];
				for (unsigned int i = 0; i < _n; i++)
					this->_arr[i] = rhs._arr[i];
			}
			return *this;
		}

		T &		operator[]( const unsigned int index )
		{
			if (index < 0 || index >= _n)
				throw std::out_of_range("index of of range");
			else
				return _arr[index];
		}

		int size() const
		{
			return (_n);
		}

	private:
		T *_arr;
		unsigned int _n;
};

#endif /* *********************************************************** ARRAY_H */