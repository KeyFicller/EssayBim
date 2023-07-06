#include "renderer_batch_render.h"

#include "renderer_batch_render_impl.h"


namespace EB
{
    static BatchRender* pIns = nullptr;

    BatchRender::BatchRender()
    {
        EB_IMPL() = createScoped<BatchRenderImpl>();
    }

    BatchRender::~BatchRender()
    {
        EB_IMPL().reset();
    }

    void BatchRender::initialize()
    {
        EB_CORE_ASSERT(!pIns);
        pIns = new BatchRender();
    }

    const BatchRenderStatistic& BatchRender::statistic()
    {
        return pIns->m_pImpl->statistic();
    }

    void BatchRender::terminate()
    {
        EB_CORE_ASSERT(pIns);
        EB_SAFE_DELETE(pIns);
    }

    void BatchRender::start(const Mat4& viewprojectionMatrix)
    {
        pIns->m_pImpl->start(viewprojectionMatrix);
    }

    void BatchRender::end()
    {
        pIns->m_pImpl->end();
    }

    void BatchRender::line(const Vec3f& start, const Vec3f& end)
    {
        pIns->m_pImpl->line(start, end);
    }

    void BatchRender::polyline(const std::vector<Vec3f>& vertices)
    {
        pIns->m_pImpl->polyline(vertices);
    }

    void BatchRender::frame(const std::vector<Vec3f>& vertices, const std::vector<Vec2i>& indices)
    {
        pIns->m_pImpl->frame(vertices, indices);
    }

    void BatchRender::mesh(const std::vector<Vec3f>& vertices, const std::vector<Vec3i>& indices, const std::vector<Vec3f>& normals)
    {
        pIns->m_pImpl->mesh(vertices, indices, normals);
    }

}