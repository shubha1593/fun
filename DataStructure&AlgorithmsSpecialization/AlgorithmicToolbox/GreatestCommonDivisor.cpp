#include <cstdlib>
#include <iostream>

int computeGCD(int a, int b) {
	int gcd = 1;
	for (int i = 2; i < a + b; i++) {
		if (a % i == 0 && b % i == 0)
			gcd = i;
	}
	return gcd;
}

int computeGCDFast(int a, int b) {
	if (b == 0)
		return a;
	return computeGCDFast(b, a % b);

}

int main() {
	// STRESS TEST
	//while (true) {
	//	int a = rand() % 20 + 2;	// 2 <= a <= 21
	//	int b = rand() % 30 + 2;	// 2 <= b <= 31
	//	int gcdSlow = computeGCD(a, b);
	//	int gcdFast = computeGCDFast(a, b);
	//	if (gcdSlow != gcdFast) {
	//		std::cout << "Wrong answer: " << gcdSlow << ' ' << gcdFast << "\n";
	//		break;
	//	} else {
	//		std::cout << "Okay\n";
	//	}
	//}

	int a, b;
	std::cin >> a >> b;
	std::cout << computeGCDFast(a, b) << "\n";
	return 0;
}