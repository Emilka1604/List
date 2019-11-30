#pragma once
#include <iostream>
#include <vector>
#include <exception>
template<typename T>
std::vector<T> quicksort(std::vector<T> v) {
	if (v.size() != 0) {
		int k = v.size() / 2;
		std::vector<T> vm;
		std::vector<T> vb;
		int i;
		for (i = 0; i < v.size(); i++) {

			if (v[i] < v[k])
				vm.push_back(v[i]);
			else
				if (i != k)
					vb.push_back(v[i]);

		}
		if (vm.size() > 1 || vb.size() > 1) {
			std::vector<T> v1 = quicksort(vm);
			std::vector<T> v2 = quicksort(vb);
			v1.push_back(v[k]);
			for (i = 0; i < v2.size(); i++)
				v1.push_back(v2[i]);
			return v1;
		}
		else {
			vm.push_back(v[k]);
			for (i = 0; i < vb.size(); i++)
				vm.push_back(vb[i]);
			return vm;
		}
	}
}
template<class T>
class List {
private:
	template<class T>
	class Node
	{
	public:
		Node<T>* next;
		T data;
		Node(T data = T(), Node* next = nullptr) {
			this->next = next;
			this->data = data;
		}
	};
	Node<T>* head;
	int size;

public:
	class iterator {
	private:
		Node<T>* elem;
	public:
		iterator(Node<T>* elem) { this->elem = elem; }
		void operator++(int) { elem = elem->next; }
		T& operator*() { return elem->data; }
		bool operator==(iterator it) {
			return (this->elem == it.elem);
		}
		bool operator!=(iterator it) { return !(this->operator==(it)); }
		friend class List;
	};
	List();
	List(int n);
	void insert(iterator& it, T data) {
		Node<T>* a = new Node<T>;
		a = it.elem->next;
		Node<T>* tmp = new Node<T>(data, a);
		it.elem->next = tmp;
		size++;
	}
	void remove(iterator& it) {
		Node<T>* a = new Node<T>;
		a = it.elem->next->next;
		delete[] it.elem->next;
		it.elem->next = a;
		size--;
	}
	iterator begin() {
		auto it = iterator(head);
		return it;
	}
	iterator end() {
		auto it = List<T>::iterator(NULL);
		return it;
	}
	~List();
	void push_back(T);
	void push_begin(T);
	void delete_back();
	void delete_begin();
	int getsize() { return size; }
	bool operator==(List<T>&);
	List(List<T>&);

};
template<class T>
List<T>::List() {
	head = nullptr;
	size = 0;
}
template<class T>
List<T>::List(int n) {
	size = n;
	head = new Node<T>;
	Node<T>* tmp = head;
	for (int i = 1; i < size; i++) {
		Node<T>* tmp2 = new Node<T>;
		tmp->next = tmp2;
		tmp = tmp2;
	}
	tmp->next = nullptr;

}
template<class T>
List<T>::~List() {
	if ( head != nullptr) {
		Node<T>* a = head;
		if (a->next != nullptr) {
			Node<T>* b;
			while (a->next != nullptr) {
				b = a;
				a = a->next;
				delete[] b;
			}
			delete[] a;
		}
		else
			delete[] a;
	}
}
template<class T>
void List<T>::push_back(T data) {
	if (size == 0)
		head = new Node<T>(data);

	else {
		Node<T>* tmp = this->head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = new Node<T>(data);
	}
	size++;
}
template<class T>
void List<T>::push_begin(T data) {
	if (size == 0) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* tmp = new Node<T>(data, head);
		head = tmp;
	}
	size++;
}
template<class T>
void List<T>::delete_back() {
	if (size == 0) {
		std::exception ex("Empty list");
		throw ex;
	}
	else {
		Node<T>* tmp = head;
		if (tmp->next != nullptr) {
			tmp = tmp->next;
			Node<T>* tmp1 = head;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
				tmp1 = tmp1->next;
			}
			delete[] tmp;
			tmp1->next = nullptr;
			size--;
		}
		else {
			delete[] tmp;
			size--;
			head = nullptr;
		}
	}
}
template<class T>
void List<T>::delete_begin() {
	if (size == 0) {
		std::exception ex("Empty list");
		throw ex;
	}
	else {
		Node<T>* a = head;
		head = head->next;
		delete[] a;
		size--;
	}
}
template<class T>
bool List<T>::operator==(List<T>& lst) {
	if (this == &lst)
		return true;
	else {
		bool a = false;
		if (size == lst.size) {
			if (size == 0)
				a = true;
			else {
				int sum = 0;
				List<T>::iterator it_this(begin());
				List<T>::iterator it_lst(lst.begin());
				while(it_this != end()) {
					if ((*it_this) == (*it_lst))
						sum++;
					it_this++;
					it_lst++;
				}
				if (size == sum)
					a = true;

			}
		}
		return a;
	}
}
template<class T>
List<T>::List(List<T>& lst) {
	if (lst.head == nullptr) {
		head == nullptr;
		size = 0;
	}
	else {
		size = lst.size;
		List<T>::iterator it = lst.begin();
		head = new Node<T>(*it);
		Node<T>* tmp = head;
		it++;
		while (it != lst.end()) {
			tmp->next = new Node<T>(*it);
			tmp = tmp->next;
			it++;
		}
		tmp->next = nullptr;
	}
}

