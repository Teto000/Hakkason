//============================
//
// ゲーム画面のヘッダー
// Author:Teruto Sato
//
//============================
#ifndef _GAME_H_		//このマクロが定義されてなかったら
#define _GAME_H_		//2重インクルード防止のマクロ定義

//---------------------
// プロトタイプ宣言
//---------------------
void InitGame(void);
void UninitGame(void);
void UpdateGame(void);
void DrawGame(void);

#endif