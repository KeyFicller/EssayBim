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

}