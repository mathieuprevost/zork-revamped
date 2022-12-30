////////////////////////////////////////////////////////////////////////////////
/// File	 World.cpp
/// Author	 Mathieu Prevost
/// Date     2021-12-22
/// Creation 2021-12-04
/// Definition of the methods of the class World
////////////////////////////////////////////////////////////////////////////////

#include"World.hpp"

World::World()
{
	createInitialRooms();
	createInitialObjects();
	createInitialLinks();
	createUsableObjects();
}

void World::createInitialRooms()
{
	createRoom(	Rooms::classroom, "Classroom", "There is a lot of squeaky chairs."
				"There is about one electrical outlet for 30 seats.");
	createRoom(	Rooms::cafeteria, "Cafeteria", "There is a small counter for food."
				"The smell of delicious sandwichs and cheap fries is very strong.");
	createRoom(	Rooms::computerLab, "Computer Lab",
				"The computers looks very old. The walls are blue.");
	createRoom(	Rooms::bathroom, "Bathroom",
				"The soap dispenser is empty. One of the sinks is out of order.");
	createRoom(	Rooms::serverRoom, "Server Room",
				"A bag of patatoes is near the exit. The fans make a lot of noise.");
	createRoom(	Rooms::hall, "Hall",
				"It is very cold. Some paintings are hanging on the wall.");
	createRoom(	Rooms::entrance, "Entrance",
				"The escalators are out of order. There is a mask dispenser.");
	createRoom(	Rooms::projectRoom, "Project Room",
				"A console with colorful screens. There is posters on the wall.");
}

void World::createInitialObjects()
{
	createObject(	Objects::seat, Rooms::classroom, "Seat",
					"This is a red seat. It seems from the 1950s.",
					"As you sit in the seat, an incredibly loud sound emits"
					" from it. You immediately get up.",
					{ "seat" });
	createObject(	Objects::board, Rooms::classroom, "Black board",
					"This is a black board. It has strange symbols on it.",
					"As soon as you try to write something on it, you hear"
					" a young girl laughing. You turn around and see no one.",
					{ "black", "board" });
	createObject(	Objects::outlet, Rooms::classroom, "Electrical outlet",
					"This is a single electrical outlet. It's full of dust.",
					"You try charging your laptop, but it doesn't seems to work.",
					{ "electrical", "electric" , "outlet" });

	createObject(	Objects::lunchTable, Rooms::cafeteria, "Lunch table",
					"This is a table for four person. "
					"There's some fries on the table.",
					"You try to plank on the table and "
					"can hear your ancestors laughing at you.",
					{ "table", "lunch" });
	createObject(	Objects::microwave, Rooms::cafeteria, "Microwave oven",
					"This is a modern microwave. "
					"The buttons are so used you can barely see the numbers.",
					"You try to use it, but the door seems stuck. It's very sticky.",
					{ "micro", "wave","oven" });
	createObject(	Objects::lunchTray, Rooms::cafeteria, "Lunch tray",
					"This is a blue lunch tray. "
					"It has a small crack on one of his side.",
					"You try to use as a sledge, but can't find a hill near by.",
					{ "lunch", "tray" });

	createObject(	Objects::computer, Rooms::computerLab, "Computer",
					"This is a computer with a monitor. "
					"The keyboard seems very dirty. The mouse seems old.",
					"After booting it and opening Internet Explorer, "
					"you manage to open Google in 10 minutes.",
					{ "computer" });
	createObject(	Objects::projector, Rooms::computerLab, "Projector",
					"This is a projector connected to the computer. "
					"It's in a metal box.",
					"After pushing the power button, "
					"a screen comes down and a very loud noise can be heard.",
					{ "projector" });

	createObject(	Objects::sink, Rooms::bathroom, "Sink",
					"This is a white sink. "
					"There's a small puddle of water around it.",
					"You try to wash your hands, but it seems to be out of order.",
					{ "sink" });
	createObject(	Objects::soapDispenser, Rooms::bathroom, "Soap dispenser",
					"This is a soap dispenser, but it seems empty. "
					"There is a puddle of pink soap under it.",
					"You try to use it and realise that it's empty. "
					"Your hands are now dirtier.",
					{ "soap","dispenser" });
	createObject(	Objects::toilet, Rooms::bathroom, "Toilet",
					"This is a toilet of the brand <<TOTO>>. "
					"There is plenty of toilet paper next to it.",
					"Before trying to do anything, "
					"you realise that door can't lock and forget about it.",
					{ "toilet" });

	createObject(	Objects::serverCase, Rooms::serverRoom, "Server Case",
					"This is a case for a server that you can see. "
					"It seems locked.",
					"You try to force the lock, but it doesn't budge.",
					{ "server","case" });

	createObject(	Objects::fan, Rooms::serverRoom, "Industrial Fan",
					"This is a an industrial fan. "
					"It seems to be used manage the heat in this room.",
					"You try to touch it with your finger and immediately "
					"hurt yourself. What were you thinking?.",
					{ "industrial","fan" });
	createObject(	Objects::patatoes, Rooms::serverRoom, "Bag of Potatoes",
					"This is a bag of Russet potatoes. They seems very fresh.",
					"You pick up the bag to smell it. "
					"It has a very unique smell like ... Moodle Servers?",
					{ "bag","patato" });

	createObject(	Objects::waterFountain, Rooms::hall, "Water Fountain",
					"This is a water fountain. You could also refill a bottle",
					"As you drink from it, "
					"you notice that the pressure is extremely low.",
					{ "water", "fountain" });
	createObject(	Objects::elevator, Rooms::hall, "Elevator",
					"This is an old elevator. It seems out of order.",
					"When you press the button to call it, nothing happens.",
					{ "elevator" });
	createObject(	Objects::cerealBowl, Rooms::hall, "Blue cereal bowl",
					"This is a blue cerreal bowl. "
					"It seems to have milk and cereal in it.",
					"When you lift the bowl, you notice a fine print. "
					"DOO NOOT MICROOWAVEE",
					{ "blue","cereal","bowl" });
	createObject(	Objects::digitalClock, Rooms::hall, "Digital Clock",
					"This is a digital clock with the date. "
					"The time is 13:37 on the 20th of april.",
					"The clock is too high. You can't reach it.",
					{ "digital","clock" });
	createObject(	Objects::poster, Rooms::entrance, "Colorful Poster",
					"This is a poster with a lot of colors.",
					"The poster is made of metal and glued to the wall.",
					{ "colorful","poster" });

	createObject(	Objects::console, Rooms::projectRoom, "Huge Console",
					"This is an enormous console. "
					"It has over 30 screens and 500 buttons.",
					"As you press random buttons,"
					" error messages appear and the screens.",
					{ "huge","console" });
	createObject(	Objects::instructions, Rooms::projectRoom,
					"Project Instructions",
					"This is so beautiful. It's a file with many pages inside.",
					"After opening it, "
					"you read the project requirements and feel incredibly"
					" happy. You can now live in peace.",
					{ "project","instructions" }, false);
}

