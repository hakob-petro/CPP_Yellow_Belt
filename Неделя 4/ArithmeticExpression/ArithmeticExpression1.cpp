#include <iostream>
#include <deque>
#include <string>

using namespace std;


struct operation{
	string type;
	string value;
};

deque<string>& push_bracketts(deque<string>& deq){
	deq.push_front("(");
	deq.push_back(")");
	return deq;
}

int main(){
	deque<string> result;
	int number;

	cin >> number;
	result.push_back(to_string(number));

	int count;
	cin >> count;
	while(count > 0){
		operation command;
		cin >> command.type >> command.value;
		push_bracketts(result);
		result.push_back(" ");
		result.push_back(command.type);
		result.push_back(" ");
		result.push_back(command.value);
		
		count --;
	}

	
	for(auto elem: result){
		cout << elem;
	}
	return 0;
}
