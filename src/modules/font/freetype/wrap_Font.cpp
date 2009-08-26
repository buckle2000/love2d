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

#include "wrap_Font.h"

#include <font/wrap_GlyphData.h>
#include <font/wrap_Rasterizer.h>

#include "TrueTypeRasterizer.h"

namespace love
{
namespace font
{
namespace freetype
{
	static Font * instance = 0;

	int w_newRasterizer(lua_State * L)
	{
		Data * d = luax_checkdata(L, 1);
		int size = luaL_checkint(L, 2);
		
		Rasterizer * t = instance->newRasterizer(d, size);
		luax_newtype(L, "Rasterizer", FONT_RASTERIZER_T, t);
		return 1;
	}

	int w_newGlyphData(lua_State * L)
	{
		Rasterizer * r = luax_checkrasterizer(L, 1);
		unsigned short g = (unsigned short)luaL_checkint(L, 2);
		
		GlyphData * t = instance->newGlyphData(r, g);
		luax_newtype(L, "GlyphData", FONT_GLYPH_DATA_T, t);
		return 1;
	}

	// List of functions to wrap.
	static const luaL_Reg functions[] = {
		{ "newRasterizer",  w_newRasterizer },
		{ "newGlyphData",  w_newGlyphData },
		{ 0, 0 }
	};

	static const lua_CFunction types[] = {
		luaopen_glyphdata,
		luaopen_rasterizer,
		0
	};

	int luaopen_love_font(lua_State * L)
	{
		if(instance == 0)
		{
			try
			{
				instance = new Font();
			}
			catch(Exception & e)
			{
				return luaL_error(L, e.what());
			}
		}

		luax_register_gc(L, instance);

		return luax_register_module(L, functions, types, 0, "font");
	}

} // freetype
} // font
} // love
