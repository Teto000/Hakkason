//============================
//
// �G�̃w�b�_�[
// Author:Teruto Sato
//
//============================
#ifndef _ENEMY_H_		//���̃}�N������`����ĂȂ�������
#define _ENEMY_H_		//2�d�C���N���[�h�h�~�̃}�N����`

//------------------------
// �C���N���[�h
//------------------------
#include "main.h"

//------------------------
// �G�̍\���̂̒�`
//------------------------
typedef struct
{
	D3DXVECTOR3 pos;	//�ʒu
	D3DXVECTOR3 move;	//�ړ���
	D3DXVECTOR3 rot;	//����
	int nPlace;			//�o���ʒu
	float fWidth;		//��
	float fHeight;		//����
	bool bUse;			//�g�p���Ă��邩
}Enemy;

//------------------------
// �v���g�^�C�v�錾
//------------------------
void InitEnemy(void);
void UninitEnemy(void);
void UpdateEnemy(void);
void DrawEnemy(void);
void SetEnemy(void);
Enemy *GetEnemy(void);

#endif