#include <iostream>
#include <time.h>
using namespace std;
#define MAX_ITEMS_PER_CATEGORY 100
enum {
	TABLET = 1,
	INJECTION,
	SYRUP,
	POWDER,
	MAX_TYPE
}medType;
enum {
	LIST_ALL_ITEMS = 1,
	ITEM_LOCATION = 2,
	ADD_NEW_ITEM = 3,
	SALE_ITEM = 4,
	UPADTE_ITEM_STOCK = 5,
	QUIT = 6
}serviceOptions;
// Base class
class Medicine {
	string name;
	int type; // tablet, injection,syrup
	string manufacturer;
	int price;
	int dosage;
	time_t expiry_date;
public:
	Medicine() {
		time_t defTime = (time_t)-1;
		expiry_date = time(&defTime);
		type = -1;
		price = 0;
		dosage = 0;
	}
	void setName(string n) {
		name = n;
	}
	void setType(int t) {
		type = t;
	}
	void setManu(string m) {
		manufacturer = m;
	}
	void setExpiryDate(time_t d) {
		expiry_date = d;
	}
	void setPrice(int p) {
		price = p;
	}
	void setDosage(int d) {
		dosage = d;
	}
	string getName() {
		return name;
	}
	int getType() {
		return type;
	}
	string getManu() {
		return manufacturer;
	}
	time_t getExpiryDate() {
		return expiry_date;
	}
	int getPrice() {
		return price;
	}
	int getDosage() {
		return dosage;
	}
};
// inverntory management base class
class inventoryUnit {
	int loc_cupBoard;
	int loc_row;
	int loc_col;
	int stock;
public:
	inventoryUnit() {
		stock = 0;
		loc_row = 0;
		loc_col = 0;
		loc_cupBoard = 0;
	}
	void setLocCupboard(int b) {
		loc_cupBoard = b;
	}
	void setLocRow(int r) {
		loc_row = r;
	}
	void setLocCol(int c) {
		loc_col = c;
	}
	void setStock(int s) {
		stock = s;
	}
	int getLocCupboard() {
		return loc_cupBoard;
	}
	int getLocRow() {
		return loc_row;
	}
	int getLocCol() {
		return loc_col;
	}
	int getStock() {
		return stock;
	}
};
// Derived class
class entry : public Medicine, public inventoryUnit {
	bool haveExpiredItems;
	time_t max_expiry_date; // the max date of expiry for the inventory item
public:
	entry() {
		time_t defTime = (time_t)-1;
		max_expiry_date = time(&defTime);
		haveExpiredItems = false;
	}
	void setExpiryStatus(bool status) {// do not need this
		haveExpiredItems = status;
	}
	bool getExpiryStatus() {
		time_t now = time(0);
		if (difftime(now, Medicine::getExpiryDate()) >= 0 || difftime(now,
			max_expiry_date) >= 0) {
			haveExpiredItems = true;
		}
		else {
			haveExpiredItems = false;
		}
		return haveExpiredItems;
	}
	void setExpiryDate(time_t lt) {// base class set method overloaded
		if (difftime(lt, Medicine::getExpiryDate()) > 0) {
			if (difftime(lt, max_expiry_date)) {
				max_expiry_date = lt;
			}
		}
		else {
			Medicine::setExpiryDate(lt);
		}
	}
	time_t getMaxExpiryDate() {
		return max_expiry_date;
	}
};
class TabletEntry :public entry {
public:
	TabletEntry() {
		entry::setType(TABLET);
	}
	void display() {
		cout << endl;
		cout << " Category TABLET! \n";
		cout << "Name: " << getName() << endl;
		cout << "Dosage per tablet: " << getDosage() << " mg" << endl;
		cout << "Price per tablet: Rs " << getPrice() << endl;
		cout << "Total Items: " << getStock() << endl;;
		cout << "Manufacturer: " << getManu() << endl;
		cout << "Location: Cupboard " << getLocCupboard() << endl;
		cout << " Row: " << getLocRow() << " Col: " << getLocCol() << endl;
		if (getExpiryStatus() == true)
			cout << "Expiry Status: Have expired items" << endl;
		else
			cout << "Expiry Status: NO expired items" << endl;
		time_t now = time(0);
		// convert now time to string form
		char date[26];
		ctime_s(date, sizeof date, &now);
		cout << "Date of EXP: " << date << endl;
	}
};
class InjectionEntry :public entry {
public:
	InjectionEntry() {
		entry::setType(INJECTION);
	}
	void display() {
		cout << endl;
		cout << " Category INJECTIONS! \n";
		cout << "Name: " << getName() << endl;
		cout << "Dosage per Injection: " << getDosage() << " ml" << endl;
		cout << "Price per Injection: Rs " << getPrice() << endl;
		cout << "Total Items: " << getStock() << endl;;
		cout << "Manufacturer: " << getManu() << endl;
		cout << "Location: Cupboard " << getLocCupboard() << endl;
		cout << " Row: " << getLocRow() << " Col: " << getLocCol() << endl;
		if (getExpiryStatus() == true)
			cout << "Expiry Status: Have expired items" << endl;
		else
			cout << "Expiry Status: NO expired items" << endl;
		time_t now = time(0);
		// convert now time to string form
		char date[26];
		ctime_s(date, sizeof date, &now);
		cout << "Date of EXP: " << date << endl;
	}
};
class SyrupEntry :public entry {
public:
	SyrupEntry() {
		entry::setType(SYRUP);
	}
	void display() {
		cout << endl;
		cout << " Category SYRRUPS! \n";
		cout << "Name: " << getName() << endl;
		cout << "Dosage per Syrrup: " << getDosage() << " ml" << endl;
		cout << "Price per syrrup: Rs " << getPrice() << endl;
		cout << "Total Items: " << getStock() << endl;;
		cout << "Manufacturer: " << getManu() << endl;
		cout << "Location: Cupboard " << getLocCupboard() << endl;
		cout << " Row: " << getLocRow() << " Col: " << getLocCol() << endl;
		if (getExpiryStatus() == true)
			cout << "Expiry Status: Have expired items" << endl;
		else
			cout << "Expiry Status: NO expired items" << endl;
		time_t now = time(0);
		// convert now time to string form
		char date[26];
		ctime_s(date, sizeof date, &now);
		cout << "Date of EXP: " << date << endl;
	}
};
class PowderEntry :public entry {
public:
	PowderEntry() {
		entry::setType(POWDER);
	}
	void display() {
		cout << endl;
		cout << " Category POWDERS! \n";
		cout << "Name: " << getName() << endl;
		cout << "Dosage per sache: " << getDosage() << " mg" << endl;
		cout << "Price per sache: Rs " << getPrice() << endl;
		cout << "Total Items: " << getStock() << endl;;
		cout << "Manufacturer: " << getManu() << endl;
		cout << "Location: Cupboard " << getLocCupboard() << endl;
		cout << " Row: " << getLocRow() << " Col: " << getLocCol() << endl;
		if (getExpiryStatus() == true)
			cout << "Expiry Status: Have expired items" << endl;
		else
			cout << "Expiry Status: NO expired items" << endl;
		time_t now = time(0);
		// convert now time to string form
		char date[26];
		ctime_s(date, sizeof date, &now);
		cout << "Date of EXP: " << date << endl;
	}
};
class InventoryManager {// composite class
	TabletEntry tabletsRec[MAX_ITEMS_PER_CATEGORY];
	InjectionEntry injectionsRec[MAX_ITEMS_PER_CATEGORY];
	SyrupEntry syrupsRec[MAX_ITEMS_PER_CATEGORY];
	PowderEntry powdersRec[MAX_ITEMS_PER_CATEGORY];
	int findCategoryItem(string name, int cat) {
		int indx = 0;
		string item;
		switch (cat) {
		case 1:
			for (indx = 0; indx < MAX_ITEMS_PER_CATEGORY; indx++) {
				item = tabletsRec[indx].getName();
				if (item == name) {
					return indx;
				}
			}
			break;
		case 2:
			for (indx = 0; indx < MAX_ITEMS_PER_CATEGORY; indx++) {
				item = injectionsRec[indx].getName();
				if (item == name) {
					return indx;
				}
			}
			break;
		case 3:
			for (indx = 0; indx < MAX_ITEMS_PER_CATEGORY; indx++) {
				item = syrupsRec[indx].getName();
				if (item == name) {
					return indx;
				}
			}
			break;
		case 4:
			for (indx = 0; indx < MAX_ITEMS_PER_CATEGORY; indx++) {
				item = powdersRec[indx].getName();
				if (item == name) {
					return indx;
				}
			}
			break;
		default:
			break;
		}
		return -1;
	}
	int findemptySlot(int cat) {
		int indx = 0;
		string item;
		switch (cat) {
		case 1:
			for (indx = 0; indx < MAX_ITEMS_PER_CATEGORY; indx++) {
				item = tabletsRec[indx].getName();
				if (item.empty() == true) {
					return indx;
				}
			}
			break;
		case 2:
			for (indx = 0; indx < MAX_ITEMS_PER_CATEGORY; indx++) {
				item = injectionsRec[indx].getName();
				if (item.empty() == true) {
					return indx;
				}
			}
			break;
		case 3:
			for (indx = 0; indx < MAX_ITEMS_PER_CATEGORY; indx++) {
				item = syrupsRec[indx].getName();
				if (item.empty() == true) {
					return indx;
				}
			}
			break;
		case 4:
			for (indx = 0; indx < MAX_ITEMS_PER_CATEGORY; indx++) {
				item = powdersRec[indx].getName();
				if (item.empty() == true) {
					return indx;
				}
			}
			break;
		default:
			break;
		}
		return -1;
	}
public:
	InventoryManager() {
		// init first entry for each medicine type
		tabletsRec[0].setName("CECON");
		tabletsRec[0].setManu("ABBOTT");
		tabletsRec[0].setPrice(20);
		tabletsRec[0].setDosage(500);
		tabletsRec[0].setStock(10);
		time_t exp = time(0);
		tabletsRec[0].setExpiryDate(exp);
		tabletsRec[0].setLocCupboard(1);
		tabletsRec[0].setLocRow(2);
		tabletsRec[0].setLocCol(3);
		injectionsRec[0].setName("CHERABAT");
		injectionsRec[0].setManu("MAHAM");
		injectionsRec[0].setPrice(150);
		injectionsRec[0].setDosage(5);
		injectionsRec[0].setStock(20);
		exp = time(0);
		injectionsRec[0].setExpiryDate(exp);
		injectionsRec[0].setLocCupboard(2);
		injectionsRec[0].setLocRow(3);
		injectionsRec[0].setLocCol(3);
		syrupsRec[0].setName("Paracetamol");
		syrupsRec[0].setManu("ABBOTT");
		syrupsRec[0].setPrice(89);
		syrupsRec[0].setDosage(250);
		syrupsRec[0].setStock(30);
		exp = time(0);
		syrupsRec[0].setExpiryDate(exp);
		syrupsRec[0].setLocCupboard(3);
		syrupsRec[0].setLocRow(1);
		syrupsRec[0].setLocCol(2);
		powdersRec[0].setName("ABC");
		powdersRec[0].setManu("XYZ");
		powdersRec[0].setPrice(134);
		powdersRec[0].setDosage(600);
		powdersRec[0].setStock(40);
		exp = time(0);
		powdersRec[0].setExpiryDate(exp);
		powdersRec[0].setLocCupboard(4);
		powdersRec[0].setLocRow(4);
		powdersRec[0].setLocCol(5);
	}
	int updateitem(int cat, string name, int newstock, time_t exp) {
		int indx = findCategoryItem(name, cat);
		if (indx > -1) {
			switch (cat) {
			case TABLET:
				newstock += tabletsRec[indx].getStock(); //todo implement += operator
				overload for TabletEntry class
					tabletsRec[indx].setStock(newstock);
				tabletsRec[indx].setExpiryDate(exp);
				break;
			case INJECTION:
				newstock += injectionsRec[indx].getStock();//todo implement += operator
				overload for InjectionEntry class
					injectionsRec[indx].setStock(newstock);
				injectionsRec[indx].setExpiryDate(exp);
				break;
			case SYRUP:
				newstock += syrupsRec[indx].getStock(); //todo implement += operator
				overload for SyrupEntry class
					syrupsRec[indx].setStock(newstock);
				syrupsRec[indx].setExpiryDate(exp);
				break;
			case POWDER:
				newstock += powdersRec[indx].getStock();//todo implement += operator
				overload for PowderEntry class
					powdersRec[indx].setStock(newstock);
				powdersRec[indx].setExpiryDate(exp);
				break;
			default:
				break;
			}
		}
		return -1;
	}
	int addNewitem(int cat, string name, string manu, int unit_price, int unit_dosage,
		int stock, time_t exp,
		int cupboard, int row, int col) {
		int slot = -1;
		switch (cat)
		{
		case TABLET:
			slot = findemptySlot(cat);
			if (slot > -1) {
				tabletsRec[slot].setName(name);
				tabletsRec[slot].setManu(manu);
				tabletsRec[slot].setPrice(unit_price);
				tabletsRec[slot].setDosage(unit_dosage);
				tabletsRec[slot].setStock(stock);
				tabletsRec[slot].setExpiryDate(exp);
				tabletsRec[slot].setLocCupboard(cupboard);
				tabletsRec[slot].setLocRow(row);
				tabletsRec[slot].setLocCol(col);
			}
			else
			{
				cout << "No empty slot avaliable in Tablet category database" << endl;
			}
			break;
		case INJECTION:
			slot = findemptySlot(cat);
			if (slot > -1) {
				injectionsRec[slot].setName(name);
				injectionsRec[slot].setManu(manu);
				injectionsRec[slot].setPrice(unit_price);
				injectionsRec[slot].setDosage(unit_dosage);
				injectionsRec[slot].setStock(stock);
				injectionsRec[slot].setExpiryDate(exp);
				injectionsRec[slot].setLocCupboard(cupboard);
				injectionsRec[slot].setLocRow(row);
				injectionsRec[slot].setLocCol(col);
			}
			else
			{
				cout << "No empty slot avaliable in Injection category database" << endl;
			}
			break;
		case SYRUP:
			slot = findemptySlot(cat);
			if (slot > -1) {
				syrupsRec[slot].setName(name);
				syrupsRec[slot].setManu(manu);
				syrupsRec[slot].setPrice(unit_price);
				syrupsRec[slot].setDosage(unit_dosage);
				syrupsRec[slot].setStock(stock);
				syrupsRec[slot].setExpiryDate(exp);
				syrupsRec[slot].setLocCupboard(cupboard);
				syrupsRec[slot].setLocRow(row);
				syrupsRec[slot].setLocCol(col);
			}
			else
			{
				cout << "No empty slot avaliable in Injection category database" << endl;
			}
			break;
		case POWDER:
			slot = findemptySlot(cat);
			if (slot > -1) {
				powdersRec[slot].setName(name);
				powdersRec[slot].setManu(manu);
				syrupsRec[slot].setPrice(unit_price);
				syrupsRec[slot].setDosage(unit_dosage);
				powdersRec[slot].setStock(stock);
				powdersRec[slot].setExpiryDate(exp);
				powdersRec[slot].setLocCupboard(cupboard);
				powdersRec[slot].setLocRow(row);
				powdersRec[slot].setLocCol(col);
			}
			else
			{
				cout << "No empty slot avaliable in Powder category database" << endl;
			}
			break;
		default:
			break;
		}
		return -1;
	}
	int saleItem(int cat, string name, int units_sale) {
		int indx = 0;
		int unit_price = 0, dosage = 0, remaining_stock = 0;
		switch (cat) {
		case TABLET:
			indx = findCategoryItem(name, cat);
			if (indx > -1) {
				unit_price = tabletsRec[indx].getPrice();
				dosage = tabletsRec[indx].getDosage();
				remaining_stock = (tabletsRec[indx].getStock() - units_sale);
				tabletsRec[indx].setStock(remaining_stock);
			}
			break;
		case INJECTION:
			indx = findCategoryItem(name, cat);
			if (indx > -1) {
				unit_price = injectionsRec[indx].getPrice();
				dosage = injectionsRec[indx].getDosage();
				remaining_stock = (injectionsRec[indx].getStock() - units_sale);
				injectionsRec[indx].setStock(remaining_stock);
			}
			break;
		case SYRUP:
			indx = findCategoryItem(name, cat);
			if (indx > -1) {
				unit_price = syrupsRec[indx].getPrice();
				dosage = syrupsRec[indx].getDosage();
				remaining_stock = (syrupsRec[indx].getStock() - units_sale);
				syrupsRec[indx].setStock(remaining_stock);
			}
			break;
		case POWDER:
			indx = findCategoryItem(name, cat);
			if (indx > -1) {
				unit_price = powdersRec[indx].getPrice();
				dosage = powdersRec[indx].getDosage();
				remaining_stock = (powdersRec[indx].getStock() - units_sale);
				powdersRec[indx].setStock(remaining_stock);
			}
			break;
		default:
			break;
		}
		time_t now = time(0);
		char date[26];
		ctime_s(date, sizeof date, &now);
		cout
			cout
			<<
			<<
			"Medical Store Inventory System!\n";
		" SALE-RECEIPT:" << endl;
		cout << " ITEM NAME:" << name << " DOSAGE: " << dosage << endl;
		cout << " TOTAL UNITS SALED: " << units_sale << endl;
		cout << " PRICE PER UNIT: RS " << unit_price << endl;
		cout << " TOTAL PRICE: RS " << unit_price * units_sale << endl;
		cout << " Date: " << date << endl;
		return 0;
	}
	void findLocation(string item) {
		int indx;
		indx = findCategoryItem(item, TABLET);
		if (indx > -1 && indx < MAX_ITEMS_PER_CATEGORY) {
			cout << "The Location for " << item << endl;
			tabletsRec[indx].display();
			return;
		}
		indx = findCategoryItem(item, INJECTION);
		if (indx > -1 && indx < MAX_ITEMS_PER_CATEGORY) {
			cout << "The Location for " << item << endl;
			injectionsRec[indx].display();
			return;
		}
		indx = findCategoryItem(item, SYRUP);
		if (indx > -1 && indx < MAX_ITEMS_PER_CATEGORY) {
			cout << "The Location for " << item << endl;
			syrupsRec[indx].display();
			return;
		}
		indx = findCategoryItem(item, POWDER);
		if (indx > -1 && indx < MAX_ITEMS_PER_CATEGORY) {
			cout << "The Location for " << item << endl;
			powdersRec[indx].display();
			return;
		}
		cout << "Item: " << item << " does not exit in the inventory system!\n";
	}
	void display() {
		cout << "\nDISPLAY ALL ITEMS IN TH INVENTORY!" << endl;
		int indx = 0;
		string item;
		for (indx = 0; indx < MAX_ITEMS_PER_CATEGORY; indx++) {
			item = tabletsRec[indx].getName();
			if (item.empty() != true)
				tabletsRec[indx].display();
		}
		for (indx = 0; indx < MAX_ITEMS_PER_CATEGORY; indx++) {
			item = injectionsRec[indx].getName();
			if (item.empty() != true)
				injectionsRec[indx].display();
		}
		for (indx = 0; indx < MAX_ITEMS_PER_CATEGORY; indx++) {
			item = syrupsRec[indx].getName();
			if (item.empty() != true)
				syrupsRec[indx].display();
		}
		for (indx = 0; indx < MAX_ITEMS_PER_CATEGORY; indx++) {
			item = powdersRec[indx].getName();
			if (item.empty() != true)
				powdersRec[indx].display();
		}
	}
}; // InventoryManager class end
int getServiceOption() {
	int usr_service_opt = -1;
	system("CLS");
	cout << "MEDICAL STORE INVENTORY SYSTEM SERVICE OPTIONS MENU!\n\n";
	cout << " Enter 1 to list all items in the inventory system\n";
	cout << " Enter 2 to find any existed item location in the inventory\n";
	cout << " Enter 3 to add new item into the inventory\n";
	cout << " Enter 4 to sale any item\n";
	cout << " Enter 5 to update an existed item into the inventory\n";
	cout << " Enter 6 to Quit Inventory system\n";
	cin >> usr_service_opt;
	return usr_service_opt;
}
void listAllItems(InventoryManager* inventoryMan) {
	inventoryMan->display();
}
void getItemLocation(InventoryManager* inventoryMan) {
	string item2find;
	cout << " Enetr item name to find its Location \n";
	cin >> item2find;
	inventoryMan->findLocation(item2find);
}
void updateItemStock(InventoryManager* inventoryMan) {
	string item2update;
	int cat;
	int newstock = 0;
	cout << " Enetr item name to update \n";
	cin >> item2update;
	cout << " Enter item category(1:tablet, 2:Injection, 3:syrrup 4:powder\n";
	cin >> cat;
	cout << " Enter new stock (number of units)\n";
	cin >> newstock;
	time_t newStockExp = time(0);
	inventoryMan->updateitem(cat, item2update, newstock, newStockExp);
}
void addNewItem(InventoryManager* inventoryMan) {
	string newItem, newItemManu;
	int cat;
	int newstock = 0;
	int unit_price = 0;
	int unit_dosage = 0;
	int cupboard = 4;
	int r = 2, c = 3;
	cout << " Enetr item name to add in inventory system \n";
	cin >> newItem;
	cout << " Enetr item manufacturer to add in inventory system \n";
	cin >> newItemManu;
	cout << " Enter item category(1:tablet, 2:Injection, 3:syrrup 4:powder\n";
	cin >> cat;
	cout << " Enter stock (number of units)\n";
	cin >> newstock;
	cout << " Enter unit price)\n";
	cin >> unit_price;
	cout << " Enter dosage per unit)\n";
	cin >> unit_dosage;
	cout << " Enter location cupboard)\n";
	cin >> cupboard;
	cout << " Enter location row)\n";
	cin >> r;
	cout << " Enter location column)\n";
	cin >> c;
	time_t newStockExp = time(0);
	inventoryMan->addNewitem(cat, newItem, newItemManu,
		unit_price, unit_dosage, newstock, newStockExp, cupboard, r, c);
}
void handle_sale(InventoryManager* inventoryMan) {
	string item2sale;
	int cat;
	int sale_stock = 0;
	cout << " Enetr item name to sale \n";
	cin >> item2sale;
	cout << " Enter item category(1:tablet, 2:Injection, 3:syrrup 4:powder\n";
	cin >> cat;
	cout << " Enter number of units to sale)\n";
	cin >> sale_stock;
	time_t newStockExp = time(0);
	inventoryMan->saleItem(cat, item2sale, sale_stock);
}
int handle_user_options(int usr_service, InventoryManager* inventoryMan)
{
	int retcode = -1;
	switch (usr_service)
	{
	case LIST_ALL_ITEMS:
		listAllItems(inventoryMan);
		break;
	case ITEM_LOCATION:
		getItemLocation(inventoryMan);
		break;
	case UPADTE_ITEM_STOCK:
		updateItemStock(inventoryMan);
		break;
	case ADD_NEW_ITEM:
		addNewItem(inventoryMan);
		break;
	case SALE_ITEM:
		handle_sale(inventoryMan);
		break;
	case QUIT:
		break;
	default:
		cout << "unsupported service " << usr_service << endl;
		break;
	}
	return retcode;
}
void user_quit()
{
	system("CLS");
	cout << " The Inventory system is quited!\n";
}
int main()
{
	int user_service_option = -1;
	bool service_loop = true;
	InventoryManager myMedicalStore;
	while (service_loop)
	{
		user_service_option = getServiceOption();
		if (user_service_option == 6)
		{
			service_loop = false;
			user_quit();
			continue;
		}
		else
		{
			handle_user_options(user_service_option, &myMedicalStore);
		}
		//string ignore;
		//cin >> ignore;
		char c = getchar();
		// wait before display options again
		cout << "\nEnter any key to goback to main serivces menu\n";
		c = getchar();
	}
}
