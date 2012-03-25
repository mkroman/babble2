#include "VisualObject.hpp"

VisualObject::VisualObject(const std::string& image_path)
	: m_imageAsset(NULL)
{
	m_position.x = 0;
	m_position.y = 0;

	loadImageAsset(image_path);
}

VisualObject::~VisualObject()
{
	SDL_FreeSurface(m_imageAsset);
}

void VisualObject::loadImageAsset(const std::string& image)
{
	if (m_imageAsset != NULL) {
		SDL_FreeSurface(m_imageAsset);

		m_imageAsset = NULL;
	}

	m_imageAsset = IMG_Load(image.c_str());

	if (m_imageAsset != NULL) {
		_debug("Loaded image asset %s", image.c_str());
	}
	else {
		_debug("Failed to load image asset: %s", IMG_GetError());
	}
}

void VisualObject::paint(SDL_Surface* const surface)
{
	// Position the image.
	SDL_Rect image_position = { m_position.x, m_position.y, 0, 0 };

	// Draw the image asset.
	SDL_BlitSurface(m_imageAsset, NULL, surface, &image_position);
}
