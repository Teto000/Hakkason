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
#include "score.h"


//========================
// �Q�[���̏���������
//========================
void InitGame(void)
{
	//�w�i�̏���������
	InitBG();

	InitScore();

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

	UninitScore();
}

//========================
// �Q�[���̍X�V����
//========================
void UpdateGame(void)
{
	//�w�i�̍X�V����
	UpdateBG();

	UpdateScore();

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

	DrawScore();

}