#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750

int main() { // Removed unused argc, argv
    // Original tests
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try {
        numbers[-2] = 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }

    // Additional tests
    std::cout << "--- Additional Tests ---\n";

    // Test 1: Default constructor
    Array<int> empty;
    std::cout << "Default constructor size: " << empty.size() << std::endl;
    try {
        empty[0] = 42;
    } catch (const std::exception& e) {
        std::cout << "Accessing empty array: " << e.what() << std::endl;
    }

    // Test 2: Zero-sized array
    Array<int> zero(0);
    std::cout << "Zero-sized array size: " << zero.size() << std::endl;
    try {
        zero[0] = 42;
    } catch (const std::exception& e) {
        std::cout << "Accessing zero-sized array: " << e.what() << std::endl;
    }

    // Test 3: Copy constructor with modification
    Array<int> small(3);
    small[0] = 1;
    small[1] = 2;
    small[2] = 3;
    Array<int> small_copy(small);
    small_copy[1] = 999;
    std::cout << "Original small[1]: " << small[1] << ", Copy small_copy[1]: " << small_copy[1] << std::endl;

    // Test 4: Assignment operator with different sizes
    Array<int> assign_test(5);
    for (int i = 0; i < 5; i++) {
        assign_test[i] = i + 1;
    }
    Array<int> assign_target(2);
    assign_target = assign_test;
    std::cout << "Assigned array size: " << assign_target.size() << std::endl;
    for (unsigned int i = 0; i < assign_target.size(); i++) { // Changed int to unsigned int
        std::cout << "assign_target[" << i << "] = " << assign_target[i] << std::endl;
    }

    // Test 5: Large index access
    try {
        numbers[1000] = 42;
    } catch (const std::exception& e) {
        std::cout << "Large index access: " << e.what() << std::endl;
    }

    // Clean up
    delete[] mirror;
    return 0;
}
