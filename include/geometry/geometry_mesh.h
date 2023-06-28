#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"
#include "basic_vector.h"

#include <string>

namespace EB
{
    class GeMeshImpl;

    /**
     * @brief  this struct defines mesh data.
     */
    struct EB_EXPORT GeMeshData
    {
        /** < vertices coordinate > */
        std::vector<Vec3f> Vertices;

        /** < triangle mesh indices > */
        std::vector<Vec3i> Indices;
    };

    /**
     * @brief  this class define mesh
     */
    class EB_EXPORT GeMesh
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(GeMesh)
    public:
        /**
         * @biref   constructor for mesh
         */
        GeMesh();

        /**
         * @brief   constructor for mesh.
         * @param[in]   impl    implement of derived class.
         */
        GeMesh(GeMeshImpl& impl);

        /**
         * @brief   destructor for mesh.
         */
        virtual ~GeMesh();

    public:
        /**
         * @brief   load mesh from obj file.
         * @param[in]    fileName    file path of obj file.
         */
        void importFromObj(const std::string& fileName);

        /**
         * @brief  get geom mesh data.
         * @return   geom mesh data.
         */
        const GeMeshData& data() const;

        /**
         * @brief  get bound box of mesh.
         * @return   bound box of mesh.
         */
        const std::vector<Vec3f>& boundingBox() const;
    };
}