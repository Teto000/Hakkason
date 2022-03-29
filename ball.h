bullet.h
アクセスできるユーザー

千
堺
東
システム プロパティ
種類
テキスト
#ifndef _BULL_H_
#define _BULL_H_

#include"main.h"

#define	MAX_BULL	(4096)
#define	MAX_RECIPE	(5)

//構造体
typedef struct
{
	D3DXVECTOR3 pos;	//位置
	D3DXVECTOR3 move;	//移動量
	int nLife;			//寿命
	bool bUse;		//使用してるかどうか
	int Trigger;   //種類
	int nType;
	float fSiz; //サイズ
	int Move2;
}Bull;

//プロトタイプ宣言
void InitBall(void);
void UninitBall(void);
void UpdateBall(void);
void DrawBall(void);
void SetBall(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, int nType, float fSiz);

#endif #pragma once
