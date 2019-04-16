#ifndef CREATETEXTURE_H
#define CREATETEXTURE_H

#include "pav_pch.h"

namespace pav {
	class createTexture
	{
	private:



	public:
		createTexture();
		createTexture(unsigned int texture_id);

		~createTexture();

		unsigned int id;
		std::string type;
		std::string path;


		void UseTexture()
		{


		}

	};
}


#endif