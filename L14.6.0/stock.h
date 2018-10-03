#pragma once
class stock
{
private:
	char * name;
	char * type;
	int amount;
	float price;
public:
	stock();
	stock(char * investment_name, char * investment_type, int investment_amount, float investment_price);
	void set_investment(char * investment_name, char * investment_type, int investment_amount, float investment_price);
	void recalc_investment(stock purchase, stock sale);
	void show_investment() const;
	char * get_name() const;
	char * get_type() const;
	int get_amount() const;
	float get_price() const;
};