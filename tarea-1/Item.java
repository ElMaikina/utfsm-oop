public class Item {
    public int id;                
    public int cantidad;
    public String nombre;
        
    public Item(int newId, int newCant, String newNom) {
        this.id = newId;
        this.cantidad = newCant;
        this.nombre = newNom;
    }
    public int getId() {
        return id;
    }
    public int getCant() {
        return cantidad;
    }
    public void setCant(int cant) {
        cantidad = cant;
    }
    public void mostrarItem() {
        System.out.println(this.id + " " + this.nombre + " " + this.cantidad);
    }
}

