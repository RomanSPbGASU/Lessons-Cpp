class stock
{
private:
	char * name;
	char * type;
	int amount;
	float price;
public:
	stock(char * investment_name, char * investment_type, int investment_amount, float investment_price) :
		name(investment_name), type(investment_type), amount(investment_amount), price(investment_price) {}
	void set_investment(char * investment_name, char * investment_type, int investment_amount, float investment_price);
	void recalc_investment(stock purchase, stock sale);
	void show_investment() const;
	float portfolio_cost(stock portfolio[], int count) const; //смог сделать только так
};