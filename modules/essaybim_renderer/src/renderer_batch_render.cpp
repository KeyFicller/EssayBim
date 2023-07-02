#include "renderer_batch_render.h"

#include "renderer_batch_render_impl.h"


namespace EB
{

    BatchRender::BatchRender()
    {
        EB_IMPL() = createScoped<BatchRenderImpl>();
    }

    BatchRender::~BatchRender()
    {
        EB_IMPL().reset();
    }

    BatchRender& BatchRender::instance()
    {
        static BatchRender ins;
        return ins;
    }

    void BatchRender::start(const Mat4& viewprojectionMatrix)
    {
        instance().m_pImpl->start(viewprojectionMatrix);
    }

    void BatchRender::end()
    {
        instance().m_pImpl->end();
    }

    void BatchRender::line(const Vec3f& start, const Vec3f& end)
    {

    }

    void BatchRender::mesh(const std::vector<Vec3f>& vertices, const std::vector<Vec3i>& indices, const std::vector<Vec3f>& normals)
    {
        instance().m_pImpl->mesh(vertices, indices, normals);
    }

}