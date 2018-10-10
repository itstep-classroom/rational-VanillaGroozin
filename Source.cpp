#include "Header.h"
int main() {
	int N;
	cout << "length: ";
	cin >> N;
	cout << "rationals: ";
	Rational *Rat = new Rational[20];

	getRat(Rat, N);
	cout << "sum: ";
	print(ratSum(Rat, N));
	cout << "average: ";
	print(ratAverage(Rat, N));
	cout << "from bigger to smaller sort: ";
	ratSortFB(Rat, N);
	cout << "from smaller to bigger sort: ";
	ratSortFS(Rat, N);

	Rational r1 = newRational(24, 8);
	Rational r2 = newRational(8, 25);

	print(r1);
	print(r2);
	Rational r3 = add(r1, r2);

	print(add(5, r2));
	print(add(r2, 5));
	print(div(r1,r2));
	system("pause");
}
