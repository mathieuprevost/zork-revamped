////////////////////////////////////////////////////////////////////////////////
/// File	 Link.hpp
/// Author	 Mathieu Prevost
/// Date     2021-12-22
/// Creation 2021-12-04
/// Definition of the class Link
////////////////////////////////////////////////////////////////////////////////

#pragma once

class Room;

class Link {
public:
	Link() = default;
	Link(char direction, Room* endRoom, bool visible) :
		direction_(direction),
		endRoom_(endRoom),
		visible_(visible)
	{}

	void reveal() { visible_ = true; }
	char getDirection() { return direction_; }
	Room* getEndRoom() { return endRoom_; }
	bool getVisible() { return visible_; }

private:
	char direction_;
	Room* endRoom_ = nullptr;
	bool visible_ = true;
};