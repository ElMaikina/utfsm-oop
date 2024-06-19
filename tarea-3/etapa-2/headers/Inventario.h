//#include "Item.h"
//#include "Macota.h"
#include <vector>

class Mascota;
class Item;

class Inventario{
    
    public:
    Inventario(Mascota &mascota);
    Inventario(Inventario &original);
    ~Inventario();

    std::vector<Item> abrirInventario()const;

    void agregarItem(Item item);
    void consumirItem(Item item);
    Item buscarItem(int ID);

    private:
    Mascota *mascota;
    std::vector<Item> invJuguetes;
    std::vector<Item> invComida;
    std::vector<Item> invMedicina;
};
