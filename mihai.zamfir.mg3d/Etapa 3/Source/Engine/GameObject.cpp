#include "GameObject.h"

GameObject::GameObject() {
	transform = new Transform();

	//scaleAndOffset = UI::GetScaleAndOffset(49);

}

GameObject::GameObject(char *name) {
	this->name = name;

	//mesh = new Mesh();
	//transform = new Transform();

	//scaleAndOffset = UI::GetScaleAndOffset(49);

	/*
	hasNormals = true;
	hasTangents = true;
	hasColors = true;
	hasUvs = true;
	hasUvs2 = true;
	*/

	//std::cout << "Vertex size " << GetVertexSize() << std::endl;

	//AddVertex((float*)malloc(3 * sizeof(float)));
}

GameObject::~GameObject() {

}

void GameObject::Init(Transform* transform, Mesh* mesh, Shader* shader) {
	this->transform = transform;
	this->mesh = mesh;
	this->shader = shader;
}

bool GameObject::IsColliding(GameObject* other) {

	// I am cube
	if (mesh->noVertices == 24) {

		// Cube
		if (other->mesh->noVertices == 24) {
			return checkCubeCubeCollision(this, other);
		}

		// Sphere
		if (other->mesh->noVertices == 530) {
			return checkCubeSphereCollision(this, other);
		}

		// Cylinder
		if (other->mesh->noVertices == 130) {
			return checkCubeCylinderCollision(this, other);
		}
	}

	// I am sphere
	if (mesh->noVertices == 530) {

		// Cube
		if (other->mesh->noVertices == 24) {
			return checkCubeSphereCollision(other, this);
		}

		// Sphere
		if (other->mesh->noVertices == 530) {
			return checkSphereSphereCollision(this, other);
		}

		// Cylinder
		if (other->mesh->noVertices == 130) {
			return checkSphereCylinderCollision(this, other);
		}
	}

	// I am cylinder
	if (mesh->noVertices == 130) {

		// Cube
		if (other->mesh->noVertices == 24) {
			return checkCubeCylinderCollision(other, this);
		}

		// Sphere
		if (other->mesh->noVertices == 530) {
			return checkSphereCylinderCollision(other, this);
		}

		// Cylinder
		if (other->mesh->noVertices == 130) {
			return checkCylinderCylinderCollision(this, other);
		}
	}

	return false;
}


void GameObject::Update(double deltaTime) {
}

void GameObject::Draw() {

	glm::mat4 model = transform->GetModelMatrix();
	shader->use();
	shader->setMat4("model", model);

	shader->setBool("isColliding", isColliding);

	mesh->Draw();
}


// 24 530 130
bool GameObject::checkCubeCubeCollision(GameObject* cube, GameObject* otherCube) {

	//std::cout << "checkCubeCubeCollision " << cube->mesh->noVertices << " " << otherCube->mesh->noVertices << std::endl;	

	glm::vec3 position = cube->transform->GetPosition();
	glm::vec3 scale = cube->transform->GetScale();

	glm::vec3 otherPosition = otherCube->transform->GetPosition();
	glm::vec3 otherScale = otherCube->transform->GetScale();

	if (abs(position.x - otherPosition.x) > ((scale.x + otherScale.x) / 2)) {
		return false;
	}

	if (abs(position.y - otherPosition.y) > ((scale.y + otherScale.y) / 2)) {
		return false;
	}

	if (abs(position.z - otherPosition.z) > ((scale.z + otherScale.z) / 2)) {
		return false;
	}

	return true;
}

bool GameObject::checkCubeSphereCollision(GameObject* cube, GameObject* sphere) {
	
	//std::cout << "checkCubeSphereCollision " << cube->mesh->noVertices << " " << sphere->mesh->noVertices << std::endl;

	glm::vec3 sphereCenter = sphere->transform->GetPosition();

	glm::vec3 cubePosition = cube->transform->GetPosition();
	glm::vec3 cubeScale = cube->transform->GetScale();

	float sqrDist = sqrDistPointToAABB(sphereCenter, cubePosition, cubeScale);

	return sqrDist <= 0.25f;
}

