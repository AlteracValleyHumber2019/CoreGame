#ifndef Projectile_H
#define Projectile_H

#include "../i_game_object.h"

namespace pav{
class Projectile
{
private:

	glm::vec3 position;
public:
	Projectile();


	void ApplyForce(const glm::vec3 Force_);
	void setPosition(const glm::vec3 position_);
	const glm::vec3 getPosition();


};

}
#endif