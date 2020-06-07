#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int isValidInt(string input){
	try{
		int i = stoi(input);
		return 1;
	}
	catch(invalid_argument const &e){
		return 0;
	}
	catch(out_of_range const &e){
		return -1;
	}
	return 0;
}

int main(){
	
	char selection;
	int current_list_size;
	vector <int> list;
	
	string menu_option =
		string("P - Print numbers\n")+
		"A - Add a number\n"+
		"M - Display mean of the numbers\n"+
		"S - Display the smallest number\n"+
		"L - Display the largest number\n"+
		"Q - Quit\n\n"+
		"Enter your choice: ";
		
	string add_menu = "Input an integer: ";
	string not_integer = "Invalid input - not a number. Please try again.\n";
	string not_in_range = "Invalid input - number not in valid range. Please try again.\n";
	string empty_list = "The list is currently empty.";
	
	do{
		cout<<menu_option;
		cin>>selection;
		current_list_size = list.size();
		
		switch(tolower(selection)){
			case 'p':
				if(current_list_size<1)
					cout<<empty_list<<endl;
				else{
					cout<<"[";
					for(auto i:list){
						cout<<" "<<i<<" ";
					}
					cout<<"]"<<endl;
				}
			break;
			case 'a':
			{
				int validity = 0;
				string some_num;
				
				do{					
					cout<<add_menu;
					cin>>some_num;
					cin.clear();
					cin.ignore(INT_MAX,'\n');
					validity = isValidInt(some_num);
					if(validity==0){
						cout<<not_integer<<endl;
					}
					else if(validity==-1){
						cout<<not_in_range<<endl;
					}
				} while(validity<1);
				list.push_back(stoi(some_num));
			}
			break;
			case 'm':
				if(current_list_size<1)
					cout<<empty_list<<endl;
				else{
					int sum = 0;
					int mean = 0;
					for(int i = 0; i<list.size(); i++){
						sum += list.at(i);
					}
					mean = static_cast<int>(sum/list.size());
					cout<<"The mean is: "<<mean<<endl;
				}
			break;
			case 's':
				if(current_list_size<1)
					cout<<empty_list<<endl;
				else{
					int* smallest;
					smallest = min_element(list.begin(),list.end());
					cout<<"Smallest element is: "<<*smallest<<endl;
				}
			break;
			case 'l':
			break;
			case 'q':
			break;
			default:
				cout<<"Unknown selection, please try again.\n\n"<<endl;
			break;
		}
	}while (tolower(selection)!='q');
	
	
	return 0;
}