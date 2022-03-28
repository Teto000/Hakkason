//===================
//�`���[�g���A��
//autho hamada ryuuga
//===================
#include"tutorial.h"
#include "input.h"
#include "sound.h"
#include"fade.h"

//�摜�̐�
#define NUM_TUTORIAL (3)

//�O���[�o���֐�
static LPDIRECT3DTEXTURE9 s_pTextureTutorial[NUM_TUTORIAL] = {}; //�e�N�X�`���̃|�C���^
static LPDIRECT3DVERTEXBUFFER9 s_pVtxBuffTutorial = NULL; //���_�o�b�t�@�̐ݒ�
static D3DXVECTOR3 s_moveTutorial;	//�ړ���
static D3DCOLOR s_moveColTutorial;	//�F�ړ���
static D3DXVECTOR3 s_posTutorial[NUM_TUTORIAL];	//���W
static D3DCOLOR s_colTutorial[NUM_TUTORIAL];
static int s_TimeTutorial;
static bool s_TimeTutorialCut;
static int gamemode;

//================
//����������
//================
void InitTutorial(void)
{
	LPDIRECT3DDEVICE9  pDevice;
	s_moveTutorial = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//�f�o�C�X�̎擾
	pDevice = GetDevice();
	gamemode = 0;

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/�`���[�g���A��.jpg",
		&s_pTextureTutorial[0]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/�`���[�g���A���Q.jpg",
		&s_pTextureTutorial[1]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/Title002.png",
		&s_pTextureTutorial[2]);



	//���_�o�b�t�@
	pDevice->CreateVertexBuffer(
		sizeof(VERTEX_2D) * 4 * NUM_TUTORIAL,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,//�������_�t�H�[�}�b�g
		&s_pVtxBuffTutorial,
		NULL);
	//���Ԃ̂��
	s_TimeTutorial = 0;
	s_TimeTutorialCut = false;
	VERTEX_2D*pVtx; //���_�ւ̃|�C���^
	s_posTutorial[0] = D3DXVECTOR3(0.0, 0.0, 0.0);
	s_posTutorial[1] = D3DXVECTOR3(0.0, 0.0, 0.0);

	s_colTutorial[0] = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	s_colTutorial[1] = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	//���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
	s_pVtxBuffTutorial->Lock(0, 0, (void**)&pVtx, 0);

		
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
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);;
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);;
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);;
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);;

	
		//�e�N�X�`���̍��W�ݒ�
		Settex(pVtx, 0.0f, 1.0f, 0.0f, 1.0f);

		//���_���W
		pVtx[4].pos = D3DXVECTOR3(840.0f, 0.0f, 0.0f);
		pVtx[5].pos = D3DXVECTOR3(940.0f, 0.0f, 0.0f);
		pVtx[6].pos = D3DXVECTOR3(840.0f, 940.0f, 0.0f);
		pVtx[7].pos = D3DXVECTOR3(940.0f, 940.0f, 0.0f);
		
		//RHW�̐ݒ�
		pVtx[4].rhw = 1.0f;
		pVtx[5].rhw = 1.0f;
		pVtx[6].rhw = 1.0f;
		pVtx[7].rhw = 1.0f;
		
		//���_�J���[�̐ݒ�
		pVtx[4].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[5].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[6].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[7].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		
		//�e�N�X�`���̍��W�ݒ�
		
		//�e�N�X�`���̍��W�ݒ�
		Settex(pVtx, 0.0f, 1.0f, 0.0f, 1.0f);


	//�T�E���h�J�n
	//PlaySound(SOUND_LABEL_BGM005);
	//���_�o�b�t�@���A�����b�N
	s_pVtxBuffTutorial->Unlock();

}

