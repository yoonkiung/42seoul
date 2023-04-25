#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>
#include <sstream>

class BitcoinExchange
{

	public:

		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();

		int						printNotPositive();
		int						printInputError(std::string buff);
		void					open_csv();
		int						power(int num, int i);
		std::pair<int, double>	parsing(std::string date);
		int						checkInfo(int year, int month, int day, double value, std::string buffer);
		std::string 			intToString(int value);
		void					findData(int convert, double value);
		int						vaildCheck(std::string buffer);
		void					matchValue(std::string date);
		void					printInfo(std::string filename);
		void					setMap();
		
		BitcoinExchange &		operator=( BitcoinExchange const & rhs );

		std::map<int, double>	getbitcoin();


	private:
		std::ifstream fs;
		std::ifstream input_fs;
		std::map<int, double> bitcoin;
};

#endif /* ************************************************* BITCOINEXCHANGE_H */