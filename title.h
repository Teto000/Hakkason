//============================
//
// �^�C�g����ʂ̃w�b�_�[
// Author:hamada ryuuga
//
//============================
#pragma once
#ifndef _TITLE_H_
#define _TITLE_H_

#include"main.h"

#define	MAX_TITLE	(8)

typedef struct
{
	D3DXCOLOR col;		//�F
	D3DXCOLOR colSet;	//�����ق��̐F
	bool nSwitch;		//�X�C�b�`
	int nSelect;		//�����N�g
	int degree;			//��Փx
}TITLE;

//�v���g�^�C�v�錾
void InitTitle(void);
void UninitTitle(void);
void UpdateTitle(void);
void DrawTitle(void);
int Getdegree(void);


#endif