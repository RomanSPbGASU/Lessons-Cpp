#include "Average.h"

Average::Average()
{
	amount = 0;
	price = 0;
	count = 0;
}
void Average::buy(int investment_amount, float investment_price)
{
	amount += investment_amount;
	price *= count++; // + investment_price)/(count * amount);
	price += investment_price;
	price /= count;

	}
float Average::sale(int investment_amount, float investment_price)
{
	count--;
	amount -= investment_amount;
	return (investment_price - price) * investment_amount;
}