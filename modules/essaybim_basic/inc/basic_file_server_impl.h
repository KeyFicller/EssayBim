#pragma once

#include "basic_file_server.h"

namespace EB
{
    class FileServerImpl
    {
    public:
        std::string projectPathRoot(eModules mod) const;
        std::string resourcesPathRoot() const;
        std::string readFromFilePath(const std::string& filePath) const;
        std::string fileNameOfPath(const std::string& filePath) const;
        std::string openFile(const char* filter, HWND owner = nullptr) const;
        std::string saveFile(const char* filter, HWND owner = nullptr) const;
    };
}