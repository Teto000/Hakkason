bullet.h
�A�N�Z�X�ł��郆�[�U�[

��
��
��
�V�X�e�� �v���p�e�B
���
�e�L�X�g
#ifndef _BULL_H_
#define _BULL_H_

#include"main.h"

#define	MAX_BULL	(4096)
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
}Bull;

//�v���g�^�C�v�錾
void InitBall(void);
void UninitBall(void);
void UpdateBall(void);
void DrawBall(void);
void SetBall(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, int nType, float fSiz);

#endif #pragma once
