#include "renderer_debugger.h"

#include "basic_assert.h"

#include <glad/glad.h>

namespace EB
{
    void GLDebugger::clearError()
    {
        int errorCount = 0;
        while (true) {
            GLenum error = glGetError();
            if (error == GL_NO_ERROR) {
                break;
            }
            errorCount++;
        }
        if (errorCount) {
            EB_CORE_WARN("[OpenGL Error]%d renderer error ignored.", errorCount);
        }
    }

    bool GLDebugger::trace(const char* function, const char* file, int line)
    {
        while (GLenum error = glGetError()) {
            EB_CORE_ERROR("[OpenGL Error](%d): %s - %s - %d", error, function, file, line);
            __debugbreak();
            return true;
        }
        return false;
    }

    GLSentry::GLSentry(const char* funcSig, const char* file, int line)
        : m_FuncSig(funcSig), m_File(file), m_Line(line)
    {
        GLDebugger::clearError();
    }

    GLSentry::~GLSentry()
    {
        GLDebugger::trace(m_FuncSig, m_File, m_Line);
    }

}