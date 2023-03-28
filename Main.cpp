#include <iostream>
#include <vector>
#include <stack>
#include <list>

void print(std::stack<int> st, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << st.top() << " ";
		st.pop();
	}
}

int main() {
	std::list<int> ls{ 1,2,3,4,5,6,7,8,9,10 };
	std::stack<int> st;

	std::cout << "Stack #1: ";
	for (int i = 0; i < 10; i++) {
		st.push(ls.back());
		std::cout << st.top() << " ";

		ls.pop_back();
	}

	for (int i = 0; i < 10; i++) {
		if (st.top() != 7) {
			std::cout << "\nDeleted from stack #1: " << st.top();
			st.pop();
		}
	}

	// На основі стоса з попередньої програми створити новий. 
	std::stack<int> NewSt; 
	ls = { 1,2,3,4,5,6,7,8,9,10 };

	std::cout << "\nStack #2: ";
	for (int i = 0; i < 10; i++) {
		NewSt.push(ls.back());
		std::cout << NewSt.top() << " ";

		ls.pop_back();
	}

	// Потім вилучати з нового стоса елементи до тих пір, поки на вершині опиниться число 3.
	for (int i = 0; i < 10; i++) {
		if (NewSt.top() != 3) {
			std::cout << "\nDeleted from stack #2: " << NewSt.top();
			//std::cout << "\nAdded to stack #2: " << NewSt.top();
			// Вилучені елементи з нового стоса додавати в старий стек.
			st.push(NewSt.top());
			NewSt.pop();
		}
	}

	// Вивести весь процес на екран.
	std::cout << "\nStack: ";
	print(st, st.size());

	return 0;
}

/*
На основі стоса з попередньої програми створити новий. 
Потім вилучати з нового стоса елементи до тих пір, поки на вершині опиниться число 3. 
Вилучені елементи з нового стоса додавати в старий стек. Вивести весь процес на екран.
*/
