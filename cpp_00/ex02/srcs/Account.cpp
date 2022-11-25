#include "../includes/Account.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

int Account::t::_nbAccounts;
int	Account::t::_totalAmount;
int	Account::t::_totalNbDeposits;
int	Account::t::_totalNbWithdrawals;

//What is this second constructor used for?
void	Account(void) {
}

/* Constructor */
Account::Account(int initial_deposit) {
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();	
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;

	//How to set account index??
}

/* Destructor */
Account::~Account() {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

/* Static Functions */

/* Get number of open accounts */
int	Account::t::getNbAccounts( void ) {
	return (_nbAccounts);
}

/* Get total sum of balances for all accounts */
int	Account::getTotalAmount( void ) {
	return(_totalAmount);
}

/* Get total # of deposits for all accounts */
int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

/* Get total # of withdrawals for all accounts */
int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

/* Display totals for all accounts */
void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << ";" << std::endl;
}

/* Display timestamp followed by space (no newline) */
void	Account::t::_displayTimestamp(void) {
	std::time_t result = std::time(nullptr);
	char Output[19];
	strftime(Output, 19, "[%Y%m%d_%H%M%S] ", std::localtime(&result));
	std::cout << Output;
}

/* Non-static member functions */

/* Accessor function to make a deposit */
void	Account::makeDeposit( int deposit ) {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << ";" << std::endl;
}

/* Accessor function to make a withdrawal */
bool	Account::makeWithdrawal( int withdrawal ) {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount)		/* If insufficient funds, return false and do not perform withdrawal */
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << ";" << std::endl;
	return (true);
}

/* Accessor to get account balance */
int		Account::checkAmount( void ) const {
	return (this->_amount);
}

/* Display status of individual account */
void	Account::displayStatus( void ) const {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << ";" << std::endl;
}
