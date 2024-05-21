package Program.Items;

import Program.Mascota;

public final class Comida extends Item{
    
    public Comida(int id, String nombre, int cantidad){
        super(id, nombre, cantidad);
    }

    // usar comida => energía y vida de la mascota aumentan +20, luego consume el item (eliminado de inventario)
    public void usarItem(Mascota mascota){
        int newSalud = mascota.getSalud() + 20;
        int newEnergia = mascota.getEnergia() + 20;

        if (newSalud > 100){newSalud = 100;}

        mascota.setSalud(newSalud);
        mascota.setEnergia(newEnergia);

        cantidad--;
    }
}
