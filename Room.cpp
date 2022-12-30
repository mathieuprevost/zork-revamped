////////////////////////////////////////////////////////////////////////////////
/// File	 Room.cpp
/// Author	 Mathieu Prevost
/// Date     2021-12-22
/// Creation 2021-12-04
/// Definition of the methods of the class Room
////////////////////////////////////////////////////////////////////////////////

#include"Room.hpp"

Room::Room(const std::string& name, const std::string& description):
	name_(name)
{
	description_ = "This is the " + name_ + ". " + description;
}

void Room::display(std::ostream& os)
{
	os	<< description_ << std::endl;
	if (!objects_.empty()) {
		os << "You notice : " << std::endl;
		for (auto o : objects_) {
			if (o->getVisible())
				os << "\tA " + o->getName() + "." << std::endl;
		}
	}
	else
		os << "There is no objects in this room." << std::endl;
	displayLinks(os);
}

void Room::displayLinks(std::ostream& os)
{
	for (auto it = links_.begin(); it != links_.end(); ++it){
		if (it->second->getVisible()) {
			char direction = it->second->getDirection();
			os	<< it->second->getEndRoom()->getName()
				<< " is to the " 
				<< charToString(direction) + " (" + direction << ")."
				<< std::endl;
		}
	}
}

void Room::link(char direction, Room* endRoom, bool visible) {
	links_[direction] = std::make_unique<Link>(Link(direction, endRoom, visible));
}

bool Room::checkDirection(char direction)
{
	if (links_.find(direction) != links_.end() && links_[direction]->getVisible())
		return true;
	else
		return false;
};

std::string Room::charToString(char direction) 
{
	std::string directionString;
	switch (direction) {
		case Directions::North:	return "North";
		case Directions::South:	return "South";
		case Directions::East:	return "East";
		case Directions::West:	return "West";
		default: return "";
	}
}

void Room::addObject(Object* object) {
	objects_.push_back(object);
}

Object* Room::findObject(const std::string& words)
{
	for (auto o : objects_) {
		for (auto kw : o->getKeyWords()) {
			if (words.find(kw) != std::string::npos)
				return o;
		}
	}
	return nullptr;
}

Room* Room::getRoom(char direction) {
	return links_[direction]->getEndRoom();
}

Link* Room::getLink(char direction) { 
	return links_[direction].get();
}