package Program;

import java.util.ArrayList;
import java.util.Comparator;

import Program.Items.Item;

public class Inventario {
    private Mascota mascota;
    private ArrayList<Item> inventario = new ArrayList<Item>();

    public Inventario(Mascota mascota){
        this.mascota = mascota;
    }
    
    public ArrayList<Item> abrirInventario(){
        return inventario;
    }
    
    public void agregarItem(Item item){
        inventario.add(item);
    }
    
    // retorna verdadero si se cantidad = 0, falso si no
    public boolean consumirItem(Item item){
        item.usarItem(mascota);
        if(item.getCantidad()==0){
            inventario.remove(item); // JVM sabrá cual item eliminar porque difieren en ID
            return true;
        }
        return false;
    }

    public Item buscarItem(int ID){
        Item aEnonctrar = null;
        for (Item i: inventario){
            if (i.getId() == ID){
                aEnonctrar = i;
                break;
            }
        }
        return aEnonctrar;
    }

    public void sort(){
        inventario.sort(new Comparator<Item>() {
            @Override
            public int compare(Item i1, Item i2){
                return Integer.compare(i1.getId(), i2.getId());
            }
        });
    }

}