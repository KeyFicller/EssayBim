#include "basic_file_server.h"

#include "basic_file_server_impl.h"

namespace EB
{

    FileServer::FileServer()
    {
        EB_IMPL = createScoped<FileServerImpl>();
    }

    FileServer::~FileServer()
    {
        EB_IMPL.reset();
    }

    const EB::FileServer& FileServer::instance()
    {
        static const FileServer server;
        return server;
    }

    std::string FileServer::projectPathRoot(eModules mod) const
    {
        return EB_IMPL->projectPathRoot(mod);
    }

    std::string FileServer::resourcesPathRoot() const
    {
        return EB_IMPL->resourcesPathRoot();
    }

    std::string FileServer::readFromFilePath(const std::string& filePath) const
    {
        return EB_IMPL->readFromFilePath(filePath);
    }

    std::string FileServer::fileNameOfPath(const std::string& filePath) const
    {
        return EB_IMPL->fileNameOfPath(filePath);
    }

}