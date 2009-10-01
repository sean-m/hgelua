#ifndef _RIGIDBODY2DHEADER
#define _RIGIDBODY2DHEADER

#include "mymath.h"

#define	 _THRUSTFORCE				20.0f/2
#define	 _MAXTHRUST					80.0f/2
#define	 _MINTHRUST					0.0f
#define	 _DTHRUST					0.01f
#define  _STEERINGFORCE				6.0f
#define  _LINEARDRAGCOEFFICIENT		0.3f
#define  _ANGULARDRAGCOEFFICIENT	5000.0f
#define _DEFAULT 0xfefefefe // default value
#define _DRAWHEIGHT 5.0f  // z index for draw

//------------------------------------------------------------------------//
// Rigid body structure (2D only)
//------------------------------------------------------------------------//
class RigidBody2D {
public:
	float	fMass;				// total mass (constant), ����,�����ǹ��Ե�����
	float	fInertia;			// mass moment of inertia in body coordinates (constant), ת������
	
	Vector	vPosition;			// position in earth coordinates, λ��
	Vector	vVelocity;			// velocity in earth coordinates, �ٶ�-��������
	Vector	vVelocityBody;		// velocity in body coordinates, �ٶ�-�������� 
	Vector	vAngularVelocity;	// angular velocity in body coordinates, ���ٶ�
		
	float	fSpeed;				// speed (magnitude of the velocity), �ٶȴ�С
	float	fOrientation;		// orientation , �Ƕ�	

	Vector	vForces;			// total force on body �������������ٶ�
	Vector	vMoment;			// total moment (torque) on body (2D: about z-axis only) ����,�����Ǽ��ٶ�

	float	ThrustForce;		// Magnitude of the thrust force, ������С
	Vector	PThrust, SThrust;	// bow thruster forces, ����Ť��

	// ��״���
	float	fWidth;				// bounding dimensions
	float	fLength;
	float	ProjectedArea;

	Vector	CD; // ��������ϵ����
	Vector	CT; // �������ڵ�
	Vector	CPT;// PŤ�����ڵ�
	Vector	CST;// SŤ�����ڵ�

	Vector	Fa;// other applied force
	Vector  Pa;// location of other applied force

	//Vector	vCollisionPoint;	// point of impact in local coordinates	

	RigidBody2D(void);
	void	CalcLoads(void);
	void	UpdateBodyEuler(double dt);
	void	SetThrusters(bool p, bool s);
	void	ModulateThrust(bool up);
	void	CrossBound(float w, float h);

	void	SetMass(float mass, float inertia=_DEFAULT);
	void	SetProjected(float w, float l); // draw shape
	void	SetPosistion(float x, float y, float ori);
};

Vector	VRotate2D( float angle, Vector u);

#endif
