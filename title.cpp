//====================
//�^�C�g��
//autho�@hamadaryuuga
//====================
#include "title.h"
#include "input.h"
//#include "sound.h"
#include "fade.h"
//#include "particle.h"

//�摜�̐�
#define NUM_TITLE (9)

//�X�^�e�B�b�N
static LPDIRECT3DTEXTURE9 s_pTextureTitle[NUM_TITLE] = {}; //�e�N�X�`���̃|�C���^
static LPDIRECT3DVERTEXBUFFER9 s_pVtxBuffTitle = NULL; //���_�o�b�t�@�̐ݒ�
static D3DXVECTOR3 s_moveTitle;	//�ړ���
static D3DXVECTOR3 s_posSelect;
static D3DXVECTOR3 s_posTitle[NUM_TITLE];	//���W
static TITLE s_Title[NUM_TITLE];//�\����
static int s_nTime;
static int s_nTime2;
static bool s_nTimeCut;



//================
//����������
//================
void InitTitle(void)
{
	LPDIRECT3DDEVICE9  pDevice;
	int nCnt;
	s_moveTitle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	s_posSelect = D3DXVECTOR3(0.0f, 450.0f, 0.0f);
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\TITLE\\Title_BG.png",
		&s_pTextureTitle[0]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\TITLE\\Title_Logo.png",
		&s_pTextureTitle[1]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/Title002.png",
		&s_pTextureTitle[2]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/STA.png",
		&s_pTextureTitle[3]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/tutorial.png",
		&s_pTextureTitle[4]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/ranking.png",
		&s_pTextureTitle[5]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/Easy.png",
		&s_pTextureTitle[6]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/Normal.png",
		&s_pTextureTitle[7]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/Hard.png",
		&s_pTextureTitle[8]);

	s_nTime2 = 0;
	s_nTime = 0;

	//���_�o�b�t�@
	pDevice->CreateVertexBuffer(
		sizeof(VERTEX_2D) * 4 * NUM_TITLE,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,//�������_�t�H�[�}�b�g
		&s_pVtxBuffTitle,
		NULL);

	//���Ԃ̂��
	s_nTime = 0;
	s_nTimeCut = false;
	VERTEX_2D*pVtx; //���_�ւ̃|�C���^

					//���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
	s_pVtxBuffTitle->Lock(0, 0, (void**)&pVtx, 0);
	for (nCnt = 0; nCnt < NUM_TITLE - 2; nCnt++)
	{
		s_Title[nCnt].degree = 0;
		s_Title[nCnt].nSwitch = false;
		s_posTitle[nCnt] = D3DXVECTOR3(0.0, 0.0, 0.0);
		s_Title[nCnt].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		if (nCnt == 2)
		{

			SetNormalpos(pVtx,
				0.0f,
				SCREEN_WIDTH,
				0.0f,
				1100.0f);

		}
		else if (nCnt >= 3 && nCnt <= 5)
		{
			SetNormalpos(pVtx,
				0.0f,
				SCREEN_WIDTH,
				s_posSelect.y - 200.0f,
				s_posSelect.y + 200.0f);
			s_posSelect += D3DXVECTOR3(0.0, 100.0, 0.0);
		}
		else if (nCnt == 6)
		{

			s_posSelect = D3DXVECTOR3(0.0, 400.0, 0.0);
			SetNormalpos(pVtx,
				100.0f,
				SCREEN_WIDTH,
				s_posSelect.y - 200.0f,
				s_posSelect.y + 200.0f);
		}
		else
		{
			SetNormalpos(pVtx,
				0.0f,
				SCREEN_WIDTH,
				0.0f,
				SCREEN_HEIGHT);

		}
		if (nCnt == 1)
		{

			SetNormalpos(pVtx,
				100.0f,
				1000,
				0.0f,
				1100.0f);

		}
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		Settex(pVtx, 0.0f, 1.0f, 0.0f, 1.0f);
		pVtx += 4;
	}

	//�T�E���h�J�n
	//PlaySound(SOUND_LABEL_BGM001);
	//���_�o�b�t�@���A�����b�N
	s_pVtxBuffTitle->Unlock();


}

