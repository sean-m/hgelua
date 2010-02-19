#include <windows.h>
#include ".\cn\GfxFont.h"

#pragma comment(lib,"./HGE16/lib/hge.lib")
#pragma comment(lib,"./HGE16/lib/hgehelp.lib")
#pragma comment(linker, "/NODEFAULTLIB:libcmt.lib")

HGE *hge=0;

GfxFont* pGfxFont		= NULL;	// ��ͨģʽ
GfxFont* pBlodFont		= NULL;	// ����ģʽ
GfxFont* pItalicFont	= NULL;	// б��ģʽ
GfxFont* pNotAntialias	= NULL; // ��ƽ��ģʽ
GfxFont* pAntialias		= NULL; // ƽ��ģʽ

void Init()
{
	
	pGfxFont		= new GfxFont("����",12,FALSE,FALSE,FALSE);// ���飬�Ǵ��壬��б�壬��ƽ��
	pBlodFont		= new GfxFont("����",18,TRUE,FALSE,FALSE);// ���飬���壬��б�壬��ƽ��
	pItalicFont		= new GfxFont("����",26,TRUE,TRUE,FALSE);// ���飬���壬б�壬��ƽ��
	pNotAntialias	= new GfxFont("����",36,TRUE,FALSE,FALSE);// ���飬���壬��б�壬��ƽ��
	pAntialias		= new GfxFont("����",36,TRUE,FALSE,TRUE);// ���飬���壬��б�壬ƽ��

	pGfxFont->SetColor(0xFF00FFFF);		// ��������������ɫ
	pBlodFont->SetColor(0xFFFF0FF0);	// ��������������ɫ
	pItalicFont->SetColor(0xFF0FF0FF);	// ��������������ɫ
	pNotAntialias->SetColor(0xFFFFF00F);// ��������������ɫ
	pAntialias->SetColor(0xFF0FFF0F);	// ��������������ɫ
}

void Done()
{
	// ������������ָ��
	delete pGfxFont;
}

bool FrameFunc()
{
	return false;
}

bool RenderFunc()
{
	hge->Gfx_Clear(0);
	hge->Gfx_BeginScene();


	const char* lpString = ""
		"��ʾ������ʾ�·�����֧��ƽ��(�޾��)ģʽ\n"
		"\n"
		"����Ҫ�����κ�ͼƬ��ģ���ḻ��������ʾ������\n"
		"\n"
		"ʹ�÷����ܼ򵥣������ <CN> Ŀ¼�µ� Readme.txt �ļ���\n";

	// ʹ�������������
	pGfxFont->Print(10,10,lpString);

	pBlodFont->Print(10,100,"������ʾ���� ��ʾ�����塱");		
	pItalicFont->Print(10,150,"������ʾ���� ��ʾ��б�塱");
	pNotAntialias->Print(10,200,"������ʾ���� ��ʾ����ƽ��ģʽ��");
	pAntialias->Print(10,250,"������ʾ���� ��ʾ��ƽ�������ģʽ��");

	hge->Gfx_EndScene();

	return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	hge = hgeCreate(HGE_VERSION);

	hge->System_SetState(HGE_INIFILE, "hgedemo.ini");
	hge->System_SetState(HGE_LOGFILE, "hgedemo.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "HGE ������ʾ������� : ΢���ƽ�� HTTP://BOGY.CN");
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENBPP, 32);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_HIDEMOUSE, false);
	hge->System_SetState(HGE_USESOUND, false);

	if(hge->System_Initiate())
	{
		Init();
		hge->System_Start();
	}
	else MessageBox(NULL, hge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
	Done();

	hge->System_Shutdown();
	hge->Release();
	return 0;
}
