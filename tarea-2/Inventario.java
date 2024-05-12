public class Inventario {
    public Item[] items;
    public int capacidad;
    public int cantidad;

    
    public Inventario(int capacidad) {
        this.capacidad = capacidad;
        this.items = new Item[capacidad];
        this.cantidad = 0;
    }
    public void agregarItem(Item item) {
        if (cantidad < capacidad){
            items[cantidad] = item;
            cantidad++;
        }
    }
    public void mostrarInventario() {
        for(int i = 0; i < cantidad; i++) {
            items[i].mostrarItem();
        }
    }
    public Item searchById(int id) {
        Item item = null;
        for (int i = 0; i <= cantidad; i++) {
            Item current = items[i];
            if (current!=null && current.getId() == id){
                return current;
            }
        }
        return item;
    }
    public void actualizarCantidad(int id) {
        for(int i = 0; 0 < cantidad; i++){
            if ((int)items[i].getId() == id) {
                items[i].setCant(items[i].getCant() - 1);
                if ((int)items[i].getCant() == 0) {
                    deleteItem(i);
                }
                break;
            }
        }
    }
    public void deleteItem(int ind) {
        for(int i = ind; i < cantidad - 1; i++) {
            items[i] = items[i+1];
        }
        items[cantidad -1] = null;
        cantidad--;
    }
}