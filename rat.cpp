/*
Rational newRational(int n, int m); // инициализирует
void print(Rational r, char del='\n') // печатает
void read(Rational &r); // читает

void simplify(Rational& r); // упрощает дробь
int gcd(int n, int m); // для упрощения дополнительная функция, НОД

// арифметические операции
r3 = add(r1,r2), add(r,int) add(int,r)
r3 = sub(r1,r2)
r3 = mul(r1,r2)
r3 = div(r1,r2)
r2 = inv(r1)
// операции сравнения
bool lt(r1,r2)
bool gt(r1,r2)
bool le(r1,r2)
bool ge(r1,r2)
bool eq(r1,r2)
bool ne(r1,r2)

C: no operators
C++: yes operators
*/

#include <iostream>
using namespace std;

struct Rational {
	int n; // числитель numerator
	int m; // знаменатель denominator
};

Rational newRational(int n, int m) {
	Rational r;
	r.n = n;
	r.m = m;
	return r;
}

void print(Rational r, char del = '\n') {
	cout << r.n << "/" << r.m << del;
}

void read(Rational &r) {
	cin >> r.n;
	cin.ignore();
	cin >> r.m;
}

bool lt(Rational r1, Rational r2) {
	return r1.n*r2.m < r2.n*r1.m;
}
bool gt(Rational r1, Rational r2) {
	return r1.n*r2.m > r2.n*r1.m;
}
bool le(Rational r1, Rational r2) {
	return r1.n*r2.m <= r2.n*r1.m;
}
bool ge(Rational r1, Rational r2) {
	return r1.n*r2.m >= r2.n*r1.m;
}
bool eq(Rational r1, Rational r2) {
	return r1.n*r2.m == r2.n*r1.m;
}
bool ne(Rational r1, Rational r2) {
	return r1.n*r2.m != r2.n*r1.m;
}

int gcd(int x, int y) {
	int n;
	if (x > y)n = y;
	else if (x < y)n = x;

	for (int i = n; i > 0; i--) {
		if (x%i == 0 && y%i == 0) return i;
	}
}

Rational simplify(Rational r) {
	int x;
	if (r.n > r.m) x = r.m;
	else x = r.n;
	for (int i = 2; i <= x; i++) {
		if (r.n%i == 0 && r.m%i == 0) {
			r.n /= i;
			r.m /= i;
			i = 1;
		}
	}
	return r;
}
Rational inv(Rational r) {
	Rational r2;
	r2.m = r.n;
	r2.n = r.m;
	return r2;
}
Rational add(Rational r1, Rational r2) {
	Rational r3;
	r3.m = r1.m*r2.m;
	r3.n = r1.n*r2.m + r2.n*r1.m;
	return simplify(r3);
}
Rational add(Rational r, int n) {
	return add(r, newRational(n, 1));
}
Rational add(int n, Rational r) {
	return add(newRational(n, 1), r);
}

Rational sub(Rational r1, Rational r2) {
	Rational r3;
	r3.m = r1.m*r2.m;
	r3.n = r1.n*r2.m - r2.n*r1.m;
	return simplify(r3);
}
Rational sub(int n, Rational r) {
	return (newRational(n, 1), r);
}
Rational sub(Rational r, int n) {
	return (r, newRational(n, 1));
}

Rational mul(Rational r1, Rational r2) {
	Rational r3;
	r3.m = r1.m*r2.m;
	r3.n = r1.n*r2.n;
	return simplify(r3);
}
Rational mul(int n, Rational r) {
	return mul(newRational(n, 1), r);
}
Rational mul(Rational r, int n) {
	return mul(r, newRational(n, 1));
}

Rational div(Rational r1, Rational r2) {
	r2 = inv(r2);
	return (mul(r1, r2));
}
Rational div(int n, Rational r) {
	return div(newRational(n, 1), r);
}
Rational div(Rational r, int n) {
	return div(r, newRational(n, 1));
}

void getRat(Rational *Rat, int N)
{
	cin.ignore();
	for (int i = 0; i<N; i++)
	{
		read(Rat[i]);
	}
}

void showRat(Rational *Rat, int N) {
	for (int i = 0; i < N; i++)
	{
		cout << Rat[i].n << "/" << Rat[i].m << " ";
	}
	cout << endl;
}

Rational ratSum(Rational *Rat, int N) {
	Rational sum = newRational(0, 1);
	for (int i = 0; i < N; i++)
	{
		sum = add(sum, Rat[i]);
	}
	return sum;
}

Rational ratAverage(Rational *Rat, int N) {
	return(div(ratSum(Rat, N), N));
}

void ratSortFB(Rational *Rat, int N) {
f:
	bool sorted = true;
	for (int i = 0; i < N-1; i++) {
		if (lt(Rat[i], Rat[i + 1])) {
			swap(Rat[i], Rat[i + 1]);
			sorted = false;
		}
	}
	if (sorted == false) goto f;
	showRat(Rat, N);
}
void ratSortFS(Rational *Rat, int N) {
f:
	bool sorted = true;
	for (int i = 0; i < N - 1; i++) {
		if (gt(Rat[i], Rat[i + 1])) {
			swap(Rat[i], Rat[i + 1]);
			sorted = false;
		}
	}
	if (sorted == false) goto f;
	showRat(Rat, N);
}

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


	/*Rational r1 = newRational(24, 8);
	Rational r2 = newRational(8, 25);
	
	print(r1);
	print(r2);

	Rational r3 = add(r1, r2);
	

	print(add(5, r2));
	print(add(r2, 5));

	print(div(r1,r2));*/
	system("pause");
}
