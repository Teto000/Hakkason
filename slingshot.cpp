//====================
//�R�C���l������
//autho�@hamadaryuuga 
//====================

#include "game.h"
#include "slingshot.h"
#include "input.h"

static LPDIRECT3DTEXTURE9 s_pTextureSlingshotleft = NULL; //�e�N�X�`���̃|�C���^
static LPDIRECT3DVERTEXBUFFER9 s_pVtxBuffSlingshotleft = NULL; //���_�o�b�t�@�̐ݒ�

static LPDIRECT3DTEXTURE9 s_pTextureSlingshotlight = NULL; //�e�N�X�`���̃|�C���^
static LPDIRECT3DVERTEXBUFFER9 s_pVtxBuffSlingshotlight = NULL; //���_�o�b�t�@�̐ݒ�

static D3DXVECTOR3 s_posSlingshot; //�X�R�A�̈ʒu
static int s_nSlingshot, nCounterAnim, nPatternAnim;


//===================
//����������
//===================
void InitSlingshot(void)
{

	LPDIRECT3DDEVICE9  pDevice;
	//int nCntSlingshot;
	//s_nSlingshot = 0;
	s_posSlingshot = D3DXVECTOR3(320.0f, 650.0f, 0.0f);
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/pipo-gwspinitem007.png",
		&s_pTextureSlingshotleft);

	//���_�o�b�t�@
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,//�������_�t�H�[�}�b�g
		&s_pVtxBuffSlingshotleft,
		NULL);

	VERTEX_2D*pVtx; //���_�ւ̃|�C���^
					//���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
	s_pVtxBuffSlingshotleft->Lock(0, 0, (void**)&pVtx, 0);
	//���_���W
	pVtx[0].pos = D3DXVECTOR3(s_posSlingshot.x - 20, s_posSlingshot.y - 20, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(s_posSlingshot.x + 20, s_posSlingshot.y - 20, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(s_posSlingshot.x - 20, s_posSlingshot.y + 20, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(s_posSlingshot.x + 20, s_posSlingshot.y + 20, 0.0f);
	
	//RHW�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//�e�N�X�`���̍��W�ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N
	s_pVtxBuffSlingshotleft->Unlock();


	//---------------------
	//�݂��̐ݒ�
	//---------------------
	s_posSlingshot = D3DXVECTOR3(720.0f, 650.0f, 0.0f);
	
	pDevice = GetDevice();

	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/pipo-gwspinitem007.png",
		&s_pTextureSlingshotlight);

	//���_�o�b�t�@
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,//�������_�t�H�[�}�b�g
		&s_pVtxBuffSlingshotlight,
		NULL);

	//VERTEX_2D*pVtx; //���_�ւ̃|�C���^
					//���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
	s_pVtxBuffSlingshotlight->Lock(0, 0, (void**)&pVtx, 0);
	//���_���W
	pVtx[0].pos = D3DXVECTOR3(s_posSlingshot.x - 20, s_posSlingshot.y - 20, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(s_posSlingshot.x + 20, s_posSlingshot.y - 20, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(s_posSlingshot.x - 20, s_posSlingshot.y + 20, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(s_posSlingshot.x + 20, s_posSlingshot.y + 20, 0.0f);
	
	//RHW�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//�e�N�X�`���̍��W�ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N
	s_pVtxBuffSlingshotlight->Unlock();

	

}

//===================
//�j������
//===================
void UninitSlingshot(void)
{
	//�e�N�X�`���̔j��
	if (s_pTextureSlingshotleft != NULL)
	{
		s_pTextureSlingshotleft->Release();
		s_pTextureSlingshotleft = NULL;
	}

	//���_�o�b�t�@�̔j��
	if (s_pVtxBuffSlingshotleft != NULL)
	{
		s_pVtxBuffSlingshotleft->Release();
		s_pVtxBuffSlingshotleft = NULL;
	}

	//�e�N�X�`���̔j��
	if (s_pTextureSlingshotlight != NULL)
	{
		s_pTextureSlingshotlight->Release();
		s_pTextureSlingshotlight = NULL;
	}

	//���_�o�b�t�@�̔j��
	if (s_pVtxBuffSlingshotlight != NULL)
	{
		s_pVtxBuffSlingshotlight->Release();
		s_pVtxBuffSlingshotlight = NULL;
	}


}

//===================
//�X�V����
//===================
void UpdateSlingshot(void)
{
	if (GetMousePress(MOUSE_INPUT_LEFT))
	{

	}
	if (GetMouseTrigger(MOUSE_INPUT_LEFT))
	{

	}

	VERTEX_2D*pVtx; //���_�ւ̃|�C���^
					//���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
	s_pVtxBuffSlingshotleft->Lock(0, 0, (void**)&pVtx, 0);
	//���_���W
	pVtx[0].pos = D3DXVECTOR3(s_posSlingshot.x - 20, s_posSlingshot.y - 20, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(s_posSlingshot.x + 20, s_posSlingshot.y - 20, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(s_posSlingshot.x - 20, s_posSlingshot.y + 20, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(s_posSlingshot.x + 20, s_posSlingshot.y + 20, 0.0f);

	//���_�o�b�t�@���A�����b�N
	s_pVtxBuffSlingshotleft->Unlock();
}

//===================
//�`�揈��
//===================
void DrawSlingshot(void)
{
	LPDIRECT3DDEVICE9 pDevice;//�f�o�C�X�̃|�C���^
//	int nCntSlingshot;


	pDevice = GetDevice();		//���

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, s_pVtxBuffSlingshotleft, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, s_pTextureSlingshotleft);

	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,
		0,
		2);

	//---------------------
	//�݂��̐ݒ�
	//---------------------
	pDevice = GetDevice();		//���

								//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, s_pVtxBuffSlingshotlight, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, s_pTextureSlingshotlight);

	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,
		0,
		2);

}

