#ifndef VALOGEN_VALOENGINE_H
#define VALOGEN_VALOENGINE_H

#include <vector>
#include "valowin.h"

const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

class valoengine {
public:
    valoengine(int width, int height);
    ~valoengine();
    void start();
private:
    VkInstance instance{};
    VkDebugUtilsMessengerEXT debugMessenger{};

    valowin window;

    void initVulkan();
    void createInstance();
    void cleanup();
    static bool checkValidationLayerSupport();

    static std::vector<const char *> getRequiredExtensions();

    //Debug
    static void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT messageType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserData);
    void setupDebugMessenger();
    static VkResult CreateDebugUtilsMessengerEXT(
            VkInstance vkInstance,
            const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
            const VkAllocationCallbacks* pAllocator,
            VkDebugUtilsMessengerEXT* pDebugMessenger);
    static void DestroyDebugUtilsMessengerEXT(
            VkInstance instance,
            VkDebugUtilsMessengerEXT debugMessenger,
            const VkAllocationCallbacks* pAllocator);

};

#endif //VALOGEN_VALOENGINE_H
