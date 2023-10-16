#include "shaders/vinylqualityshader.h"

using namespace mixxx;

void VinylQualityShader::init() {
    QString vertexShaderCode = QStringLiteral(R"--(
uniform mat4 matrix;
attribute highp vec4 position; // use vec4 here (will be padded) for matrix multiplication
attribute highp vec2 texcoord;
varying highp vec2 vTexcoord;
void main()
{
    vTexcoord = texcoord;
    gl_Position = matrix * position;
}
)--");

    QString fragmentShaderCode = QStringLiteral(R"--(
uniform sampler2D texture;
uniform highp vec3 color;
varying highp vec2 vTexcoord;
void main()
{
    gl_FragColor = vec4(color, texture2D(texture, vTexcoord) * 0.75);
}
)--");

    load(vertexShaderCode, fragmentShaderCode);

    m_matrixLocation = uniformLocation("matrix");
    m_positionLocation = attributeLocation("position");
    m_texcoordLocation = attributeLocation("texcoord");
    m_textureLocation = uniformLocation("texture");
    m_colorLocation = uniformLocation("color");
}
