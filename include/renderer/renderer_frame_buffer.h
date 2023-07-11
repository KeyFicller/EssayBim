#pragma once

#include "renderer_export.h"

#include "basic_impl_template.h"

#include <vector>

namespace EB
{
    /**
     * @brief enum class of frame buffer texture data format.
     */
    enum class eFrameBufferTextureFormat
    {
        kNone = 0,                   /** < none > */
        kRGBA8,                      /** < red, green, blue, alpha for 8 bit > */
        kRedInteger,                 /** < integer > */
        kDepth,                      /** < depth buffer > */
        kDepth24Stencil8 = kDepth    /** < depth buffer > */
    };

    /**
     * @brief  struct specify frame buffer property.
     */
    struct FrameBufferSpecification
    {
        unsigned int Width;                                  /** < frame buffer width > */
        unsigned int Height;                                 /** < frame buffer height > */
        unsigned int Samples = 1;                            /** < sample channels > */
        bool SwapChainTarget = false;                        /** <  > */
        std::vector<eFrameBufferTextureFormat> Attachments;  /** < data formats > */
    };

    /**
     * @brief  this enum defines sampler precision from frame buffer.
     */
    enum class eSamplerPrecision
    {
        kPrecisionHighest     = 4,               /** read for 4 * 4 pixels to get intersection */
        kPrecisionHigh        = 8,               /** read for 8 * 8 pixels to get intersection */
        kPrecisionMedium      = 16,              /** read for 16 * 16 pixels to get intersection */
        kPrecisionLow         = 32,              /** read for 32 * 32 pixels to get intersection */
        kPrecisionLowest      = 64,              /** read for 64 * 64 pixels to get intersection */
    };

    /**
     * @brief  this class is used to define frame buffer.
     */
    class EB_RENDERER_EXPORT FrameBuffer
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(FrameBuffer)
    public:
        /**
         * @brief   create frame buffer with property specification.
         * @return  shared pointer of created frame buffer.
         */
        static Shared<FrameBuffer> create(const FrameBufferSpecification& specification);
    public:
        /**
         * @brief   constructor for frame buffer.
         * @param[in]  specification      frame buffer property.
         */
        FrameBuffer(const FrameBufferSpecification& specification);

        /**
         * @brief   destructor for frame buffer.
         */
        ~FrameBuffer();

    public:
        /**
         * @brief  get frame buffer property.
         * @return   reference to frame buffer property.
         */
        const FrameBufferSpecification& specification() const;

        /**
         * @brief   bind this frame buffer to OpenGL.
         */
        void bind() const;

        /**
         * @brief  unbind this frame buffer.
         */
        void unbind() const;

        /**
         * @biref  on frame buffer resize event.
         * @param[in]   width    resized width.
         * @param[in]   height   resized height.
         */
        void onResize(unsigned int width, unsigned int height);

        /**
         * @brief   read pixel data from layer and position.
         * @param[in]   attachmentIdx    frame buffer layer index.
         * @param[in]   x                x coordinate of pixel read.
         * @param[in]   y                y coordinate of pixel read.
         * @return     pixel data read.
         */
        int pixel(unsigned int attachmentIdx, int x, int y, eSamplerPrecision precision = eSamplerPrecision::kPrecisionMedium) const;

        /**
         * @brief    get renderer id of frame buffer layer.
         * @param[in]   index    frame buffer layer index.
         * @return   renderer id allocated by OpenGL.
         */
        unsigned int colorAttachmentRendererId(unsigned int index = 0) const;

        /**
         * @brief    flush frame buffer layer with specified value.
         * @param[in]   attachmentIdx     frame buffer layer index.
         * @param[in]   value             fill value.
         */
        void clearAttachment(unsigned int attachmentIdx, int value);
    };
}