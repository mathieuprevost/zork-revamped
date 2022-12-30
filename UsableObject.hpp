////////////////////////////////////////////////////////////////////////////////
/// File	 UsableObject.hpp
/// Author	 Mathieu Prevost
/// Date     2021-12-22
/// Creation 2021-12-04
/// Definition of the class UsableObject
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Object.hpp"

class UsableObject : public Object
{
public :
	UsableObject(const std::string& name, const std::string& description, const std::string& action,
		const std::vector<std::string>& keyWords,
		const std::string& usedMessage, Object* revealedObject, Link* link, Link* oppositeLink,
		bool visible);

	void use(std::ostream& os) override;

private:
	bool used_ = false;
	std::string usedMessage_;
	Object* revealedObject_;
	std::pair<Link*, Link*> revealedLinks_;
};