//�j��
void UninitTitle(void)
{


	//�T�E���h��~
	//StopSound();
	int nCnt;
	//�e�N�X�`���̔j��
	for (nCnt = 0; nCnt < NUM_TITLE; nCnt++)
	{
		if (s_pTextureTitle[nCnt] != NULL)
		{
			s_pTextureTitle[nCnt]->Release();
			s_pTextureTitle[nCnt] = NULL;
		}
		//���_�o�b�t�@�̔j��

		if (s_pVtxBuffTitle != NULL)
		{
			s_pVtxBuffTitle->Release();
			s_pVtxBuffTitle = NULL;
		}


	}
}
//==================
//�X�V����
//==================
void UpdateTitle(void)
{
	int nCnt;

	VERTEX_2D*pVtx; //���_�ւ̃|�C���^
					//���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
	s_pVtxBuffTitle->Lock(0, 0, (void**)&pVtx, 0);

	//�^�C�g������������
	s_nTime++;
	s_nTime %= 40;

	////�����ɂ悱�Ƀv���X�G���^�[����������
	//s_posTitle[2].x += 0.008f;


	FADE pFade;
	pFade = GetFade();
	for (nCnt = 0; nCnt < NUM_TITLE - 2; nCnt++)
	{
		if (s_Title[nCnt].nSwitch == false)
		{
			if (s_nTime >= 20)
			{
				s_Title[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			}
			else
			{

				s_Title[2].col = D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f);
			}
		}
		if (s_Title[nCnt].nSwitch == true)
		{
			if ((GetKeyboardTrigger(DIK_W) ||
				GetKeyboardTrigger(JOYKEY_UP)) && pFade == FADE_NONE)
			{//�エ�������Z
				s_Title[nCnt].nSelect--;
				//PlaySound(SOUND_LABEL_SE_MOVE);
				if (s_Title[nCnt].nSelect < 0)
				{
					s_Title[nCnt].nSelect = 2;
				}
			}
			else if ((GetKeyboardTrigger(DIK_S) ||
				GetKeyboardTrigger(JOYKEY_DOWN)) && pFade == FADE_NONE)
			{//�����L�[���Z
				s_Title[nCnt].nSelect++;
				//PlaySound(SOUND_LABEL_SE_MOVE);
				if (s_Title[nCnt].nSelect >= 3)
				{
					s_Title[nCnt].nSelect = 0;
				}
			}
			if ((GetKeyboardTrigger(DIK_A) ||
				GetKeyboardTrigger(JOYKEY_UP)) && pFade == FADE_NONE)
			{//�エ�������Z
				s_Title[nCnt].degree--;
				//PlaySound(SOUND_LABEL_SE_MOVE);
				if (s_Title[nCnt].degree < 0)
				{
					s_Title[nCnt].degree = 2;
				}
			}
			else if ((GetKeyboardTrigger(DIK_D) ||
				GetKeyboardTrigger(JOYKEY_DOWN)) && pFade == FADE_NONE)
			{//�����L�[���Z
				s_Title[nCnt].degree++;
				//PlaySound(SOUND_LABEL_SE_MOVE);
				if (s_Title[nCnt].degree >= 3)
				{
					s_Title[nCnt].degree = 0;
				}
			}

			if ((GetKeyboardTrigger(DIK_RETURN) ||
				GetKeyboardTrigger(JOYKEY_B)) && pFade == FADE_NONE)
			{
				//���j���[�̓��e
				switch (s_Title[nCnt].nSelect)
				{
				case 0://�J�n

				{ //SPACE�������ꂽ�Ƃ�
				  //PlaySound(SOUND_LABEL_SE_ENTER);
					SetFade(MODE_GAME);

				}
				break;
				case 1://�`���[�g���A��

				{//SPACE�������ꂽ�Ƃ�
				 //PlaySound(SOUND_LABEL_SE_ENTER);
					//SetFade(MODE_TUTORIAL);

				}
				break;
				case 2://��񂫂񂮂ɂ���

				{ //SPACE�������ꂽ�Ƃ�
				  //PlaySound(SOUND_LABEL_SE_ENTER);
					//SetFade(MODE_RANKING);
				}
				break;
				}
			}

		}
		if (((GetKeyboardTrigger(DIK_RETURN)
			|| GetKeyboardTrigger(JOYKEY_START))
			&& s_Title[nCnt].nSwitch == false)
			&& pFade == FADE_NONE)
		{//�G���^�[�������ꂽ�Ƃ�
			s_Title[nCnt].nSwitch = true;
			s_Title[nCnt].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
			//PlaySound(SOUND_LABEL_SE_MENU);
			s_Title[nCnt].nSelect = 0;
		}
		s_posTitle[nCnt] += s_moveTitle;
		Settex(pVtx, 0.0f + s_posTitle[nCnt].x, 1.0f + s_posTitle[nCnt].x, 0.0f + s_posTitle[nCnt].y, 1.0f + s_posTitle[nCnt].y);


		////�ړ��ʂ��X�V(����������)
		//s_moveTitle.x += (0.0f - s_moveTitle.x)*0.5f;//�i�ړI�̒l-���݂̒l�j�������W��
		//s_moveTitle.y += (0.0f - s_moveTitle.y)*0.5f;
		if (nCnt == 1)
		{
			SetNormalpos(pVtx,
				0.0f - s_posTitle[1].x,
				1300.0f + s_posTitle[1].x,
				50.0f - s_posTitle[1].y,
				520.0f + s_posTitle[1].y);


		}
		if (!s_Title[nCnt].nSwitch)
		{
			if (nCnt == 2)
			{
				//���_�J���[�̐ݒ�
				pVtx[0].col = s_Title[nCnt].col;
				pVtx[1].col = s_Title[nCnt].col;
				pVtx[2].col = s_Title[nCnt].col;
				pVtx[3].col = s_Title[nCnt].col;
			}
			else if (nCnt >= 3)
			{
				//���_�J���[�̐ݒ�
				pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
				pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
				pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
				pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
			}
			else
			{
				//���_�J���[�̐ݒ�
				pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			}

		}
		else
		{
			//���_�J���[�̐ݒ�
			if (nCnt == 2)
			{
				pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
				pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
				pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
				pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
			}
			else if (nCnt == s_Title[nCnt].nSelect + 3)
			{
				//���_�J���[�̐ݒ�
				pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

			}
			else
			{
				//���_�J���[�̐ݒ�
				pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.6f);
				pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.6f);
				pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.6f);
				pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.6f);

			}
		}
		pVtx += 4;
	}
	//���_�o�b�t�@���A�����b�N
	s_pVtxBuffTitle->Unlock();



