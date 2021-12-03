#pragma once
#include<map>
#include<string>
#include<sstream>
#include<fstream>
#include <iostream>


#include "../RapidXML/rapidxml.hpp"

#include "Engine/Mesh.h"
#include "Engine/Texture.h"
#include "Engine/Shader.h"

using namespace rapidxml;

struct ModelResource {
	char* path;
};

struct ShaderResource {
	char* vs;
	char* fs;
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

		void Init();
		static ResourceManager* GetInstance();
		void FreeResources();
		~ResourceManager();

		/*
		Model* LoadModel(int modelId);
		Texture* LoadTexture(int textureId);
		Shader* LoadShader(int shaderId);
		*/

		Mesh* LoadModel(int modelId);
		Shader* LoadShader(int shaderId);

	private:
		ResourceManager();

		void ParseModels(xml_node<>* pNode);
		void ParseTextures(xml_node<>* pNode);
		void ParseShaders(xml_node<>* pNode);

		std::map<int, ModelResource*> modelResources;
		std::map<int, TextureResource*> textureResources;
		std::map<int, ShaderResource*> shaderResources;

		std::map<int, Mesh*> models;
		std::map<int, Texture*> textures;
		std::map<int, Shader*> shaders;

		static ResourceManager* rmInstance;
};
