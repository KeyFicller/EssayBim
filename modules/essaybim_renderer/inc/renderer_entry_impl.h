#pragma once

#include "renderer_entry.h"

namespace EB
{
    class RendererEntryImpl
    {
    public:
        RendererEntryImpl();
        ~RendererEntryImpl();

    public:
        void clear() const;
        void setClearColor(const Vec4& color) const;
        void setViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const;
        void mesh(const Shared<VertexArray>& vao, unsigned int count) const;

    protected:
        void init() const;
    };
}