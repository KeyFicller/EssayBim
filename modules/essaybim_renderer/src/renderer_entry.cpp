#include "renderer_entry.h"

#include "renderer_entry_impl.h"

namespace EB
{

    RendererEntry::RendererEntry()
    {
        EB_IMPL() = createScoped<RendererEntryImpl>();
    }

    RendererEntry::~RendererEntry()
    {
        EB_IMPL().reset();
    }

    const RendererEntry& RendererEntry::instance()
    {
        static RendererEntry ins;
        return ins;
    }

    void RendererEntry::clear() const
    {
        EB_IMPL()->clear();
    }

    void RendererEntry::setClearColor(const Vec4f& color) const
    {
        EB_IMPL()->setClearColor(color);
    }

    void RendererEntry::setViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const
    {
        EB_IMPL()->setViewport(x, y, width, height);
    }

    void RendererEntry::mesh(const VertexArray* vao, unsigned int count) const
    {
        EB_IMPL()->mesh(vao, count);
    }

    void RendererEntry::line(const VertexArray* vao, unsigned int count) const
    {
        EB_IMPL()->line(vao, count);
    }

}