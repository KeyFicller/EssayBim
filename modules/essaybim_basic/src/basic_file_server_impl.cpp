#include "basic_file_server_impl.h"

#include "basic_assert.h"

#include <windows.h>
#include <fstream>

namespace
{
    std::string exeRootPath(void)
    {
        WCHAR path[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, path);
        std::string str;
        DWORD dwMinSize = 0;
        LPSTR lpszStr = NULL;
        dwMinSize = WideCharToMultiByte(CP_OEMCP, NULL, path, -1, NULL, 0, NULL, FALSE);
        if (dwMinSize == 0) {
            EB_CORE_ASSERT(false, "string transform failed.");
        }
        lpszStr = new char[dwMinSize];
        WideCharToMultiByte(CP_OEMCP, NULL, path, -1, lpszStr, dwMinSize, NULL, FALSE);
        str = lpszStr;
        delete lpszStr;
        return str;
    }

    enum class eExecuteEnvironment
    {
        kByIDE,      /* < the program is executed by visual studio > */
        kByExe       /* < the program is executed by binary file > */
    };

    eExecuteEnvironment executeEnvironment()
    {
        STARTUPINFO startupInfo;
        GetStartupInfo(&startupInfo);

        return (startupInfo.dwFlags & STARTF_USESHOWWINDOW) ? eExecuteEnvironment::kByExe : eExecuteEnvironment::kByIDE;
    }
}


namespace EB
{

    std::string FileServerImpl::projectPathRoot(eModules mod) const
    {
        std::string& prefix = exeRootPath();
        std::string suffix;
        switch (mod)
        {
        case EB::eModules::kBasic:
            suffix = "essaybim_basic";
            break;
        case EB::eModules::kDocument:
            suffix = "essaybim_document";
            break;
        case EB::eModules::kEvent:
            suffix = "essaybim_event";
            break;
        case EB::eModules::kGeometry:
            suffix = "essaybim_geometry";
            break;
        case EB::eModules::kGui:
            suffix = "essaybim_gui";
            break;
        case EB::eModules::kRenderer:
            suffix = "essaybim_renderer";
            break;
        case EB::eModules::kWindow:
            suffix = "essaybim_window";
            break;
        default:
            EB_CORE_ASSERT("Invalid module enum input.")
            break;
        }
        if (executeEnvironment() == eExecuteEnvironment::kByIDE) {
            return prefix + "\\..\\modules\\" + suffix;
        }
        else {
            return prefix + "\\..\\..\\..\\modules\\" + suffix;
        }
    }

    std::string FileServerImpl::resourcesPathRoot() const
    {
        if (executeEnvironment() == eExecuteEnvironment::kByIDE) {
            return exeRootPath() + "\\..\\resources";
        }
        else {
            return exeRootPath() + "\\..\\..\\..\\resources";
        }
    }

    std::string FileServerImpl::readFromFilePath(const std::string& filePath)
    {
        std::string result;
        std::ifstream fin(filePath, std::ios::binary);
        if (fin) {
            fin.seekg(0, std::ios::end);
            result.resize(fin.tellg());
            fin.seekg(0, std::ios::beg);
            fin.read(&result[0], result.size());
        }
        else {
            EB_CORE_ERROR("can't open file path : %s", filePath.c_str());
        }
        return result;
    }

    std::string FileServerImpl::fileNameOfPath(const std::string& filePath) const
    {
        size_t lastSlash = filePath.find_last_of("/\\");
        lastSlash = lastSlash == std::string::npos ? 0 : lastSlash + 1;
        size_t lastDot = filePath.find_last_of('.');
        lastDot = lastDot == std::string::npos ? filePath.size() : lastDot;

        size_t count = lastDot - lastSlash;
        return filePath.substr(lastSlash, count);
    }

}