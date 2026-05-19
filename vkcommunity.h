#ifndef VKCOMMUNITY_H
#define VKCOMMUNITY_H

#include <iostream>
#include <string>

class VKCommunity {
private:
	std::string name;
	int id;
	std::string category;
	int subscribers;

public:
	VKCommunity();
	VKCommunity(const std::string& n, int i, const std::string& c, int s);

	const std::string& getName() const;
	int getId() const;
	const std::string& getCategory() const;
	int getSubscribers() const;

	void setName(const std::string& n);
	void setId(int i);
	void setCategory(const std::string& c);
	void setSubscribers(int s);

	friend std::ostream& operator<<(std::ostream& os, const VKCommunity& obj);
	friend std::istream& operator>>(std::istream& is, VKCommunity& obj);
};

#endif
