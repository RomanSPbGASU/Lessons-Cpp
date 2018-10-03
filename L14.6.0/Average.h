#include "stock.h"

class Average
{
private:
	int amount;
	float price;
	int count; // количество пакетов акций
public:
	Average();
	void buy(int investment_amount, float investment_price);
	float sale(int investment_amount, float investment_price);
};