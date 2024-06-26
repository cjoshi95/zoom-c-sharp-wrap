#pragma once
using namespace System;
using namespace System::Windows;
#include "zoom_sdk_dotnet_wrap_def.h"
#include "customized_annotation_dotnet_wrap.h"
#include "customized_share_render_dotnet_wrap.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	public interface class IAnnotationControllerDotNetWrap
	{
	public:
		bool IsAnnotationDisable();
		SDKError StartAnnotation(SDKViewType viewtype);
		SDKError StopAnnotation(SDKViewType viewtype);
		SDKError SetTool(SDKViewType viewtype, AnnotationToolType type);
		SDKError Clear(SDKViewType viewtype, AnnotationClearType type);
		SDKError SetColor(SDKViewType viewtype, unsigned long color);
		SDKError SetLineWidth(SDKViewType viewtype, long lineWidth);
		SDKError Undo(SDKViewType viewtype);
		SDKError Redo(SDKViewType viewtype);
		bool IsAnnotationLegalNoticeAvailable();
		String^ getAnnotationLegalNoticesPrompt();
		String^ getAnnotationLegalNoticesExplained();
		ICustomizedAnnotationControllerDotNetWrap^ GetCustomizedAnnotationController(ICustomizedShareRenderDotNetWrap^ pShareRender);
	};

	private ref class CAnnotationControllerDotNetWrap sealed : public IAnnotationControllerDotNetWrap
	{
		// TODO: Add your methods for this class here.
	public:
		static property CAnnotationControllerDotNetWrap^ Instance
		{
			CAnnotationControllerDotNetWrap^ get() { return m_Instance; }
		}

		void BindEvent() {};

		virtual bool IsAnnotationDisable();
		virtual SDKError StartAnnotation(SDKViewType viewtype);
		virtual SDKError StopAnnotation(SDKViewType viewtype);
		virtual SDKError SetTool(SDKViewType viewtype, AnnotationToolType type);
		virtual SDKError Clear(SDKViewType viewtype, AnnotationClearType type);
		virtual SDKError SetColor(SDKViewType viewtype, unsigned long color);
		virtual SDKError SetLineWidth(SDKViewType viewtype, long lineWidth);
		virtual SDKError Undo(SDKViewType viewtype);
		virtual SDKError Redo(SDKViewType viewtype);
		virtual bool IsAnnotationLegalNoticeAvailable();
		virtual String^ getAnnotationLegalNoticesPrompt();
		virtual String^ getAnnotationLegalNoticesExplained();
		virtual ICustomizedAnnotationControllerDotNetWrap^ GetCustomizedAnnotationController(ICustomizedShareRenderDotNetWrap^ pShareRender);
	private:
		CAnnotationControllerDotNetWrap() {};
		virtual ~CAnnotationControllerDotNetWrap() {};
		static CAnnotationControllerDotNetWrap^ m_Instance = gcnew CAnnotationControllerDotNetWrap;
	};
}