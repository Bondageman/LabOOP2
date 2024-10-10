#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

class Ingredient {
public:
    string name;   
    double dosage;
    double pricePerUnit;

    Ingredient() {
        name = "Пірко";
        dosage = 0.2;
        pricePerUnit = 10;
    }

    Ingredient(const string& n, double d, double p) {
        name = n;
        dosage = d;
        pricePerUnit = p;
    }
    
    
    double getCost() {
        return dosage * pricePerUnit;
    }
};

class Recipe {
public:
    Ingredient ingredients[10]; 
    int ingredientCount;

    Recipe() {
        ingredientCount = 0;
    }

    void addIngredient(const string& name, double dosage, double pricePerUnit) {
        ingredients[ingredientCount] = Ingredient(name, dosage, pricePerUnit);
        ingredientCount++;
    }

    double calculateTotalCost() {
        double totalCost = 0;
        for (int i = 0; i < ingredientCount; i++) {
            totalCost += ingredients[i].getCost();
        }
        return totalCost;
    }

    void saveToFile(const char* filename) {
        ofstream file(filename);
        if (file.is_open()) {
            for (int i = 0; i < ingredientCount; i++) {
                file << ingredients[i].name << " " << ingredients[i].dosage << " " << ingredients[i].pricePerUnit << endl;
            }
            file.close();
            cout << "Рецепт збережено в файл " << filename << endl;
        }
    }

    void display() {
        cout << "Інгредієнти рецепту:" << endl;
        for (int i = 0; i < ingredientCount; i++) {
            cout << "- " << ingredients[i].name << ", дозування: " << ingredients[i].dosage
                << " одиниць, ціна за одиницю: " << ingredients[i].pricePerUnit << " грн" << endl;
        }
        cout << "Загальна вартість: " << calculateTotalCost() << " грн" << endl;
    }
};

int main() {
    SetConsoleOutputCP(1251);

    Recipe recipe;
    recipe.addIngredient("Борошно", 1.5, 12);
    recipe.addIngredient("Цукор", 0.5, 20);
    recipe.addIngredient("Масло", 0.25, 100);
    Ingredient ingredient1;
    cout << "SSSSSSSSS = " << ingredient1.getCost() << endl;


    recipe.display();

    recipe.saveToFile("recipe.txt");



    return 0;
}
