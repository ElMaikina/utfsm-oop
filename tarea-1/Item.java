public class Item {
    private int id;                
    private String tipo;
    private String nombre;
    private int cantidad;
        
    public Item(int id, String tipo, String nombre, int cantidad) {
        this.id = id;
        this.tipo = tipo;
        this.nombre = nombre;
        this.cantidad = cantidad;
    }
    public int getId() {return id;}

    public String getTipo() {return tipo;}

    public String getNombre() {return nombre;}

    public int getCant() {return cantidad;}

    public void setCant(int newCant) {
        cantidad = newCant;
    }
    
    public void mostrarItem() {
        System.out.println(this.id + ": " + this.nombre + ", cantidad " + this.cantidad);
    }
}

