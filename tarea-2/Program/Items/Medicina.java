package Program.Items;

import Program.Mascota;

public final class Medicina extends Item{
    String tipo = "MEDICINA";

    public Medicina(int id, String nombre, int cantidad){
        super(id, nombre, cantidad);
    }

    @Override
    public void usarItem(Mascota mascota){
        double newSalud = mascota.getSalud().get() + 40;

        if (newSalud > Mascota.MAX_STATS){
            newSalud = Mascota.MAX_STATS;
        }
        
        mascota.setSalud(newSalud);

        cantidad--;
    }

    @Override
    public String getTipo() {return tipo;}
}
