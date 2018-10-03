#include <iomanip>
#include <iostream>
#include "stock.h"
using namespace std;

stock::stock()
{}

stock::stock(char * investment_name, char * investment_type, int investment_amount, float investment_price) :
	name(investment_name), type(investment_type), amount(investment_amount), price(investment_price) {}

void stock::set_investment(char * investment_name, char * investment_type, int investment_amount, float investment_price)
{
	name = investment_name;
	type = investment_type;
	amount = investment_amount;
	price = investment_price;
}
void stock::recalc_investment(stock purchase, stock sale)
{
	price = (amount * price + purchase.amount * purchase.price) / (amount + purchase.amount);
	amount += (purchase.amount - sale.amount);
}
void stock::show_investment() const
{
	if (amount != 0)
		cout << " " << setw(20) << left << name << setw(12) << left << type
		<< setw(15) << left << amount << setw(12) << left << price<<endl;
}
char * stock::get_name() const
{
	return name;
}
char * stock::get_type() const
{
	return type;
}
int stock::get_amount() const
{
	return amount;
}
float stock::get_price() const
{
	return price;
}
