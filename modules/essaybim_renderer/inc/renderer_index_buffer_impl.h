#pragma once

namespace EB
{
    class IndexBufferImpl
    {
    public:
        IndexBufferImpl(unsigned int* pIndices, unsigned int count);
        ~IndexBufferImpl();

    public:
        void bind();
        void unbind();
        unsigned int count() const;

    private:
        unsigned int m_RendererId = -1;     /** < identifier allocated by OpenGL > */
        unsigned int m_Count = 0;           /** < count of indices > */
    };
}