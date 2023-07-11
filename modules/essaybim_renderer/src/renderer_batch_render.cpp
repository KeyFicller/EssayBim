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

    void BatchRender::pushColor(const Vec3f& color)
    {
        pIns->m_pImpl->pushColor(color);
    }

    void BatchRender::popColor()
    {
        pIns->m_pImpl->popColor();
    }

    void BatchRender::pushTransparency(float alpha)
    {
        pIns->m_pImpl->pushTransparency(alpha);
    }

    void BatchRender::popTransparency()
    {
        pIns->m_pImpl->popTransparency();
    }

    void BatchRender::pushObjectId(const Handle& hdl)
    {
        pIns->m_pImpl->pushObjectId(hdl);
    }

    void BatchRender::popObjectId()
    {
        pIns->m_pImpl->popObjectId();
    }

    int BatchRender::addTexture(const Shared<Texture2D>& texture)
    {
        return pIns->m_pImpl->addTexture(texture);
    }

    void BatchRender::removeTexture(int allocatedIdx)
    {
        pIns->m_pImpl->removeTexture(allocatedIdx);
    }

    void BatchRender::removeAllTextures()
    {
        pIns->m_pImpl->removeAllTextures();
    }

    void BatchRender::pushTextureId(int texId)
    {
        pIns->m_pImpl->pushTextureId(texId);
    }

    void BatchRender::popTextureId()
    {
        pIns->m_pImpl->popTextureId();
    }

    void BatchRender::line(const Vec3f& start, const Vec3f& end)
    {
        pIns->m_pImpl->line(start, end);
    }

    void BatchRender::circle(const Vec3f& center, float radius, const Vec3f& normal)
    {
        pIns->m_pImpl->circle(center, radius, normal);
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

    void BatchRender::quad(const Vec3f& center, const Vec3f& xDir, const Vec3f& yDir)
    {
        pIns->m_pImpl->quad(center, xDir, yDir);
    }

}