#ifdef _DEBUG

	if (GetKeyboardPress(DIK_0))
	{
		SetFade(MODE_RESULT);
	}
	if (GetKeyboardPress(DIK_9))
	{
		//SetFade(MODE_GAMEOVER);
	}

#endif // DEBUG
}
//==================
//�`�揈��
//==================
void DrawTitle(void)
{
	int nCnt;

	LPDIRECT3DDEVICE9 pDevice;//�f�o�C�X�̃|�C���^

	pDevice = GetDevice(); //���

						   //���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, s_pVtxBuffTitle, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̕`��
	for (nCnt = 0; nCnt < NUM_TITLE - 3; nCnt++)
	{

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, s_pTextureTitle[nCnt]);

		//�|���S���̕`�� �l�p
		pDevice->DrawPrimitive(
			D3DPT_TRIANGLESTRIP,		//�v���~�e�B�u�̎��
			nCnt * 4,			//�`�悷��ŏ��̒��_�C���f�b�N�X
			2);							//�v���~�e�B�u(�|���S��)��
	}

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, s_pTextureTitle[s_Title[nCnt].degree + nCnt]);

	//�|���S���̕`�� �l�p
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,		//�v���~�e�B�u�̎��
		nCnt * 4, 2);			//�`�悷��ŏ��̒��_�C���f�b�N�X


}

int Getdegree(void)
{
	return s_Title[0].degree;
}