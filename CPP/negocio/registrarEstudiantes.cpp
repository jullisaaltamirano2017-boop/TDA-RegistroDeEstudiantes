#include "../modelo/estudiante.cpp"

class registrarEstudiantes {
private:
    static const int MAX = 35;
    estudiante lista[MAX];
    int cantidad;

public:
    registrarEstudiantes() : cantidad(0) {}

    int getCantidad() const { return cantidad; }
    int getCapacidadMax() const { return MAX; }

    bool agregarEstudiante(const estudiante& est) {
        if (cantidad >= MAX) {
            std::cout << "Error: Arreglo lleno." << std::endl;
            return false;
        }
        if (buscarPorId(est.getId()) != nullptr) {
            std::cout << "Error: ID duplicado." << std::endl;
            return false;
        }
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
        std::cout << "\n---------------------------------------------------------" << std::endl;
        for (int i = 0; i < cantidad; i++) {
            std::cout << "[" << i << "] ";
            lista[i].mostrarInfo();
        }
        std::cout << "---------------------------------------------------------" << std::endl;
        std::cout << "Total de estudiantes: " << cantidad << " / Capacidad: " << MAX << std::endl;
    }

    void cargarAlumnosIniciales() {
        std::string nombres[28] = {
            "Aguagallo Tuston Anthony Isaac", "Altamirano Segovia Jullisa Brigitte", "Alvarado Alarcon Josue Israel",
            "Bailon Vasquez Mateo Josue", "Barros Lopez Mateo Sebastian", "Caiza Guaman Alexander Ismael",
            "Canseco Solis Isaac Alejandro", "Caza Telenchana Christian Mateo", "Caza Telenchana Mateo Sebastian",
            "Chimarro Ramos Nicole Estefania", "Chisag Lagua Bryan Gabriel", "Espin Tenelema Juan Carlos",
            "Espinoza Vargas Dylan Alexander", "Figueroa Sanchez Matias Javier", "Gualpa Gualpa David Alexander",
            "Jumbo Celi Anthony Josue", "Lara Choco Erick David", "Lopez Vargas Alan Mateo",
            "Morocho Morales Kevin Omar", "Naranjo Garcia Luis Eduardo", "Naranjo Paredes David Alejandro",
            "Nuñez Freire Evelyn Jacqueline", "Ortiz Perez Gabriel Alejandro", "Pico Vargas Kevin Paul",
            "Quinatoa Pilamunga Josue Stalin", "Sanchez Villegas Joel Santiago", "Toapanta Guaman Erika Lizbeth",
            "Vargas Chimborazo Carlos Luis"
        };

        for (int i = 0; i < 28; i++) {
            std::string id = (i + 1 < 10 ? "0" : "") + std::to_string(i + 1);
            agregarEstudiante(estudiante(id, nombres[i], 8.0 + (i % 3) * 0.5));
        }
    }
};