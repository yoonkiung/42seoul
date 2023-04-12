#include "Account.hpp"
#include <iostream>
#include <ctime>

//static 변수 초기화
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
//

//생성자
Account::Account( int initial_deposit )
{
	//멤버 변수 초기화
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	//

	//출력
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << initial_deposit 
			  << ";created" << std::endl;
	//
}
//

//소멸자
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}
//

//static 메소드
	int	Account::getNbAccounts(void)
	{
		return (_nbAccounts);
	}

	int	Account::getTotalAmount( void )
	{
		return (_totalAmount);
	}

	int	Account::getNbDeposits(void)
	{
		return (_totalNbDeposits);
	}

	int	Account::getNbWithdrawals(void)
	{
		return (_totalNbWithdrawals);
	}

	void	Account::displayAccountsInfos(void)
	{
		_displayTimestamp();
		std::cout << "accounts:" << _nbAccounts
				  << ";total:" << _totalAmount
				  << ";deposits:" << _totalNbDeposits
				  << ";withdrawals:" << _totalNbWithdrawals
				  << std::endl; 
	}

	void	Account::_displayTimestamp( void )
	{
		time_t	timestamp;
		char	buff[16];

		time(&timestamp);
		strftime(buff, sizeof(buff), "%Y%m%d_%H%M%S", localtime(&timestamp));
		std::cout << "[" << buff << "] ";
	}
//

// 메소드
void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";deposit:" << deposit
			  << ";amount:" << _amount + deposit
			  << ";nb_deposits:" << ++_nbDeposits
			  << std::endl;
	
	_amount += deposit;
	_totalNbDeposits++;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount;
	if (_amount - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal
				  << ";amount:" << _amount
				  << ";nb_withdrawals:" << ++_nbWithdrawals
				  << std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}