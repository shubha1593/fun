#include <cstdlib>
#include <iostream>

long long computeLCM(int a, int b) {
	if (a == b)
		return a;
	int start = (a < b) ? b : a;
	long long end = a * b;
	long long lcm = end;
	for (long long i = (long long)start; i < end; i++) {
		if ((i % a == 0) && (i % b == 0)) {
			lcm = i;
			break;
		}
	}
	return lcm;
}

int computeGCDFast(int a, int b) {
	if (b == 0)
		return a;
	return computeGCDFast(b, a % b);

}

long long computeLCMFast(int a, int b) {
	if (a == b)
		return a;
	return ((long long)(a) * b) / computeGCDFast(a, b);
}

int main() {
	// STRESS TEST
	//while (true) {
	//	int a = rand() % 20 + 2;	// 2 <= a <= 21
	//	int b = rand() % 30 + 2;	// 2 <= b <= 31
	//	long long lcmSlow = computeLCM(a, b);
	//	long long lcmFast = computeLCMFast(a, b);
	//	if (lcmSlow != lcmFast) {
	//		std::cout << "Wrong answer: " << lcmSlow << ' ' << lcmFast << "\n";
	//		break;
	//	} else {
	//		std::cout << "Okay\n";
	//	}
	//}

	int a, b;
	std::cin >> a >> b;
	std::cout << computeLCMFast(a, b) << "\n";
	return 0;
}