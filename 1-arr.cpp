#include <iostream>
using namespace std;

const int N = 5;

void print_array(int *c){
    for(int i = 0; i < N; i++)
        cout << c[i] << ' ';
    cout << endl;
}

struct my_array
{
    int v[N];
};

int main(){
int c1[N];
int c2[] = {1 ,2 ,3 ,4 ,5};
int *c3 = new int [N];
int *c4 = (int*)calloc( N, sizeof(int));
int *c5 = (int*)malloc(N);
struct my_array c6;

for(int i = 0; i < N; i++){
    c1[i] = i + 1;
    c3[i] = i + 1;
    c4[i] = i + 1;
    c5[i] = i + 1;
    c6.v[i] = i + 1;
    }

for(int i = 0; i < N; i++){
    *(c1 + i) = i + 2;
    }
print_array(c5);
}
