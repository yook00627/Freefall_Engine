#pragma once
#include <iostream>
#include <glew/glew.h>

#include <ft2build.h>
#include FT_FREETYPE_H 


class PrintText
{
private:
	FT_Library ft;
	FT_Face face;
	FT_GlyphSlot g = face->glyph;
public:
	PrintText();
	~PrintText();
private:
	int init();
};