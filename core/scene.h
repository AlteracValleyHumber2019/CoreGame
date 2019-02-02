#ifndef SCENE_H
#define SCENE_H

namespace pav
{

	/**
	 * \class	Scene
	 *
	 * \brief	Scene class used to hold all GameObject objects and special partition them with scene
	 * 			graph
	 *
	 * \author	Jaymie
	 * \date	2/2/2019
	 */
	class Scene
	{
	public:
		void BeginScene();
		void EndScene();
		void Update(const float delta_time);
	};
}

#endif // SCENE_H
