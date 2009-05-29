#include "StdAfx.h"
#include "TexManager.h"

extern HGE *hge;

TexManager::TexManager(void)
{
	L = NULL;
	is_load_once = true;
}

TexManager::~TexManager(void)
{
	if(L) lua_close(L);
}

void TexManager::Init(const char *srcipt_path)
{
	L = lua_open();
	luaL_openlibs(L);
	if (luaL_dofile(L, srcipt_path))
	{
		printf("����ű��������!!\n");
	}
	if(is_load_once)
	{	
		if(! LoadOnce())
			printf("������������ɹ�����!\n");
	}
}

void TexManager::SetLoadMode(bool load_once)
{
	is_load_once = load_once;
}

HTEXTURE TexManager::GetTexture(int tid)
{
	if(AssertExist(tid))
		return tex_map[tid];
	else
		return NULL;
}

const char* TexManager::GetInfo(int tid)
{
	if(AssertExist(tid))
		return info_map[tid];
	else
		return NULL;
}

bool TexManager::AssertExist(int tid)
{
	bool res = ( tex_map.find(tid) != tex_map.end() );
	if(res)
	{
		return true;
	}else
	{
		if (is_load_once)
		{
			printf("���Ϊ[ %d ]����������!\n", tid);
			return false;
		}else
		{
			return TryAddTexture(tid);
		}
	}
}

bool TexManager::TryAddTexture(int tid)
{
	lua_getglobal(L, "GetTex");
	lua_pushinteger(L, tid);
	if (lua_pcall(L, 1, 2, 0) )
	{
		printf(" ���Ե��ýű����� GetTex ����!\n");
		return false;
	}
	bool res = lua_isnil(L, -2);
	if ( ! res)
	{
		const char* path = lua_tostring(L, -2);
		const char* info = lua_isnil(L, -1) ? "None" : lua_tostring(L, -1);
		printf("�������� %s , %s\n", path, info);
		HTEXTURE tex = hge->Texture_Load(path);
		tex_map[tid] = tex;
		info_map[tid] = info;
	}else
	{
		printf("��̬����ʧ��, ���Ϊ[ %d ]����������!\n", tid);
	}
	lua_pop(L, 2);	
	return res;
}

bool TexManager::LoadOnce()
{
	return false;
}