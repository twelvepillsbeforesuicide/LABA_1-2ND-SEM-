#ifndef DATABASE_H
#define DATABASE_H

#include "vkcommunity.h"
#include <string>

class Database {
private:

	struct Node {
		VKCommunity data;
		Node* next;

		Node(const VKCommunity& d)
			: data(d), next(nullptr) {}
		};

	Node* head;
	std::string filename;

public:
	Database(const std::string& file);

	~Database();

	void load();

	void save();

	void print() const;

	void add(const VKCommunity& obj);

	void remove(int index);

	void edit(int index);

	void searchByName(const std::string& name) const;

	void searchByCategory(const std::string& category) const;
	};

#endif
