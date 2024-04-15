#pragma once
#include <Core/types.h>
#include <vector>

namespace RE
{
	struct VertexLayoutElement
	{
		ushort dataSize, glDataType, bufferSize, normalized;
	};

	struct VertexLayout
	{
		std::vector<VertexLayoutElement> elements;
		int strideSize = 0;

		void AddElement(VertexLayoutElement element);
	};

	struct VertexArray
	{
		friend class Sprite;
	private:
		unsigned int VA_ID, VB_ID, IB_ID;
	public:
		VertexArray(
			float* vertices, ushort vsize, 
			uint* indices, ushort isize,
			VertexLayout &layout);
		~VertexArray();
		void Bind();
		void Unbind();
	};
}