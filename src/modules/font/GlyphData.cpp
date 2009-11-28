/**
* Copyright (c) 2006-2009 LOVE Development Team
* 
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* 
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 
* 1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software. If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
**/

#include "GlyphData.h"

namespace love
{
namespace font
{

	GlyphData::GlyphData(unsigned short glyph, GlyphMetrics glyphMetrics)
		: glyph(glyph), metrics(glyphMetrics)
	{
		data = new unsigned char[getWidth() * getHeight() * 2];
	}

	GlyphData::~GlyphData()
	{
		delete[] data;
	}

	void * GlyphData::getData() const
	{
		return (void *) data;
	}

	int GlyphData::getSize() const
	{
		return getWidth() * getHeight() * 2;
	}

	int GlyphData::getHeight() const
	{
		return metrics.height;
	}

	int GlyphData::getWidth() const
	{
		return metrics.width;
	}
	
	int GlyphData::getAdvance() const
	{
		return metrics.advance;
	}

	int GlyphData::getBearingX() const
	{
		return metrics.bearingX;
	}

	int GlyphData::getBearingY() const
	{
		return metrics.bearingY;
	}

	int GlyphData::getMinX() const
	{
		return this->getBearingX();
	}

	int GlyphData::getMinY() const
	{
		return this->getHeight() - this->getBearingY();
	}

	int GlyphData::getMaxX() const
	{
		return this->getBearingX() + this->getWidth();
	}

	int GlyphData::getMaxY() const
	{
		return this->getBearingY();
	}

} // font
} // love
