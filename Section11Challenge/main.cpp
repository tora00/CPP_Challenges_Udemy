#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

enum Process {
	PRINT_LIST,
	ADD_NUM,
	DISP_MEAN,
	DISP_SMALLEST,
	DISP_LARGEST,
	FIND_NUM,
	QUIT,
	INVALID
};

//================Prototype======================================================

void menu();
void printMenu();
void printNumbers(vector<int> &numberList);
void addNumber(vector<int> &numberList);
void findNum(vector<int> &numberList);
void displayMean(vector<int> &numberList);
void displaySmallest(vector<int> &numberList);
void displayLargest(vector<int> &numberList);
void executeProcess(Process type);
void printEmpty();
Process processInput(string input);


// Entry Point
int main(){
	menu();
	return 0;
}

//===============Function implementation========================================
void menu(){
	string input;
	Process opt;
	
	do{
		printMenu();
		cin>>input;
		opt = processInput(input);
		if(opt<QUIT){
			executeProcess(opt);
		}
		else if(opt==INVALID){
			cout<<"Invalid selection. Please try again.\n"<<endl;
		}
	}
	while(opt!=QUIT);
	
	cout<<"Exiting program. Goodbye."<<endl;
}

/**
 * @brief Calls function based on process
 * @param type
 */
void executeProcess(Process type){
	static vector<int> numberList;
	switch(type){
		case PRINT_LIST:
			printNumbers(numberList);
			break;
		case ADD_NUM:
			addNumber(numberList);
			break;
		case DISP_MEAN:
			displayMean(numberList);
			break;
		case DISP_SMALLEST:
			displaySmallest(numberList);
			break;
		case DISP_LARGEST:
			displayLargest(numberList);
			break;
		case FIND_NUM:
			findNum(numberList);
			break;			
		//Should never reach this point
		case QUIT:
		case INVALID:
		default:
			break;
	}
}

/**
 * @brief Finds a number in the list
 * @param numberList
 */
void findNum(vector<int> &numberList){
	string input;
	
	cout<<"Input number to search: ";
	cin>>input;
	
	try{
		int num = stoi(input);
		int last = *numberList.end();
		
		int idx = *find(numberList.begin(),numberList.end(),num);
		if(idx!=last){
			cout<<"The number "<<num<<" is in the list.\n"<<endl;
		}
		else{
			cout<<"The number "<<num<<" is NOT in the list.\n"<<endl;
		}
	}
	catch(invalid_argument const &e){
		cout<<"Invalid number. Returning to main menu.\n"<<endl;
	}
	catch(out_of_range const &e){
		cout<<"Integer overflow. Returning to main menu.\n"<<endl;
	}
}

/**
 * @brief Prints the largest number in the list
 * @param numberList
 */
void displayLargest(vector<int> &numberList){
	if(numberList.size()>0){
		int max = *max_element(numberList.begin(),numberList.end());
		cout<<"The largest number in the list is: "<<max<<"\n"<<endl;
	}
	else{
		printEmpty();
	}
}

/**
 * @brief Prints the smallest number in the list
 * @param numberList
 */
void displaySmallest(vector<int> &numberList){
	if(numberList.size()>0){
		int min = *min_element(numberList.begin(),numberList.end());
		cout<<"The smallest number in the list is: "<<min<<"\n"<<endl;
	}
	else{
		printEmpty();
	}
}

/**
 * @brief Prints mean of the list
 * @param numberList
 */
void displayMean(vector<int> &numberList){
	auto s = numberList.size();
	float average = 0.0f;
	if(s>0){
		average = accumulate(numberList.begin(), numberList.end(), 0.0) / s;
		cout<<"The average of numbers in the list is: "<<average<<"\n"<<endl;
	}
	else{
		printEmpty();
	}
}

void printEmpty(){
	cout<<"The list is currently empty. Please add a number first.\n"<<endl;
}

/**
 * @brief Submenu for adding a number
 * @param num
 * @param numberList
 */
void addNumber(vector<int> &numberList){
	string input;
	cout<<"Input a number: ";
	cin>>input;
	try{
		int num = stoi(input);
		numberList.push_back(num);
		cout<<"Added "<<num<<" to the list.\n"<<endl;
	}
	catch(invalid_argument const &e){
		cout<<"Invalid number. Returning to main menu.\n"<<endl;
	}
	catch(out_of_range const &e){
		cout<<"Integer overflow. Returning to main menu.\n"<<endl;
	}	
}

/**
 * @brief Print numbers in list. Notify if list is currently empty.
 * @param numberList
 */
void printNumbers(vector<int> &numberList){
	if(numberList.size()>0){
		cout<<"Items in list:"<<endl;
		string output = "[";
		for(size_t i = 0; i<numberList.size(); i++){
			string conv = to_string(numberList.at(i));
			output += " "+conv;
			if(i<numberList.size()-1)
				output += ",";
		}
		cout<<output<<" ]"<<endl;
	}
	else{
		printEmpty();
	}
}

/**
 * @brief Print menu selection
 */
void printMenu(){
	cout<<"P - Print numbers"<<endl;
	cout<<"A - Add a number"<<endl;
	cout<<"F - Find number in list"<<endl;
	cout<<"M - Display mean of the numbers"<<endl;
	cout<<"S - Display the smallest number"<<endl;
	cout<<"L - Display the largest number"<<endl;
	cout<<"Q - Quit"<<endl;
	cout<<"Make your selection: ";
}

/*
 * Returns the enum value of the menu option
 */
Process processInput(string input){
	Process res;
	if(input.size()!=1)
		return INVALID;
	switch((int)input.at(0)){
		case 'P':
		case 'p':
			res = PRINT_LIST;
			break;
		case 'A':
		case 'a':
			res = ADD_NUM;
			break;
		case 'M':
		case 'm':
			res = DISP_MEAN;
			break;
		case 'S':
		case 's':
			res = DISP_SMALLEST;
			break;
		case 'L':
		case 'l':
			res = DISP_LARGEST;
			break;
		case 'Q':
		case 'q':
			res = QUIT;
			break;
		case 'F':
		case 'f':
			res = FIND_NUM;
			break;
		default:
			res = INVALID;
			break;
	}
	return res;
}