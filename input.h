//============================
//
// ���͂̃w�b�_�[
// Author:Teruto Sato
//
//============================
#ifndef _INPUT_H_	//���̃}�N������`����ĂȂ�������
#define _INPUT_H_	//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"

//�L�[�̎��
typedef enum
{
	JOYKEY_UP = 0,				//�\���{�^����
	JOYKEY_DOWN,				//�\���{�^����
	JOYKEY_LEFT,				//�\���{�^����
	JOYKEY_RIGHT,				//�\���{�^���E
	JOYKEY_START,				//�X�^�[�g�{�^��
	JOYKEY_BACK,				//�o�b�N�{�^��
	JOYKEY_LEFT_THUMB,			//���X�e�B�b�N������
	JOYKEY_RIGHT_THUMB,			//�E�X�e�B�b�N������
	JOYKEY_LEFT_SHOULDER,		//L�P�{�^��
	JOYKEY_RIGHT_SHOULDER,		//R�P�{�^��
	JOYKEY_LEFT_TRIGGER,		//L�Q�g���K�[
	JOYKEY_RIGHT_TRIGGER,		//R�Q�g���K�[
	JOYKEY_A,					//A�{�^��
	JOYKEY_B,					//B�{�^��
	JOYKEY_X,					//X�{�^��
	JOYKEY_Y,					//Y�{�^��
	JOYKEY_LEFT_STICK,			//���X�e�B�b�N
	JOYKEY_RIGHT_STICK,			//�E�X�e�B�b�N
	JOYKEY_MAX
}JOYKEY;

//�v���g�^�C�v�錾
//�L�[�{�[�h
HRESULT InitKeyboard(HINSTANCE hInstance, HWND hWnd);
void UninitKeyboard(void);
void UpdateKeyboard(void);
bool GetKeyboardPress(int nKey);
bool GetKeyboardTrigger(int nKey);
//�Q�[���p�b�h
HRESULT InitJoypad(void);
void UninitJoypad(void);
void UpdateJoypad(void);
bool GetJoypadPress(JOYKEY key);
bool GetJoypadTrigger(JOYKEY key);

#endif