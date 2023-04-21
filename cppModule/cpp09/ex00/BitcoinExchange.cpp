#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{
	open_csv();
	setMap();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
	this->fs.close();
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if ( this != &rhs )
	{
		this->open_csv();
		this->setMap();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	BitcoinExchange::printInputError(std::string buff)
{
	std::cout << "Error: bad input => " << buff << std::endl;
}

void	BitcoinExchange::open_csv()
{
	this->fs.open("data.csv");
}

int	BitcoinExchange::power(int num, int i)
{
	int ret = 1;
	for (int j = 0; j < i; j++)
		ret = ret * num;
	return (ret);
}

std::pair<int, double>	BitcoinExchange::parsing(std::string date)
{
	std::pair <int, double> p;
	int	day = 0;
	double	value = 0;
	int	pos = 0;
	int	temp_day;
	for (int i = 0; i < 2; i++)
	{
		pos = date.find("-");
		std::stringstream temp(date.substr(0, pos));
		temp >> temp_day;
		day = day + temp_day * this->power(10, (2 - i) * 2);
		date.erase(0, pos + 1);
	}
	
	pos = date.find(",");
	std::stringstream _temp(date.substr(0, pos));
	_temp >> temp_day;
	day = day + temp_day;
	date.erase(0, pos + 1);
	
	std::stringstream temp_value(date);
	temp_value >> value;

	p.first = day;
	p.second = value;
	return (p);
}

int	BitcoinExchange::checkInfo(int year, int month, int day, double value, std::string buffer)
{
	if (year < 0 || month < 0 || day < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (0);
	}
	if (year < 2009)
	{
		printInputError(buffer);
		return (0);
	}
	if (month > 12)
	{
		printInputError(buffer);
		return (0);
	}
	if (month == 2 && day > 29)
	{
		printInputError(buffer);
		return (0);
	}
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
	{
		printInputError(buffer);
		return (0);
	}
	if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		printInputError(buffer);
		return (0);
	}
	if (value <= 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (0);
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (0);
	}
	return (1);
}

std::string BitcoinExchange::intToString(int value)
{
	std::string ret;
	std::string day_part;
	std::string month_part;
	std::string year_part;
	int day;
	int month;
	int year;

	day = value % 100;
	value = value / 100;
	std::stringstream temp_day;
	temp_day << day;
	day_part = temp_day.str();
	if (day_part.length() == 1)
		day_part = "0" + day_part;
	month = value % 100;
	value = value / 100;
	std::stringstream temp_month;
	temp_month << month;
	month_part = temp_month.str();
	if (month_part.length() == 1)
		month_part = "0" + month_part;
	year = value;
	std::stringstream temp_year;
	temp_year << year;
	year_part = temp_year.str();

	ret = year_part + "-" + month_part + "-" + day_part;

	return (ret);
}

void	BitcoinExchange::findData(int convert, double value)
{
	int	flag;

	std::map<int, double>::iterator iter;

	iter = bitcoin.find(convert);
	if (iter != bitcoin.end())
	{
		std::cout << this->intToString(iter->first) << " => " << value << " = " << iter->second * value << std::endl;
	}
	else
	{
		flag = 0;
		for (iter = bitcoin.begin(); iter != bitcoin.end(); iter++)
		{
			if (iter->first > convert)
			{
				iter--;
				std::cout << this->intToString(convert) << " => " << value << " = " << iter->second * value << std::endl;
				flag = 1;
				break ;
			}
		}
		if (!flag)
		{
			iter--;
			std::cout << this->intToString(convert) << " => " << value << " = " << iter->second * value << std::endl;
		}
	}
}

int	BitcoinExchange::vaildCheck(std::string buffer)
{
	int	i = 0;

	while (buffer[i])
	{
		if ((buffer[i] >= '0' && buffer[i] <= '9') || buffer[i] == '|' || buffer[i] == ' ' || buffer[i] == '.' ||  buffer[i] == '-')
			i++;
		else
		{
			printInputError(buffer);
			return (0);
		}
	}
	if (buffer[4] != '-' || buffer[7] != '-' || buffer[10] != ' ')
	{
		printInputError(buffer);
		return (0);
	}
	return (1);
}

void	BitcoinExchange::matchValue(std::string date)
{
	std::string buffer = date;
	int	year;
	int month;
	int day;
	int convert;
	double	value;
	size_t	pos = 0;
	if (!vaildCheck(date))
		return ;
	pos = date.find("-");
	if (pos == std::string::npos)
	{
		this->printInputError(buffer);
		return ;
	}
	std::stringstream temp_year(date.substr(0, pos));
	temp_year >> year;
	date.erase(0, pos + 1);
	if (!(date[0] >= '0' && date[0] <= '9'))
	{
		this->printInputError(buffer);
		return ;
	}
	pos = date.find("-");

	std::stringstream temp_month(date.substr(0, pos));
	temp_month >> month;
	date.erase(0, pos + 1);

	pos = date.find(" ");
	if (pos == std::string::npos)
	{
		this->printInputError(buffer);
		return ;
	}
	std::stringstream temp_day(date.substr(0, pos));
	temp_day >> day;
	date.erase(0, pos + 1);

	pos = date.find("|");
	if (pos == std::string::npos)
	{
		this->printInputError(buffer);
		return ;
	}
	date.erase(0, pos + 1);
	pos = date.find(" ");
	if (pos == std::string::npos)
	{
		this->printInputError(buffer);
		return ;
	}
	date.erase(0, pos + 1);
	if (date == "")
	{
		this->printInputError(buffer);
		return ;
	}
	std::stringstream temp(date);
	temp >> value;
	if (year == 0 || month == 0 || day == 0)
	{
		this->printInputError(buffer);
		return ;
	}
	if (!this->checkInfo(year, month, day, value, buffer))
		return ;
	convert = year * power(10, 4) + month * power(10, 2) + day;
	findData(convert, value);
}

void	BitcoinExchange::printInfo(std::string filename)
{
	input_fs.open(filename);
	if (input_fs.fail() || this->bitcoin.empty())
	{
		std::cout << "Error: File not exsit" << std::endl;
		return ;
	}
	std::string buff;

	getline(this->input_fs, buff);
	while (!this->input_fs.eof())
	{
		getline(this->input_fs, buff);
		if (buff == "")
			break ;
		this->matchValue(buff);
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	BitcoinExchange::setMap()
{
	std::string buff;
	getline(this->fs, buff);

	while (!this->fs.eof())
    {
        getline(this->fs, buff);
		if (buff == "")
			break ;
		this->bitcoin.insert(this->parsing(buff));
    }
}

std::map<int, double> BitcoinExchange::getbitcoin()
{
	return (this->bitcoin);
}

/* ************************************************************************** */