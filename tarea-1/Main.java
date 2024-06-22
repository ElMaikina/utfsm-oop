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
            
                        Item newItem = new Item(id, tipo, nombre, cantidad);
                        inventario.agregarItem(newItem);
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Lector que maneja las entradas por el jugador 
        Scanner input = new Scanner(System.in);

        Mascota mascota = new Mascota(nombreMascota);
        
        String siguienteJugada = "";


        // Ciclo general del juego, termina cuando el usuario escribe "Salir"
        while (true) {
            mascota.pasarTiempo();
            // Actualización de estado/estadísticas y penalización por déficit de estadísticas
            mascota.penalizar();
            mascota.actualizarEstado();
            System.out.println("tiempo simulado: " + mascota.edad);
            mascota.mostrarMascota();
            // Confirmar que la mascota no ha muerto
            if(mascota.estado == Estado.MUERTO){System.out.println("\nFin de la simulación\n");break;}

            // Solicitud de input
            System.out.println("\nAcciones");
            System.out.println("--------");
            System.out.println("0: dormir");
            inventario.mostrarInventario();
            System.out.print("\nSeleccione un elemento del inventario, 'c' para continuar, y 'x' para salir: ");
            siguienteJugada = input.nextLine();

            // Los comandos que se aceptan por consola
            switch(siguienteJugada){

                // Sale del juego
                case "x":
                    System.out.println("\nFin de la simulación\n");
                    input.close();
                    return;

                // Continuar
                case "c":
                    System.out.println("\nPasa el tiempo...");
                    break;

                // La mascota duerme
                case "0":
                    System.out.println("\n"+ mascota.nombre + " ha dormido como un tronco!");
                    mascota.dormir();
                    //mascota.pasarTiempo();
                    break;

                // Se usa un item de inventario
                case "1","2","3","4":
                    int id = Integer.parseInt(siguienteJugada);
                    if(inventario.searchById(id)!=null){
                        mascota.usarItem(inventario.searchById(id));
                        inventario.actualizarCantidad(id);
                        break;           
                    }else{
                        System.out.println("\n¡Item agotado!");
                        mascota.edad -= 0.5;
                        mascota.salud += 5;
                        mascota.energia += 5;
                        mascota.felicidad +=5;   
                        break;  
                    }

                // Cualquier otro caso es invalido
                default:
                    System.out.println("\n¡Entrada no valida!");
                    mascota.edad -= 0.5;
                    mascota.salud += 5;
                    mascota.energia += 5;
                    mascota.felicidad +=5;
                    break;
            }         
        }
        input.close();
    }
}
