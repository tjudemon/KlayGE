// glloader
// Copyright (C) 2004-2005 Minmin Gong
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

#include <glloader/glloader.h>
#include <glloader/gl21.h>
#include <glloader/gl20.h>
#include "utils.hpp"

#ifdef GLLOADER_GL

using glloader::load_funcs;
using glloader::gl_features_extractor;

namespace
{
	bool _GL_VERSION_2_1 = false;

	char APIENTRY _glloader_GL_VERSION_2_1()
	{
		return _GL_VERSION_2_1;
	}

	void init_GL_VERSION_2_1()
	{
		glloader_GL_VERSION_2_1 = _glloader_GL_VERSION_2_1;

		{
			glUniformMatrix2x3fv = NULL;
			glUniformMatrix3x2fv = NULL;
			glUniformMatrix2x4fv = NULL;
			glUniformMatrix4x2fv = NULL;
			glUniformMatrix3x4fv = NULL;
			glUniformMatrix4x3fv = NULL;
		}

		if (glloader_is_supported("GL_VERSION_2_1"))
		{
			_GL_VERSION_2_1 = true;

			entries_t entries(6);
			{
				entries[0] = reinterpret_cast<void**>(&glUniformMatrix2x3fv);
				entries[1] = reinterpret_cast<void**>(&glUniformMatrix3x2fv);
				entries[2] = reinterpret_cast<void**>(&glUniformMatrix2x4fv);
				entries[3] = reinterpret_cast<void**>(&glUniformMatrix4x2fv);
				entries[4] = reinterpret_cast<void**>(&glUniformMatrix3x4fv);
				entries[5] = reinterpret_cast<void**>(&glUniformMatrix4x3fv);
			}

			funcs_names_t names(6);
			{
				names[0] = "glUniformMatrix2x3fv";
				names[1] = "glUniformMatrix3x2fv";
				names[2] = "glUniformMatrix2x4fv";
				names[3] = "glUniformMatrix4x2fv";
				names[4] = "glUniformMatrix3x4fv";
				names[5] = "glUniformMatrix4x3fv";
			}

			load_funcs(entries, names);
		}
	}

	char APIENTRY self_init_glloader_GL_VERSION_2_1()
	{
		glloader_GL_VERSION_2_0();

		init_GL_VERSION_2_1();
		return glloader_GL_VERSION_2_1();
	}
}

glloader_GL_VERSION_2_1FUNC glloader_GL_VERSION_2_1 = self_init_glloader_GL_VERSION_2_1;

#ifdef GL_VERSION_2_1

namespace
{
	void APIENTRY self_init_glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
	{
		init_GL_VERSION_2_1();
		return glUniformMatrix2x3fv(location, count, transpose, value);
	}
	void APIENTRY self_init_glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
	{
		init_GL_VERSION_2_1();
		return glUniformMatrix3x2fv(location, count, transpose, value);
	}
	void APIENTRY self_init_glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
	{
		init_GL_VERSION_2_1();
		return glUniformMatrix2x4fv(location, count, transpose, value);
	}
	void APIENTRY self_init_glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
	{
		init_GL_VERSION_2_1();
		return glUniformMatrix4x2fv(location, count, transpose, value);
	}
	void APIENTRY self_init_glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
	{
		init_GL_VERSION_2_1();
		return glUniformMatrix3x4fv(location, count, transpose, value);
	}
	void APIENTRY self_init_glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
	{
		init_GL_VERSION_2_1();
		return glUniformMatrix4x3fv(location, count, transpose, value);
	}
}

glUniformMatrix2x3fvFUNC glUniformMatrix2x3fv = self_init_glUniformMatrix2x3fv;
glUniformMatrix3x2fvFUNC glUniformMatrix3x2fv = self_init_glUniformMatrix3x2fv;
glUniformMatrix2x4fvFUNC glUniformMatrix2x4fv = self_init_glUniformMatrix2x4fv;
glUniformMatrix4x2fvFUNC glUniformMatrix4x2fv = self_init_glUniformMatrix4x2fv;
glUniformMatrix3x4fvFUNC glUniformMatrix3x4fv = self_init_glUniformMatrix3x4fv;
glUniformMatrix4x3fvFUNC glUniformMatrix4x3fv = self_init_glUniformMatrix4x3fv;

#endif		// GL_VERSION_2_1

#endif			// GLLOADER_GL
