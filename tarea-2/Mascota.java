

public class Mascota {
    String nombre;
    float edad;
    int salud;
    int energia;
    int felicidad;
    Estado estado;

    public Mascota(String nombre){
        this.nombre = nombre;
        this.edad = 0;
        this.salud = 100;
        this.energia = 100;
        this.felicidad = 50;
        this.actualizarEstado();
    }

    public void mostrarMascota() {
        System.out.println("Atributos");
        System.out.println("---------");
        System.out.println("Nombre: " + this.nombre);
        System.out.println("Edad: " + this.edad);
        System.out.println("Salud: " + this.salud);
        System.out.println("Energia: " + this.energia);
        System.out.println("Felicidad: " + this.felicidad);
        this.printEstado(this.estado);
    }


    public void penalizar(){
        // Al pasar el tiempo de simulación, la felicidad y la energía pueden disminuir 
        // dependiendo de si se cumple alguna las condiciones:
        if      (edad<=5 && salud<=10) {felicidad -= 20;}
        else if (5<edad && edad<=10 && salud<=50) {felicidad -= 20; energia -= 10;}
        else if (edad>10 && salud<=50) {felicidad -= 30; energia -= 20;}

        // Volver a calibrar las estadísticas antes de empezar el nuevo ciclo por si alguna estadística
        // resultara quedar con valor negativo
        if(salud<0){salud=0;}
        if(energia<0){energia=0;}
        if(felicidad<0){felicidad=0;}        
    }

    public void actualizarEstado(){
        // Chequear y actualizar el estado de la mascota.
        // El orden de ejecución de las condiciones respeta el orden de prioridad de los estados de mayor a menor. 
        // De esa manera se cumple que la primera condición que sea verdadera será el estado de mayor prioridad.

        // MUERTO -> edad >= 15 o salud = 0 o energía = 0.
        if (edad==15 || salud==0 || energia==0) {estado = Estado.MUERTO;}

        // CANSADO -> energia <= 15.
        else if (energia <= 15) {estado = Estado.CANSADO;}

        // ENOJADO -> edad >= 5 y salud <= 30 y energia <= 30.
        else if (edad>=5 && salud<=30 && energia<=30) {estado = Estado.ENOJADO;}

        // HAMBRIENTO -> edad <= 5 y salud <= 20,
        // o también -> 5 < edad < 10 y salud <= 50. 
        // En la segunda condición el pdf dice "edad entre 5 y 10" y no especifica si se incluye el 10, yo asumí que no.
        else if ((edad<=5 && salud <= 20) || (5<edad && edad<10 && salud <= 50)) {estado = Estado.HAMBRIENTO;}

        // TRISTE -> felicidad <= 20.
        else if (felicidad<=20) {estado = Estado.TRISTE;}

        // FELIZ -> felicidad >= 60;
        else if (felicidad>=60) {estado = Estado.FELIZ;}

        // NEUTRO -> default;
        else {estado = Estado.NEUTRO;}
    }

    public void printEstado(Estado estado){
        switch(estado){
            case NEUTRO:
                System.out.println("Estado: (-_-) Meh....");
                break;
            case FELIZ:
                System.out.println("Estado: (^_^)/ Weeeeeh!");
                break;
            case TRISTE:
                System.out.println("Estado: (._.) snif....");
                break;
            case HAMBRIENTO:
                System.out.println("Estado: (0o0) hambre hambre! ");
                break;
            case ENOJADO:
                System.out.println("Estado: (ôwô) grrrr....");
                break;
            case CANSADO:
                System.out.println("Estado: (=_=) zzzz....");
                break;
            case MUERTO:
                System.out.println("Estado: (x_x) fin del juego");
                break;
        }
    }



    // Toda acción [dormir(), usarItem() o continuar()] => edad + 0.5

    public void dormir(){
        // Dormir => salud/felicidad +15; energía al máximo.
        // Al dormir, según el pdf de la tarea(ver ejemplos de ejecución), no hay penalización de -5 salud/energía/felicidad,
        // por eso agrego +0.5 de edad en esta función directamente (así no hay que ejecutar .continuar()).
        salud += 15;
        if(salud>100){salud=100;}

        felicidad += 15;
        if(felicidad>100){felicidad=100;}

        energia = 100;
    }

    public void usarItem(Item item){
        // Usar item del inventario => aumenta estadísticas
        switch (item.getTipo()){
           case "Comida":
               salud += 20;
               energia += 20;
               System.out.println("\nDando de comer " + item.getNombre() + "...");
               break;           

           case "Medicina":
               salud += 40;
               System.out.println("\nAplicando medicamento " + item.getNombre() + "...");
               break;

           case "Juguete":
               felicidad += 30;
               System.out.println("\nUsando juguete " + item.getNombre() + "...");
               break;
        }
    }

    public void pasarTiempo(){
        if(salud>100){salud=100;}
        salud -= 5;
        if(salud<0){salud=0;}

        if(energia>100){energia=100;}
        energia -= 5;
        if(energia<0){energia=0;}

        if(felicidad>100){felicidad=100;}
        felicidad -= 5;
        if(felicidad<0){felicidad=0;}

        edad += 0.5;
    }
}
