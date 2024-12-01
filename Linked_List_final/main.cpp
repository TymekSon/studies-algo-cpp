#include <iostream>
#include "list.h"
#include <cstdlib>
#include <chrono>

int main() {
	List<int> testList;

	List<char> testList2;

	testList2.append('a');
	testList2.append('b');
	testList2.append('c');
	testList2.append('d');

	testList2.print();

	// testing the appending time
	for (int i = 2000; i <= 20000; i += 2000) {

		double totalTime = 0;

		for (int k = 0; k < 100; k++) {
			auto start = std::chrono::high_resolution_clock::now();

			for (int j = 0; j < i; j++) {
				testList.append(rand() % 90 + 10);
			}

			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double, std::milli> time_taken = end - start;
			totalTime += time_taken.count();

			testList.clear();
		}
		std::cout << "Average time for " << i << " appends: " << totalTime / 100 << " ms." << std::endl;
	}
	std::cout << std::endl;


	// testing the searching time
	for (int i = 0; i < 10000; i++) {
		testList.append(rand() % 90 + 10);
	}

	for (int i = 1000; i <= 10000; i += 1000) {

		auto start = std::chrono::high_resolution_clock::now();

		for (int j = 0; j < i; j++) {
			int position = rand() % 1000;
			testList.get(position);
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> time_taken = end - start;
		std::cout << "Time to get " << i << " random positions from 10000size list: " << time_taken.count() << " ms." << std::endl;
	}
	std::cout << std::endl;
	testList.clear();


	// testing the deleting time
	for (int i = 200; i <= 2000; i += 200) {
		int size = 10000;
		for (int i = 0; i < size; i++) {
			testList.append(rand() % 90 + 10);
		}
		auto start = std::chrono::high_resolution_clock::now();

		for (int j = 0; j < i; j++) {
			int toDelete = rand() % size;
			testList.remove(toDelete);
			size--;
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> time_taken2 = end - start;
		std::cout << "Time to remove " << i << " random positions from 10000size list: " << time_taken2.count() << " ms." << std::endl;
		testList.clear();
	}
	std::cout << std::endl;

}