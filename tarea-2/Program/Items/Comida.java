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

        if (newSalud > 100){newSalud = 100;}

        mascota.setSalud(newSalud);
        mascota.setEnergia(newEnergia);

        cantidad--;
    }

    @Override
    public String getTipo() {return tipo;}
}
