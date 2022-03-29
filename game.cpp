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
#include "enemy.h"
#include "score.h"
#include "slingshot.h"


//========================
// ゲームの初期化処理
//========================
void InitGame(void)
{
	//背景の初期化処理
	InitBG();

	//敵の初期化処理
	InitEnemy();

	//敵の設定処理
	SetEnemy();

	InitScore();

	//ぱちんこの初期化
	InitSlingshot();

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

	//ぱちんこの終了
	UninitSlingshot();
}

//========================
// ゲームの更新処理
//========================
void UpdateGame(void)
{
	//背景の更新処理
	UpdateBG();

	//敵の更新処理
	UpdateEnemy();

	UpdateScore();

	//ぱちんこの更新
	UpdateSlingshot();

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

	//敵の描画処理
	DrawEnemy();

	DrawScore();

	//ぱちんこの描画
	DrawSlingshot();
}