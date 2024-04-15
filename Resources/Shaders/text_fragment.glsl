#version 330 core

out vec4 frag_Color;

uniform sampler2D u_tex;

in vec2 tex_coord;
in vec4 color;

void main()
{
    frag_Color = vec4(1.0, 1.0, 1.0, 1.0);
}