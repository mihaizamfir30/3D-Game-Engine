#include "Server.h"

Server* Server::serverInstance = NULL;

Server::Server() {

}

void Server::Init() {
	 
	parseUsers();
}

void Server::parseUsers() {

	xml_document<> doc;

	std::ifstream file("../Resources/XMLs/users.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	// Iterate through users list
	for (xml_node<>* pNode = doc.first_node()->first_node(); pNode; pNode = pNode->next_sibling()) {


		if (strcmp(pNode->name(), "user") != 0) {
			std::cout << "ERROR::SERVER_INIT:UNEXPECTED_ELEMENT" << std::endl;
			continue;
		}

		int id;

		User* user = new User();

		// Read User Id
		xml_attribute<>* pAttr = pNode->first_attribute("id");
		if (pAttr != NULL) {
			id = atoi(pAttr->value());
		}
		else {
			std::cout << "ERROR::SERVER_INIT:NO_VALID_USER_ID" << std::endl;
			continue;
		}

		// Read Child Attributes
		for (xml_node<>* pChild = pNode->first_node(); pChild; pChild = pChild->next_sibling()) {

			// Name
			if (strcmp(pChild->name(), "name") == 0) {
				user->name = (char*)malloc(strlen(pChild->value()) + 1);
				user->name = strncpy(user->name, pChild->value(), strlen(pChild->value()));
				user->name[strlen(pChild->value())] = '\0';
			}

			// Password
			if (strcmp(pChild->name(), "password") == 0) {
				user->password = (char*)malloc(strlen(pChild->value()) + 1);
				user->password = strncpy(user->password, pChild->value(), strlen(pChild->value()));
				user->password[strlen(pChild->value())] = '\0';
			}
		}

		serverInstance->users.insert(std::pair<int, User*>(id, user));
		serverInstance->usernameToIdMap.insert(std::pair<char*, int>(user->name, id));

	}



}

Server* Server::GetInstance() {
	if (serverInstance == NULL) {
		serverInstance = new Server();
	}

	return serverInstance;
}

void Server::FreeResources() {

}

Server::~Server() {

}

bool Server::Login(char* name, char* password) {

	// Check if user exists
	auto user2Idi = usernameToIdMap.find(name);

	if (user2Idi == usernameToIdMap.end()) {
		std::cout << "ERROR::SERVER::UNRECOGNIZED_USERNAME" << name << std::endl;
		return false;
	}
	
	// Check if passwords match
	int id = user2Idi->second;
	auto iu = users.find(id);
	
	if (strcmp(iu->second->password, password) == 0) {
		return true;
	}
	else {
		std::cout << "ERROR::SERVER::WRONG_PASSWORD" << std::endl;
		return false;
	}

}