#include "vkcommunity.h"

VKCommunity::VKCommunity()
	: name(""), id(0), category(""), subscribers(0) {}

VKCommunity::VKCommunity(const std::string& n, int i,	const std::string& c,	int s)
	: name(n), id(i), category(c), subscribers(s) {}

const std::string& VKCommunity::getName() const {
	return name;
	}

int VKCommunity::getId() const {
	return id;
	}

const std::string& VKCommunity::getCategory() const {
	return category;
	}

int VKCommunity::getSubscribers() const {
	return subscribers;
	}

void VKCommunity::setName(const std::string& n) {
	name = n;
	}

void VKCommunity::setId(int i) {
	id = i;
	}

void VKCommunity::setCategory(const std::string& c) {
	category = c;
	}

void VKCommunity::setSubscribers(int s) {
	subscribers = s;
	}

std::ostream& operator<<(std::ostream& os, const VKCommunity& obj) {

	os << obj.name << " "
		<< obj.id << " "
		<< obj.category << " "
	<< obj.subscribers;

	return os;
	}

std::istream& operator>>(std::istream& is,
		VKCommunity& obj) {

	is >> obj.name
	>> obj.id
	>> obj.category
	>> obj.subscribers;

	return is;
	}
