#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, opcao, idade;

	// se for fila, verifico a cada eliminacao o primeiro da fila.
	queue<int> primeiros;
	// se for uma pilha, verifico a cada eliminacao se eh o ultimo da STL
	list<int> ultimos;
	// se for fila de prioridade, verifico a cada eliminacao se eh o maior da STL
	priority_queue<int> maiores;
	int flag_queue = 1, flag_stack = 1, flag_priority_q = 1;

	// uma list, que tem insercao em O(1) no final
	cin >> n;

	for(int i = 0; i < n; i++) {
		if(flag_priority_q == 0 && (flag_priority_q == flag_queue) && (flag_priority_q == flag_stack)) {
			cout << "unknown\n";
			return 0;
		}

		cin >> opcao >> idade;

		if(opcao == 0) {
			primeiros.push(idade);
			ultimos.push_front(idade);
			maiores.push(idade);
		} else {
			if(idade != primeiros.front()) flag_queue = 0;
			if(idade != ultimos.front()) flag_stack = 0;
			if(idade != maiores.top()) flag_priority_q = 0;

			primeiros.pop();
			ultimos.pop_front();
			maiores.pop();
		}
		// cout << "primeiros: ";
		// queue<int> primeiros_copy = primeiros;
		// while(!primeiros_copy.empty()) {
		// 	cout << primeiros_copy.front() << " ";
		// 	primeiros_copy.pop();
		// }
		// cout << endl;

		// cout << "ultimos: ";
		// list<int> ultimos_copy = ultimos;
		// while(!ultimos_copy.empty()) {
		// 	cout << ultimos_copy.front() << " ";
		// 	ultimos_copy.pop_front();
		// }
		// cout << endl;

		// cout << "maiores: ";
		// priority_queue<int> maiores_copy = maiores;
		// while(!maiores_copy.empty()) {
		// 	cout << maiores_copy.top() << " ";
		// 	maiores_copy.pop();
		// }
		// cout << endl;
	}
	if((flag_priority_q && (flag_queue || flag_stack)) || (flag_stack && (flag_queue || flag_priority_q)) || (flag_queue && (flag_stack || flag_priority_q))) {
		cout << "ambiguous\n";
	} else if(flag_priority_q) {
		cout << "priority\n";
	} else if(flag_stack) {
		cout << "lifo\n";
	} else if(flag_queue) {
		cout << "fifo\n";
	}

	return 0;
}