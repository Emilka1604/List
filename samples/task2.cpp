#include "stack.h"
int main() {
	List<int> lst;
	for (int i = 0; i < 10; i++) {
		lst.push_back(i);
	}
	std::cout <<"3 elem on the end" <<" " <<k_elem(lst, 3) << "\n";
	std::cout << "middle elem" <<" "<< middle_elem(lst);
	return 0;
}