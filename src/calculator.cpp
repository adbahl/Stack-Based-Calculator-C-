/*
 *  calculator.cpp : Stack Based Calculator.
 *  The program uses three stacks to save and process input.
 *  First of type int int_stack, second of type double dou_stack, third of type char type_stack.
 *  Each of them saves the type of input and type_stack saves the serially the value to popped.
 *  The values are popped and input operations are performed on it.
 *  Similarly reverse command uses three queues. Deque used for repeat statement.
 *  Created on: Aug 1, 2017
 *  Author: Arvind Bahl, z5129975
 */

// Included files.
#include<iostream>
#include<string>
#include<typeinfo>
#include<stack>
#include <vector>
#include <queue>
#include <deque>
#include<fstream>
#include<typeinfo>
#include <cmath>
#include <stdexcept>

using namespace std;

// Three stack defined at the global level.
std::stack<int> int_stack;
std::stack<double> dou_stack;
std::stack<char> type_stack;

//Calculate function: Calculates and print the output, based on operation as parameter.
void Calculate(string caType){

	std::cout.setf(std::ios::fixed,std::ios::floatfield);
	std::cout.precision(3);
		if (::type_stack.top() == 'i'){ // if the top entity is int.
			auto num1 = ::int_stack.top();
			::int_stack.pop();
			::type_stack.pop();
			if (::type_stack.top() == 'i'){ // if the second entity is int.
				auto num2 = ::int_stack.top();
				::int_stack.pop();
				::type_stack.pop();
				int answer =0;
				if(caType == "sub"){answer = (num1-num2);
				std::cout<< num1 << " - " <<num2 << " = " << answer<<std::endl;}
				if(caType == "add"){answer = (num1+num2);
				std::cout<< num1 << " + " <<num2 << " = " << answer<<std::endl;}
				if(caType == "mult"){answer = (num1*num2);
				std::cout<< num1 << " * " <<num2 << " = " << answer<<std::endl;}
				try{
				if(caType == "div"){
					if (num2 == 0) { std::cout<< "Divison by zero"<<std::endl; return;}
					answer = (num1/num2);
					std::cout<< num1 << " / " <<num2 << " = " << answer<<std::endl;
				}}
				catch(std::overflow_error &err){
					std::cout<<err.what()<< " -->" <<num2<<std::endl;
				}
				::int_stack.push(answer);
				::type_stack.push('i');
			}
			else {
				auto num2 = ::dou_stack.top(); // if the second entity is double.
				::dou_stack.pop();
				::type_stack.pop();
				double answer =0;
				if(caType == "sub"){answer = (num1-num2);
				std::cout<< num1 << " - " <<num2 << " = " << answer<<std::endl;}
				if(caType == "add"){answer = (num1+num2);
				std::cout<< num1 << " + " <<num2 << " = " << answer<<std::endl;}
				if(caType == "mult"){answer = (num1*num2);
				std::cout<< num1 << " * " <<num2 << " = " << answer<<std::endl;}
				try{
					if(caType == "div"){
						//if (num2 == 0) { std::cout<< "Divison by zero"<<std::endl; return;}
						answer = (num1/num2);
						std::cout<< num1 << " / " <<num2 << " = " << answer<<std::endl;}}
				catch(std::overflow_error &err){
					std::cout<<err.what()<<" --> "<<num2<<std::endl;
				}
				::dou_stack.push(answer);
				::type_stack.push('d');
			}
		}
		else {                            // if the top entity is double.
			auto num1 = ::dou_stack.top();
			::dou_stack.pop();
			::type_stack.pop();

			if (::type_stack.top() == 'i'){
				auto num2 = ::int_stack.top();
				::int_stack.pop();
				::type_stack.pop();
				double answer = 0;
				if(caType == "sub"){answer = (num1-num2);
				std::cout<< num1 << " - " <<num2 << " = " << answer<<std::endl;}
				if(caType == "add"){answer = (num1+num2);
				std::cout<< num1 << " + " <<num2 << " = " << answer<<std::endl;}
				if(caType == "mult"){answer = (num1*num2);
				std::cout<< num1 << " * " <<num2 << " = " << answer<<std::endl;}
				try{
					if(caType == "div"){
						if (num2 == 0) { std::cout<< "Divison by zero"<<std::endl; return;}
						answer = (num1/num2);
						std::cout<< num1 << " / " <<num2 << " = " << answer<<std::endl;}}
				catch(std::overflow_error &err){
					std::cout<<err.what()<<" --> "<<num2<<std::endl;
				}
				::dou_stack.push(answer);
				::type_stack.push('d');
			}
			else {                               // if the second entity is double.
				auto num2 = ::dou_stack.top();
				::dou_stack.pop();
				::type_stack.pop();
				double answer =0;
				if(caType == "sub"){answer = (num1-num2);
				std::cout<< num1 << " - " <<num2 << " = " << answer<<std::endl;}
				if(caType == "add"){answer = (num1+num2);
				std::cout<< num1 << " + " <<num2 << " = " << answer<<std::endl;}
				if(caType == "mult"){answer = (num1*num2);
				std::cout<< num1 << " * " <<num2 << " = " << answer<<std::endl;}
				try{
					if(caType == "div"){
						if (num2 == 0) { std::cout<< "Divison by zero"<<std::endl; return;}
						answer = (num1/num2);
						std::cout<< num1 << " / " <<num2 << " = " << answer<<std::endl;}}
				catch(std::overflow_error &err){
					std::cout<<err.what()<<" --> "<<num2<<std::endl;
				}
				::dou_stack.push(answer);
				::type_stack.push('d');
			}
		}
}
// Reverse function pops the top item and reverse the popped number entity in stack.
void reverse(){

	int reverse_num=0;        //initiate the variable reverse_num.
	std::queue <int> int_temp;
	std::queue <double> dou_temp;
	std::queue <char> type_temp;

	if (::type_stack.top() == 'i'){
		reverse_num = ::int_stack.top();
		::int_stack.pop();
		::type_stack.pop();
	}
	else{
		reverse_num = ::dou_stack.top();
		::dou_stack.pop();
		::type_stack.pop();
	}
	for(int i=0; i<reverse_num; i++){  // loop to push the entities in queue.

		if (::type_stack.top() == 'i'){
			int_temp.push(::int_stack.top());
			type_temp.push(::type_stack.top());
			::int_stack.pop();
			::type_stack.pop();
		}
		else{
			dou_temp.push(::dou_stack.top());
			type_temp.push(::type_stack.top());
			::dou_stack.pop();
			::type_stack.pop();
		}
	}
	for(int i=0; i<reverse_num; i++){ // loop to push the entities back in stack from queue.
		if (type_temp.front() == 'i'){
			::int_stack.push(int_temp.front());
			::type_stack.push(type_temp.front());
			int_temp.pop();
			type_temp.pop();
		}
		else{
			::dou_stack.push(dou_temp.front());
			::type_stack.push(type_temp.front());
			dou_temp.pop();
			type_temp.pop();
		}
	}
}
// Main function, which takes input parameter as file name.
int main(int argc, char* argv[]){

	std::cout.setf(std::ios::fixed,std::ios::floatfield);
	std::cout.precision(3);
	std::ifstream in(argv[1]);
	bool repeat_mode = false;
	int repeat_times =0;
	std::deque<std::string> repeat_queue; // deque for repeat queue items.

	while(true){
		std::string word = ""; // token from file saved in string word.
		if (repeat_times == 0){
			in>>word;
		}
		if(repeat_mode == true && repeat_times > 0){// input from
			 in>>word;
			 repeat_queue.push_back(word);
			 if (word == "endrepeat"){
				 repeat_mode = false;
			 }
			 continue;
		}
		if (repeat_times > 0){
			word = repeat_queue.front();
			repeat_queue.pop_front();
			repeat_queue.push_back(word);
			 if (word == "endrepeat"){
				 repeat_times = repeat_times-1;
				 if(repeat_times ==0) repeat_queue.clear();
				 continue;
			 }
		}
		if(in.fail())break;
		if (isdigit(word[0]) == true || isdigit(word[1])== true ) { // string pushed in stack based on type.
			if (word.find('.')!= std::string::npos){
				double num1_1= stod(word);
				::dou_stack.push(num1_1);
				::type_stack.push('d');
			}
			else{
				int num2_1= stoi(word);
				::int_stack.push(num2_1);
				::type_stack.push('i');
			}
		}
		else{                       // operation performed if the input is string type.
			if (word=="sub"){
				Calculate("sub");
			}
			if (word=="add"){
				Calculate("add");
			}
			if (word=="mult"){
				Calculate("mult");
			}
			if (word=="div"){
				Calculate("div");
			}
			if (word=="sqrt"){
				if (::type_stack.top() == 'i'){
					int num1 = ::int_stack.top();
					::int_stack.pop();
					::type_stack.pop();
					int answer = sqrt(num1);
					std::cout<< "sqrt " << num1 << " = "<<answer<<std::endl;
					::int_stack.push(answer);
					::type_stack.push('i');
				}
				else{
					double num2 = ::dou_stack.top();
					::dou_stack.pop();
					::type_stack.pop();
					double answer = sqrt(num2);
					std::cout<< "sqrt " << num2 << " = "<<answer<<std::endl;
					::dou_stack.push(answer);
					::type_stack.push('d');
				}
			}
			if (word=="pop"){
				if (::type_stack.empty()){std::cout<<"nothing to pop"<<std::endl; return 0;}
				if (::type_stack.top() == 'i'){
					::int_stack.pop();
					::type_stack.pop();
				}
				else{
					::dou_stack.pop();
					::type_stack.pop();
				}
			}
			if (word=="reverse"){
				reverse();
			}
			if (word=="repeat"){ // if the command is repeat, the repeat mode set to true.

				repeat_mode = true;
				if (::type_stack.top() == 'i'){
					repeat_times = ::int_stack.top();
					::int_stack.pop();
					::type_stack.pop();
				}
				else{
					repeat_times = ::dou_stack.top();
					::dou_stack.pop();
					::type_stack.pop();
				}
			}
		}
	}
	return 0;
}
//-------------------------------------------------------------

