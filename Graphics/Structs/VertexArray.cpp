#include "VertexArray.h"
#include <External/Glad/glad.h>
#include <iostream>

RE::VertexArray::VertexArray(
    float* vertices, ushort vsize,
    uint* indices, ushort isize,
    VertexLayout &layout)
{
    glGenVertexArrays(1, &VA_ID);
    glGenBuffers(1, &VB_ID);
    glGenBuffers(1, &IB_ID);

    glBindVertexArray(VA_ID);

    glBindBuffer(GL_ARRAY_BUFFER, VB_ID);
    glBufferData(GL_ARRAY_BUFFER, vsize, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB_ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, isize, indices, GL_STATIC_DRAW);

    int offset = 0;
    for (int i = 0; i < layout.elements.size(); i++)
    {
        VertexLayoutElement &e = layout.elements[i];
        glVertexAttribPointer(
            i, 
            e.bufferSize,
            e.glDataType,
            e.normalized,
            layout.strideSize * e.dataSize,
            (void*)(offset)
        );
        glEnableVertexAttribArray(i);
        offset += e.bufferSize * e.dataSize;
    }

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

RE::VertexArray::~VertexArray()
{
	Unbind();
	glDeleteBuffers(1, &VB_ID);
	glDeleteBuffers(1, &IB_ID);
	glDeleteVertexArrays(1, &VA_ID);
}

void RE::VertexArray::Bind()
{
	glBindVertexArray(VA_ID);
}

void RE::VertexArray::Unbind()
{
	glBindVertexArray(0);
}

void RE::VertexLayout::AddElement(VertexLayoutElement element)
{
    elements.push_back(element);
    strideSize += element.bufferSize;
}