float GameObject::sqrDistPointToAABB(glm::vec3 point, glm::vec3 position, glm::vec3 scale) {

	float sqrDist = 0;

	// X Axis
	float p = point.x;
	float posMin = position.x - scale.x / 2;
	float posMax = position.x + scale.x / 2;

	if (point.x < posMin) {
		sqrDist += (posMin - point.x) * (posMin - point.x);
	}
	else if (point.x > posMax) {
		sqrDist += (point.x - posMax) * (point.x - posMax);
	}

	// Y Axis
	p = point.y;
	posMin = position.y - scale.y / 2;
	posMax = position.y + scale.y / 2;

	if (point.y < posMin) {
		sqrDist += (posMin - point.y) * (posMin - point.y);
	}
	else if (point.y > posMax) {
		sqrDist += (point.y - posMax) * (point.y - posMax);
	}

	// Z Axis
	p = point.z;
	posMin = position.z - scale.z / 2;
	posMax = position.z + scale.z / 2;

	if (point.z < posMin) {
		sqrDist += (posMin - point.z) * (posMin - point.z);
	}
	else if (point.z > posMax) {
		sqrDist += (point.z - posMax) * (point.z - posMax);
	}

	return sqrDist;
}


bool GameObject::checkCubeCylinderCollision(GameObject* cube, GameObject* cylinder) {
	
	//std::cout << "checkCubeCylinderCollision " << cube->mesh->noVertices << " " << cylinder->mesh->noVertices << std::endl;

	return false;
}

bool GameObject::checkSphereSphereCollision(GameObject* sphere, GameObject* otherSphere) {
	
	//std::cout << "checkSphereSphereCollision " << sphere->mesh->noVertices << " " << otherSphere->mesh->noVertices << std::endl;

	glm::vec3 position = sphere->transform->GetPosition();
	glm::vec3 otherPosition = otherSphere->transform->GetPosition();

	glm::vec3 distanceVector = position - otherPosition;

	float distance = distanceVector.x * distanceVector.x + distanceVector.y * distanceVector.y + distanceVector.z * distanceVector.z;

	return distance < 1;
}

bool GameObject::checkSphereCylinderCollision(GameObject* sphere, GameObject* cylinder) {
	
	//std::cout << "checkSphereCylinderCollision " << sphere->mesh->noVertices << " " << cylinder->mesh->noVertices << std::endl;

	return false;
}

bool GameObject::checkCylinderCylinderCollision(GameObject* cylinder, GameObject* otherCylinder) {
	
	//std::cout << "checkCylinderCylinderCollision " << cylinder->mesh->noVertices << " " << otherCylinder->mesh->noVertices << std::endl;

	return false;
}

void GameObject::Save(int indentLevel) {

	/*
			<gameObject id="3">
			<parent>-1</parent>
			<name>Mihai3</name>
			<transform>
				<position>
					<x>-2.0</x>
					<y>0.0</y>
					<z>0.0</z>
				</position>
				<rotation>
					<x>0.0</x>
					<y>0.0</y>
					<z>0.0</z>
				</rotation>
				<scale>
					<x>1.0</x>
					<y>1.0</y>
					<z>1.0</z>
				</scale>
			</transform>
			<model>2</model>
			<shader>0</shader>
		</gameObject>
	*/

	//		char *name;

	// Game Object Id
	Utils::PrintIndent(indentLevel);
	std::cout << "<gameObject id=\"" << Id << "\">" << std::endl;

	// Close XML Element
	Utils::PrintIndent(indentLevel);
	std::cout << "</gameObject>" << std::endl;

	// Parent Id
	Utils::PrintIndent(indentLevel + 1);
	std::cout << "<parent>" << ParentId << "</parent>" << std::endl;

	// Name
	Utils::PrintIndent(indentLevel + 1);
	std::cout << "<name>" << name << "</name>" << std::endl;

	// Transform
	transform->Save(indentLevel + 1);


	return;
	std::cout << "		<gameObject id=\"" << Id << "\">" << std::endl;
	std::cout << "		</gameObject>" << std::endl;
	std::cout << "				<parent>" << ParentId << "</parent>" << std::endl;
	std::cout << "				<name>" << name << "</name>" << std::endl;
	
	// Save Transform
	transform->Save(0);

	/*
	std::cout << "				<model>" << name << "</model>" << std::endl;
	std::cout << "				<shader>" << name << "</shader>" << std::endl;
	*/

}