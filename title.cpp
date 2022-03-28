//================================
//
// �^�C�g�����
// Author:Teruto Sato
//
//================================

//------------------------
// �C���N���[�h
//------------------------
#include "title.h"
#include "tutorial.h"
#include "input.h"
#include "fade.h"
#include "sound.h"
#include "texture.h"

//------------------------
// �}�N����`
//------------------------

//------------------------
// �X�^�e�B�b�N�ϐ�
//------------------------
static TEXTURE	s_pTexture;		//�e�N�X�`���ւ̃|�C���^
static LPDIRECT3DVERTEXBUFFER9	s_pVtxBuff = NULL;	//���_�o�b�t�@�ւ̃|�C���^;

//�\����
static Title s_Title;	//�^�C�g���\����

//========================
// �^�C�g���̏���������
//========================
void InitTitle(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();	//�f�o�C�X�̎擾

	//------------------------
	// �e�N�X�`���̓ǂݍ���
	//------------------------
	s_pTexture = TEXTURE_TITLE_BG;

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,	//�m�ۂ���o�b�t�@�̃T�C�Y
								D3DUSAGE_WRITEONLY,
								FVF_VERTEX_2D,			//���_�t�H�[�}�b�g
								D3DPOOL_MANAGED,
								&s_pVtxBuff,
								NULL);

	//------------------------
	// �^�C�g���\���̂̏�����
	//------------------------
	s_Title.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	s_Title.fWidth = 0.0f;
	s_Title.fHeight = 0.0f;
	s_Title.bUse = false;

	VERTEX_2D*pVtx;		//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	s_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//------------------------
	// ���_���̐ݒ�
	//------------------------
	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

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
	//PlaySound(SOUND_LABEL_BGM001);

	//���_�o�b�t�@���A�����b�N����
	s_pVtxBuff->Unlock();
}

//========================
// �^�C�g���̏I������
//========================
void UninitTitle(void)
{
	//�T�E���h�̒�~
	//StopSound(SOUND_LABEL_SE_NEXT);

	//���_�o�b�t�@�̔j��
	if (s_pVtxBuff != NULL)
	{
		s_pVtxBuff->Release();
		s_pVtxBuff = NULL;
	}
}

//========================
// �^�C�g���̍X�V����
//========================
void UpdateTitle(void)
{
	//��ʑJ��
	if (GetKeyboardTrigger(DIK_RETURN) == true || GetJoypadTrigger(JOYKEY_A))
	{
		SetFade(MODE_GAME);
	}
}

//========================
// �^�C�g���̕`�揈��
//========================
void DrawTitle(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();	//�f�o�C�X�̎擾

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, s_pVtxBuff, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, GetTexture(s_pTexture));

	//�^�C�g���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,		//�v���~�e�B�u�̎��
						   0,						//�`�悷��ŏ��̒��_�C���f�b�N�X
						   2);						//�`�悷��v���~�e�B�u��
}

//========================
// �^�C�g���w�i�̐ݒ�
//========================
void SetTitleBG(void)
{
	VERTEX_2D*pVtx;		//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	s_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	if (s_Title.bUse == false)
	{//�g�p���Ă��Ȃ��Ȃ�
		//�\���̂̐ݒ�
		s_Title.pos = D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f);
		s_Title.col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		s_Title.fWidth = SCREEN_WIDTH / 2;
		s_Title.fHeight = SCREEN_HEIGHT / 2;
		s_Title.bUse = true;

		//���_���W�̐ݒ�
		pVtx[0].pos = s_Title.pos + D3DXVECTOR3(-s_Title.fWidth, -s_Title.fHeight, 0.0f);
		pVtx[1].pos = s_Title.pos + D3DXVECTOR3(s_Title.fWidth, -s_Title.fHeight, 0.0f);
		pVtx[2].pos = s_Title.pos + D3DXVECTOR3(-s_Title.fWidth, s_Title.fHeight, 0.0f);
		pVtx[3].pos = s_Title.pos + D3DXVECTOR3(s_Title.fWidth, s_Title.fHeight, 0.0f);
	}

	//���_�o�b�t�@���A�����b�N����
	s_pVtxBuff->Unlock();
}