void World::createUsableObjects()
{
	createUsable(	Objects::blackButton, Rooms::entrance, "Black button",
					"This is a button as black as coal.",
					"After pushing it, a very loid nouse is heard. "
					"You should check the other rooms.",
					{ "black", "button" },
					"Pushing it again doesn't seem to do anything.", nullptr,
					rooms_[Rooms::serverRoom]->getLink(Directions::South),					
					false);

	createUsable(	Objects::painting, Rooms::entrance, "Painting",
					"This is a painting of an old man.",
					"While moving the painting, you notice a button behind it.",
					{ "painting" },
					"Please don't paint over someone else's artwork.",
					objects_[Objects::blackButton].get());

	createUsable(	Objects::cabinet, Rooms::projectRoom, "File cabinet",
					"This is a standard cabinet. It's brown and metallic.",
					"After forcing, you manage to open the last drawer "
					"and find a document.", { "file", "cabinet" },
					"The drawer won't budge. "
					"It seems you put too much force and broke it.", 
					objects_[Objects::instructions].get());
}

void World::createInitialLinks()
{
	linkRooms(Rooms::hall, Directions::North,	Rooms::cafeteria);
	linkRooms(Rooms::hall, Directions::South,	Rooms::entrance);
	linkRooms(Rooms::hall, Directions::East,	Rooms::bathroom);
	linkRooms(Rooms::hall, Directions::West,	Rooms::classroom);

	linkRooms(Rooms::entrance, Directions::East, Rooms::computerLab);

	linkRooms(Rooms::serverRoom, Directions::North, Rooms::classroom);

	linkRooms(Rooms::serverRoom, Directions::South, Rooms::projectRoom, false);
}

void World::createRoom(int roomId, const std::string& name, const std::string& description)
{
	rooms_[roomId] = std::make_unique<Room>(Room(name, description));
}

void World::createObject(	int objectId, int roomId, const std::string& name,
							const std::string& description, const std::string& action,
							const std::vector<std::string>& keyWords, bool visible)
{
	objects_[objectId] = std::make_unique<Object>(Object(name, description,
													action, keyWords, visible));
	rooms_[roomId]->addObject(objects_[objectId].get());
}

void World::createUsable(	int objectId, int roomId, const std::string& name,
							const std::string& description, const std::string& action,
							const std::vector<std::string>& keyWords,
							const std::string& usedMessage, Object* revealedObject,
							Link* link, bool visible)
{
	Link* oppositeLink = getOppositeLink(link);
	
	UsableObject object = UsableObject(	name, description, action, keyWords,
										usedMessage, revealedObject, link,
										oppositeLink, visible);

	objects_[objectId] = std::make_unique<UsableObject>(object);
	rooms_[roomId]->addObject(objects_[objectId].get());

}

void World::linkRooms(int startRoomId, char direction, int endRoomId, bool visible)
{
	char oppositeDirection = getReverseDirection(direction);
	rooms_[startRoomId]->link(direction, rooms_[endRoomId].get(), visible);
	rooms_[endRoomId]->link(oppositeDirection, rooms_[startRoomId].get(), visible);
}

char World::getReverseDirection(char direction) const
{
	switch (direction) {
		case Directions::North: return Directions::South;
		case Directions::South: return Directions::North;
		case Directions::East:	return Directions::West;
		case Directions::West:	return Directions::East;
		default: return 'X';
	} 
}

Link* World::getOppositeLink(Link* link) const
{
	if (link != nullptr) {
		char oppositeDirection = getReverseDirection(link->getDirection());
		Room* endRoom = link->getEndRoom();
		return endRoom->getLink(oppositeDirection);
	}
	else
		return nullptr;
}