#pragma once

#include <spdlog/spdlog.h>

#include "Base.h"

namespace LFrame
{
    /// <summary>
    /// ��־����������ͼ�¼��־��Ϣ
    /// </summary>
    class Log
    {
    public:
        /// <summary>
        /// ��ʼ��
        /// </summary>
        static void Init();

        /// <summary>
        /// �����ں���־
        /// </summary>
        /// <returns>�ں���־</returns>
        inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

        /// <summary>
        /// ���ؿͻ�����־
        /// </summary>
        /// <returns>�ͻ�����־</returns>
        inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static Ref<spdlog::logger> s_CoreLogger;    // �ں���־
        static Ref<spdlog::logger> s_ClientLogger;  // �ͻ�����־
    };
}

// �ں���־
#define LF_CORE_TRACE(...)  ::LFrame::Log::GetCoreLogger()->trace(__VA_ARGS__)      // ��ʾ����ϸ������Ϣ���������á�ѭ��״̬�ȣ�
#define LF_CORE_INFO(...)   ::LFrame::Log::GetCoreLogger()->info(__VA_ARGS__)       // ��Ϣ������״̬����Ҫ�¼�����־��Ϣ��ģ���ʼ����ɵȣ�
#define LF_CORE_WARN(...)   ::LFrame::Log::GetCoreLogger()->warn(__VA_ARGS__)       // ���棺���ܵ��������������������ܼ������У�����ȱʧ�ȣ�
#define LF_CORE_ERROR(...)  ::LFrame::Log::GetCoreLogger()->error(__VA_ARGS__)      // ���󣺿ɻָ�������쳣��������δ�������ļ���ȡʧ�ܡ����糬ʱ�ȣ�
#define LF_CORE_FATAL(...)  ::LFrame::Log::GetCoreLogger()->critical(__VA_ARGS__)   // ���ش��󣺲��ɻָ���������ֹ�����ڴ����ʧ�ܡ��ؼ���Դ��ʼ��ʧ�ܵȣ�

// �ͻ�����־
#define LF_TRACE(...)       ::LFrame::Log::GetClientLogger()->trace(__VA_ARGS__)    // ��ʾ����ϸ������Ϣ���������á�ѭ��״̬�ȣ�
#define LF_INFO(...)        ::LFrame::Log::GetClientLogger()->info(__VA_ARGS__)     // ��Ϣ������״̬����Ҫ�¼�����־��Ϣ��ģ���ʼ����ɵȣ�
#define LF_WARN(...)        ::LFrame::Log::GetClientLogger()->warn(__VA_ARGS__)     // ���棺���ܵ��������������������ܼ������У�����ȱʧ�ȣ�
#define LF_ERROR(...)       ::LFrame::Log::GetClientLogger()->error(__VA_ARGS__)    // ���󣺿ɻָ�������쳣��������δ�������ļ���ȡʧ�ܡ����糬ʱ�ȣ�
#define LF_FATAL(...)       ::LFrame::Log::GetClientLogger()->critical(__VA_ARGS__) // ���ش��󣺲��ɻָ���������ֹ�����ڴ����ʧ�ܡ��ؼ���Դ��ʼ��ʧ�ܵȣ