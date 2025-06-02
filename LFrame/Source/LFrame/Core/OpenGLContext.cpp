#include "lpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace LFrame
{
    Scope<OpenGLContext> OpenGLContext::Create(GLFWwindow* windowHandle)
    {
        return CreateScope<OpenGLContext>(windowHandle);
    }

    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
        : m_WindowHandle(windowHandle)
    {
        LF_CORE_ASSERT(m_WindowHandle, "Window handle is null!");
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle); // ���ô���������Ϊ��ǰ�߳���������

        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);    // ��ʼ�� GLAD
        LF_CORE_ASSERT(status, "Failed to initialize Glad!");

        LF_CORE_INFO("OpenGL Info");                                        // OpenGL ��Ϣ
        LF_CORE_INFO("    Vendor: {0}", (char*)glGetString(GL_VENDOR));     // ������
        LF_CORE_INFO("    Renderer: {0}", (char*)glGetString(GL_RENDERER)); // GPU ����
        LF_CORE_INFO("    Version: {0}", (char*)glGetString(GL_VERSION));   // �汾

        // ��� OpenGL �汾
        LF_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Lucky requires at least OpenGL version 4.5!");
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);    // ����ǰ�󻺳���
    }
}