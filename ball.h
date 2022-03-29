
#ifndef _BALL_H_
#define _BALL_H_

#include"main.h"

#define	MAX_BALL	(4096)
#define	MAX_RECIPE	(5)

//�\����
typedef struct
{
	D3DXVECTOR3 pos;	//�ʒu
	D3DXVECTOR3 move;	//�ړ���
	int nLife;			//����
	bool bUse;		//�g�p���Ă邩�ǂ���
	int Trigger;   //���
	int nType;
	float fSiz; //�T�C�Y
	int Move2;
	bool moveset;
	bool moveOn;

}Ball;

//�v���g�^�C�v�錾
void InitBall(void);
void UninitBall(void);
void UpdateBall(void);
void DrawBall(void);
void SetBall(D3DXVECTOR3 pos,int nLife, int nType, float fSiz);
void MoveBall(D3DXVECTOR3 move);

#endif #pragma once
