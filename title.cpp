//================================
//
// タイトル画面
// Author:Teruto Sato
//
//================================

//------------------------
// インクルード
//------------------------
#include "tutorial.h"
#include "input.h"
#include "fade.h"
#include "sound.h"
#include "texture.h"

//------------------------
// スタティック変数
//------------------------
static TEXTURE	s_pTexture;		//テクスチャへのポインタ
static LPDIRECT3DVERTEXBUFFER9	s_pVtxBuff = NULL;	//頂点バッファへのポインタ;

//========================
// タイトルの初期化処理
//========================
void InitTitle(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();	//デバイスの取得

	//------------------------
	// テクスチャの読み込み
	//------------------------
	s_pTexture = TEXTURE_TITLE_BG;

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,	//確保するバッファのサイズ
								D3DUSAGE_WRITEONLY,
								FVF_VERTEX_2D,			//頂点フォーマット
								D3DPOOL_MANAGED,
								&s_pVtxBuff,
								NULL);

	//タイトルの位置の設定
	D3DXVECTOR3 pos = D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f);

	VERTEX_2D*pVtx;		//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	s_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//------------------------
	// 頂点情報の設定
	//------------------------
	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(pos.x - SCREEN_WIDTH / 2, pos.y - SCREEN_HEIGHT / 2, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + SCREEN_WIDTH / 2, pos.y - SCREEN_HEIGHT / 2, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - SCREEN_WIDTH / 2, pos.y + SCREEN_HEIGHT / 2, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + SCREEN_WIDTH / 2, pos.y + SCREEN_HEIGHT / 2, 0.0f);

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
	//PlaySound(SOUND_LABEL_BGM001);

	//頂点バッファをアンロックする
	s_pVtxBuff->Unlock();
}

//========================
// タイトルの終了処理
//========================
void UninitTitle(void)
{
	//サウンドの停止
	//StopSound(SOUND_LABEL_SE_NEXT);

	//頂点バッファの破壊
	if (s_pVtxBuff != NULL)
	{
		s_pVtxBuff->Release();
		s_pVtxBuff = NULL;
	}
}

//========================
// タイトルの更新処理
//========================
void UpdateTitle(void)
{
	VERTEX_2D*pVtx;		//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	s_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//画面遷移
	if (GetKeyboardTrigger(DIK_RETURN) == true || GetJoypadTrigger(JOYKEY_A))
	{

		SetFade(MODE_GAME);
	}

	//頂点バッファをアンロックする
	s_pVtxBuff->Unlock();
}

//========================
// タイトルの描画処理
//========================
void DrawTitle(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();	//デバイスの取得

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, s_pVtxBuff, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, GetTexture(s_pTexture));

	//タイトルの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,		//プリミティブの種類
						   0,						//描画する最初の頂点インデックス
						   2);						//描画するプリミティブ数
}