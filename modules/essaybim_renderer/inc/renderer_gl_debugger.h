#pragma once

namespace EB
{
    class GLDebugger
    {
    public:
        static void clearError();
        static bool trace(const char* function, const char* file, int line);;
    };

    class GLSentry
    {
    public:
        GLSentry(const char* funcSig, const char* file, int line);
        ~GLSentry();
    private:
        const char* m_FuncSig = nullptr;
        const char* m_File = nullptr;
        int m_Line = 0;
    };
}

//#define EB_ENABLE_RENDERER_DEBUG
#ifdef EB_ENABLE_RENDERER_DEBUG
    #define EB_GL_TRACE(x) do {\
        ::EB::GLDebugger::clearError();\
        x;\
        ::EB::GLDebugger::trace(#x, __FILE__, __LINE__);\
    } while (0)
    #define EB_GL_AUTO_TRACE() ::EB::GLSentry sentry##__LINE__(__FUNCSIG__, __FILE__, __LINE__)
#else
    #define EB_GL_TRACE(x)
    #define EB_GL_AUTO_TRACE()
#endif
