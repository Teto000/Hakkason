//============================
//
// �L�[�{�[�h�̓��͏���
// Author:Teruto Sato
//
//============================

//------------------------
// �C���N���[�h
//------------------------
#include "main.h"
#include "input.h"

//------------------------
// �}�N����`
//------------------------
#define NUM_KEY_MAX		(256)		//�L�[�̍ő吔

//------------------------
// �X�^�e�B�b�N�ϐ�
//------------------------
static	LPDIRECTINPUT8 g_pInput = NULL;					//DirectInput�I�u�W�F�N�g�ւ̃|�C���^
static	LPDIRECTINPUTDEVICE8 g_pDevKeyboard = NULL;		//���̓f�o�C�X(�L�[�{�[�h)�ւ̃|�C���^
static	BYTE g_aKeyState[NUM_KEY_MAX];					//�L�[�{�[�h�̃v���X���
static	BYTE g_aKeyStateTrigger[NUM_KEY_MAX];			//�L�[�{�[�h�̃g���K�[���
static	XINPUT_STATE g_JoyKeyState;						//�W���C�p�b�h�̃v���X���
static	XINPUT_STATE g_JoyKeyStateTrigger;				//�W���C�p�b�h�̃g���K�[���
static	D3DXVECTOR3 g_JoyStickPos;						//�W���C�X�e�B�b�N�̌X��

//============================
// �L�[�{�[�h�̏���������
//============================
HRESULT InitKeyboard(HINSTANCE hInstance, HWND hWnd)
{
	//DirectInput�I�u�W�F�N�g�̐���
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION,
								  IID_IDirectInput8, (void**)&g_pInput, NULL)))
	{
		return E_FAIL;
	}

	//���̓f�o�C�X(�L�[�{�[�h)�̐���
	if (FAILED(g_pInput->CreateDevice(GUID_SysKeyboard, &g_pDevKeyboard, NULL)))
	{
		return E_FAIL;
	}

	//�f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(g_pDevKeyboard->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//�������[�h��ݒ�
	if (FAILED(g_pDevKeyboard->SetCooperativeLevel(hWnd,
												  (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	//�L�[�{�[�h�ւ̃A�N�Z�X�����l��
	g_pDevKeyboard->Acquire();

	return S_OK;
}

//============================
// �L�[�{�[�h�̏I������
//============================
void UninitKeyboard(void)
{
	//���̓f�o�C�X(�L�[�{�[�h)�̔j��
	if (g_pDevKeyboard != NULL)
	{
		g_pDevKeyboard->Unacquire();	//�L�[�{�[�h�ւ̃A�N�Z�X�������
		g_pDevKeyboard->Release();
		g_pDevKeyboard = NULL;
	}

	//DirectInput�I�u�W�F�N�g�̔j��
	if (g_pInput != NULL)
	{
		g_pInput->Release();
		g_pInput = NULL;
	}
}

//============================
// �L�[�{�[�h�̍X�V����
//============================
void UpdateKeyboard(void)
{
	BYTE aKeyState[NUM_KEY_MAX];	//�L�[�{�[�h�̓��͏��
	int nCntKey;

	//���̓f�o�C�X����f�[�^���擾
	if (SUCCEEDED(g_pDevKeyboard->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
		{
			g_aKeyStateTrigger[nCntKey] = (g_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & aKeyState[nCntKey];	//�L�[�{�[�h�̃g���K�[����ۑ�
			g_aKeyState[nCntKey] = aKeyState[nCntKey];				//�L�[�{�[�h�̃v���X����ۑ�
		}
	}
	else
	{
		g_pDevKeyboard->Acquire();		//�L�[�{�[�h�ւ̃A�N�Z�X�����l��
	}
}

//=================================
// �L�[�{�[�h�̃v���X�����擾
//=================================
bool GetKeyboardPress(int nKey)
{
	return(g_aKeyState[nKey] & 0x80) ? true : false;
}

//=================================
// �L�[�{�[�h�̃g���K�[�����擾
//=================================
bool GetKeyboardTrigger(int nKey)
{
	return(g_aKeyStateTrigger[nKey] & 0x80) ? true : false;
}

//============================
// �W���C�p�b�h�̏���������
//============================
HRESULT InitJoypad(void)
{
	//�������̃N���A
	memset(&g_JoyKeyState, 0, sizeof(XINPUT_STATE));
	memset(&g_JoyKeyStateTrigger, 0, sizeof(XINPUT_STATE));

	//XInput�̃X�e�[�g�ݒ�(�L���ɂ���)
	XInputEnable(true);

	return S_OK;
}

//============================
// �W���C�p�b�h�̏I������
//============================
void UninitJoypad(void)
{
	//XInput�̃X�e�[�g�ݒ�(�����ɂ���)
	XInputEnable(false);
}

//============================
// �W���C�p�b�h�̍X�V����
//============================
void UpdateJoypad(void)
{
	XINPUT_STATE joykeyState;		//�W���C�p�b�h�̓��͏��

	//�W���C�p�b�h�̏�Ԃ��ێ�
	if (XInputGetState(0, &joykeyState) == ERROR_SUCCESS)
	{
		g_JoyKeyStateTrigger.Gamepad.wButtons = ~g_JoyKeyState.Gamepad.wButtons & joykeyState.Gamepad.wButtons; //�g���K�[����ۑ�
		g_JoyKeyState = joykeyState;	//�W���C�p�b�h�̃v���X����ۑ�
	}
}

//=================================
// �W���C�p�b�h�̃v���X�����擾
//=================================
bool GetJoypadPress(JOYKEY key)
{
	return (g_JoyKeyState.Gamepad.wButtons & (0x01 << key)) ? true : false;
}

//===================================
// �W���C�p�b�h�̃g���K�[�����擾
//===================================
bool GetJoypadTrigger(JOYKEY key)
{
	return (g_JoyKeyStateTrigger.Gamepad.wButtons & (0x01 << key)) ? true : false;
}