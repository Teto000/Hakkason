//============================
//
// ゲーム画面
// Author:Teruto Sato
//
//============================

//------------------------
// インクルード
//------------------------
#include "game.h"
#include "input.h"
#include "fade.h"
#include "sound.h"
#include "bg.h"
#include "score.h"


//========================
// ゲームの初期化処理
//========================
void InitGame(void)
{
	//背景の初期化処理
	InitBG();

	InitScore();

	//サウンドの再生
	//PlaySound(SOUND_LABEL_BGM000);
}

//========================
// ゲームの終了処理
//========================
void UninitGame(void)
{
	//サウンドの停止
	//StopSound();

	//背景の終了処理
	UninitBG();

	UninitScore();
}

//========================
// ゲームの更新処理
//========================
void UpdateGame(void)
{
	//背景の更新処理
	UpdateBG();

	UpdateScore();

	//画面遷移
	if (GetKeyboardTrigger(DIK_RETURN) == true || GetJoypadTrigger(JOYKEY_A))
	{

		SetFade(MODE_RESULT);
	}
}

//========================
// ゲームの描画処理
//========================
void DrawGame(void)
{
	//背景の描画処理
	DrawBG();

	DrawScore();

}