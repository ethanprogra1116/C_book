#include <cstdio>
#include <iostream>

using namespace std;
bool dentro;

class Perro {

};

int main() {
    dentro = true;
    cout << "Hola mundo" << endl;
    if (dentro) {
        printf("Estamos dentro\n");
    }
    return 0;
}
