#include <iostream>

int main(){
// ��� ����� �����
double **p1 = 0;
p1 = new double*(new double);
**p1 = 2;
std::cout << **p1 << std::endl;
delete *p1;
delete p1;
// ��� ����� �����, ����� �������������
double **p2 = 0;
p2 = new double*(new double(2));
std::cout << **p2 << std::endl;
delete *p2;
delete p2;
// ���������� ������������� �������
double* c1 = new double[3];
// ���������� ������������� �������
int N = 10;
auto c2 = new int[N][3];
//auto c2 = new int[3][N];// ��� ������
//double* c3 = new double[]{1, 2, 3};// ����� ����������������� ������� � �++20
}
