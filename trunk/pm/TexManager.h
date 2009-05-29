#pragma once

#include <hge.h>
#include <lua.hpp>
#include <map>

// typedef
typedef std::map<int, HTEXTURE> TexMap;
typedef std::map<int, const char* > StrMap;

// help function


// class def
class TexManager
{
	TexMap tex_map;
	StrMap info_map;
	bool is_load_once; //һ������������
	bool AssertExist(int tid); //�ж������Ƿ���map��, ��������ڲ��� is_load_once Ϊ flase, ��������
	bool TryAddTexture(int tid); //����������Ϊtid������
	bool LoadOnce(); //����һ��������
	// ״̬
	lua_State *L;
public:
	TexManager(void);
	void Init(const char* srcipt_path);
	~TexManager(void);
	void SetLoadMode(bool load_once); //�������뷽ʽ
	HTEXTURE GetTexture(int tid);
	const char* GetInfo(int tid);
};
