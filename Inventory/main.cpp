#include <iostream>
#include <vector>

using namespace std;

class Items{
    string m_name;
    int m_value;
    string m_description;
    static vector<Items*> m_generatedItems;

public:
    Items(string name, int value, string description){
        m_name = name;
        m_value = value;
        m_description = description;
    }
    ~Items() = default;

    string getName(){
        return m_name;
    }

    void addToItemList(Items* item){
        m_generatedItems.push_back(item);
    }

};

class Weapon: public Items{
    int m_damage;
    int m_defense;
    string m_type;

public:
    Weapon(string name, int value, string desription, int damage, int defense, string type)
        :Items(name, value, desription)
    {
        m_damage = damage;
        m_defense = defense;
        m_type = type;
    }

};

class Armor: public Items{
    int m_defense;
    string m_type;

public:
    Armor(string name, int value, string desription, int defense, string type)
    :Items(name, value, desription)
    {
        m_defense = defense;
        m_type = type;
    }
};

class Consumables : public Items{
    int m_hpGain;
    int m_mpGain;

public:
    Consumables(string name, int value, string desription, int hpGain, int mpGain)
    :Items(name, value, desription)
    {
        m_hpGain = hpGain;
        m_mpGain = mpGain;
    }
};


class Inventory{
public:
    int m_inventorySize;
    int m_itemCount;
    vector<Items*> m_itemList;

public:
    Inventory(int inventorySize){
        m_inventorySize = inventorySize;
        m_itemCount = 0;
        for(int i = 0; i < inventorySize; i++){
            m_itemList.push_back(nullptr);
        }
    }
    ~Inventory()= default;

    void addItemToInventory(Items* selectedItem){
        m_itemList.at(getEmptyIndex()) = selectedItem;
        m_itemCount++;
    }

    void dropItemFromInventory(int itemIndex){
            if (m_itemList.at(itemIndex - 1) != nullptr){
                m_itemList.at(itemIndex - 1) = nullptr;
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
            cout << i+1 << ". " << emptyItemChecker(m_itemList.at(i)) << endl;
        }
    }

private:

    int getEmptyIndex(){
        bool emptyPlace = false;
        int emptyIndex = 0;
        while(!emptyPlace){
            if(m_itemList.at(emptyIndex)== nullptr){
                emptyPlace = true;
            }
            else{
                emptyIndex++;
            }
        }
        return emptyIndex;
    }

    static string emptyItemChecker(Items* indexToCheck){
        if(indexToCheck != nullptr){
            return indexToCheck->getName();
        }
        else{
            return "---";
        }
    }
};



int main() {
    Weapon* mec = new Weapon("Mec",42,"Velky zelezny mec", 10, 0,"oneHand");

    Inventory* mujInventar = new Inventory(5);
    mujInventar ->addItemToInventory(mec);


    mujInventar ->viewInventory();
    return 0;
}