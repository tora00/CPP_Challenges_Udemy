#include <iostream>

using namespace std;

int main(){
	const int dollar = 100;
	const int quarter = 25;
	const int dime = 10;
	const int nickel = 5;
	const int penny = 1;
	
	int cents;
	int part_dollar;
	int part_quarter;
	int part_dime;
	int part_nickel;
	int part_penny;
	
	cout<<"Enter number of cents :";
	cin>>cents;
	
	part_dollar = cents/dollar;
	cents%=dollar;
	part_quarter = cents/quarter;
	cents%=quarter;
	part_dime = cents/dime;
	cents%=dime;
	part_nickel = cents/nickel;
	cents%=nickel;
	part_penny = cents;
	
	cout<<"Dollars :"<<part_dollar<<"\n"
		<<"Quarters :"<<part_quarter<<"\n"
		<<"Dimes :"<<part_dime<<"\n"
		<<"Nickels :"<<part_nickel<<"\n"
		<<"Pennies :"<<part_penny<<endl;
	
	
	
	return 0;
}