#include "text.h"

int PrintText::init()
{
	

	if (FT_Init_FreeType(&ft)) {
		fprintf(stderr, "Could not init freetype library\n");
		return 1;
	}

	

	if (FT_New_Face(ft, "../../ARLRDBD.TTF", 0, &face)) {
		fprintf(stderr, "Could not open font\n");
		return 1;
	}

	FT_Set_Pixel_Sizes(face, 0, 48);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


}