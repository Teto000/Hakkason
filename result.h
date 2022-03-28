//============================
//
// リザルト画面のヘッダー
// Author:Teruto Sato
//
//============================
#ifndef _RESULT_H_		//このマクロが定義されてなかったら
#define _RESULT_H_		//2重インクルード防止のマクロ定義

#include "main.h"

//プロトタイプ宣言
void InitResult(void);
void UninitResult(void);
void UpdateResult(void);
void DrawResult(void);

#endif