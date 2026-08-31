#include <iostream>
#include <string>
#include "../negocio/registrarEstudiantes.cpp"

int main() {
    registrarEstudiantes registro;
    registro.cargarAlumnosIniciales();

    int opcion = -1;
    do {
        std::cout << "\n========== TDA REGISTRO DE ESTUDIANTES (3B) ==========" << std::endl;
        std::cout << "1. Registrar estudiante" << std::endl;
        std::cout << "2. Listar estudiantes" << std::endl;
        std::cout << "3. Buscar estudiante" << std::endl;
        std::cout << "4. Modificar estudiante (Promedio)" << std::endl;
        std::cout << "5. Eliminar estudiante" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        if (opcion == 1) {
            std::string id, nombre;
            double promedio;
            std::cout << "\n--- REGISTRAR ESTUDIANTE ---" << std::endl;
            std::cout << "Ingrese ID: ";
            std::getline(std::cin, id);
            std::cout << "Ingrese Nombre completo: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingrese Promedio: ";
            std::cin >> promedio;
            std::cin.ignore();

            if (registro.agregarEstudiante(estudiante(id, nombre, promedio))) {
                std::cout << "¡Estudiante registrado exitosamente!" << std::endl;
            }
        } else if (opcion == 2) {
            std::cout << "\n--- LISTA DE ESTUDIANTES ---" << std::endl;
            registro.listarEstudiantes();
        } else if (opcion == 3) {
            std::string idBuscar;
            std::cout << "\n--- BUSCAR ESTUDIANTE ---" << std::endl;
            std::cout << "Ingrese el ID a buscar: ";
            std::getline(std::cin, idBuscar);
            estudiante* buscado = registro.buscarPorId(idBuscar);
            if (buscado != nullptr) {
                std::cout << "Estudiante encontrado -> ";
                buscado->mostrarInfo();
            } else {
                std::cout << "Error: Estudiante con ID '" << idBuscar << "' no existe." << std::endl;
            }
        } else if (opcion == 4) {
            std::string idMod;
            double nuevoProm;
            std::cout << "\n--- MODIFICAR PROMEDIO ---" << std::endl;
            std::cout << "Ingrese el ID del estudiante: ";
            std::getline(std::cin, idMod);
            if (registro.buscarPorId(idMod) != nullptr) {
                std::cout << "Ingrese el nuevo promedio: ";
                std::cin >> nuevoProm;
                std::cin.ignore();
                if (registro.modificarPromedio(idMod, nuevoProm)) {
                    std::cout << "¡Promedio actualizado con exito!" << std::endl;
                }
            } else {
                std::cout << "Error: El estudiante especificado no existe." << std::endl;
            }
        } else if (opcion == 5) {
            std::string idElim;
            std::cout << "\n--- ELIMINAR ESTUDIANTE ---" << std::endl;
            std::cout << "Ingrese el ID del estudiante a eliminar: ";
            std::getline(std::cin, idElim);
            if (registro.eliminarEstudiante(idElim)) {
                std::cout << "¡Estudiante eliminado y arreglo compactado correctamente!" << std::endl;
            } else {
                std::cout << "Error: No se pudo eliminar, el ID no existe." << std::endl;
            }
        } else if (opcion == 0) {
            std::cout << "Saliendo del programa..." << std::endl;
        } else {
            std::cout << "Opción no valida. Intente nuevamente." << std::endl;
        }
    } while (opcion != 0);

    return 0;
}