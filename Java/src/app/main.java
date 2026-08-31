import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        registroEstudiantes registro = new registroEstudiantes();
        
        registro.cargarAlumnosIniciales();

        int opcion = -1;
        do {
            System.out.println("\n========== TDA REGISTRO DE ESTUDIANTES (3B) ==========");
            System.out.println("1. Registrar estudiante");
            System.out.println("2. Listar estudiantes");
            System.out.println("3. Buscar estudiante");
            System.out.println("4. Modificar estudiante (Promedio)");
            System.out.println("5. Eliminar estudiante");
            System.out.println("0. Salir");
            System.out.print("Seleccione una opción: ");
            
            try {
                opcion = Integer.parseInt(sc.nextLine());
            } catch (Exception e) {
                opcion = -1;
            }

            switch (opcion) {
                case 1:
                    System.out.println("\n--- REGISTRAR ESTUDIANTE ---");
                    System.out.print("Ingrese ID: ");
                    String id = sc.nextLine();
                    System.out.print("Ingrese Nombre completo: ");
                    String nombre = sc.nextLine();
                    System.out.print("Ingrese Promedio: ");
                    double promedio = Double.parseDouble(sc.nextLine());

                    if (registro.agregarEstudiante(new estudiante(id, nombre, promedio))) {
                        System.out.println("¡Estudiante registrado exitosamente!");
                    }
                    break;

                case 2:
                    System.out.println("\n--- LISTA DE ESTUDIANTES ---");
                    registro.listarEstudiantes();
                    break;

                case 3:
                    System.out.println("\n--- BUSCAR ESTUDIANTE ---");
                    System.out.print("Ingrese el ID a buscar: ");
                    String idBuscar = sc.nextLine();
                    estudiante buscado = registro.buscarPorId(idBuscar);
                    if (buscado != null) {
                        System.out.println("Estudiante encontrado -> " + buscado);
                    } else {
                        System.out.println("Error: Estudiante con ID '" + idBuscar + "' no existe.");
                    }
                    break;

                case 4:
                    System.out.println("\n--- MODIFICAR PROMEDIO ---");
                    System.out.print("Ingrese el ID del estudiante: ");
                    String idMod = sc.nextLine();
                    if (registro.buscarPorId(idMod) != null) {
                        System.out.print("Ingrese el nuevo promedio: ");
                        double nuevoProm = Double.parseDouble(sc.nextLine());
                        if (registro.modificarPromedio(idMod, nuevoProm)) {
                            System.out.println("¡Promedio actualizado con éxito!");
                        }
                    } else {
                        System.out.println("Error: El estudiante especificado no existe.");
                    }
                    break;

                case 5:
                    System.out.println("\n--- ELIMINAR ESTUDIANTE ---");
                    System.out.print("Ingrese el ID del estudiante a eliminar: ");
                    String idElim = sc.nextLine();
                    if (registro.eliminarEstudiante(idElim)) {
                        System.out.println("¡Estudiante eliminado y arreglo compactado correctamente!");
                    } else {
                        System.out.println("Error: No se pudo eliminar, el ID no existe.");
                    }
                    break;

                case 0:
                    System.out.println("Saliendo del programa...");
                    break;

                default:
                    System.out.println("Opción no válida. Intente nuevamente.");
                    break;
            }
        } while (opcion != 0);

        sc.close();
    }
}