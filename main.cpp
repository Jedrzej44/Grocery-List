#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void displayItems(map<string, int> &items) {
	for (auto it = items.begin(); it != items.end(); ++it) {
		cout << it -> first << " (" << it -> second << " )" << endl;
	}
}

void addItem(map<string, int> & items) {
	string item;
	int quantity;

	cout << "Podaj nazwę produktu: ";
	cin >> item;
	cout << "Podaj ilość: ";
	cin >> quantity;

	if (items.count(item) > 0) {
		items.at(item) += quantity;
		cout << "Zwiększono ilość istniejącego produktu" << endl;
	} else { 
		items.emplace(item, quantity);
		cout << "Dodano produkt" << endl;
	}
}

void saveListToFile(map<string, int> &items) {
	ofstream groceryListFile;
	groceryListFile.open("groceryList.txt");
	
	for (auto it = items.begin(); it != items.end(); ++it) {
		groceryListFile << it -> first << " (" << it -> second << " )" << endl;
	}
	groceryListFile.close();
}

int main() {
	map<string, int> items;
	items.emplace("Jajka", 3);

	int option = -1;

	while (option != 0) {
		cout << "0. Zakoń program" << endl;
		cout << "1. Wyświetl produkty" << endl;
		cout << "2. Dodaj produkt" << endl;
		cout << "3. Zapisz listę zakupów do pliku" << endl;
		cout << "Wybierz opcję: ";

		cin >> option;

	if (option == 1) {
		displayItems(items);
	 	} else if (option == 2) {
		addItem(items);
		} else if (option == 3) {
		saveListToFile(items);
		}
	}
}