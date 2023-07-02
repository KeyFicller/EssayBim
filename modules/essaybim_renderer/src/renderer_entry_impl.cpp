#include "renderer_entry_impl.h"

#include "renderer_index_buffer.h"
#include "renderer_gl_debugger.h"

#include <glad/glad.h>

namespace EB
{

    RendererEntryImpl::RendererEntryImpl()
    {
        init();
    }

    RendererEntryImpl::~RendererEntryImpl()
    {

    }

    void RendererEntryImpl::clear() const
    {
        EB_GL_AUTO_TRACE();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void RendererEntryImpl::setClearColor(const Vec4f& color) const
    {
        EB_GL_AUTO_TRACE();
        glClearColor(color.x(), color.y(), color.z(), color.w());
    }

    void RendererEntryImpl::setViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const
    {
        EB_GL_AUTO_TRACE();
        glViewport(x, y, width, height);
    }

    void RendererEntryImpl::mesh(const VertexArray* vao, unsigned int count) const
    {
        EB_GL_AUTO_TRACE();
        vao->bind();
        unsigned int idx = count ? count : vao->indexBuffer()->count();
        glDrawElements(GL_TRIANGLES, idx, GL_UNSIGNED_INT, nullptr);
    }

    void RendererEntryImpl::line(const VertexArray* vao, unsigned int count) const
    {
        EB_GL_AUTO_TRACE();
        vao->bind();
        unsigned int idx = count ? count : vao->indexBuffer()->count();
        glDrawElements(GL_LINES, idx, GL_UNSIGNED_INT, nullptr);
    }

    void RendererEntryImpl::init() const
    {
        EB_GL_AUTO_TRACE();
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LINE_SMOOTH);
        glLineWidth(2.0f);
    }

}