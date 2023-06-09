#pragma once

#include "basic_file_server.h"

namespace EB
{
    class FileServerImpl
    {
    public:
        std::string projectPathRoot(eModules mod) const;
        std::string resourcesPathRoot() const;
    };
}