////////////////////////////////////////////////////////////////////////////////
/// File	 World.hpp
/// Author	 Mathieu Prevost
/// Date     2021-12-22
/// Creation 2021-12-04
/// Definition of the class World
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Room.hpp"
#include "Link.hpp"
#include "Object.hpp"
#include "UsableObject.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include <algorithm>
#include <cppitertools/range.hpp>

const enum Rooms {
	classroom, hall, bathroom, cafeteria, computerLab,
	entrance, serverRoom, projectRoom
};
/*
const enum class Rooms {
	classroom, hall, bathroom, cafeteria, computerLab,
	entrance, serverRoom, projectRoom
};
*/
const enum Objects {
	seat, board, outlet,
	lunchTable, microwave, lunchTray,
	computer, projector,
	sink, soapDispenser, toilet,
	serverCase, fan, patatoes,
	waterFountain, elevator, cerealBowl, digitalClock,
	painting, blackButton, poster,
	console, cabinet, instructions
};


class World {
public:
	World();

	void createInitialRooms();
	void createInitialObjects();
	void createUsableObjects();
	void createInitialLinks();
	void createRoom(int roomId, const std::string& name, const std::string& description);

	void createObject(	int objectId, int roomId, const std::string& name,
						const std::string& description, const std::string& action,
						const std::vector<std::string>& keyWords, bool visible = true);

	void createUsable(	int objectId, int roomId, const std::string& name,
						const std::string& description, const std::string& action,
						const std::vector<std::string>& keyWords,
						const std::string& usedMessage, Object* revealedObject,
						Link* link = nullptr, bool visible = true);

	void linkRooms(int startRoomId, char direction, int endRoomId, bool visible = true);

	Room* getRoom(int roomId) { return rooms_[roomId].get(); };
	char getReverseDirection (char direction) const;
	Link* getOppositeLink (Link* link) const;

private:
	std::unordered_map<int, std::unique_ptr<Room>>		rooms_;
	std::unordered_map<int, std::unique_ptr<Object>>	objects_;
};
