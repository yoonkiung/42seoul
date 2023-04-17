#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <vector>
# include <sstream>

class RPN
{

	public:

		RPN();
		RPN( RPN const & src );
		~RPN();

		RPN &		operator=( RPN const & rhs );
		
		void parsingDebug();
		void	parsing(std::string av);
		int	isAllNum(std::string str);
		int isOnlyOperator(std::string str);
		int	check();
		int	isInInt(int a, int b, std::string oper);
		int	operation(std::string oper);
		int	calculate();
		
		int	setAv(std::string av);
		std::string getAv() const;
		std::stack<int> getStack() const;
		std::vector<std::string>  getToken() const;

	private:
		std::string _av;
 	 	std::stack<int> stack;
		std::vector<std::string> _token;
};


#endif /* ************************************************************* RPN_H */