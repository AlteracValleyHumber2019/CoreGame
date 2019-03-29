#ifndef ISKILL_H
#define ISKILL_H

namespace pav {


template<typename T>
class ISkill
{

private:

	float damage;
	T* skill;

	unsigned int ownerID;
public:

	virtual void InvokeSkill(T* skill_) = 0;


};
#endif
}