import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.println("Ponle un nombre a tu mascoa: ");
        String nombreMascota = input.nextLine();

        Mascota mascota = new Mascota(nombreMascota);
        
        boolean juegoHaTerminado = false;
        String siguienteJugada = "";


        // Ciclo general del juego, termina cuando el usuario escribe "Salir"
        while (!juegoHaTerminado) {
            mascota.mostrarMascota();
            System.out.println("\n¿Que desea hacer?");
            siguienteJugada = input.nextLine();

            // Los comandos que se aceptan por consola
            switch(siguienteJugada){

                // Sale del juego
                case "Salir":
                    System.out.println("\nAdios!\n");
                    return;

                // Pasa el tiempo
                case "Continuar":
                    System.out.println("\nContinuando...\n");
                    mascota.pasarTiempo();
                    break;

                // La mascota duerme
                case "Dormir":
                    System.out.println("\nZZZZZzzZZZZzzz...\n");
                    mascota.dormir();
                    break;

                // Cualquier otro caso es invalido
                default:
                    System.out.println("\n¡Entrada no valida!\n");
                    break;
            }
        }
    }
}