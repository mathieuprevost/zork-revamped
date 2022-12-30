////////////////////////////////////////////////////////////////////////////////
/// File	 Room.hpp
/// Author	 Mathieu Prevost
/// Date     2021-12-22
/// Creation 2021-12-04
/// Definition of the class Room
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Link.hpp"
#include "Object.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "cppitertools/range.hpp"

class Link;
class Object;

enum Directions : char {
	North =	'N',
	South =	'S',
	East =	'E',
	West =	'W'
};

class Room {
public:
	Room() = default;
	Room(const std::string& name, const std::string& description);

	void display(std::ostream& os);
	void displayLinks(std::ostream& os);

	void link(char direction, Room* endRoom, bool visible = true);
	bool checkDirection(char direction);
	std::string charToString(char direction);

	void addObject(Object* object);
	Object* findObject(const std::string& words);

	Room* getRoom(char direction);
	Link* getLink(char direction);
	const std::string& getName() const { return name_; }
	const std::string& getDescription() const { return description_;  }

private:
	std::string name_;
	std::string description_;
	std::map<char, std::unique_ptr<Link>> links_;
	std::vector<Object*> objects_;
};