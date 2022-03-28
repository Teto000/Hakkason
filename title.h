//================================
//
// タイトル画面のヘッダー
// Author:Teruto Sato
//
//================================
#ifndef _TITLE_H_		//このマクロが定義されてなかったら
#define _TITLE_H_		//2重インクルード防止のマクロ定義

#include "main.h" 

//プロトタイプ宣言
void InitTitle(void);
void UninitTitle(void);
void UpdateTitle(void);
void DrawTitle(void);

#endif