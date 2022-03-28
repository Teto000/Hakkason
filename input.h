//============================
//
// 入力のヘッダー
// Author:Teruto Sato
//
//============================
#ifndef _INPUT_H_	//このマクロが定義されてなかったら
#define _INPUT_H_	//2重インクルード防止のマクロ定義

#include "main.h"

//キーの種類
typedef enum
{
	JOYKEY_UP = 0,				//十字ボタン上
	JOYKEY_DOWN,				//十字ボタン下
	JOYKEY_LEFT,				//十字ボタン左
	JOYKEY_RIGHT,				//十字ボタン右
	JOYKEY_START,				//スタートボタン
	JOYKEY_BACK,				//バックボタン
	JOYKEY_LEFT_THUMB,			//左スティック押込み
	JOYKEY_RIGHT_THUMB,			//右スティック押込み
	JOYKEY_LEFT_SHOULDER,		//L１ボタン
	JOYKEY_RIGHT_SHOULDER,		//R１ボタン
	JOYKEY_LEFT_TRIGGER,		//L２トリガー
	JOYKEY_RIGHT_TRIGGER,		//R２トリガー
	JOYKEY_A,					//Aボタン
	JOYKEY_B,					//Bボタン
	JOYKEY_X,					//Xボタン
	JOYKEY_Y,					//Yボタン
	JOYKEY_LEFT_STICK,			//左スティック
	JOYKEY_RIGHT_STICK,			//右スティック
	JOYKEY_MAX
}JOYKEY;

//プロトタイプ宣言
//キーボード
HRESULT InitKeyboard(HINSTANCE hInstance, HWND hWnd);
void UninitKeyboard(void);
void UpdateKeyboard(void);
bool GetKeyboardPress(int nKey);
bool GetKeyboardTrigger(int nKey);
//ゲームパッド
HRESULT InitJoypad(void);
void UninitJoypad(void);
void UpdateJoypad(void);
bool GetJoypadPress(JOYKEY key);
bool GetJoypadTrigger(JOYKEY key);

#endif