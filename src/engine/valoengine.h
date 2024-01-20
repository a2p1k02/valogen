#ifndef VALOGEN_VALOENGINE_H
#define VALOGEN_VALOENGINE_H

#include <vector>
#include <optional>
#include "valowin.h"

const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    [[nodiscard]] bool isComplete() const
    {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

class valoengine {
public:
    valoengine(int width, int height);
    ~valoengine();
    void start();
private:
    //Objects
    VkInstance instance{};
    VkPhysicalDevice physicalDevice{};
    VkDevice vkDevice{};
    VkQueue graphicsQueue{};
    VkQueue presentQueue{};
    VkSurfaceKHR surface{};
    VkDebugUtilsMessengerEXT debugMessenger{};
    valowin window;

    //Classes methods
    void initVulkan();
    void createInstance();
    void pickPhysicalDevice();
    void createLogicalDevice();
    void createSurface();
    void cleanup();

    //Vulkan methods
    static bool checkValidationLayerSupport();
    bool isDeviceSuitable(VkPhysicalDevice device);
    static std::vector<const char *> getRequiredExtensions();
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

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
