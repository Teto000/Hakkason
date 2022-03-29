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
#include "effect.h"
#include "combo.h"
#include "right.h"
//------------------------------
// �}�N����`
//------------------------------
#define MAX_POP_TIME	(160 - s_Acceleration)		//�G�̏o������
#define HALF_POP_TIME	(MAX_POP_TIME / 2)			//�G�̏o�����Ԃ̔���
#define MAX_SPEED		(50)		//�ō����x

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
	InitRight();

	//�G�̏���������
	InitEnemy();

	//�G�̐ݒ菈��
	SetEnemy();

	InitTimer();

	InitLife();

	InitScore();

	InitCombo();

	//�ʏ�����
	InitBall();

	//�ς��񂱂̏�����
	InitSlingshot();

	InitEffect();
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
	UninitRight();

	UninitLife();

	UninitTimer();

	UninitScore();

	//�ʏI��
	UninitBall();

	UninitCombo();

	//�ς��񂱂̏I��
	UninitSlingshot();
	UninitEffect();
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
	UpdateRight();

	//�G�̍X�V����
	UpdateEnemy();

	UpdateEffect();


	UpdateCombo();

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

	if (GetKeyboardTrigger(DIK_SPACE) == true || GetJoypadTrigger(JOYKEY_A))
	{

		SetFade(MODE_RANKING);
	}

}

//========================
// �Q�[���̕`�揈��
//========================
void DrawGame(void)
{
	//�w�i�̕`�揈��
	DrawBG();
	DrawRight();

	DrawEffect();
	//�G�̕`�揈��
	DrawEnemy();

	DrawCombo();

	DrawLife();

	DrawScore();

	DrawTimer();

	//�ʕ`��
	DrawBall();

	//�ς��񂱂̕`��
	DrawSlingshot();
}