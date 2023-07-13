#include "basic_file_server.h"

#include "basic_file_server_impl.h"

namespace EB
{

    namespace
    {
        static FileServer g_Server;
    }

    FileServer::FileServer()
    {
        EB_IMPL() = createScoped<FileServerImpl>();
    }

    FileServer::~FileServer()
    {
        EB_IMPL().reset();
    }

    std::string FileServer::projectPathRoot(eModules mod)
    {
        return g_Server.m_pImpl->projectPathRoot(mod);
    }

    std::string FileServer::resourcesPathRoot()
    {
        return g_Server.m_pImpl->resourcesPathRoot();
    }

    std::string FileServer::readFromFilePath(const std::string& filePath)
    {
        return g_Server.m_pImpl->readFromFilePath(filePath);
    }

    std::string FileServer::fileNameOfPath(const std::string& filePath)
    {
        return g_Server.m_pImpl->fileNameOfPath(filePath);
    }

    std::string FileServer::openFile(const char* filter, HWND owner /*= nullptr*/)
    {
        return g_Server.m_pImpl->openFile(filter, owner);
    }

    std::string FileServer::saveFile(const char* filter, HWND owner /*= nullptr*/)
    {
        return g_Server.m_pImpl->saveFile(filter, owner);
    }

}