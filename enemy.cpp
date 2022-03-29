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
#include "Life.h"

#include <stdlib.h>
#include <time.h>


//------------------------
// �X�^�e�B�b�N�ϐ�
//------------------------
static	TEXTURE		s_pTexture;		//�e�N�X�`���ւ̃|�C���^
static	LPDIRECT3DVERTEXBUFFER9		s_pVtxBuff = NULL;		//���_�o�b�t�@�ւ̃|�C���^

//�\����
static	Enemy s_Enemy[MAX_ENEMY];	//�G�̍\����

//�l
static float s_fLength = sqrtf((WIDTH * WIDTH) + (HEIGHT * HEIGHT));	//�Ίp���̒������Z�o����
static float s_fAngle = atan2f(WIDTH, HEIGHT);		//�Ίp���̊p�x���Z�o
static D3DXVECTOR3 vecEnemy[MAX_VECTOR];	//�v���C���[�ƃG�l�~�[�Ԃ̃x�N�g��
static int s_nNumber;	//��ԋ߂��ԍ�
static int s_nMin;		//�ŏ�

//========================
// �G�̏���������
//========================
void InitEnemy(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//�f�o�C�X�̎擾

	//------------------------
	// �e�N�X�`���̓ǂݍ���
	//------------------------
	s_pTexture = TEXTURE_BALLOONBOM;

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_ENEMY,	//�m�ۂ���o�b�t�@�̃T�C�Y
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
		enemy->move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//�ړ���
		enemy->rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//����
		enemy->nPlace = 0;		//�o���ꏊ
		enemy->bUse = false;	//�g�p���Ă��邩
		enemy->bHorming = false;
	}

	//------------------------
	// �����_���Ȓl�̐���
	//------------------------
	//���������Ƃɂ��������_���Ȓl�𐶐�
	srand((unsigned int)time(NULL));

	for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	{
		Enemy *enemy = s_Enemy + nCnt;

		int nMax = (int)(SCREEN_WIDTH - (WIDTH * 2));	//�ő�l
		int nMin = (int)(WIDTH * 2);					//�ŏ��l

		enemy->nPlace = rand() % nMax + nMin;	//�G�̏o���ꏊ�̐ݒ�
	}

	//------------------------
	// ���_���̐ݒ�
	//------------------------
	for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	{
		Enemy *enemy = s_Enemy + nCnt;

		//���_���W�̐ݒ�
		pVtx[0].pos.x = enemy->pos.x + sinf(enemy->rot.z + (D3DX_PI + s_fAngle)) * s_fLength;
		pVtx[0].pos.y = enemy->pos.y + cosf(enemy->rot.z + (D3DX_PI + s_fAngle)) * s_fLength;
		pVtx[0].pos.z = 0.0f;

		pVtx[1].pos.x = enemy->pos.x + sinf(enemy->rot.z + (D3DX_PI - s_fAngle)) * s_fLength;
		pVtx[1].pos.y = enemy->pos.y + cosf(enemy->rot.z + (D3DX_PI - s_fAngle)) * s_fLength;
		pVtx[1].pos.z = 0.0f;

		pVtx[2].pos.x = enemy->pos.x + sinf(enemy->rot.z - (0 + s_fAngle)) * s_fLength;
		pVtx[2].pos.y = enemy->pos.y + cosf(enemy->rot.z - (0 + s_fAngle)) * s_fLength;
		pVtx[2].pos.z = 0.0f;

		pVtx[3].pos.x = enemy->pos.x + sinf(enemy->rot.z - (0 - s_fAngle)) * s_fLength;
		pVtx[3].pos.y = enemy->pos.y + cosf(enemy->rot.z - (0 - s_fAngle)) * s_fLength;
		pVtx[3].pos.z = 0.0f;

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

		pVtx += 4;
	}

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
	VERTEX_2D*pVtx;		//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	s_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	Life *pLife = GetLife();	//���C�t���̎擾

	for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	{
		Enemy *enemy = s_Enemy + nCnt;

		if (enemy->bUse == true)
		{//�G���g�p����Ă���Ȃ�

			//------------------------
			// �G�̐i�s�����̉�]
			//------------------------
			if (enemy->pos.y >= 200.0f)
			{
				for (int i = 0; i < MAX_VECTOR; i++)
				{
					s_nNumber = FindDistance();
				}

				if (enemy->bHorming == false)
				{
					float moveEnemyX = pLife[s_nNumber].pos.x - enemy->pos.x;
					float moveEnemyY = pLife[s_nNumber].pos.y - enemy->pos.y;
					float moveEnemyR = sqrtf(moveEnemyX * moveEnemyX + moveEnemyY * moveEnemyY);

					enemy->move.x = (moveEnemyX / moveEnemyR) * 3.0f;
					enemy->move.y = (moveEnemyY / moveEnemyR) * 3.0f;
				}

				if (enemy->pos.y >= pLife[s_nNumber].pos.y)
				{
					enemy->bHorming = true;
					enemy->move.y = FALL_SPEED;
				}
			}

			//------------------------
			// ��ʒ[�̏���
			//------------------------
			if (enemy->pos.y - HEIGHT >= SCREEN_HEIGHT 
				|| enemy->pos.x + WIDTH <= 0.0f 
				|| enemy->pos.x - WIDTH >= SCREEN_WIDTH)
			{//�G���n�ʂ̉��ɍs����
				enemy->bUse = false;	//�G������
			}

			//�ʒu�̍X�V
			enemy->pos += enemy->move;

			//���_���W�̐ݒ�
			pVtx[0].pos.x = enemy->pos.x + sinf(enemy->rot.z + (D3DX_PI + s_fAngle)) * s_fLength;
			pVtx[0].pos.y = enemy->pos.y + cosf(enemy->rot.z + (D3DX_PI + s_fAngle)) * s_fLength;
			pVtx[0].pos.z = 0.0f;

			pVtx[1].pos.x = enemy->pos.x + sinf(enemy->rot.z + (D3DX_PI - s_fAngle)) * s_fLength;
			pVtx[1].pos.y = enemy->pos.y + cosf(enemy->rot.z + (D3DX_PI - s_fAngle)) * s_fLength;
			pVtx[1].pos.z = 0.0f;

			pVtx[2].pos.x = enemy->pos.x + sinf(enemy->rot.z - (0 + s_fAngle)) * s_fLength;
			pVtx[2].pos.y = enemy->pos.y + cosf(enemy->rot.z - (0 + s_fAngle)) * s_fLength;
			pVtx[2].pos.z = 0.0f;

			pVtx[3].pos.x = enemy->pos.x + sinf(enemy->rot.z - (0 - s_fAngle)) * s_fLength;
			pVtx[3].pos.y = enemy->pos.y + cosf(enemy->rot.z - (0 - s_fAngle)) * s_fLength;
			pVtx[3].pos.z = 0.0f;

			//�e�N�X�`�����W�̐ݒ�
			pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
			pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
			pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
			pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
		}

		pVtx += 4;
	}

	//���_�o�b�t�@���A�����b�N����
	s_pVtxBuff->Unlock();
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

	for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	{
		Enemy *enemy = s_Enemy + nCnt;

		if (enemy->bUse == true)
		{//�G���g�p����Ă���Ȃ�
			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, GetTexture(s_pTexture));

			//�G�̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,		//�v���~�e�B�u�̎��
								   nCnt * 4,				//�`�悷��ŏ��̒��_�C���f�b�N�X
								   2);						//�`�悷��v���~�e�B�u��
		}
	}
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
		{//�G���g�p����Ă��Ȃ��Ȃ�
			enemy->pos = D3DXVECTOR3((float)enemy->nPlace, 0.0f - HEIGHT, 0.0f);		//�ʒu
			enemy->move = D3DXVECTOR3(3.0f, 0.0f, 0.0f);	//�ړ���
			enemy->rot = D3DXVECTOR3(0.0f, 0.0f, 45.0f);		//����
			enemy->bUse = true;			//�g�p���Ă��邩

			//���_���W�̐ݒ�
			pVtx[0].pos.x = enemy->pos.x + sinf(enemy->rot.z + (D3DX_PI + s_fAngle)) * s_fLength;
			pVtx[0].pos.y = enemy->pos.y + cosf(enemy->rot.z + (D3DX_PI + s_fAngle)) * s_fLength;
			pVtx[0].pos.z = 0.0f;

			pVtx[1].pos.x = enemy->pos.x + sinf(enemy->rot.z + (D3DX_PI - s_fAngle)) * s_fLength;
			pVtx[1].pos.y = enemy->pos.y + cosf(enemy->rot.z + (D3DX_PI - s_fAngle)) * s_fLength;
			pVtx[1].pos.z = 0.0f;

			pVtx[2].pos.x = enemy->pos.x + sinf(enemy->rot.z - (0 + s_fAngle)) * s_fLength;
			pVtx[2].pos.y = enemy->pos.y + cosf(enemy->rot.z - (0 + s_fAngle)) * s_fLength;
			pVtx[2].pos.z = 0.0f;

			pVtx[3].pos.x = enemy->pos.x + sinf(enemy->rot.z - (0 - s_fAngle)) * s_fLength;
			pVtx[3].pos.y = enemy->pos.y + cosf(enemy->rot.z - (0 - s_fAngle)) * s_fLength;
			pVtx[3].pos.z = 0.0f;

			//�e�N�X�`�����W�̐ݒ�
			pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
			pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
			pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
			pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

			break;
		}
		pVtx += 4;
	}

	//���_�o�b�t�@���A�����b�N����
	s_pVtxBuff->Unlock();
}

