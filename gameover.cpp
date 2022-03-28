//==================
//�Q�[���I�[�o�[����
//
//autho hamadaryuuga
//==================
#include "gameover.h"
#include "input.h"
#include "sound.h"
#include "fade.h"
#include "score.h"

#define	NUR_GOV (2)
#define SIZ_BG (0.041666666f)//�w�i�T�C�Y

//�X�^�e�B�b�N�֐�
static LPDIRECT3DTEXTURE9 s_pTextureGameover[NUR_GOV] = {}; //�e�N�X�`���̃|�C���^
static LPDIRECT3DVERTEXBUFFER9 s_pVtxBuffGameover = NULL; //���_�o�b�t�@�̐ݒ�
static int s_taim;
static int s_CounterAnim;
static int s_PatternAnim;

//===================
//����������
//===================
void InitGameover(void)
{	
	//�X�R�A������
	InitScore();

	LPDIRECT3DDEVICE9  pDevice;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/�Q�[���I�[�o�[.jpg",
		&s_pTextureGameover[0]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/GAME.png",
		&s_pTextureGameover[1]);

	//���_�o�b�t�@
	pDevice->CreateVertexBuffer(
		sizeof(VERTEX_2D) * 4* NUR_GOV,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,//�������_�t�H�[�}�b�g
		&s_pVtxBuffGameover,
		NULL);


	VERTEX_2D*pVtx; //���_�ւ̃|�C���^

	//���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
	s_pVtxBuffGameover->Lock(0, 0, (void**)&pVtx, 0);

	for (int i = 0; i < NUR_GOV; i++)
	{
		if (i == 1)
		{
			//���_���W
			SetNorotpos(pVtx,
				0.0f,
				SCREEN_WIDTH,
				0.0f,
				SCREEN_HEIGHT);

			//RHW�̐ݒ�
			pVtx[0].rhw = 1.0f;
			pVtx[1].rhw = 1.0f;
			pVtx[2].rhw = 1.0f;
			pVtx[3].rhw = 1.0f;

			//���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			//�e�N�X�`���̍��W�ݒ�
			Settex(pVtx, 0.0f, 1.0f, 0.0f, 1.0f);
		}
		else if (i == 2)
		{
			//���_���W
			SetNorotpos(pVtx,
				400.0f,
				800.0f,
				200.0f,
				SCREEN_HEIGHT);


			//RHW�̐ݒ�
			pVtx[0].rhw = 1.0f;
			pVtx[1].rhw = 1.0f;
			pVtx[2].rhw = 1.0f;
			pVtx[3].rhw = 1.0f;

			//���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			//�e�N�X�`���̍��W�ݒ�
			Settex(pVtx, 0.0f, 1.0f, 0.0f, 1.0f);
			
		}
		else
		{
		
			//���_���W
			SetNorotpos(pVtx,
				0.0f,
				SCREEN_WIDTH,
				0.0f,
				SCREEN_HEIGHT);

			//RHW�̐ݒ�
			pVtx[0].rhw = 1.0f;
			pVtx[1].rhw = 1.0f;
			pVtx[2].rhw = 1.0f;
			pVtx[3].rhw = 1.0f;

			//���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			//�e�N�X�`���̍��W�ݒ�
			Settex(pVtx, 0.0f, 1.0f, 0.0f, 1.0f);
			
		}
		pVtx += 4; //���_�|�C���g���l�i��
	}
	int pScore;
	pScore = GetScore();
	SetScore(pScore);
	
	//�T�E���h�J�n
	PlaySound(SOUND_LABEL_BGM003);

	//���_�o�b�t�@���A�����b�N
	s_pVtxBuffGameover->Unlock();
}

//===================
//�j������
//===================
void UninitGameover(void)
{
	//�T�E���h��~
	StopSound();

	//�X�R�A�j��
	UninitScore();
	//�e�N�X�`���̔j��
	for (int i = 0; i < NUR_GOV; i++)
	{
		if (s_pTextureGameover[i] != NULL)
		{
			s_pTextureGameover[i]->Release();
			s_pTextureGameover[i] = NULL;
		}
	}
	
	//���_�o�b�t�@�̔j��

	if (s_pVtxBuffGameover != NULL)
	{
		s_pVtxBuffGameover->Release();
		s_pVtxBuffGameover = NULL;
	}
}

//===================
//�X�V����
//===================
void UpdateGameover(void)
{
	//�X�R�A�X�V
	UpdateScore();
	s_taim++;
	if (s_taim == 1200)
	{
		SetFade(MODE_RANKING);
	}

	FADE pFade;
	pFade = GetFade();

	if ((GetKeyboardTrigger(DIK_RETURN) ||
		GetKeyboardTrigger(JOYKEY_START)) && pFade == FADE_NONE)
	{//�G���^�[�������ꂽ�Ƃ�
		SetFade(MODE_RANKING);
	}

	VERTEX_2D*pVtx; //���_�ւ̃|�C���^
	//���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
	s_pVtxBuffGameover->Lock(0, 0, (void**)&pVtx, 0);


	for (int i = 0; i < NUR_GOV; i++)
	{
		if (i == 2)
		{

			//���_���W
			SetNorotpos(pVtx,
				400.0f,
				800.0f,
				500.0f,
				SCREEN_HEIGHT);

			//RHW�̐ݒ�
			pVtx[0].rhw = 1.0f;
			pVtx[1].rhw = 1.0f;
			pVtx[2].rhw = 1.0f;
			pVtx[3].rhw = 1.0f;

			//���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		}
		else
		{
			//���_���W
			SetNorotpos(pVtx,
				0.0f,
				SCREEN_WIDTH,
				0.0f,
				SCREEN_HEIGHT);


			//RHW�̐ݒ�
			pVtx[0].rhw = 1.0f;
			pVtx[1].rhw = 1.0f;
			pVtx[2].rhw = 1.0f;
			pVtx[3].rhw = 1.0f;

			//���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);



		}
		pVtx += 4; //���_�|�C���g���l�i��
	}
	//���_�o�b�t�@���A�����b�N
	s_pVtxBuffGameover->Unlock();
}

//===================
//�`�揈��
//===================
void DrawGameover(void)
{
	LPDIRECT3DDEVICE9 pDevice;//�f�o�C�X�̃|�C���^

	pDevice = GetDevice(); //���

						   //���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, s_pVtxBuffGameover, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (int i = 0; i < NUR_GOV; i++)
	{
		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, s_pTextureGameover[i]);

		//�|���S���̕`�� �l�p
		pDevice->DrawPrimitive(
			D3DPT_TRIANGLESTRIP,		//�v���~�e�B�u�̎��
			i*4,			//�`�悷��ŏ��̒��_�C���f�b�N�X
			2);							//�v���~�e�B�u(�|���S��)��
	}
	//�X�R�A�̕`�揈��
	DrawScore();
}