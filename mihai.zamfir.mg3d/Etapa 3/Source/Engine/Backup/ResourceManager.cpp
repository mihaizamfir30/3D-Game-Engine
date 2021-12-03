#include "ResourceManager.h"

ResourceManager* ResourceManager::rmInstance = NULL;

ResourceManager::ResourceManager() {
}

ResourceManager::~ResourceManager() {

}

ResourceManager* ResourceManager::GetInstance() {
	if (rmInstance == NULL) {
		rmInstance = new ResourceManager();
	}

	return rmInstance;
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

		if (strcmp(pNode->name(), "models") == 0) {
			parseModels(pNode);
		}

		if (strcmp(pNode->name(), "textures") == 0) {
			parseTextures(pNode);
		}

		if (strcmp(pNode->name(), "shaders") == 0) {
			parseShaders(pNode);
		}

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

		//std::cout << id << " " << mr->path << std::endl;
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

		//std::cout << id << " " << tr->path <<" " << tr->type << " " << tr->mag_filter << " " << tr->min_filter << " " << tr->wrap_s << " " << tr->wrap_t << std::endl;

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

		//std::cout << id << " " << sr->vs << " " << sr->fs << std::endl;

		rmInstance->shaderResources.insert(std::pair<int, ShaderResource*>(id, sr));
	}

}

void ResourceManager::FreeResources() {

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
			newMesh->CreateCubeMesh();
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
			newMesh->CreateSphereMesh(3, 4);
			models.insert(std::pair<int, Mesh*>(modelId, newMesh));
			return newMesh;
		}
		if (modelId == 3) {
			Mesh* newMesh = new Mesh();
			newMesh->CreateCylinderMesh(6);
			models.insert(std::pair<int, Mesh*>(modelId, newMesh));
			return newMesh;
		}

		// Load with assimp

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
