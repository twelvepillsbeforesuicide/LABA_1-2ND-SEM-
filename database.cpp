#include "database.h"

#include <fstream>
#include <iostream>

Database::Database(const std::string& file)
	: head(nullptr), filename(file) {}

Database::~Database() {

	Node* current = head;
	while (current != nullptr) {

		Node* temp = current;
		current = current->next;
		delete temp;
	}
}

void Database::add(const VKCommunity& obj) {

	Node* newNode = new Node(obj);

	if (head == nullptr) {
		head = newNode;
		return;
	}

	Node* current = head;

	while (current->next != nullptr) {
	current = current->next;
	}

	current->next = newNode;
}

void Database::print() const {
	Node* current = head;
	int index = 0;
	while (current != nullptr) {

	std::cout
		<< index
		<< ": "
		<< current->data
		<< std::endl;

	current = current->next;

	index++;
	}
}

void Database::remove(int index) {

	if (head == nullptr || index < 0)
		return;
	if (index == 0) {
		Node* temp = head;
		head = head->next;
	delete temp;
	return;
	}
	Node* current = head;
	for (int i = 0; i < index - 1; i++) {
		if (current->next == nullptr)
			return;
		current = current->next;
	}
	if (current->next == nullptr)
		return;
	Node* temp = current->next;
	current->next = temp->next;
	delete temp;
}

void Database::edit(int index) {
	Node* current = head;
	for (int i = 0; i < index; i++) {
		if (current == nullptr)
		return;
	current = current->next;
	}
	if (current == nullptr)
		return;
	std::cout << "Введите новые данные:\n";
	std::cin >> current->data;
}

void Database::searchByName(
	const std::string& name
) const {

	Node* current = head;
	while (current != nullptr) {
		if (current->data.getName() == name) {std::cout << current->data << std::endl;
		}
		current = current->next;
	}
}

void Database::searchByCategory(
	const std::string& category
) const {

	Node* current = head;
	while (current != nullptr) {
	if (current->data.getCategory() == category) {
		std::cout << current->data << std::endl;
		}
		current = current->next;
	}
}

void Database::save() {

	std::ofstream out(filename);
	Node* current = head;
	while (current != nullptr) {
		out << current->data << std::endl;
		current = current->next;
	}
}

void Database::load() {
	std::ifstream in(filename);
	if (!in.is_open())
		return;

	VKCommunity temp;
	while (in >> temp) {
		add(temp);
	}
}
