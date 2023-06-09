#include "basic_file_server_impl.h"

#include "basic_assert.h"

#include <windows.h>

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

}