//===========================
// �G�ƃ��C�t�̋��������߂�
//===========================
int FindDistance(void)
{
	Life *pLife = GetLife();	//���C�t���̎擾

	if (pLife[0].bUse == true)
	{//0�Ԗڂ������Ă���Ȃ�
		if (pLife[0].pos.x < pLife[1].pos.x && pLife[0].pos.x < pLife[2].pos.x && pLife[0].pos.x < pLife[3].pos.x)
		{//0����ԏ�����
			s_nMin = 0;
		}
	}
	if (pLife[1].bUse == true)
	{//1�Ԗڂ������Ă���Ȃ�
		if (pLife[1].pos.x < pLife[0].pos.x && pLife[1].pos.x < pLife[2].pos.x && pLife[1].pos.x < pLife[3].pos.x)
		{//1����ԏ�����
			s_nMin = 1;
		}
	}
	if (pLife[2].bUse == true)
	{//2�Ԗڂ������Ă���Ȃ�
		if (pLife[2].pos.x < pLife[0].pos.x && pLife[2].pos.x < pLife[1].pos.x && pLife[2].pos.x < pLife[3].pos.x)
		{//2����ԏ�����
			s_nMin = 2;
		}
	}
	if (pLife[3].bUse == true)
	{//3�Ԗڂ������Ă���Ȃ�
		if (pLife[3].pos.x < pLife[0].pos.x && pLife[3].pos.x < pLife[1].pos.x && pLife[3].pos.x < pLife[2].pos.x)
		{//3����ԏ�����
			s_nMin = 3;
		}
	}

	return s_nMin;	//��ԋ߂��l��Ԃ�
}

//========================
// �G���̎擾
//========================
Enemy *GetEnemy(int a)
{
	return &s_Enemy[a];
}