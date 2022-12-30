
#include "UsableObject.hpp"

UsableObject::UsableObject(const std::string& name, const std::string& description, const std::string& action,
	const std::vector<std::string>& keyWords,
	const std::string& usedMessage, Object* revealedObject, Link* link, Link* oppositeLink,
	bool visible) : 
	Object(name, description, action, keyWords, visible),
	usedMessage_(usedMessage),
	revealedObject_(revealedObject),
	revealedLinks_({ link, oppositeLink })
{}

void UsableObject::use(std::ostream& os) {
	if (used_) {
		os << usedMessage_ + "\n";
	}
	else {
		if (revealedObject_ != nullptr)
			revealedObject_->reveal();
		if (revealedLinks_.first != nullptr) {
			revealedLinks_.first->reveal();
			revealedLinks_.second->reveal();
		}
		used_ = true;
		displayAction(os);
	}
}