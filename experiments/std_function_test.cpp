#include <iostream>
#include <functional>

void function_wrapper(std::function<void()> function){
	function();
}

int main(){
	int n=0;

	std::function<void()> function_to_pass = [](){
	std::cout<<"called first function\n";
	}; //noop
	function_wrapper(function_to_pass);

	// increment n
	std::cout << "n before is: " << n << "\n";
	function_to_pass = [&n]() mutable { n++; };
	function_wrapper(function_to_pass);
	std::cout << "n after is: " << n << "\n";
	return 0;
}
