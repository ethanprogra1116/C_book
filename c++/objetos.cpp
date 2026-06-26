#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <ostream>

struct {

} point_t;

class Personaje {
  public:
    uint16_t edad;
    const char *nombre;
    const char *apellido;

    // En C++ el constructor es un método con el mismo nombre
    Personaje(uint16_t edad, const char *nombre)
        : edad(edad), nombre(nombre), nivel_vida(100) {}

    uint8_t get_nivel_vida() { return nivel_vida; }

    // Tambien hay variables privadas
  private:
    uint8_t nivel_vida;
};

int main(void) {
    // Hello world en C++
    std::cout << "Hello World" << std::endl;

    // Personaje que esta en el heap y por ahora no usa RAII
    const Personaje *mujer = new Personaje(20, "Maria");

    // Personaje que esta en el stack. Digamos que usa RAII de cierta forma
    Personaje hombre(50, "Oscar");

    std::cout << "Edad: " << mujer->edad
              << std::endl; // Accedemos a un dato de un puntero
    std::cout << "Nombre: " << Personaje(25, "Ethan").nombre << std::endl;
    std::cout << "Nivel de vida: " << hombre.get_nivel_vida()
              << std::endl;

    std::cout << "Tamaño del puntero: " << sizeof(mujer) << std::endl;
    std::cout << "Tamaño del objeto: " << sizeof(hombre) << std::endl;


    delete mujer;

    uint8_t edad_personaje;

    return EXIT_SUCCESS;
}
