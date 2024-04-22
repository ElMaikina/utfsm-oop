public class Inventario {
    private Item[] items;
    private int capacidad;
    private int cant;

    
    public Inventario(int capacidad) {
        this.capacidad = capacidad;
        this.items = new Item[capacidad];
        this.cant = 0;
    }
    public void agregarItem(Item item) {
        if (cant < capacidad){
            items[cant] = item;
            cant++;
        }
    }
    public void mostrarInventario() {
        for(int i = 0; i < cant; i++) {
            items[i].mostrarItem();
        }
    }
    public Item searchbyid(int id) {
        Item item = null;
        for (int i = 0; 0 < cant; i++) {
            if ((int)items[i].getId() == id){
                return item;
            }
        }
        return item;
    }
    public void actualizarcant(int id) {
        for(int i = 0; 0 < cant; i++){
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
        for(int i = ind; i < cant - 1; i++) {
            items[i] = items[i+1];
        }
        items[cant -1] = null;
        cant--;
    }
}