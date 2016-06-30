--[[

Copyright (c) 2011-2014 chukong-inc.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

]]

--[[--

OpenGL 相关定义

]]

gl = gl or {}
gl.GL_ZERO                = GL_ZERO
gl.GL_ONE                 = GL_ONE
gl.GL_SRC_COLOR           = GL_SRC_COLOR
gl.GL_ONE_MINUS_SRC_COLOR = GL_ONE_MINUS_SRC_COLOR
gl.GL_SRC_ALPHA           = GL_SRC_ALPHA
gl.GL_ONE_MINUS_SRC_ALPHA = GL_ONE_MINUS_SRC_ALPHA
gl.GL_DST_ALPHA           = GL_DST_ALPHA
gl.GL_ONE_MINUS_DST_ALPHA = GL_ONE_MINUS_DST_ALPHA
gl.GL_DST_COLOR           = GL_DST_COLOR
gl.GL_ONE_MINUS_DST_COLOR = GL_ONE_MINUS_DST_COLOR

gl.GL_POINTS = 0x0000
gl.GL_LINES = 0x0001
gl.GL_LINE_LOOP = 0x0002
gl.GL_POINT_BIT = 0x00000002
gl.GL_CLIENT_VERTEX_ARRAY_BIT = 0x00000002
gl.GL_LINE_STRIP = 0x0003
gl.GL_LINE_BIT = 0x00000004
gl.GL_TRIANGLES = 0x0004
gl.GL_TRIANGLE_STRIP = 0x0005
gl.GL_TRIANGLE_FAN = 0x0006
gl.GL_QUADS = 0x0007
gl.GL_QUAD_STRIP = 0x0008
gl.GL_POLYGON_BIT = 0x00000008
gl.GL_POLYGON = 0x0009

gl.GL_NONE = 0
gl.GL_NEAREST = 0x2600
gl.GL_LINEAR = 0x2601
gl.GL_NEAREST_MIPMAP_NEAREST = 0x2700
gl.GL_LINEAR_MIPMAP_NEAREST = 0x2701
gl.GL_NEAREST_MIPMAP_LINEAR = 0x2702
gl.GL_LINEAR_MIPMAP_LINEAR = 0x2703
gl.GL_CLAMP = 0x2900
gl.GL_REPEAT = 0x2901
