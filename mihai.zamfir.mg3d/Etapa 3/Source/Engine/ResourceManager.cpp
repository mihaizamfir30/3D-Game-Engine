#include "ResourceManager.h"

ResourceManager* ResourceManager::rmInstance = NULL;

ResourceManager::ResourceManager() {

	// Set a default resolution in case we don't find one in config files
	settings.resolution = glm::ivec2(300, 300);

}

ResourceManager::~ResourceManager() {

}

ResourceManager* ResourceManager::GetInstance() {
	if (rmInstance == NULL) {
		rmInstance = new ResourceManager();
	}

	return rmInstance;
}

void ResourceManager::InitSettings() {

	xml_document<> doc;

	std::ifstream file("../Resources/XMLs/settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	parseSettings(doc.first_node());

}

void ResourceManager::Init() {

	xml_document<> doc;

	std::ifstream file("../Resources/XMLs/resourceManager.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	// Iterate through root's children nodes: Models, Shaders, Textures etc. 
	for (xml_node<>* pNode = doc.first_node()->first_node(); pNode; pNode = pNode->next_sibling()) {

		if (strcmp(pNode->name(), "settings") == 0) {
			parseSettings(pNode);
		}

		if (strcmp(pNode->name(), "maps") == 0) {
			parseMaps(pNode);
		}

		if (strcmp(pNode->name(), "models") == 0) {
			parseModels(pNode);
		}

		if (strcmp(pNode->name(), "textures") == 0) {
			parseTextures(pNode);
		}

		if (strcmp(pNode->name(), "shaders") == 0) {
			parseShaders(pNode);
		}

		if (strcmp(pNode->name(), "scripts") == 0) {
			parseScripts(pNode);
		}
	}

}

void ResourceManager::parseScripts(xml_node<>* pNode) {

	for (xml_node<>* pChild = pNode->first_node(); pChild; pChild = pChild->next_sibling()) {

		if (strcmp(pChild->name(), "script") != 0) {
			std::cout << "ERROR::RESOURCE_MANAGER_SCRIPT:UNEXPECTED_ELEMENT" << std::endl;
			continue;
		}

		int id;

		ScriptResource* sr = new ScriptResource();

		// Read Script Id
		xml_attribute<>* pAttr = pChild->first_attribute("id");
		if (pAttr != NULL) {
			id = atoi(pAttr->value());
		}
		else {
			std::cout << "ERROR::RESOURCE_MANAGER_SCRIPT:NO_VALID_ID" << std::endl;
			continue;
		}

		// Read Model Attributes
		for (xml_node<>* pGchild = pChild->first_node(); pGchild; pGchild = pGchild->next_sibling()) {


			// Path
			if (strcmp(pGchild->name(), "path") == 0) {
				sr->path = (char*)malloc(strlen(pGchild->value()) + 1);
				sr->path = strncpy(sr->path, pGchild->value(), strlen(pGchild->value()));
				sr->path[strlen(pGchild->value())] = '\0';
			}


		}

		rmInstance->scriptResources.insert(std::pair<int, ScriptResource*>(id, sr));

	}

}

void ResourceManager::parseSettings(xml_node<>* pNode) {

	for (xml_node<>* pChild = pNode->first_node(); pChild; pChild = pChild->next_sibling()) {


		if (strcmp(pChild->name(), "resolution") == 0) {
			
			
			for (xml_node<>* pGchild = pChild->first_node(); pGchild; pGchild = pGchild->next_sibling()) {
				
				if (strcmp(pGchild->name(), "x") == 0) {
					settings.resolution.x = atoi(pGchild->value());
				}

				if (strcmp(pGchild->name(), "y") == 0) {
					settings.resolution.y = atoi(pGchild->value());
				}
			}		
		}
	}
}


void ResourceManager::parseMaps(xml_node<>* pNode) {

	for (xml_node<>* pChild = pNode->first_node(); pChild; pChild = pChild->next_sibling()) {
	
		if (strcmp(pChild->name(), "map") != 0) {
			std::cout << "ERROR::RESOURCE_MANAGER_MAP:UNEXPECTED_ELEMENT" << std::endl;
			continue;
		}

		int id;

		MapResource* mr = new MapResource();

		// Read Model Id
		xml_attribute<>* pAttr = pChild->first_attribute("id");
		if (pAttr != NULL) {
			id = atoi(pAttr->value());
			std::cout << id << std::endl;
		}
		else {
			std::cout << "ERROR::RESOURCE_MANAGER_MAP:NO_VALID_ID" << std::endl;
			continue;
		}

		// Read Model Attributes
		for (xml_node<>* pGchild = pChild->first_node(); pGchild; pGchild = pGchild->next_sibling()) {

			// Name
			if (strcmp(pGchild->name(), "name") == 0) {
				mr->name = (char*)malloc(strlen(pGchild->value()) + 1);
				mr->name = strncpy(mr->name, pGchild->value(), strlen(pGchild->value()));
				mr->name[strlen(pGchild->value())] = '\0';
			}

			// Model id
			if (strcmp(pGchild->name(), "model") == 0) {
				mr->modelId = atoi(pGchild->value());
			}

			// Position
			if (strcmp(pGchild->name(), "position") == 0) {

				float x = 0, y = 0, z = 0;

				for (xml_node<>* pGgchild = pGchild->first_node(); pGgchild; pGgchild = pGgchild->next_sibling()) {

					if (strcmp(pGgchild->name(), "x") == 0) {
						x = atof(pGgchild->value());
					}
					if (strcmp(pGgchild->name(), "y") == 0) {
						y = atof(pGgchild->value());
					}
					if (strcmp(pGgchild->name(), "z") == 0) {
						z = atof(pGgchild->value());
					}

					mr->position = glm::vec3(x, y, z);
				}
			}

			// Scale
			if (strcmp(pGchild->name(), "scale") == 0) {

				float x = 0, y = 0, z = 0;

				for (xml_node<>* pGgchild = pGchild->first_node(); pGgchild; pGgchild = pGgchild->next_sibling()) {

					if (strcmp(pGgchild->name(), "x") == 0) {
						x = atof(pGgchild->value());
					}
					if (strcmp(pGgchild->name(), "y") == 0) {
						y = atof(pGgchild->value());
					}
					if (strcmp(pGgchild->name(), "z") == 0) {
						z = atof(pGgchild->value());
					}

					mr->scale = glm::vec3(x, y, z);
				}
			}
		}


		/*
		std::cout << std::endl << "MAP " << std::endl;
		std::cout << "   id " << id << std::endl;
		std::cout << "   name " << mr->name << std::endl;
		std::cout << "   model " << mr->modelId << std::endl;
		std::cout << "   position " << mr->position << std::endl;
		std::cout << "   scale " << mr->scale << std::endl;
		*/

		rmInstance->mapResources.insert(std::pair<int, MapResource*>(id, mr));

	}

}

void ResourceManager::parseModels(xml_node<>* pNode) {

	for (xml_node<>* pChild = pNode->first_node(); pChild; pChild = pChild->next_sibling()) {

		if (strcmp(pChild->name(), "model") != 0) {
			std::cout << "ERROR::RESOURCE_MANAGER_MODEL:UNEXPECTED_ELEMENT" << std::endl;
			continue;
		}

		int id;

		ModelResource* mr = new ModelResource();

		// Read Model Id
		xml_attribute<>* pAttr = pChild->first_attribute("id");
		if (pAttr != NULL) {
			id = atoi(pAttr->value());
		}
		else {
			std::cout << "ERROR::RESOURCE_MANAGER_MODEL:NO_VALID_ID" << std::endl;
			continue;
		}

		// Read Model Attributes
		for (xml_node<>* pGchild = pChild->first_node(); pGchild; pGchild = pGchild->next_sibling()) {

			// Name
			if (strcmp(pGchild->name(), "path") == 0) {
				mr->path = (char*)malloc(strlen(pGchild->value()) + 1);
				mr->path = strncpy(mr->path, pGchild->value(), strlen(pGchild->value()));
				mr->path[strlen(pGchild->value())] = '\0';
			}
		}

		rmInstance->modelResources.insert(std::pair<int, ModelResource*>(id, mr));
	}
}

void ResourceManager::parseTextures(xml_node<>* pNode) {

	for (xml_node<>* pChild = pNode->first_node(); pChild; pChild = pChild->next_sibling()) {

		if (strcmp(pChild->name(), "texture") != 0) {
			std::cout << "ERROR::RESOURCE_MANAGER_TEXTURE:UNEXPECTED_ELEMENT" << std::endl;
			continue;
		}

		int id;
		char* type = NULL;

		TextureResource* tr = new TextureResource();

		// Read Texture Id
		xml_attribute<>* pAttr = pChild->first_attribute("id");
		if (pAttr != NULL) {
			id = atoi(pAttr->value());
		}
		else {
			std::cout << "ERROR::RESOURCE_MANAGER_TEXTURE:NO_VALID_ID" << std::endl;
			continue;
		}
		
		// Read Texture Type
		pAttr = pChild->first_attribute("type");
		if (pAttr != NULL) {
			type = (char*)malloc(strlen(pAttr->value()) + 1);
			type = strncpy(type, pAttr->value(), strlen(pAttr->value()));
			type[strlen(pAttr->value())] = '\0';
		}

		// Read Texture Attributes
		for (xml_node<>* pGchild = pChild->first_node(); pGchild; pGchild = pGchild->next_sibling()) {

			// Name
			if (strcmp(pGchild->name(), "path") == 0) {
				tr->path = (char*)malloc(strlen(pGchild->value()) + 1);
				tr->path = strncpy(tr->path, pGchild->value(), strlen(pGchild->value()));
				tr->path[strlen(pGchild->value())] = '\0';
			}

			// Minifying Filter
			if (strcmp(pGchild->name(), "min_filter") == 0) {
				tr->min_filter = (char*)malloc(strlen(pGchild->value()) + 1);
				tr->min_filter = strncpy(tr->min_filter, pGchild->value(), strlen(pGchild->value()));
				tr->min_filter[strlen(pGchild->value())] = '\0';
			}

			// Magnifying Filter
			if (strcmp(pGchild->name(), "mag_filter") == 0) {
				tr->mag_filter = (char*)malloc(strlen(pGchild->value()) + 1);
				tr->mag_filter = strncpy(tr->mag_filter, pGchild->value(), strlen(pGchild->value()));
				tr->mag_filter[strlen(pGchild->value())] = '\0';
			}

			// Wrap S
			if (strcmp(pGchild->name(), "wrap_s") == 0) {
				tr->wrap_s = (char*)malloc(strlen(pGchild->value()) + 1);
				tr->wrap_s = strncpy(tr->wrap_s, pGchild->value(), strlen(pGchild->value()));
				tr->wrap_s[strlen(pGchild->value())] = '\0';
			}

			// Wrap T
			if (strcmp(pGchild->name(), "wrap_t") == 0) {
				tr->wrap_t = (char*)malloc(strlen(pGchild->value()) + 1);
				tr->wrap_t = strncpy(tr->wrap_t, pGchild->value(), strlen(pGchild->value()));
				tr->wrap_t[strlen(pGchild->value())] = '\0';
			}

			tr->type = type;

		}

		rmInstance->textureResources.insert(std::pair<int, TextureResource*>(id, tr));
	}
}

void ResourceManager::parseShaders(xml_node<>* pNode) {

	for (xml_node<>* pChild = pNode->first_node(); pChild; pChild = pChild->next_sibling()) {

		if (strcmp(pChild->name(), "shader") != 0) {
			std::cout << "ERROR::RESOURCE_MANAGER_SHADER:UNEXPECTED_ELEMENT" << std::endl;
			continue;
		}

		int id;
		ShaderResource* sr = new ShaderResource();

		// Read Shader Id
		xml_attribute<>* pAttr = pChild->first_attribute("id");
		if (pAttr != NULL) {
			id = atoi(pAttr->value());
		}
		else {
			std::cout << "ERROR::RESOURCE_MANAGER_SHADER:NO_VALID_ID" << std::endl;
			continue;
		}

		// Read Vertex and Fragment Shader names
		for (xml_node<>* pGchild = pChild->first_node(); pGchild; pGchild = pGchild->next_sibling()) {
			if (strcmp(pGchild->name(), "vs") == 0) {
				sr->vs = (char*)malloc(strlen(pGchild->value()) + 1);
				sr->vs = strncpy(sr->vs, pGchild->value(), strlen(pGchild->value()));
				sr->vs[strlen(pGchild->value())] = '\0';
			}
			if (strcmp(pGchild->name(), "fs") == 0) {
				sr->fs = (char*)malloc(strlen(pGchild->value()) + 1);
				sr->fs = strncpy(sr->fs, pGchild->value(), strlen(pGchild->value()));
				sr->fs[strlen(pGchild->value())] = '\0';
			}
		}

		rmInstance->shaderResources.insert(std::pair<int, ShaderResource*>(id, sr));
	}

}

void ResourceManager::FreeResources() {

}

Map* ResourceManager::LoadMap(int mapId) {
	return NULL;
}

Mesh* ResourceManager::LoadModel(int modelId) {

	std::map<int, ModelResource*>::iterator imr = modelResources.find(modelId);

	if (imr == modelResources.end()) {
		std::cout << "ERROR::RESOURCE_MANAGER::UNRECOGNIZED_MODEL_ID " << modelId << std::endl;
		return NULL;
	}

	std::map<int, Mesh*>::iterator im = models.find(modelId);

	if (im == models.end()) {

		// The model was not loaded yet
		if (modelId == 0) {
			Mesh* newMesh = new Mesh();
			newMesh->CreateSphereMesh(3, 4);
			models.insert(std::pair<int, Mesh*>(modelId, newMesh));
			return newMesh;
		}
		if (modelId == 1) {
			Mesh* newMesh = new Mesh();
			newMesh->CreateCubeMesh();
			models.insert(std::pair<int, Mesh*>(modelId, newMesh));
			return newMesh;
		}
		if (modelId == 2) {
			Mesh* newMesh = new Mesh();
			newMesh->CreateCylinderMesh(6);
			models.insert(std::pair<int, Mesh*>(modelId, newMesh));
			return newMesh;
		}
		if (modelId == 3) {
			Mesh* newMesh = new Mesh();
			newMesh->CreateBoxMesh();
			models.insert(std::pair<int, Mesh*>(modelId, newMesh));
			return newMesh;
		}

		// Load with assimp
		Mesh* newMesh = new Mesh(imr->second->path);
		models.insert(std::pair<int, Mesh*>(modelId, newMesh));
		return newMesh;
	}
	else {
		Mesh* model = im->second;
		return model;
	}

	return NULL;
}

Texture* ResourceManager::LoadTexture(int textureId) {

	std::map<int, TextureResource*>::iterator imr = textureResources.find(textureId);

	if (imr == textureResources.end()) {
		std::cout << "ERROR::RESOURCE_MANAGER::UNRECOGNIZED_TEXTURE_ID " << textureId << std::endl;
		return NULL;
	}

	std::map<int, Texture*>::iterator im = textures.find(textureId);

	if (im == textures.end()) {
		// The texture was not loaded yet.
		Texture* newTexture = new Texture();
		newTexture->LoadTexture(imr->second->path);
		
		return newTexture;
	}
	else {
		Texture* texture = im->second;
		return texture;
	}

	std::cout << "Return NULL :(" << std::endl;
	return NULL;
}

Shader* ResourceManager::LoadShader(int shaderId) {

	std::map<int, ShaderResource*>::iterator imr = shaderResources.find(shaderId);

	if (imr == shaderResources.end()) {
		std::cout << "ERROR::RESOURCE_MANAGER::UNRECOGNIZED_SHADER_ID " << shaderId << std::endl;
		return NULL;
	}

	std::map<int, Shader*>::iterator im = shaders.find(shaderId);

	if (im == shaders.end()) {
		// The shader was not loaded yet
		Shader* newShader = new Shader(imr->second->vs, imr->second->fs);
		shaders.insert(std::pair<int, Shader*>(shaderId, newShader));
		return newShader;
	}
	else {
		Shader* shader = im->second;
		return shader;
	}

	return NULL;
}

char* ResourceManager::LoadScript(int scriptId) {

	std::map<int, ScriptResource*>::iterator sr = scriptResources.find(scriptId);

	if (sr == scriptResources.end()) {
		std::cout << "ERROR::RESOURCE_MANAGER::UNRECOGNIZED_SCRIPT_ID " << scriptId << std::endl;
		return NULL;
	}

	std::map<int, char*>::iterator is = scripts.find(scriptId);

	if (is == scripts.end()) {
		// The script was not loaded yet

		
		std::string filename = std::string(Utils::GetScriptPath());
		filename += sr->second->path;

		//std::cout << "IT HAS COME TO THIS " << filename << std::endl;

		std::ifstream in(filename);
		std::string contents((std::istreambuf_iterator<char>(in)),
			std::istreambuf_iterator<char>());

		//std::cout << "LENGTH " << contents.c_str() << std::endl;

		char* script = (char*)malloc(contents.length() * sizeof(char));
		script = strncpy(script, contents.c_str(), contents.length());
		script[contents.length()] = '\0';

		scripts.insert(std::pair<int, char*>(scriptId, script));

		return script;
	}
	else {
		char* script = is->second;
		return script;
	}

	return NULL;
}


glm::ivec2 ResourceManager::GetResolution() {
	return settings.resolution;
}