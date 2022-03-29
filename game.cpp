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
#include "Life.h"
#include "slingshot.h"

//------------------------------
// マクロ定義
//------------------------------
#define MAX_POP_TIME	(160 - s_Acceleration)				//敵の出現時間
#define HALF_POP_TIME	(MAX_POP_TIME / 2)	//敵の出現時間の半分

//------------------------
// スタティック変数
//------------------------
static int s_nPopTime;			//出現時間
static int s_Acceleration = 0;	//加速


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

	InitLife();

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

	UninitLife();

	UninitScore();

	//ぱちんこの終了
	UninitSlingshot();
}

//========================
// ゲームの更新処理
//========================
void UpdateGame(void)
{
	s_nPopTime++;				//タイムの加算
	s_nPopTime %= MAX_POP_TIME;	//タイムの初期化

	//背景の更新処理
	UpdateBG();

	//敵の更新処理
	UpdateEnemy();

	if (s_nPopTime == HALF_POP_TIME)
	{
		//敵の設定処理
		SetEnemy();

		s_Acceleration++;	//加速度の上昇
	}

	UpdateLife();

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

	//背景の描画処理
	DrawBG();

	DrawLife();

	DrawScore();

	//ぱちんこの描画
	DrawSlingshot();
}