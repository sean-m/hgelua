#ifndef _MAINHEADER
#define _MAINHEADER

#include "winmain.h"
#include "mymath.h"
#include "RigidBody2D.h"


#define	_RENDER_FRAME_COUNT		330


void	UpdateSimulation(void);
bool	Initialize(void);
void	DrawCraft(RigidBody2D	craft, COLORREF clr);
void	DoCraft2Chase(void);
void	DoCraft2Evade(void);
void	DoCraft2Intercept(void);

int		GetRandomNumber(int min, int max, bool seed=false);
Vector	GetVelocityIntersection(void);
void	DoCraft2ModulateThrust(void);

void	DoCraft2InterceptAlt(void);

//����-��˹�ƣ�Lennard-Jones potential function, �ֳ�L-J���ܺ�����6-12���ܺ�����
//�Ǽ��㻯ѧ������ģ�������Ӽ��������ܵ�һ��������
// ���以�������������ڿ���ʱ���ֳ�ͻȻ�뿪
void	DoAttractCraft2(void);

#endif