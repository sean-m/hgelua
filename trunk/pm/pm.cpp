// pm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma comment(linker, "/NODEFAULTLIB:libc.lib")
extern HGE *hge;
HCHANNEL tmp;
hgeQuad quad;


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

bool FrameFunc()
{
	float dt=hge->Timer_GetDelta();
	switch(hge->Input_GetKey())
	{
	case HGEK_ESCAPE: return true;
	case HGEK_RIGHT:
		hge->Channel_Resume(tmp);
		break;
	case HGEK_LEFT:
		hge->Channel_Pause(tmp);
		break;
	case HGEK_UP:
		hge->Channel_SetVolume(tmp,50);
		break;
	}
	float x = 400;
	float y = 300;
	// Set up quad's screen coordinates
	quad.v[0].x=x-16; quad.v[0].y=y-16;
	quad.v[1].x=x+16; quad.v[1].y=y-16;
	quad.v[2].x=x+16; quad.v[2].y=y+16;
	quad.v[3].x=x-16; quad.v[3].y=y+16;

	return false;
}
bool RenderFunc()
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	hge->Gfx_RenderQuad(&quad);

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


	HpBar bar(100,20,2);
	bar.Render();

	hge->Gfx_EndScene();
	return false;
}
int main()
{
	hge = hgeCreate(HGE_VERSION);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_LOGFILE, "game.log");
	hge->System_SetState(HGE_SCREENBPP, 32);

	if(! hge->System_Initiate())
	{
		printf("Hge System_Initiate Failed!\n");
		return 1;		
	}
	Init();
	TexManager tex_manager;
	tex_manager.Init("script/tex.lua");
	SoundManager sound_manager;
	sound_manager.Init("script/sounds.lua");
	tmp = hge->Effect_PlayEx(sound_manager.GetSound(2054),100,100,2,true);
	hge->Channel_Pause(tmp);
	quad.tex = tex_manager.GetTexture(1003);


	// Set up quad which we will use for rendering sprite
	//quad.blend=BLEND_ALPHAADD | BLEND_COLORMUL | BLEND_ZWRITE;

	for(int i=0;i<4;i++)
	{
		// Set up z-coordinate of vertices
		quad.v[i].z=0.5f;
		// Set up color. The format of DWORD col is 0xAARRGGBB
		quad.v[i].col=0xFFFFA000;
	}

	// Set up quad's texture coordinates.
	// 0,0 means top left corner and 1,1 -
	// bottom right corner of the texture.
	quad.v[0].tx=96.0/128.0; quad.v[0].ty=64.0/128.0; 
	quad.v[1].tx=128.0/128.0; quad.v[1].ty=64.0/128.0; 
	quad.v[2].tx=128.0/128.0; quad.v[2].ty=96.0/128.0; 
	quad.v[3].tx=96.0/128.0; quad.v[3].ty=96.0/128.0; 
	//////////////////////////////////////////////////////////////////////////
	hge->System_Start();

	tex_manager.CleanUp();
	sound_manager.CleanUp();
	hge->System_Shutdown();
	hge->Release();

	return 0;
}

