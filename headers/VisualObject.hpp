#ifndef __VISUAL_OBJECT_HPP
#define __VISUAL_OBJECT_HPP
#include <string>
#include <SDL/SDL_image.h>
#include "Babble.hpp"
#include "BaseObject.hpp"

class VisualObject : public BaseObject
{
public:
	VisualObject(const std::string& image_path);
	~VisualObject();

	void paint(SDL_Surface* const surface);

protected:
	void loadImageAsset(const std::string& image);

	SDL_Surface* m_imageAsset;
};

#endif
