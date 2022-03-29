//============================
//
// 敵の処理
// Author:Teruto Sato
//
//============================

//------------------------
// インクルード
//------------------------
#include "enemy.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "sound.h"
#include "texture.h"

//------------------------
// マクロ定義
//------------------------
#define	MAX_ENEMY	(256)	//敵の最大数

//------------------------
// スタティック変数
//------------------------
static	TEXTURE		s_pTexture;		//テクスチャへのポインタ
static	LPDIRECT3DVERTEXBUFFER9		s_pVtxBuff = NULL;		//頂点バッファへのポインタ

//構造体
static	Enemy s_Enemy[MAX_ENEMY];	//敵の構造体

//========================
// 敵の初期化処理
//========================
void InitEnemy(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//デバイスの取得

	//------------------------
	// テクスチャの読み込み
	//------------------------
	s_pTexture = TEXTURE_RESULT_BG;

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,	//確保するバッファのサイズ
								D3DUSAGE_WRITEONLY,
								FVF_VERTEX_2D,			//頂点フォーマット
								D3DPOOL_MANAGED,
								&s_pVtxBuff,
								NULL);

	VERTEX_2D*pVtx;		//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	s_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//------------------------
	// 敵の構造体の初期化
	//------------------------
	for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	{
		Enemy *enemy = s_Enemy + nCnt;

		enemy->pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//位置
		enemy->fWidth = 0.0f;	//幅
		enemy->fHeight = 0.0f;	//高さ
		enemy->bUse = false;	//使用しているか
	}

	//------------------------
	// 頂点情報の設定
	//------------------------
	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(SCREEN_WIDTH, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f);

	//rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラーの設定
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//サウンドの再生
	//PlaySound(SOUND_LABEL_BGM002);

	//頂点バッファをアンロックする
	s_pVtxBuff->Unlock();
}

//========================
// 敵の終了処理
//========================
void UninitEnemy(void)
{
	//サウンドの停止
	//StopSound();

	//頂点バッファの破壊
	if (s_pVtxBuff != NULL)
	{
		s_pVtxBuff->Release();
		s_pVtxBuff = NULL;
	}
}

//========================
// 敵の更新処理
//========================
void UpdateEnemy(void)
{

}

//========================
// 敵の描画処理
//========================
void DrawEnemy(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//デバイスへのポインタ

	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, s_pVtxBuff, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, GetTexture(s_pTexture));

	//プレイヤーの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,		//プリミティブの種類
						   0,						//描画する最初の頂点インデックス
						   2);						//描画するプリミティブ数
}

//========================
// 敵の設定処理
//========================
void SetEnemy(void)
{
	VERTEX_2D*pVtx;		//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	s_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	{
		Enemy *enemy = s_Enemy + nCnt;

		if (enemy->bUse == false)
		{
			enemy->pos = D3DXVECTOR3(500.0f, 300.0f, 0.0f);		//位置
			enemy->fWidth = 50.0f;	//幅
			enemy->fHeight = 50.0f;	//高さ
			enemy->bUse = true;	//使用しているか

			//頂点座標の設定
			pVtx[0].pos = enemy->pos + D3DXVECTOR3(-enemy->fWidth, -enemy->fHeight, 0.0f);
			pVtx[1].pos = enemy->pos + D3DXVECTOR3(enemy->fWidth, -enemy->fHeight, 0.0f);
			pVtx[2].pos = enemy->pos + D3DXVECTOR3(-enemy->fWidth, enemy->fHeight, 0.0f);
			pVtx[3].pos = enemy->pos + D3DXVECTOR3(enemy->fWidth, enemy->fHeight, 0.0f);

			break;
		}
		pVtx += 4;
	}

	//頂点バッファをアンロックする
	s_pVtxBuff->Unlock();
}