#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <queue>

class RPN {
	private:
		std::stack<int>		_stack;
		std::queue<char>	_queue;
	public:
		RPN();
		RPN(RPN const &copy);
		RPN &operator=(RPN const &rhs);
		~RPN();
		
		RPN(const std::string &str);
};
