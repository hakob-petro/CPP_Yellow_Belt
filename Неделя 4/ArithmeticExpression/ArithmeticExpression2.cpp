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

	int count, i=0;
	cin >> count;
	operation command;
	while(count > i){
		if(i != 0){
			string old_type = command.type;
			cin >> command.type >> command.value;
			if ((old_type == "+" || old_type == "-") && (command.type == "*" || command.type == "/")) push_bracketts(result);
			result.push_back(" ");
			result.push_back(command.type);
			result.push_back(" ");
			result.push_back(command.value);
		}else{
			cin >> command.type >> command.value;
			result.push_back(" ");
			result.push_back(command.type);
			result.push_back(" ");
			result.push_back(command.value);
		}
		i++;
	}

	
	for(auto elem: result){
		cout << elem;
	}
	return 0;
}