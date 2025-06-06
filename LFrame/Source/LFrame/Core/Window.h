#pragma once

#include <GLFW/glfw3.h>

#include "LFrame/Core/Base.h"
#include "LFrame/Core/Events/Event.h"
#include "LFrame/Core/OpenGLContext.h"

namespace LFrame
{
    /// <summary>
    /// 窗口属性
    /// </summary>
    struct WindowProps
    {
        std::string Title;      // 标题
        unsigned int Width;     // 宽
        unsigned int Height;    // 高

        WindowProps(const std::string& title = "LFrame", unsigned int width = 1280, unsigned int height = 720)
            : Title(title), Width(width), Height(height)
        {

        }
    };

    /// <summary>
    /// 窗口类
    /// </summary>
    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;    // 事件回调函数 void func(Event&)

        /// <summary>
        /// 创建窗口
        /// </summary>
        /// <param name="props">窗口属性</param>
        /// <returns>窗口</returns>
        static Scope<Window> Create(const WindowProps& props = WindowProps());

        /// <summary>
        /// 窗口
        /// </summary>
        /// <param name="props">窗口属性</param>
        Window(const WindowProps& props);

        virtual ~Window();

        /// <summary>
        /// 更新：每帧调用
        /// </summary>
        void OnUpdate();

        inline unsigned int GetWidth() const { return m_Data.Width; }
        inline unsigned int GetHeight() const { return m_Data.Height; }

        /// <summary>
        /// 设置事件回调函数：从Application设置
        /// </summary>
        /// <param name="callback">回调函数</param>
        inline void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }

        /// <summary>
        /// 设置垂直同步
        /// </summary>
        /// <param name="enabled">是否启用</param>
        void SetVSync(bool enabled);

        /// <summary>
        /// 检测是否垂直同步
        /// </summary>
        /// <returns>结果</returns>
        bool IsVSync() const;

        /// <summary>
        /// 设置 DPI
        /// </summary>
        /// <param name="dpi"></param>
        void SetDPI(unsigned int dpi) { m_Data.DPI = dpi; }
        unsigned int GetDPI() const { return m_Data.DPI; }

        /// <summary>
        /// 返回 GLFW 窗口
        /// </summary>
        /// <returns>窗口指针</returns>
        inline virtual void* GetNativeWindow() const { return m_Window; }
    private:
        /// <summary>
        /// 初始化窗口
        /// </summary>
        /// <param name="props">窗口属性</param>
        virtual void Init(const WindowProps& props);

        /// <summary>
        /// 关闭窗口
        /// </summary>
        virtual void Shutdown();
    private:
        GLFWwindow* m_Window;           // GLFW 窗口
        Scope<OpenGLContext> m_Context; // OpenGL 上下文

        /// <summary>
        /// 窗口数据
        /// </summary>
        struct WindowData
        {
            std::string Title;      // 标题
            unsigned int Width;     // 宽
            unsigned int Height;    // 高
            unsigned DPI;           // DPI
            bool VSync;             // 是否垂直同步

            EventCallbackFn EventCallback;  // 事件回调函数
        };

        WindowData m_Data;  // 窗口数据
    };
}