#include <cstdlib>		// pseudo-random number generation
#include <iostream>
#include <vector>

// Find max pairwise product slow O(n^2)  (for stress test)
/* Check [roduct of each possible pair */
long long findMaxPairwaiseProduct(const std::vector<int>& numbers) {
	long long product = 0;
	int numOfElems = numbers.size();
	for (int i = 0; i < numOfElems; i++) {
		for (int j = i + 1; j < numOfElems; j++) {
			if (((long long)numbers[i]) * numbers[j] > product)
				product = ((long long)numbers[i]) * numbers[j];
		}
	}
	return product;
}


// Find max pairwise product fast O(n)
/* Find the two max numbers present in array, they will give max product */
long long findMaxPairwaiseProductFast(const std::vector<int>& numbers) {
	int firstMaxIndex = -1, secondMaxIndex = -1, numOfElems = numbers.size();
	int max = 0;
	for (int i = 0; i < numOfElems; i++) {
		if (firstMaxIndex == -1 || max < numbers[i]) {
			max = numbers[i];
			firstMaxIndex = i;
		}
	}
	max = 0;
	for (int i = 0; i < numOfElems; i++) {
		if (i != firstMaxIndex && (secondMaxIndex == -1 || max < numbers[i])) {
			max = numbers[i];
			secondMaxIndex = i;
		}
	}
	//std::cout << firstMaxIndex << "  " << secondMaxIndex << "\n";
	return (long long)numbers[firstMaxIndex] * numbers[secondMaxIndex];
}

int main() {
	// STRESS TESTING
	//while (true) {
	//	int n = rand() % 10 + 2;		// number between 2 to 11
	//	std::vector<int> numbers;
	//	for (int i = 0; i < n; i++) {
	//		numbers.push_back(rand() % 100000);
	//	}
	//	for (int i = 0; i < n; i++) {
	//		std::cout << numbers[i] << ' ';
	//	}
	//	std::cout << "\n";
//
	//	long long productSlow = findMaxPairwaiseProduct(numbers);
	//	long long productFast = findMaxPairwaiseProductFast(numbers);
	//	if (productSlow != productFast) {
	//		std::cout << "Wrong answer: " << productSlow << ' ' << productFast << "\n";
	//		break;
	//	} else {
	//		std::cout << "Ok\n";
	//	}
	//}

	int n;
	std::cin >> n;
	std::vector<int> numbers(n);
	for (int i = 0; i < n; i++) {
		std::cin >> numbers[i];
	}
	std::cout << findMaxPairwaiseProductFast(numbers) << "\n";
	return 0;
}