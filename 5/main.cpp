#include <iostream>
#include "bicola.h"
#include <cstring>
using namespace std;

int main(){
    bicola<int> bi;
    bi.pushfrente(1);
    bi.pushfrente(2);
    bi.pushfinal(3);
    bi.popfinal();
    cout << "frente" << bi.frente() << "  final " << bi.final();

}