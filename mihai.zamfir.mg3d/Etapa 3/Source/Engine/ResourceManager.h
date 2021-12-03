#pragma once
#include<map>
#include<string>
#include<sstream>
#include<fstream>
#include <iostream>


#include "../RapidXML/rapidxml.hpp"

#include "Engine/Map.h"
#include "Engine/Mesh.h"
#include "Engine/Texture.h"
#include "Engine/Shader.h"
#include "Engine/Utils.h"

using namespace rapidxml;

struct Settings {
	glm::ivec2 resolution;
};

struct MapResource {
	char* name;
	int modelId;

	glm::vec3 position;
	glm::vec3 scale;
};

struct ModelResource {;
	char* path;
};

struct ShaderResource {
	char* vs;
	char* fs;
};

struct ScriptResource {
	char* path;
};

struct TextureResource {
	char* path;
	char* type;
	char* mag_filter;
	char* min_filter;
	char* wrap_s;
	char* wrap_t;
};

class ResourceManager
{
	
	public:

		void InitSettings();
		void Init();

		static ResourceManager* GetInstance();
		void FreeResources();
		~ResourceManager();

		Map* LoadMap(int mapId);
		Mesh* LoadModel(int modelId);
		Texture* LoadTexture(int textureId);
		Shader* LoadShader(int shaderId);
		char* LoadScript(int scriptId);

		glm::ivec2 GetResolution();

	private:
		ResourceManager();

		void parseSettings(xml_node<>* pNode);
		void parseMaps(xml_node<>* pNode);
		void parseModels(xml_node<>* pNode);
		void parseTextures(xml_node<>* pNode);
		void parseShaders(xml_node<>* pNode);
		void parseScripts(xml_node<>* pNode);

		Settings settings;

		std::map<int, MapResource*> mapResources;
		std::map<int, ModelResource*> modelResources;
		std::map<int, TextureResource*> textureResources;
		std::map<int, ShaderResource*> shaderResources;
		std::map<int, ScriptResource*> scriptResources;

		std::map<int, Map*> maps;
		std::map<int, Mesh*> models;
		std::map<int, Texture*> textures;
		std::map<int, Shader*> shaders;
		std::map<int, char*> scripts;

		static ResourceManager* rmInstance;
};
