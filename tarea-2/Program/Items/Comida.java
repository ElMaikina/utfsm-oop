package Program.Items;

import Program.Mascota;

public final class Comida extends Item{
    String tipo = "COMIDA";

    public Comida(int id, String nombre, int cantidad){
        super(id, nombre, cantidad);

    }

    // usar comida => energía y vida de la mascota aumentan +20, luego consume el item (eliminado de inventario)
    @Override
    public void usarItem(Mascota mascota){
        double newSalud = mascota.getSalud().get() + 20;
        double newEnergia = mascota.getEnergia().get() + 20;

        if (newSalud > Mascota.MAX_STATS) {newSalud = Mascota.MAX_STATS;}
        if (newEnergia > Mascota.MAX_STATS) {newEnergia = Mascota.MAX_STATS;}

        mascota.setSalud(newSalud);
        mascota.setEnergia(newEnergia);

        cantidad--;
    }

    @Override
    public String getTipo() {return tipo;}

    @Override
    public Item clone() {
        Item clone = new Comida(id, nombre, cantidad);
        return clone;
    }
}
