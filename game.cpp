//============================
//
// �Q�[�����
// Author:Teruto Sato
//
//============================

//------------------------
// �C���N���[�h
//------------------------
#include "game.h"
#include "input.h"
#include "fade.h"
#include "sound.h"
#include "bg.h"
#include "enemy.h"
#include "score.h"
#include "Life.h"
#include "slingshot.h"
#include "ball.h"
#include"Time.h"
//------------------------------
// �}�N����`
//------------------------------
#define MAX_POP_TIME	(160 - s_Acceleration)		//�G�̏o������
#define HALF_POP_TIME	(MAX_POP_TIME / 2)			//�G�̏o�����Ԃ̔���
#define MAX_SPEED		(100)		//�ō����x

//------------------------
// �X�^�e�B�b�N�ϐ�
//------------------------
static int s_nPopTime;			//�o������
static int s_Acceleration = 0;	//����


//========================
// �Q�[���̏���������
//========================
void InitGame(void)
{
	//�w�i�̏���������
	InitBG();

	//�G�̏���������
	InitEnemy();

	//�G�̐ݒ菈��
	SetEnemy();

	InitTimer();

	InitLife();

	InitScore();

	//�ʏ�����
	InitBall();

	//�ς��񂱂̏�����
	InitSlingshot();

	//�T�E���h�̍Đ�
	//PlaySound(SOUND_LABEL_BGM000);
}

//========================
// �Q�[���̏I������
//========================
void UninitGame(void)
{
	//�T�E���h�̒�~
	//StopSound();

	//�w�i�̏I������
	UninitBG();

	UninitLife();

	UninitTimer();

	UninitScore();

	//�ʏI��
	UninitBall();

	//�ς��񂱂̏I��
	UninitSlingshot();
}

//========================
// �Q�[���̍X�V����
//========================
void UpdateGame(void)
{
	s_nPopTime++;				//�^�C���̉��Z
	s_nPopTime %= MAX_POP_TIME;	//�^�C���̏�����

	//�w�i�̍X�V����
	UpdateBG();

	//�G�̍X�V����
	UpdateEnemy();

	if (s_nPopTime == HALF_POP_TIME)
	{
		//�G�̐ݒ菈��
		SetEnemy();

		if (s_Acceleration <= MAX_SPEED)
		{//�ō����x����Ȃ��Ȃ�
			s_Acceleration++;	//�����x�̏㏸
		}
	}

	UpdateLife();

	UpdateTimer();

	UpdateScore();

	//�ʍX�V
	UpdateBall();

	//�ς��񂱂̍X�V
	UpdateSlingshot();

	//��ʑJ��
	if (GetKeyboardTrigger(DIK_RETURN) == true || GetJoypadTrigger(JOYKEY_A))
	{

		SetFade(MODE_RESULT);
	}
}

//========================
// �Q�[���̕`�揈��
//========================
void DrawGame(void)
{
	//�w�i�̕`�揈��
	DrawBG();

	//�G�̕`�揈��
	DrawEnemy();

	DrawLife();

	DrawScore();

	DrawTimer();

	//�ʕ`��
	DrawBall();

	//�ς��񂱂̕`��
	DrawSlingshot();
}