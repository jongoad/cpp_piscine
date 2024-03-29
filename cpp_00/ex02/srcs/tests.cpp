// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "../includes/Account.hpp"


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t; //Vector array of account objects
	typedef std::vector<int>								  ints_t;     //Vector array of ints
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;  //Create a pair of iterators that allow traversing both vectors together


	//By using typedef on the vector declarations, we can then use the typedefed name to refer to the object type


	//Create a vector array of accounts, calling the constructor with arrays of values, and then setting iterator pointers
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	//Create a vector array of deposits, stored as int, same as above
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	//Create a vector array of deposits, same as above
	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	//Display initial account info after creation
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	//Make deposits
	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
		//This will call makeDeposit with each Account and their paired int value
	}

	//Display account info again
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	//Make withdrawals
	for ( acc_int_t it( acc_begin, wit_begin ); //Create an iterator based on typedef
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	//Display account info after withdrawals
	Account::displayAccountsInfos(); //Display total for all accounts
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) ); //Display individual accounts

	return 0;
}