//�j��
void UninitTutorial(void)
{
	//�T�E���h��~
	StopSound();
	int nCnt;
	//�e�N�X�`���̔j��
	for (nCnt = 0; nCnt < NUM_TUTORIAL; nCnt++)
	{
		if (s_pTextureTutorial[nCnt] != NULL)
		{
			s_pTextureTutorial[nCnt]->Release();
			s_pTextureTutorial[nCnt] = NULL;
		}
		//���_�o�b�t�@�̔j��

		if (s_pVtxBuffTutorial != NULL)
		{
			s_pVtxBuffTutorial->Release();
			s_pVtxBuffTutorial = NULL;
		}


	}
}
//==================
//�X�V����
//==================
void UpdateTutorial(void)
{
	int nCnt;

	VERTEX_2D*pVtx; //���_�ւ̃|�C���^
					//���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
	s_pVtxBuffTutorial->Lock(0, 0, (void**)&pVtx, 0);

	//�����������������鏈��
	s_TimeTutorial++;
	if (s_TimeTutorial == 1)
	{
		s_TimeTutorialCut = false;
	}
	if (s_TimeTutorial == 31)
	{
		s_TimeTutorialCut = true;
	}
	if (s_TimeTutorial == 61)
	{
		s_TimeTutorial = 0;

	}
	if (s_TimeTutorialCut == false)
	{
		s_colTutorial[1] = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	}
	if (s_TimeTutorialCut == true)
	{
		s_colTutorial[1] = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
	}

	for (nCnt = 0; nCnt < NUM_TUTORIAL-1; nCnt++)
	{
		s_posTutorial[nCnt] += s_moveTutorial;
		s_colTutorial[nCnt] += s_moveColTutorial;
		//�e�N�X�`���̍��W�ݒ�
		Settex(pVtx, 0.0f + s_posTutorial[nCnt].x, 1.0f + s_posTutorial[nCnt].x, 0.0f + s_posTutorial[nCnt].y, 1.0f + s_posTutorial[nCnt].y);

	
		//�ړ��ʂ��X�V(����������)
		s_moveTutorial.x += (0.0f - s_moveTutorial.x)*0.5f;//�i�ړI�̒l-���݂̒l�j�������W��
		s_moveTutorial.y += (0.0f - s_moveTutorial.y)*0.5f;
		if (nCnt == 1)
		{
		
			SetNorotpos(pVtx,
				700.0f - s_posTutorial[1].x,
				1280.0f + s_posTutorial[1].x,
				400.0f - s_posTutorial[1].y,
				820.0f + s_posTutorial[1].y);
			pVtx[0].col=s_colTutorial[1];
			pVtx[1].col=s_colTutorial[1];
			pVtx[2].col=s_colTutorial[1];
			pVtx[3].col=s_colTutorial[1];

		}

		pVtx += 4;
	}
	//���_�o�b�t�@���A�����b�N
	s_pVtxBuffTutorial->Unlock();

	FADE pFade;
	pFade = GetFade();
	if ((GetKeyboardTrigger(DIK_RETURN) == true  ||
		GetKeyboardTrigger(JOYKEY_START) == true) && pFade == FADE_NONE)
	{//�G���^�[�������ꂽ�Ƃ�
		if (gamemode == 1)
		{
			SetFade(MODE_TITLE);
		
		}
		if (gamemode == 0)
		{
			gamemode++;
		}
		
	 //�T�E���h��~
		//StopSound(SOUND_LABEL_BGM005);
		//PlaySound(SOUND_LABEL_SE_PIANO);
		
	}
}
//==================
//�`�揈��
//==================
void DrawTutorial(void)
{
	int nCnt;

	LPDIRECT3DDEVICE9 pDevice;//�f�o�C�X�̃|�C���^

	pDevice = GetDevice(); //���

						   //���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, s_pVtxBuffTutorial, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);


	//�e�N�X�`���̕`��
	for (nCnt = 0; nCnt < NUM_TUTORIAL-1; ++nCnt)
	{
		if (gamemode == 0)
		{
			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, s_pTextureTutorial[nCnt*2]);

		}
		if (gamemode == 1)
		{
			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, s_pTextureTutorial[nCnt+1]);

		}
		

		//�|���S���̕`�� �l�p
		pDevice->DrawPrimitive(
			D3DPT_TRIANGLESTRIP,		//�v���~�e�B�u�̎��
			nCnt * 4,			//�`�悷��ŏ��̒��_�C���f�b�N�X
			2);							//�v���~�e�B�u(�|���S��)��
	}
}
