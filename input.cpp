//============================
//
// キーボードの入力処理
// Author:Teruto Sato
//
//============================

//------------------------
// インクルード
//------------------------
#include "main.h"
#include "input.h"

//------------------------
// マクロ定義
//------------------------
#define NUM_KEY_MAX		(256)		//キーの最大数

//------------------------
// スタティック変数
//------------------------
static	LPDIRECTINPUT8 g_pInput = NULL;					//DirectInputオブジェクトへのポインタ
static	LPDIRECTINPUTDEVICE8 g_pDevKeyboard = NULL;		//入力デバイス(キーボード)へのポインタ
static	BYTE g_aKeyState[NUM_KEY_MAX];					//キーボードのプレス情報
static	BYTE g_aKeyStateTrigger[NUM_KEY_MAX];			//キーボードのトリガー情報
static	XINPUT_STATE g_JoyKeyState;						//ジョイパッドのプレス情報
static	XINPUT_STATE g_JoyKeyStateTrigger;				//ジョイパッドのトリガー情報
static	D3DXVECTOR3 g_JoyStickPos;						//ジョイスティックの傾き

//============================
// キーボードの初期化処理
//============================
HRESULT InitKeyboard(HINSTANCE hInstance, HWND hWnd)
{
	//DirectInputオブジェクトの生成
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION,
								  IID_IDirectInput8, (void**)&g_pInput, NULL)))
	{
		return E_FAIL;
	}

	//入力デバイス(キーボード)の生成
	if (FAILED(g_pInput->CreateDevice(GUID_SysKeyboard, &g_pDevKeyboard, NULL)))
	{
		return E_FAIL;
	}

	//データフォーマットを設定
	if (FAILED(g_pDevKeyboard->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//協調モードを設定
	if (FAILED(g_pDevKeyboard->SetCooperativeLevel(hWnd,
												  (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	//キーボードへのアクセス権を獲得
	g_pDevKeyboard->Acquire();

	return S_OK;
}

//============================
// キーボードの終了処理
//============================
void UninitKeyboard(void)
{
	//入力デバイス(キーボード)の破棄
	if (g_pDevKeyboard != NULL)
	{
		g_pDevKeyboard->Unacquire();	//キーボードへのアクセス権を放棄
		g_pDevKeyboard->Release();
		g_pDevKeyboard = NULL;
	}

	//DirectInputオブジェクトの破壊
	if (g_pInput != NULL)
	{
		g_pInput->Release();
		g_pInput = NULL;
	}
}

//============================
// キーボードの更新処理
//============================
void UpdateKeyboard(void)
{
	BYTE aKeyState[NUM_KEY_MAX];	//キーボードの入力情報
	int nCntKey;

	//入力デバイスからデータを取得
	if (SUCCEEDED(g_pDevKeyboard->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
		{
			g_aKeyStateTrigger[nCntKey] = (g_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & aKeyState[nCntKey];	//キーボードのトリガー情報を保存
			g_aKeyState[nCntKey] = aKeyState[nCntKey];				//キーボードのプレス情報を保存
		}
	}
	else
	{
		g_pDevKeyboard->Acquire();		//キーボードへのアクセス権を獲得
	}
}

//=================================
// キーボードのプレス情報を取得
//=================================
bool GetKeyboardPress(int nKey)
{
	return(g_aKeyState[nKey] & 0x80) ? true : false;
}

//=================================
// キーボードのトリガー情報を取得
//=================================
bool GetKeyboardTrigger(int nKey)
{
	return(g_aKeyStateTrigger[nKey] & 0x80) ? true : false;
}

//============================
// ジョイパッドの初期化処理
//============================
HRESULT InitJoypad(void)
{
	//メモリのクリア
	memset(&g_JoyKeyState, 0, sizeof(XINPUT_STATE));
	memset(&g_JoyKeyStateTrigger, 0, sizeof(XINPUT_STATE));

	//XInputのステート設定(有効にする)
	XInputEnable(true);

	return S_OK;
}

//============================
// ジョイパッドの終了処理
//============================
void UninitJoypad(void)
{
	//XInputのステート設定(無効にする)
	XInputEnable(false);
}

//============================
// ジョイパッドの更新処理
//============================
void UpdateJoypad(void)
{
	XINPUT_STATE joykeyState;		//ジョイパッドの入力情報

	//ジョイパッドの状態を維持
	if (XInputGetState(0, &joykeyState) == ERROR_SUCCESS)
	{
		g_JoyKeyStateTrigger.Gamepad.wButtons = ~g_JoyKeyState.Gamepad.wButtons & joykeyState.Gamepad.wButtons; //トリガー情報を保存
		g_JoyKeyState = joykeyState;	//ジョイパッドのプレス情報を保存
	}
}

//=================================
// ジョイパッドのプレス情報を取得
//=================================
bool GetJoypadPress(JOYKEY key)
{
	return (g_JoyKeyState.Gamepad.wButtons & (0x01 << key)) ? true : false;
}

//===================================
// ジョイパッドのトリガー情報を取得
//===================================
bool GetJoypadTrigger(JOYKEY key)
{
	return (g_JoyKeyStateTrigger.Gamepad.wButtons & (0x01 << key)) ? true : false;
}