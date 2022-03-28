//================================
//
// �^�C�g����ʂ̃w�b�_�[
// Author:Teruto Sato
//
//================================
#ifndef _TITLE_H_		//���̃}�N������`����ĂȂ�������
#define _TITLE_H_		//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h" 

//�^�C�g���\���̂̒�`
typedef struct
{
	D3DXVECTOR3 pos;	//�ʒu
	D3DXCOLOR col;		//�F
	float fWidth;		//��
	float fHeight;		//����
	bool bUse;
}Title;

//�v���g�^�C�v�錾
void InitTitle(void);
void UninitTitle(void);
void UpdateTitle(void);
void DrawTitle(void);
void SetTitleBG(void);

#endif