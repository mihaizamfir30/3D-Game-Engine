#pragma once

#include <glm/glm.hpp>
#include <include/gl.h>

#include <iostream>

enum MeshType {
	CUBE, SPHERE, CYLINDER
};

class MeshCollider
{
	
	public:

		MeshCollider();
		~MeshCollider();

		bool IsColliding(MeshCollider* other);

	private:

		/*
		static bool cubeCubeIntersection(MeshCollider* cube, MeshCollider *otherCube);
		static bool cubeSphereIntersection(MeshCollider* cube, MeshCollider* sphere);

		static bool sphereSphereIntersection(MeshCollider sphere, MeshCollider* otherSphere);
		static bool sphereCylinderIntersection(MeshCollider* sphere, MeshCollider* cylinder);

		static bool cylinderCylinderIntersection(MeshCollider* cylinder, MeshCollider* otherCylinder);
		*/
};
