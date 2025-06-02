#include "lpch.h"
#include "ImGuiLayer.h"

// Temp
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui_internal.h>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "LFrame/Core/Application.h"

namespace LFrame
{
    const static float s_StandardDPI = 120.0f;  // ��׼ DPI

    ImGuiLayer::ImGuiLayer()
        : Layer("ImGuiLayer")
    {

    }

    ImGuiLayer::~ImGuiLayer()
    {

    }

    void ImGuiLayer::OnAttach()
    {
        LF_CORE_TRACE("ImGuiLayer::OnAttach");

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();     // ���� ImGui ������

        Application& app = Application::GetInstance();

        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;   // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;       // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;     // Enable Multi-Viewport / Platform Windows

        float fontSize = 20.0f * app.GetWindow().GetDPI() / s_StandardDPI;
        io.Fonts->AddFontFromFileTTF("Resources/Fonts/Opensans/OpenSans-Bold.ttf", fontSize);   // ��Ӵ��壨0�ţ�
        
        // Ĭ������ ��� TTF ����
        io.FontDefault = io.Fonts->AddFontFromFileTTF("Resources/Fonts/Opensans/OpenSans-Regular.ttf", fontSize);   // 1��

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            SetDefaultStyles();     // ���ó�����ʽ
        }

        GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnDetach()
    {
        LF_CORE_TRACE("ImGuiLayer::OnDetach");

        ImGui_ImplOpenGL3_Shutdown();   // �ر� ImGui 
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();        // ����������
    }

    void ImGuiLayer::OnEvent(Event& event)
    {
        // ��ֹ�����¼�
        if (m_BlockEvents)
        {
            ImGuiIO& io = ImGui::GetIO();

            //event.m_Handled |= event.IsInCategory(EventCategoryMouse) & io.WantCaptureMouse;        // ��������¼�
            //event.m_Handled |= event.IsInCategory(EventCategoryKeyboard) & io.WantCaptureKeyboard;  // ��������¼�
        }
    }

    void ImGuiLayer::Begin()
    {
        // ������֡
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiLayer::End()
    {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::GetInstance();
        io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight()); // ���ô��ڴ�С

        // Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }

    void ImGuiLayer::SetDefaultStyles()
    {
        ImGuiStyle& style = ImGui::GetStyle();
        // TODO ���� ImGuiStyle �����в���
        style.WindowBorderSize = 1.0f;
        style.ChildBorderSize = 1.0f;
        style.TabBorderSize = 1.0f;

        style.WindowMinSize.x = 50.0f;          // ������С�ߴ�

        style.FrameRounding = 4.0f;             // �ؼ��߿�Բ�� [0, 12] 4.8 <=> 0.4f
        style.FrameBorderSize = 1.0f;           // �߿�ߴ�
        style.FramePadding.y = 4.0f;
 
        style.WindowRounding = 4.0f;            // ���ڱ߿�Բ��
        style.GrabRounding = 4.0f;              // �϶��� handle Բ��
        style.PopupRounding = 4.0f;             // ��������Բ��
        style.ChildRounding = 4.0f;             // �Ӵ���Բ��
        style.TabRounding = 2.0f;               // Tab Բ��

        style.ScrollbarRounding = 12.0f;        // ������Բ��
        style.ScrollbarSize = 18.0f;

        style.ButtonTextAlign = { 0.5f, 0.5f }; // ��ť���־���
    }
}