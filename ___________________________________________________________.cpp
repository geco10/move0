#include<cstdio>
#include<cmath>
enum Direction
{
  LEFT,
  RIGHT,
  DOWN,
  UP
};
void filAr(int a[100][100], int n, int m) {
	int k = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; j++) {
			a[i][j] = k;
			++k;
		}
	}
	a[0][0] = 0;
}
int f(int b, int a[100][100], int n, int m) {
	int k = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == b)return k;
			++k;
		}
	}
}
int move(int a[100][100],int n,int m,int dir,int t) {
	int k = f(0,a, n, m);
	int i = (k - 1) / m;
	int j = (k - 1) % m;
	a[i][j] = t;
	int next;
	if (dir == RIGHT) {
		next = a[i][j + 1];
		a[i][j + 1] = 0;
	}
	if (dir == LEFT) {
		next = a[i][j - 1];
		a[i][j - 1] = 0;
	}
	if (dir == UP) {
		next = a[i-1][j];
		a[i - 1][j] = 0;
	}
	if (dir == DOWN) {
		next = a[i+1][j];
		a[i +1][j] = 0;
	}
	return next;
}
bool plus(int a[100][100], int n, int m,int l) {
	int k = f(0, a, n, m);
	int i = (k-1)/m;
	int j = (k-1) % m;
	if (i==0||i==n-1||j==0||j==m-1)return false;
	else {
		a[i + 1][j] = l;
		a[i][j - 1] = l;
		a[i][j + 1] = l;
		a[i - 1][j] = l;
		return true;
	}
}
void print(int a[100][100], int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; j++) {
			printf("%2i ", a[i][j]);
		}
		puts("");
	}
}
int main() {
	int a[100][100];
	int n, m;
	scanf_s("%i %i", &n, &m);
	int b = 1;
	filAr(a, n, m);
	print(a, n, m);
	int t = 1;
	while (b != 0) {
		printf("  Enter command:");
		scanf_s("%i", &b);
		if (b == 1 && f(0, a, n, m)%m!=1)t=move(a, n, m,LEFT,t);
		else if (b == 2 && f(0, a, n, m)%m!=0)t=move(a, n, m,RIGHT,t);
		else if (b == 3 && f(0, a, n, m)<=m*(n-1))t=move(a, n, m,DOWN,t);
		else if (b == 4 && f(0, a, n, m)>m)t=move(a, n, m,UP,t);
		else if (b == 5) {
			int l=1;
			if (plus(a, n, m,l)) {
				printf(" value:");
				scanf_s("%i",&l);
				plus(a, n, m, l);
			}
			else puts("not enough space");
		}
		print(a, n, m);
	}
}