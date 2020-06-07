#include <iostream>

int main(){
	std::cout<<"Enter your favorite number between 1 and 100: ";
	
	int num;
	
	std::cin>>num;
	
	std::cout<<"Amazing!! That's my favorite number too!"<<std::endl;
	std::cout<<"No really!! "<<num<<" is my favorite number!"<<std::endl;
	
	return 0;
}