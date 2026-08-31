#include "../modelo/estudiante.cpp"

class registrarEstudiantes {
private:
    static const int MAX = 35;
    estudiante lista[MAX];
    int cantidad;

public:
    registrarEstudiantes() : cantidad(0) {}

    int getCantidad() const { return cantidad; }

    bool agregarEstudiante(const estudiante& est) {
        if (cantidad >= MAX) return false;
        if (buscarPorId(est.getId()) != nullptr) return false;

        lista[cantidad] = est;
        cantidad++;
        return true;
    }

    estudiante* buscarPorId(const std::string& id) {
        for (int i = 0; i < cantidad; i++) {
            if (lista[i].getId() == id) {
                return &lista[i];
            }
        }
        return nullptr;
    }

    bool modificarPromedio(const std::string& id, double nuevoPromedio) {
        estudiante* est = buscarPorId(id);
        if (est != nullptr) {
            est->setPromedio(nuevoPromedio);
            return true;
        }
        return false;
    }

    bool eliminarEstudiante(const std::string& id) {
        int index = -1;
        for (int i = 0; i < cantidad; i++) {
            if (lista[i].getId() == id) {
                index = i;
                break;
            }
        }

        if (index == -1) return false;

        // Desplazamiento para mantener el arreglo contiguo
        for (int i = index; i < cantidad - 1; i++) {
            lista[i] = lista[i + 1];
        }
        cantidad--;
        return true;
    }

    void listarEstudiantes() const {
        if (cantidad == 0) {
            std::cout << "No hay estudiantes registrados." << std::endl;
            return;
        }
        for (int i = 0; i < cantidad; i++) {
            std::cout << "[" << i << "] ";
            lista[i].mostrarInfo();
        }
    }
};