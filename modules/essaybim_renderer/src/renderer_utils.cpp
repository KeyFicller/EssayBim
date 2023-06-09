#include "renderer_utils.h"

#include "basic_assert.h"

namespace EB
{

    unsigned int Utils_Renderer::shaderTypeSize(eShaderDataType type)
    {
        switch (type) {
            case EB::eShaderDataType::kNone:              break;
            case EB::eShaderDataType::kBool:              return 1;
            case EB::eShaderDataType::kInt:               return 4;
            case EB::eShaderDataType::kInt2:              return 4 * 2;
            case EB::eShaderDataType::kInt3:              return 4 * 3;
            case EB::eShaderDataType::kInt4:              return 4 * 4;
            case EB::eShaderDataType::kFloat:             return 4;
            case EB::eShaderDataType::kFloat2:            return 4 * 2;
            case EB::eShaderDataType::kFloat3:            return 4 * 3;
            case EB::eShaderDataType::kFloat4:            return 4 * 4;
            case EB::eShaderDataType::kMat2:              return 4 * 2 * 2;
            case EB::eShaderDataType::kMat3:              return 4 * 3 * 3;
            case EB::eShaderDataType::kMat4:              return 4 * 4 * 4;
        }
        EB_CORE_ASSERT(false, "unknown shader data type.");
        return 0;
    }

    unsigned int Utils_Renderer::shaderTypeComponent(eShaderDataType type)
    {
        switch (type) {
            case EB::eShaderDataType::kNone:              break;
            case EB::eShaderDataType::kBool:              return 1;
            case EB::eShaderDataType::kInt:               return 1;
            case EB::eShaderDataType::kInt2:              return 1 * 2;
            case EB::eShaderDataType::kInt3:              return 1 * 3;
            case EB::eShaderDataType::kInt4:              return 1 * 4;
            case EB::eShaderDataType::kFloat:             return 1;
            case EB::eShaderDataType::kFloat2:            return 1 * 2;
            case EB::eShaderDataType::kFloat3:            return 1 * 3;
            case EB::eShaderDataType::kFloat4:            return 1 * 4;
            case EB::eShaderDataType::kMat2:              return 1 * 2 * 2;
            case EB::eShaderDataType::kMat3:              return 1 * 3 * 3;
            case EB::eShaderDataType::kMat4:              return 1 * 4 * 4;
        }
        EB_CORE_ASSERT(false, "unknown shader data type.");
        return 0;
    }

    GLenum Utils_Renderer::glTypeOfShaderType(eShaderDataType type)
    {
        switch (type) {
            case EB::eShaderDataType::kNone:              break;
            case EB::eShaderDataType::kBool:              return GL_BOOL;
            case EB::eShaderDataType::kInt:               
            case EB::eShaderDataType::kInt2:              
            case EB::eShaderDataType::kInt3:              
            case EB::eShaderDataType::kInt4:              return GL_INT;
            case EB::eShaderDataType::kFloat:             
            case EB::eShaderDataType::kFloat2:            
            case EB::eShaderDataType::kFloat3:            
            case EB::eShaderDataType::kFloat4:            
            case EB::eShaderDataType::kMat2:              
            case EB::eShaderDataType::kMat3:              
            case EB::eShaderDataType::kMat4:              return GL_FLOAT;
        }
        EB_CORE_ASSERT(false, "unknown shader data type.");
        return -1;
    }

    std::unordered_map<GLenum, std::string> Utils_Renderer::parseShaderSource(const std::string& source)
    {
        auto shaderTypeStringToGLenum = [](const std::string& shaderTypeStr) -> GLenum {
            if (shaderTypeStr == "vertex") {
                return GL_VERTEX_SHADER;
            }
            else if (shaderTypeStr == "fragment") {
                return GL_FRAGMENT_SHADER;
            }
            else {
                EB_CORE_ASSERT(false, "unknown shader type.");
                return GL_NONE;
            }
        };

        std::unordered_map<GLenum, std::string> shaderSources;
        const char* typeToken = "#type";
        size_t typeTokenLength = strlen(typeToken);
        size_t pos = source.find(typeToken, 0);

        while (pos != std::string::npos) {
            size_t endOfLine = source.find_first_of("\r\n", pos);
            EB_CORE_ASSERT(endOfLine != std::string::npos, "shader source syntax error.");
            size_t afterTypeToken = pos + typeTokenLength + 1;
            std::string type = source.substr(afterTypeToken, endOfLine - afterTypeToken);
            size_t endOfNextLine = source.find_first_of("\r\n", endOfLine);
            pos = source.find(typeToken, endOfNextLine);
            shaderSources[shaderTypeStringToGLenum(type)] =
                source.substr(endOfNextLine, pos - (endOfNextLine == std::string::npos ? source.size() - 1 : endOfNextLine));
        }

        return shaderSources;
    }

}