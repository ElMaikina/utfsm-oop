package Program.Items;

import Program.Mascota;

public final class Medicina extends Item{

    public Medicina(int id, String nombre, int cantidad){
        super(id, nombre, cantidad);
    }

    public void usarItem(Mascota mascota){
        int newSalud = mascota.getSalud() + 40;

        if (newSalud > Mascota.MAX_STATS){newSalud = 100;}
        
        mascota.setSalud(newSalud);

        cantidad--;
    }
}
