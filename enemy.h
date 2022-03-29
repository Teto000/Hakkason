//============================
//
// 敵のヘッダー
// Author:Teruto Sato
//
//============================
#ifndef _ENEMY_H_		//このマクロが定義されてなかったら
#define _ENEMY_H_		//2重インクルード防止のマクロ定義

//------------------------
// インクルード
//------------------------
#include "main.h"

//------------------------
// 敵の構造体の定義
//------------------------
typedef struct
{
	D3DXVECTOR3 pos;	//位置
	D3DXVECTOR3 move;	//移動量
	D3DXVECTOR3 rot;	//向き
	int nPlace;			//出現位置
	bool bUse;			//使用しているか
}Enemy;

#define	MAX_ENEMY	(256)	//敵の最大数

//------------------------
// プロトタイプ宣言
//------------------------
void InitEnemy(void);
void UninitEnemy(void);
void UpdateEnemy(void);
void DrawEnemy(void);
void SetEnemy(void);
Enemy *GetEnemy(int a);

#endif