#version 410

struct u_Struct
{
    float angle;
};

uniform u_Struct u_struct;

varying float v_t;

attribute float a_phase;

void main(void)
{
    float c = sin(a_phase + u_struct.angle);

    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex + c;


    v_t = abs(sin(u_struct.angle));
    

    gl_FrontColor = gl_Color;
    gl_TexCoord[0] = gl_MultiTexCoord0;
}