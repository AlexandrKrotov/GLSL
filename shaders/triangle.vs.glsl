#version 400

in vec3 vp;

uniform struct s_nav
{
    float zoom;
}nav;

uniform vec2 tv;

void main(void) 
{
    mat3 scale = mat3(nav.zoom, 0.0, 0.0,
                      0.0, nav.zoom, 0.0,
                      0.0, 0.0, nav.zoom)
    vec3 trans = vec3(tv, 0.0);

    gl_Position = vec4(scale * vp + trans, 1.0);
}