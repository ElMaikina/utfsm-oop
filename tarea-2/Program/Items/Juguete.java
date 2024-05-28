package Program.Items;

import Program.Mascota;

public final class Juguete extends Item{
    String tipo = "JUGUETE";

    public Juguete(int id, String nombre){
        super(id, nombre,-1);

        // this.setId(id);
        // this.setNombre(nombre);
        // this.setCantidad(1);
    }
    
    // usar Jueguete => felicidad de la mascota aumenta +30, juguete NO se consume (no se elimina de inventario)
    @Override
    public void usarItem(Mascota mascota){
        double newFelicidad = mascota.getFelicidad().get() + 30;

        if (newFelicidad > Mascota.MAX_STATS) {newFelicidad = Mascota.MAX_STATS;}

        mascota.setFelicidad(newFelicidad);        
    }

    @Override
    public String getTipo() {return tipo;}
}
