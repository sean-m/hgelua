#pragma once



class TexManager
{
	ResMap tex_map;
	StrMap info_map;
	bool is_load_once; //һ������������
	bool AssertExist(int tid); //�ж������Ƿ���map��, ��������ڲ��� is_load_once Ϊ flase, ��������
	bool TryAddTexture(int tid); //����������Ϊtid������
	void LoadOnce(); //����һ��������
	// ״̬
	lua_State *L;
public:
	TexManager(void);
	void Init(const char* srcipt_path);
	void CleanUp();
	void SetLoadMode(bool load_once); //�������뷽ʽ
	HTEXTURE GetTexture(int tid);
	const char* GetInfo(int tid);
};
