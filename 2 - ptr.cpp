#include <iostream>

int main(){
// С‚Р°Рє РјРѕР¶РЅРѕ РІРµР·РґРµ
double **p1 = 0;
p1 = new double*(new double);
**p1 = 2;
std::cout << **p1 << std::endl;
delete *p1;
delete p1;
// С‚Р°Рє РјРѕР¶РЅРѕ РІРµР·РґРµ, СЃСЂР°Р·Сѓ РёРЅРёС†РёР°Р»РёР·РёСЂСѓСЏ
double **p2 = 0;
p2 = new double*(new double(2));
std::cout << **p2 << std::endl;
delete *p2;
delete p2;
// РѕР±СЊСЏРІР»РµРЅРёРµ РґРёРЅР°РјРёС‡РµСЃРєРѕРіРѕ РјР°СЃСЃРёРІР°
double* c1 = new double[3];
// РѕР±СЊСЏРІР»РµРЅРёРµ РјРЅРѕРіРѕРјРµСЂРѕРЅРѕРіРѕ РјР°СЃСЃРёРІР°
int N = 10;
auto c2 = new int[N][3];
//auto c2 = new int[3][N];// С‚Р°Рє РЅРµР»СЊР·СЏ
//double* c3 = new double[]{1, 2, 3};// СЃСЂР°Р·Сѓ РёРЅРёРЅС†РёР°Р»РёР·РёСЂРѕРІР°С‚СЊ РЅР°С‡РёРЅР°СЏ СЃ РЎ++20
}
