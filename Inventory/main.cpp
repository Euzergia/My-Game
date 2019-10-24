#include <iostream>
using namespace std;

class Item{
    static int count;
    string m_name;
    int m_value;
public:
    Item(string name, int value){
        m_name = name;
        m_value = value;

    }
    ~Item() = default;

    string getName(){
        return m_name;
    }

};

class Inventory{
public:
    int m_inventorySize;
    int m_itemCount;
    Item* m_itemList[99];

public:
    Inventory(int inventorySize){
        m_inventorySize = inventorySize;
        m_itemCount = 0;
        for(int i = 0; i <= inventorySize; i++){
            m_itemList[i] = nullptr;
        }
    }
    ~Inventory()= default;

    void addItemToInventory(Item* selectedItem){
        m_itemList[getEmptyIndex()] = selectedItem;
        m_itemCount++;
    }

    void dropItemFromInventory(int itemIndex){
            if (m_itemList[itemIndex - 1] != nullptr){
                m_itemList[itemIndex - 1] = nullptr;
            }
            else{
                cout << "You can't drop emptiness... yet" << endl;
            }

    }

    int getItemCount(){
        return m_itemCount;
    }

    void viewInventory(){
        cout << "This is your inventory:"<< endl;
        for(int i = 0; i < m_inventorySize; i++){
            cout << i+1 << ". " << emptyItemChecker(m_itemList[i]) << endl;
        }
    }

private:

    int getEmptyIndex(){
        bool emptyPlace = false;
        int emptyIndex = 0;
        while(!emptyPlace){
            if(m_itemList[emptyIndex]== nullptr){
                emptyPlace = true;
            }
            else{
                emptyIndex++;
            }
        }
        return emptyIndex;
    }

    static string emptyItemChecker(Item* indexToCheck){
        if(indexToCheck != nullptr){
            return indexToCheck->getName();
        }
        else{
            return "---";
        }
    }
};


int main() {
Item* pytel = new Item("Pytel",250);
    Item* nuz = new Item("nuz",250);
    Item* pastelka = new Item("pastelka",250);
    Item* lednice = new Item("lednice",250);
    Item* vidle = new Item("vidle",250);
    Item* vetev = new Item("vetev",250);

Inventory* mujInventar = new Inventory(10);
mujInventar ->addItemToInventory(pytel);
    mujInventar ->addItemToInventory(nuz);
    mujInventar ->addItemToInventory(pastelka);
    mujInventar ->addItemToInventory(lednice);
    mujInventar ->addItemToInventory(vidle);



mujInventar ->viewInventory();
    return 0;
}