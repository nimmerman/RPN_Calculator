#include "dlist.h"
#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

int main(){
	Dlist<double> stack;
	string s;
	
	while(cin >> s){
		if(isdigit(s[0])){
			double num = atof(s.c_str());
			stack.insertFront(num);
		}
		
		else if (s == "q") break; // Quit
		
		else{
			if(s == "+" || s == "-" || s == "*" || s == "/"){ // Add, Subtract, Multiply, Divide top two numbers 
				if(!stack.isEmpty()){
					double num1 = stack.removeFront();
					
					if(!stack.isEmpty()){
						double num2 = stack.removeFront();
						double result = num1;
						
						if(s == "+") result =  num1 + num2; // Add
						else if(s == "-") result = num2 - num1; // Subtract
						else if(s == "*") result = num1 * num2; // Multiply
						else{	// Divide						
							if(num1 == 0){// Uh-oh tried to divide by zero
								cout << "Divide by zero" << endl; 
								stack.insertFront(num2);
							} 
							else result = num2/num1;
						}
						
						stack.insertFront(result);
					}
				
					else{
						cout << "Not enough operands" << endl;
						stack.insertFront(num1);
					}
				}
				
				else cout << "Not enough operands" << endl; 
			}
			
			else if(s == "n"){ // Negate the top number on the stack
				if(!stack.isEmpty()){
					double num = stack.removeFront();
					num *= -1;
					stack.insertFront(num);
				}
				
				else cout << "Not enough operands" << endl;
			}
			
			else if(s == "d"){ // Duplicate	the top number on the stack
				if(!stack.isEmpty()){
					double num = stack.removeFront();
					stack.insertFront(num);
					stack.insertFront(num);
				}
			
				else cout << "Not enough operands" << endl;
			}
			
			else if(s == "r"){ // Reverse the two top numbers on the stack
				if(!stack.isEmpty()){
					double num1 = stack.removeFront();
			
					if(!stack.isEmpty()){
						double num2 = stack.removeFront();
						stack.insertFront(num1);
						stack.insertFront(num2);
					}
			
					else{
						cout << "Not enough operands" << endl;
						stack.insertFront(num1);
					}
				}
			
				else cout << "Not enough operands" << endl;
			}
			
			else if(s == "p"){ // Print top number on stack
				if(!stack.isEmpty()){ 
					double num = stack.removeFront();
					cout << num << endl;
					stack.insertFront(num);
				}
				
				else cout << "Not enough operands" << endl;
			}
			
			else if(s == "c"){ // Clear the stack
				while(!stack.isEmpty()){
					stack.removeFront();
				}
			}		
			
			else if(s == "a"){ // Print all of the numbers on the stack
				Dlist<double> temp;
				
				if(!stack.isEmpty()){
					double num = stack.removeFront();
					cout << num;
					temp.insertBack(num);
				}	
				
				while(!stack.isEmpty()){
					double num = stack.removeFront();
					cout << " " << num;
					temp.insertBack(num);
				}
				
				stack = temp;
				cout << " " << endl;
			}
			
			else cout << "Bad input" << endl;
		}
	} 
}
