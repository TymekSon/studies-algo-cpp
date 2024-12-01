#pragma once
#include <string>

template<typename Type>
class List {
private:
	struct Element {
		Type data;
		Element* next;
		Element* prev;

		Element(Type value) : data(value), prev(nullptr), next(nullptr) {}
	};
	Element* head;
	Element* tail;
	size_t size;

public:
	List() : head(nullptr), tail(nullptr), size(0) {}

	~List() {
		while (head) {
			Element* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void append(Type value) {
		Element* newElement = new Element(value);
		if (!tail) {
			head = tail = newElement;
		}
		else {
			tail->next = newElement;
			newElement->prev = tail;
			tail = newElement;
		}
		size++;
	}

	void push(Type value) {
		Element* newElement = new Element(value);
		if (!head) {
			head = tail = newElement;
		}
		else {
			head->prev = newElement;
			newElement->next = head;
			head = newElement;
		}
		size++;
	}

	void removeLast() {
		if (!tail) {
			std::cout << "List is empty" << std::endl;
			return;
		}
		Element* temp = tail;
		if (tail == head) {
			head = tail = nullptr;
		}
		else {
			tail = tail->prev;
			tail->next = nullptr;
		}
		delete temp;
		size--;
	}

	void removeFirst() {
		if (!head) {
			std::cout << "List is empty" << std::endl;
			return;
		}
		Element* temp = head;
		if (tail == head) {
			head = tail = nullptr;
		}
		else {
			head = head->next;
			head->prev = nullptr;
		}
		delete temp;
		size--;
	}

	void remove(size_t index) {
		if (index >= size) {
			std::cout << "Index out of range" << std::endl;
			return;
		}
		if (index == 0) {
			removeFirst();
			return;
		}
		if (index == size - 1) {
			removeLast();
			return;
		}
		Element* current;

		if (index < size / 2) {
			current = head;
			for (size_t i = 0; i < index; ++i) {
				current = current->next;
			}
		}
		else {
			current = tail;
			for (size_t i = size - 1; i > index; --i) {
				current = current->prev;
			}
		}
		current->prev->next = current->next;
		current->next->prev = current->prev;

		delete current;
		size--;
	}

	Type get(size_t index) {
		if (index >= size) {
			std::cout << "Index out of range" << std::endl;
			return 0;
		}
		Element* current;

		if (index < size / 2) {
			current = head;
			for (size_t i = 0; i < index; ++i) {
				current = current->next;
			}
		}
		else {
			current = tail;
			for (size_t i = size - 1; i > index; --i) {
				current = current->prev;
			}
		}
		return current->data;
	}

	Type set(size_t index, Type value) {
		if (index >= size) {
			std::cout << "Index out of range" << std::endl;
			return 0;
		}
		Element* current;

		if (index < size / 2) {
			current = head;
			for (size_t i = 0; i < index; ++i) {
				current = current->next;
			}
		}
		else {
			current = tail;
			for (size_t i = size - 1; i > index; --i) {
				current = current->prev;
			}
		}
		current->data = value;
	}

	void print() {
		Element* current = head;
		while (current) {
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}

	std::string toText() {
		std::string textList;
		Element* current = head;
		while (current != nullptr) {
			textList += std::to_string(current->data);
			if (current->next != nullptr) {
				textList += ";";
			}
			current = current->next;
		}
		return textList;
	}

	void clear() {
		Element* current = head;
		while (current != nullptr) {
			Element* next = current->next;
			delete current;
			current = next;
		}
		size = 0; head = nullptr; tail = nullptr;
	}
};