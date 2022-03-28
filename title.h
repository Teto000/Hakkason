//============================
//
// タイトル画面のヘッダー
// Author:hamada ryuuga
//
//============================
#pragma once
#ifndef _TITLE_H_
#define _TITLE_H_

#include"main.h"

#define	MAX_TITLE	(8)

typedef struct
{
	D3DXCOLOR col;		//色
	D3DXCOLOR colSet;	//消すほうの色
	bool nSwitch;		//スイッチ
	int nSelect;		//せレクト
	int degree;			//難易度
}TITLE;

//プロトタイプ宣言
void InitTitle(void);
void UninitTitle(void);
void UpdateTitle(void);
void DrawTitle(void);
int Getdegree(void);


#endif