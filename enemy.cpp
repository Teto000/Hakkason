//============================
//
// �G�̏���
// Author:Teruto Sato
//
//============================

//------------------------
// �C���N���[�h
//------------------------
#include "enemy.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"
#include "texture.h"

//------------------------
// �}�N����`
//------------------------
#define	MAX_ENEMY	(256)	//�G�̍ő吔

//------------------------
// �X�^�e�B�b�N�ϐ�
//------------------------
static	TEXTURE		s_pTexture;		//�e�N�X�`���ւ̃|�C���^
static	LPDIRECT3DVERTEXBUFFER9		s_pVtxBuff = NULL;		//���_�o�b�t�@�ւ̃|�C���^

//�\����
static	Enemy s_Enemy[MAX_ENEMY];	//�G�̍\����

//========================
// �G�̏���������
//========================
void InitEnemy(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//�f�o�C�X�̎擾

	//------------------------
	// �e�N�X�`���̓ǂݍ���
	//------------------------
	s_pTexture = TEXTURE_RESULT_BG;

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,	//�m�ۂ���o�b�t�@�̃T�C�Y
								D3DUSAGE_WRITEONLY,
								FVF_VERTEX_2D,			//���_�t�H�[�}�b�g
								D3DPOOL_MANAGED,
								&s_pVtxBuff,
								NULL);

	VERTEX_2D*pVtx;		//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	s_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//------------------------
	// �G�̍\���̂̏�����
	//------------------------
	for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	{
		Enemy *enemy = s_Enemy + nCnt;

		enemy->pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//�ʒu
		enemy->fWidth = 0.0f;	//��
		enemy->fHeight = 0.0f;	//����
		enemy->bUse = false;	//�g�p���Ă��邩
	}

	//------------------------
	// ���_���̐ݒ�
	//------------------------
	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDTH, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f);

	//rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//�T�E���h�̍Đ�
	//PlaySound(SOUND_LABEL_BGM002);

	//���_�o�b�t�@���A�����b�N����
	s_pVtxBuff->Unlock();
}

//========================
// �G�̏I������
//========================
void UninitEnemy(void)
{
	//�T�E���h�̒�~
	//StopSound();

	//���_�o�b�t�@�̔j��
	if (s_pVtxBuff != NULL)
	{
		s_pVtxBuff->Release();
		s_pVtxBuff = NULL;
	}
}

//========================
// �G�̍X�V����
//========================
void UpdateEnemy(void)
{

}

//========================
// �G�̕`�揈��
//========================
void DrawEnemy(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//�f�o�C�X�ւ̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, s_pVtxBuff, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, GetTexture(s_pTexture));

	//�v���C���[�̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,		//�v���~�e�B�u�̎��
						   0,						//�`�悷��ŏ��̒��_�C���f�b�N�X
						   2);						//�`�悷��v���~�e�B�u��
}

//========================
// �G�̐ݒ菈��
//========================
void SetEnemy(void)
{
	VERTEX_2D*pVtx;		//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	s_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	{
		Enemy *enemy = s_Enemy + nCnt;

		if (enemy->bUse == false)
		{
			enemy->pos = D3DXVECTOR3(500.0f, 300.0f, 0.0f);		//�ʒu
			enemy->fWidth = 50.0f;	//��
			enemy->fHeight = 50.0f;	//����
			enemy->bUse = true;	//�g�p���Ă��邩

			//���_���W�̐ݒ�
			pVtx[0].pos = enemy->pos + D3DXVECTOR3(-enemy->fWidth, -enemy->fHeight, 0.0f);
			pVtx[1].pos = enemy->pos + D3DXVECTOR3(enemy->fWidth, -enemy->fHeight, 0.0f);
			pVtx[2].pos = enemy->pos + D3DXVECTOR3(-enemy->fWidth, enemy->fHeight, 0.0f);
			pVtx[3].pos = enemy->pos + D3DXVECTOR3(enemy->fWidth, enemy->fHeight, 0.0f);

			break;
		}
		pVtx += 4;
	}

	//���_�o�b�t�@���A�����b�N����
	s_pVtxBuff->Unlock();
}