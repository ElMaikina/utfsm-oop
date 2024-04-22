import java.io.*;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args)
    {
        int capacidadInventario = 20;
        Inventario inventario = new Inventario(capacidadInventario);

        String csvFile = "config.csv";
        String line = "";
        String cvsSplitByComa = ",";
        String cvsSplitBySemiColon = ";";

        String nombreMascota = null;

        // Lee el archivo CSV, asigna el nombre para la mascota y lee los items
        try (BufferedReader br = new BufferedReader(new FileReader(csvFile))) {
            while ((line = br.readLine()) != null) 
            {
                // Usa el separador para dividir la línea en campos
                String[] data = line.split(cvsSplitByComa);

                // Imprime cada campo
                for (String field : data) {
                    if (nombreMascota == null) {
                        nombreMascota = field;
                    }
                    else {
                        String[] subdata = line.split(cvsSplitBySemiColon);

                        int id = Integer.parseInt(subdata[0]);
                        String tipo = subdata[1];
                        String nombre = subdata[2];
                        int cantidad = Integer.parseInt(subdata[3]);
            
                        switch(tipo){
                            case "Comida":
                                Item newComida = new Item(id, cantidad, nombre);
                                inventario.agregarItem(newComida);
                            case "Medicina":
                                Item newMedicina = new Item(id, cantidad, nombre);
                                inventario.agregarItem(newMedicina);
                            case "Juguete":
                                Item newJuguete = new Item(id, cantidad, nombre);
                                inventario.agregarItem(newJuguete);
                        }
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Lector que maneja las entradas por el jugador 
        Scanner input = new Scanner(System.in);

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

                // La mascota duerme
                case "Inventario":
                    inventario.mostrarInventario();
                    break;

                // Cualquier otro caso es invalido
                default:
                    System.out.println("\n¡Entrada no valida!\n");
                    break;
            }
        }
    }
}