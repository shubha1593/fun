#include <cstdlib>
#include <iostream>
#include <vector>

// Recursive approach implementing the definition of fibonacci numbers.
int findFibonacci(int n) {
	if (n <= 1)
		return n;
	return findFibonacci(n - 1) + findFibonacci(n - 2);
}

// A vector to store previous value so that each of the ith fibonacci number is computed just once.
int findFibonacciFast(std::vector<int>& fibonacciSequence, int n) {
	if (n <= 1)
		return n;
	for (int i = 2; i < n + 1; i++)
		fibonacciSequence[i] = fibonacciSequence[i - 1] + fibonacciSequence[i - 2];
	return fibonacciSequence[n];
}

int main() {
	// STRESS TEST
	//while (true) {
	//	int n = rand() % 20 + 2; 	// 2 <= n <= 21
	//	std::vector<int> fibonacciSequence(n + 1);
	//	fibonacciSequence[0] = 0;
	//	fibonacciSequence[1] = 1;
	//	int fibSlow = findFibonacci(n);
	//	int fibFast = findFibonacciFast(fibonacciSequence, n);
	//	if (fibSlow != fibFast) {
	//		std::cout << "Wrong answer: " << fibSlow << ' ' << fibFast << "\n";
	//		break;
	//	} else {
	//		std::cout << "Okay\n";
	//	}
	//}

	int n;
	std::cin >> n;
	std::vector<int> fibonacciSequence(n + 1);

	fibonacciSequence[0] = 0;
	fibonacciSequence[1] = 1;
	std::cout << findFibonacciFast(fibonacciSequence, n) << "\n";
	return 0;
}