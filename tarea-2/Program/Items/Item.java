package Program.Items;

import Program.Mascota;

public abstract class Item {
    protected int id;
    protected String nombre;
    protected int cantidad; 

    public Item(int id, String nombre, int cantidad){
        this.id = id;
        this.nombre = nombre;
        this.cantidad = cantidad;
    }

    // metodo usarItem se encuentra definido en cada subclase de Item (Juguete, Medicina, Comida)
    // aumenta las estadisticas respectivas de la mascota y consume item (a menos que sea Juguete)
    public abstract void usarItem(Mascota mascota);



    //GETers & SETers
    public int getId() {return id;}
    public void setId(int newId) {id = newId;}

    public String getNombre() {return nombre;}
    public void setNombre(String newNombre) {nombre = newNombre;}

    public int getCantidad() {return cantidad;}
    public void setCantidad(int newCantidad) {cantidad = newCantidad;} 

}
