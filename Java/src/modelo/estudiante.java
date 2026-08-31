public class estudiante {
    private String id;
    private String nombre;
    private double promedio;

    public estudiante(String id, String nombre, double promedio) {
        this.id = id;
        this.nombre = nombre;
        this.promedio = promedio;
    }

    public String getId() { return id; }
    public String getNombre() { return nombre; }
    public double getPromedio() { return promedio; }

    public void setNombre(String nombre) { this.nombre = nombre; }
    public void setPromedio(double promedio) { this.promedio = promedio; }

    @Override
    public String toString() {
        return "ID: " + id + " | Nombre: " + nombre + " | Promedio: " + promedio;
    }
}