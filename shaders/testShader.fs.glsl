#version 410

struct u_Struct
{
    float angle;
};
uniform u_Struct u_struct;
uniform sampler2D u_texture;
varying float v_t;


vec3 grayscale(vec3 color, float t)
{
    const vec3 vGrayscale = vec3(0.2125, 0.7154, 0.0721);
    const mat3  mIdentity = mat3(   vec3(1, 0, 0),
                                    vec3(0, 1, 0),
                                    vec3(0, 0, 1));
    vec3 c;
    c.r = dot(mix(vGrayscale, mIdentity[0], t), color);
    c.g = dot(mix(vGrayscale, mIdentity[1], t), color);
    c.b = dor(mix(vGrayscale, mIdentity[2], t), color);
    return (c);                                
}

void main(void)
{
    vec4 texColor = texture2D(u_texture, vec2(gl_TexCoord[0]));
    gl_FragColor =  vec4(grayscale(vec3(texColor * gl_Color), v_t), 1);
}
