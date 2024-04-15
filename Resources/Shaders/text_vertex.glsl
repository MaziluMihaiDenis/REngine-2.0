#version 330 core

layout (location = 0) in vec2 v_pos;
layout (location = 1) in vec2 v_tex_coord;

out vec2 tex_coord;
out vec4 color;

uniform mat4 matrix;
uniform mat4 projection;
uniform vec4 u_color;

void main()
{
    //projection * matrix *
    gl_Position = vec4(v_pos, 0.0, 1.0);
    tex_coord = v_tex_coord;
    color = u_color;
}