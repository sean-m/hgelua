
local folder = "sound/mp3"
local datas = 
{
	[ 1000 ] = { "0.mid", "����,����"},
	[ 1001 ] = { "1.mid" , "����,������"},
	[ 1002 ] = { "2.mid" , "����,С����"},
	[ 1003 ] = { "3.mid" , "��������, ����"},
	[ 1004 ] = { "4.mid" , "����"},
	[ 1005 ] = { "5.mid" , "ϰ�ü���"},
	[ 1006 ] = { "6.mid" , "ս��ʤ��1"},
	[ 1007 ] = { "7.mid" , "ս��ʤ��2"},
	[ 1008 ] = { "8.mid" , "ս��ʤ��3"},
	[ 1009 ] = { "9.mid" , "ս��ʤ��4"},
	[ 1010 ] = { "10.mid" , "����"},
	[ 1011 ] = { "11.mid" , "����"},
	[ 1012 ] = { "12.mid" , "ս��bgm1"},
	[ 1013 ] = { "13.mid" , "ս��bgm2"},
	[ 1014 ] = { "14.mid" , "����bgm"},
	[ 1015 ] = { "15.mid" , "�������1"},
	[ 1016 ] = { "16.mid" , "�������2"},
	[ 1017 ] = { "17.mid" , "�����˷���,��ս1"},
	[ 1018 ] = { "18.mid" , "�����˷���,��ս2"},
	[ 1019 ] = { "19.mid" , "������ȥ�ι�, ����"},
	[ 1020 ] = { "20.mid" , ""},
	[ 1021 ] = { "21.mid" , "����, ��Ѩ"},
	[ 1022 ] = { "22.mid" , "����, ����֮·"},
	[ 1023 ] = { "23.mid" , "����, ������"},
	[ 1024 ] = { "24.mid" , "��ս����"},
	[ 1025 ] = { "25.mid" , "����,��·"},
	[ 1099 ] = { "0.mid" , ""},
	[ 1099 ] = { "0.mid" , ""},
	[ 1099 ] = { "0.mid" , ""},
	[ 1099 ] = { "0.mid" , ""},
	[ 1099 ] = { "0.mid" , ""},
	[ 1099 ] = { "0.mid" , ""},
	[ 2054 ] = { "54.mp3" , ""},
}
------------------------------------------------
for k, v in pairs(datas) do
	datas[k][1] = folder.."/"..v[1]
end

local index = nil


function GetData(tid)
	if datas[tid] then
		return datas[tid][1], datas[tid][2]
	else
		return 
	end
end

function Iter()
	local path, info
	index, res = next(datas, index)
	if res == nil then return end
	return index,res[1], res[2]
end

function Test()

	local i,p,info = Iter()
	while i do
		print(i,p,info)
		i,p,info = Iter()
	end
end
