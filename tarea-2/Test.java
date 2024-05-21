import Program.*;
import Program.Items.*;

public class Test {
    public static void main(String[] args){
        Mascota mascota = new Mascota("Pablito");

        Juguete hueso = new Juguete(1, "hueso");
        Medicina jarabe = new Medicina(2, "jarabe", 3);
        Medicina jarabe2 = new Medicina(3,"jarabe2", 1);

        Inventario inventario = new Inventario(mascota);
        inventario.agregarItem(hueso);
        inventario.agregarItem(jarabe);
        inventario.agregarItem(jarabe2);

        inventario.consumirItem(hueso);

        printInventario(inventario);

        inventario.consumirItem(jarabe2);

        printInventario(inventario);

        inventario.consumirItem(jarabe);

        System.out.println(jarabe2.getClass());


        inventario.agregarItem(new Juguete(0,"cuerda"));
        printInventario(inventario);
        System.out.println("-------");
        inventario.sort();
        printInventario(inventario);
    }


    static void printInventario(Inventario inventario){
        for (Item i : inventario.abrirInventario()){
            System.out.println("ID#" + i.getId() + ", " + i.getNombre() + ", Cantidad: " + i.getCantidad());
        }
    }

    
}