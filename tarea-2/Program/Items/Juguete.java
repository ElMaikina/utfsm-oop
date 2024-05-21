package Program.Items;

import Program.Mascota;

public final class Juguete extends Item{
    
    public Juguete(int id, String nombre){
        super(id, nombre,1);
        // this.setId(id);
        // this.setNombre(nombre);
        // this.setCantidad(1);
    }
    
    // usar Jueguete => felicidad de la mascota aumenta +30, juguete NO se consume (no se elimina de inventario)
    public void usarItem(Mascota mascota){
        int newFelicidad = mascota.getFelicidad() + 30;

        if (newFelicidad > Mascota.MAX_STATS){
            newFelicidad=100;
        }
        mascota.setFelicidad(newFelicidad);        
    }
}
