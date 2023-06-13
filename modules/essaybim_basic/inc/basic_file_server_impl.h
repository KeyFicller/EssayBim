#pragma once

#include "basic_file_server.h"

namespace EB
{
    class FileServerImpl
    {
    public:
        std::string projectPathRoot(eModules mod) const;
        std::string resourcesPathRoot() const;
        std::string readFromFilePath(const std::string& filePath);
        std::string fileNameOfPath(const std::string& filePath) const;
    };
}