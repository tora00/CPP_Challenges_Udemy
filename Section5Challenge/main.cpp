#include <iostream>

using namespace std;

int main(){
	const int price_room_small {25};
	const int price_room_large {35};
	const double tax_rate {0.06};
	const int estimate_days_valid {30};
	int in_small;
	int in_large;
	int total_before_tax;
	double tax;
	
	cout<<"Estimate for carpet cleaning service"<<endl;
	cout<<"Number of small rooms: ";
	cin>>in_small;
	cout<<"Number of large rooms: ";
	cin>>in_large;
	cout<<"Price per small room: $"<<price_room_small<<endl;
	cout<<"Price per large room: $"<<price_room_large<<endl;
	total_before_tax = (in_small*price_room_small)+(in_large*price_room_large);
	tax = total_before_tax * tax_rate;
	cout<<"Cost : $"<<total_before_tax<<endl;
	cout<<"Tax: $"<<tax<<endl;
	cout<<"==================================================="<<endl;
	cout<<"Total estimate: $"<<(double)(total_before_tax+tax)<<endl;
	cout<<"This estimate is valid for "<<estimate_days_valid<<" days"<<endl;
	
	
	
	return 0;
}