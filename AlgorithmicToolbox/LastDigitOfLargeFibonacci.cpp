#include <cstdlib>
#include <iostream>
#include <vector>

// A vector to store the fibonacci sequence and finally return the last digit of nth fibonacci number.
int findLastDigit(std::vector<int>& fibonacciSequence, int n) {
	if (n <= 1)
		return n;
	for (int i = 2; i < n + 1; i++)
		fibonacciSequence[i] = fibonacciSequence[i - 1] + fibonacciSequence[i - 2];
	return fibonacciSequence[n] % 10;
}

// Faster way: A vector that stores only the last digit for every fibonacci number.
int findLastDigitFast(std::vector<int>& lastDigits, int n) {
	if (n <= 1)
		return n;
	for (int i = 2; i < n + 1; i++)
		lastDigits[i] = (lastDigits[i - 1] + lastDigits[i - 2]) % 10;
	return lastDigits[n];
}

int main() {
	// STRESS TEST
	//while (true) {
	//	int n = rand() % 20 + 2; 	// 2 <= n <= 21
	//	std::vector<int> fibonacciSequence(n + 1);
	//	fibonacciSequence[0] = 0;
	//	fibonacciSequence[1] = 1;
	//	std::vector<int> lastDigits(n + 1);
	//	lastDigits[0] = 0;
	//	lastDigits[1] = 1;
	//	int lastDigitSlow = findLastDigit(fibonacciSequence, n);
	//	int lastDigitFast = findLastDigitFast(lastDigits, n);
	//	if (lastDigitSlow != lastDigitFast) {
	//		std::cout << "Wrong answer: " << lastDigitSlow << ' ' << lastDigitFast << "\n";
	//		break;
	//	} else {
	//		std::cout << "Okay\n";
	//	}
	//}

	int n;
	std::cin >> n;
	std::vector<int> lastDigits(n + 1);

	lastDigits[0] = 0;
	lastDigits[1] = 1;
	std::cout << findLastDigitFast(lastDigits, n) << "\n";
	return 0;
}