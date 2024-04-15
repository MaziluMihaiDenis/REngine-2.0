#include "ShaderProgram.h"
#include <External/Glad/glad.h>
#include <Core/Filesystem.h>

RE::ShaderProgram::ShaderProgram(std::string vertexFn, std::string fragmentFn)
{
    int success = 0;
    
    std::string vertexSrc = RE::Filesystem::GetFileContents(vertexFn);
    std::string fragmnetSrc = RE::Filesystem::GetFileContents(fragmentFn);
    const char* vertexCStr = vertexSrc.c_str();
    const char* fragmentCStr = fragmnetSrc.c_str();

    ID = glCreateProgram();
    VertexID = glCreateShader(GL_VERTEX_SHADER);
    FragmentID = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(VertexID, 1, &vertexCStr, 0);
    glCompileShader(VertexID);
    glGetShaderiv(VertexID, GL_COMPILE_STATUS, &success);
    if (!success) printf("Small error in shaders!");

    glShaderSource(FragmentID, 1, &fragmentCStr, 0);
    glCompileShader(FragmentID);
    glGetShaderiv(FragmentID, GL_COMPILE_STATUS, &success);
    if (!success) printf("Small error in shaders!");

    glAttachShader(ID, VertexID);
    glAttachShader(ID, FragmentID);

    glLinkProgram(ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success) printf("Small error in shaders!");

    glDeleteShader(VertexID);
    glDeleteShader(FragmentID);
}

void RE::ShaderProgram::Destroy()
{
    glDeleteProgram(ID);
    delete this;
}

void RE::ShaderProgram::Bind()
{
    glUseProgram(ID);
}

void RE::ShaderProgram::Unbind()
{
    glUseProgram(0);
}

int RE::ShaderProgram::GetLocation(const char* uniformName)
{
    return glGetUniformLocation(ID, uniformName);
}

void RE::ShaderProgram::SetUniform4f(const char* uniformName, float a, float b, float c, float d)
{
    glUniform4f(GetLocation(uniformName), a, b, c, d);
}

void RE::ShaderProgram::SetUniform3f(const char* uniformName, float a, float b, float c)
{
    glUniform3f(GetLocation(uniformName), a, b, c);
}

void RE::ShaderProgram::SetUniform2f(const char* uniformName, float a, float b)
{
    glUniform2f(GetLocation(uniformName), a, b);
}

void RE::ShaderProgram::SetUniform1f(const char* uniformName, float a)
{
    glUniform1f(GetLocation(uniformName), a);
}

void RE::ShaderProgram::SetUniform4i(const char* uniformName, int a, int b, int c, int d)
{
    glUniform4i(GetLocation(uniformName), a, b, c, d);
}

void RE::ShaderProgram::SetUniform3i(const char* uniformName, int a, int b, int c)
{
    glUniform3i(GetLocation(uniformName), a, b, c);
}

void RE::ShaderProgram::SetUniform2i(const char* uniformName, int a, int b)
{
    glUniform2i(GetLocation(uniformName), a, b);
}

void RE::ShaderProgram::SetUniform1i(const char* uniformName, int a)
{
    glUniform1i(GetLocation(uniformName), a);
}

void RE::ShaderProgram::SetUniform4fMatrix(const char* propertyName, float* matrix)
{
    glUniformMatrix4fv(GetLocation(propertyName), 1, GL_FALSE, matrix);
}
