#include "stack.h"

using namespace std;

double list::getValue()
{
	return value;
}

int myStacks::infix(char* mas){
	int size = strlen(mas);
	int current = 0;
	int i = 0;
	char* out = new char[10];
	for (int i = 0; i < size; i++) {
		if (mas[i] == '(')
			push(mas[i]);
		if (mas[i] == ')') {
			while (top->getValue() != '(') {
				out[current++] = pop();
			}
			pop();
		}
		else {
			if (isdigit(mas[i])) {
				out[current] = mas[i];
				++current;
			}
			if ((mas[i] == '+') || (mas[i] == '-')) {
				if ((top) && (firstPriority())) {
					while ((top) && (firstPriority())) {
						out[current++] = pop();
					}
					push(mas[i]);
				}
				else {
					double first = pop();
					push(first);
					if ((top) && ((first == '+') || (first == '-')))
						out[current++] = pop();
					push(mas[i]);
				}
			}
			if ((mas[i] == '*') || (mas[i] == '/')) {
				push(mas[i]);
			}
		}
	}

	while (top) {
		out[current++] = pop();
	}

	for (int i = 0; i < current; ++i)
	{
		cout << out[i] ;
	}
	out[current] = '\0';
	delete top;
	return calculate(out);
}

massiveStack::massiveStack()
{
	length = 1;
	end = -1;
	top = nullptr;
}

void massiveStack::clean()
{
	list* temp = top;
	top = nullptr;
	length = 1;
	end = -1;
	delete []temp;
}

double massiveStack::pop()
{
	if (end >= 0) return top[end--].getValue();
	else 
	{
		cout << "List is empty" << endl;
		clean();
	}
}

void massiveStack::push(double value)
{
	if (end < 0) top = new list[length];
	if (end >= length - 1)
	{
		list* temp = new list[++length];
		for (int i = 0; i < length; ++i)
			temp[i] = top[i];
		delete[]top;
		top = temp;
	}
	top[++end] = value;
}

void massiveStack::print()
{
	for (int i = end; i >= 0; --i)
		cout << top[i].getValue() << ' ';
}

double myStacks::calculate(char* mas)
{
	clean();
	int len = strlen(mas);
	int const difference = 48;
	double result = 0;
	for (int i = 0; i < len; ++i)
	{
		
		if (isdigit(mas[i]))
		{
			result = double(mas[i] - difference);
		}
		else
		{
			double second = pop();
			double first = pop();
			switch (mas[i])
			{
			case '*':
			{
						result = first * second;
						break;
			}
			case '+':
			{
						result = first + second;
						break;
			}
			case '-':
			{
						result = first - second;
						break;
			}
			case '/':
			{
						result = first / second;
						break;
			}
			}
		}
		push(result);
	}
	return top ? pop() : 0;
}















pointStack::pointStack()
{
	top = nullptr;
}

void pointStack::clean()
{
	list* temp = nullptr;
	while (top)
	{
		temp = top;
		top = top->previous;
		delete temp;
	}
}

void pointStack::push(double value)
{
	if (!top)
		top = new list(value);
	else
	{
		list* temp = new list(value);
		temp->previous = top;
		top = temp;
	}
}

double pointStack::pop()
{
	if (top)
	{
		list* temp = top;
		double value = temp->getValue();
		top = top->previous;
		delete temp;
		return value;
	}
	cout << "Stack is empty" << endl;
}

void pointStack::print()
{
	list* temp = top;
	while (temp)
	{
		cout << temp->getValue() << " ";
		temp = temp->previous;
	}
}


bool myStacks::firstPriority() 
{
	return ((top->getValue() == '*') || (top->getValue() == '/'))? true : false;
}