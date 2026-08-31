#include <iostream>
#include <string>

class estudiante {
private:
    std::string id;
    std::string nombre;
    double promedio;

public:
    estudiante() : id(""), nombre(""), promedio(0.0) {}
    estudiante(std::string id, std::string nombre, double promedio) 
        : id(id), nombre(nombre), promedio(promedio) {}

    std::string getId() const { return id; }
    std::string getNombre() const { return nombre; }
    double getPromedio() const { return promedio; }

    void setNombre(std::string n) { nombre = n; }
    void setPromedio(double p) { promedio = p; }

    void mostrarInfo() const {
        std::cout << "ID: " << id << " | Nombre: " << nombre << " | Promedio: " << promedio << std::endl;
    }
};