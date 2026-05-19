#include "database.h"
#include <iostream>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Usage: ./app filename\n";
	return 1;
	}

	Database db(argv[1]);
	db.load();
	int choice;
	do {
		std::cout << "\n";
		std::cout << "1. Показать\n";
		std::cout << "2. Добавить\n";
		std::cout << "3. Удалить\n";
		std::cout << "4. Редактировать\n";
		std::cout << "5. Поиск по имени\n";
		std::cout << "6. Поиск по категории\n";
		std::cout << "0. Выход\n";
		std::cout << "Введите номер: ";
		std::cin >> choice;
		if (choice == 1) {
			db.print();
	}

	else if (choice == 2) {
		VKCommunity obj;

	std::cout
		<< "Введите:\n"
		<< "name id category subscribers\n";
	std::cin >> obj;
	db.add(obj);
	}
	else if (choice == 3) {
		int index;
		std::cout << "Введите индекс: ";
		std::cin >> index;
		db.remove(index);
	}
	else if (choice == 4) {
		int index;
		std::cout << "Введите индекс: ";
		std::cin >> index;
		db.edit(index);
	}

	else if (choice == 5) {
		std::string name;
		std::cout << "Введите имя: ";
		std::cin >> name;
		db.searchByName(name);
	}

	else if (choice == 6) {
		std::string category;
		std::cout << "Введите категорию: ";
		std::cin >> category;
		db.searchByCategory(category);
	}

	} while (choice != 0);
	db.save();
	return 0;
}
