#pragma once
#include <string>

namespace RE
{
	struct ShaderProgram
	{
	public:
		unsigned int ID, VertexID, FragmentID;
	private:
		int GetLocation(const char* propertyName);
	public:
		ShaderProgram(std::string vertexFn = "Resources/Shaders/default_vertex.glsl", 
					  std::string fragmentFn = "Resources/Shaders/default_fragment.glsl");
		void Destroy();
		void Bind();
		void Unbind();
	public:
		void SetUniform4f(const char* propertyName, float a, float b, float c, float d);
		void SetUniform3f(const char* propertyName, float a, float b, float c);
		void SetUniform2f(const char* propertyName, float a, float b);
		void SetUniform1f(const char* propertyName, float a);
		void SetUniform4i(const char* propertyName, int a, int b, int c, int d);
		void SetUniform3i(const char* propertyName, int a, int b, int c);
		void SetUniform2i(const char* propertyName, int a, int b);
		void SetUniform1i(const char* propertyName, int a);
		void SetUniform4fMatrix(const char* propertyName, float* matrix);
	};
};