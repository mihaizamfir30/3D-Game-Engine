#pragma once
#include<map>
#include<string>
#include<sstream>
#include<fstream>
#include <iostream>

#include "../RapidXML/rapidxml.hpp"
#include "Utils.h"

using namespace rapidxml;

struct User {
	char* name;
	char* password;

};

struct cmp_str
{
	bool operator()(char const* a, char const* b) const
	{
		return std::strcmp(a, b) < 0;
	}
};

class Server
{
	
	public:

		Server();

		void Init();
		static Server* GetInstance();
		void FreeResources();

		~Server();

		bool Login(char* name, char* password);

	private:

		void parseUsers();

		static Server* serverInstance;

		std::map<int, User*> users;
		std::map<char*, int, cmp_str> usernameToIdMap;


};
