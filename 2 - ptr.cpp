#include <iostream>

int main(){
double **p1 = 0;
p1 = new double*(new double);
**p1 = 2;
std::cout << **p1 << std::endl;
delete *p1;
delete p1;

double **p2 = 0;
p2 = new double*(new double(2));
std::cout << **p2 << std::endl;
delete *p2;
delete p2;

int N = 10;
auto c1 = new int[N][3];
double* c2 = new double[]{1, 2, 3};
}
