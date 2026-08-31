public class registroEstudiantes {
    private estudiante[] lista;
    private int cantidad;
    private final int MAX = 35; // Capacidad máxima del TDA Estático

    public registroEstudiantes() {
        this.lista = new estudiante[MAX];
        this.cantidad = 0;
    }

    public int getCantidad() { return cantidad; }
    public int getCapacidadMax() { return MAX; }

    public boolean agregarEstudiante(estudiante est) {
        if (cantidad >= MAX) {
            System.out.println("Error: El arreglo está lleno (Capacidad máxima alcanzada).");
            return false;
        }
        if (buscarPorId(est.getId()) != null) {
            System.out.println("Error: Ya existe un estudiante registrado con el ID '" + est.getId() + "'.");
            return false;
        }
        lista[cantidad] = est;
        cantidad++;
        return true;
    }

    public estudiante buscarPorId(String id) {
        for (int i = 0; i < cantidad; i++) {
            if (lista[i].getId().equalsIgnoreCase(id)) {
                return lista[i];
            }
        }
        return null;
    }

    public boolean modificarPromedio(String id, double nuevoPromedio) {
        estudiante est = buscarPorId(id);
        if (est != null) {
            est.setPromedio(nuevoPromedio);
            return true;
        }
        return false;
    }

    public boolean eliminarEstudiante(String id) {
        int index = -1;
        for (int i = 0; i < cantidad; i++) {
            if (lista[i].getId().equalsIgnoreCase(id)) {
                index = i;
                break;
            }
        }

        if (index == -1) return false;

        for (int i = index; i < cantidad - 1; i++) {
            lista[i] = lista[i + 1];
        }
        lista[cantidad - 1] = null;
        cantidad--;
        return true;
    }

    public void listarEstudiantes() {
        if (cantidad == 0) {
            System.out.println("No hay estudiantes registrados.");
            return;
        }
        System.out.println("\n---------------------------------------------------------");
        for (int i = 0; i < cantidad; i++) {
            System.out.println("[" + i + "] " + lista[i]);
        }
        System.out.println("---------------------------------------------------------");
        System.out.println("Total de estudiantes: " + cantidad + " / Capacidad: " + MAX);
    }

    public void cargarAlumnosIniciales() {
        String[] nombres = {
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

        for (int i = 0; i < nombres.length; i++) {
            String id = String.format("%02d", i + 1);
            agregarEstudiante(new estudiante(id, nombres[i], 8.0 + (i % 3) * 0.5));
        }
    }
}