#pragma once

class SoundManager
{
	ResMap sound_map;
	StrMap info_map;
	IntMap width_map, hight_map, left_map, top_map;
	bool IsExist(int sid); //�ж������Ƿ���map��
	void LoadOnce(lua_State *L); //����һ��������
public:
	void Init(const char* srcipt_path);
	void CleanUp();
	HEFFECT GetSound(int sid);
	HCHANNEL PlaySound(int sid);
	const char* GetInfo(int sid);
};
