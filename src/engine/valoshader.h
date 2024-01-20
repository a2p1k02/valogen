#ifndef VALOGEN_VALOSHADER_H
#define VALOGEN_VALOSHADER_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <fstream>
#include <vector>

class valoshader {
public:
    std::vector<char> vertexShader;
    std::vector<char> fragmentShader;

    void setShaders(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    static VkShaderModule createShaderModule(VkDevice device, const std::vector<char>& code);
private:

    static std::vector<char> readFile(const std::string& filename);
};


#endif //VALOGEN_VALOSHADER_H
