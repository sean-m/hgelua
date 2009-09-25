#include "StdAfx.h"
#include "SoundManager.h"


extern HGE *hge;


void SoundManager::CleanUp()
{
	for (ResMap::iterator it = sound_map.begin(); it != sound_map.end(); ++it)
	{
		HEFFECT effect = it->second;
		hge->Effect_Free(effect);
	}
}
void SoundManager::Init(const char *srcipt_path)
{
	lua_State *L = lua_open();
	luaL_openlibs(L);

	if (luaL_dofile(L, srcipt_path))
	{
		printf("����ű��������!!\n");
	}
	LoadOnce(L);
	lua_close(L);
}



HEFFECT SoundManager::GetSound(int sid)
{
	if(IsExist(sid))
		return sound_map[sid];
	else
		return NULL;
}

const char* SoundManager::GetInfo(int sid)
{
	if(IsExist(sid))
		return info_map[sid];
	else
		return NULL;
}

bool SoundManager::IsExist(int sid)
{
	bool res = ( sound_map.find(sid) != sound_map.end() );
	if(res)
	{
		return true;
	}else
	{
		printf("���Ϊ[ %d ]������������!\n", sid);
		return false;
	}
}


void SoundManager::LoadOnce(lua_State *L)
{
	lua_getglobal(L, "Iter");
	if (lua_pcall(L, 0, 3, 0) )
	{
		printf(" ���Ե��ýű����� Iter ����!\n");
	}
	bool suc = !lua_isnil(L, -3);

	while(suc)
	{
		int tid = lua_tointeger(L, -3);
		const char* path = lua_tostring(L, -2);
		const char* info = lua_isnil(L, -1) ? "None" : lua_tostring(L, -1);
		HEFFECT sound = hge->Effect_Load(path);
		if(sound==NULL){
			printf("��������ʧ�� %s , %s\n", path, info);
		}else{
			sound_map[tid] = sound;
			info_map[tid] = info;
			printf("�������� %s , %s\n", path, info);
		}
		lua_pop(L, 3);
		lua_getglobal(L, "Iter");
		lua_pcall(L, 0, 3, 0);
		suc = !lua_isnil(L, -3);
	}
}