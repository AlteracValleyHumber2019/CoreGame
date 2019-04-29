#ifndef RIGIDBODYCOMPONENT_H
#define RIGIDBODYCOMPONENT_H

#include "../i_component.h"
#include "../i_game_object.h"

namespace pav {

	class RigidBodyComponent : public IComponent<RigidBodyComponent, 2>
	{
	private:

		float GravityScale_;
		float Mass_;
		glm::vec3 Velocity_;
		glm::vec3 Acceleration_;
		glm::vec3 Position_;
	public:

		/**
	* author	Ethan
	* date	3/03/2019
	* calculates new position based on the set variables and previously appliedforce
	*/
		void Update(float DeltaTime);
		/**
	* author	Ethan
	* date	3/03/2019
	* takes in force, calculates acceleration via force/mass
	*/
		void ApplyForce(glm::vec3& force);
		/**
	* author	Ethan
	* date	3/03/2019
	* takes in float, sets mass, required for force to accleration calculation F=M*A
	*/
		void SetMass(float mass);
		/**
	* author	Ethan
	* date	3/03/2019
	* takes in Vec3, sets position, required to alter current pos
	*
	*original vec3 should be current position, gotten from transform class, pass it in. then get position to get the new position
	*/
		void SetPos(glm::vec3 Position);
		/**
	* author	Ethan
	* date	3/03/2019
	* takes in float, sets gravityscale
	*/
		void SetGravity(float gravity);
		/**
	* author	Ethan
	* date	3/03/2019
	* outputs Vec3, gets position
	*
	*final vec3 will become current position, apply to transform class, example transform.setPosition(rigidbody.getPos())
	*probably could remove a stepin getting and setting between the two different positions
	*/
		glm::vec3 GetPos();
	}
};
#endif

