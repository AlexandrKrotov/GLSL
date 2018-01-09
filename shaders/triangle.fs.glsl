#version 400

out vec4 frag_color;

void main()
{
    frag_color = vec4(gl_Color * gl_TexCoord[0]);
}