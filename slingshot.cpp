//====================
//コイン獲得枚数
//autho　hamadaryuuga 
//====================

#include "game.h"
#include "slingshot.h"
#include "input.h"

static LPDIRECT3DTEXTURE9 s_pTextureSlingshotleft = NULL; //テクスチャのポインタ
static LPDIRECT3DVERTEXBUFFER9 s_pVtxBuffSlingshotleft = NULL; //頂点バッファの設定

static LPDIRECT3DTEXTURE9 s_pTextureSlingshotlight = NULL; //テクスチャのポインタ
static LPDIRECT3DVERTEXBUFFER9 s_pVtxBuffSlingshotlight = NULL; //頂点バッファの設定

static D3DXVECTOR3 s_posSlingshot; //スコアの位置
static int s_nSlingshot, nCounterAnim, nPatternAnim;


//===================
//初期化処理
//===================
void InitSlingshot(void)
{

	LPDIRECT3DDEVICE9  pDevice;
	//int nCntSlingshot;
	//s_nSlingshot = 0;
	s_posSlingshot = D3DXVECTOR3(320.0f, 650.0f, 0.0f);
	//デバイスの取得
	pDevice = GetDevice();

	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/pipo-gwspinitem007.png",
		&s_pTextureSlingshotleft);

	//頂点バッファ
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,//ここ頂点フォーマット
		&s_pVtxBuffSlingshotleft,
		NULL);

	VERTEX_2D*pVtx; //頂点へのポインタ
					//頂点バッファをロックし頂点情報へのポインタを取得
	s_pVtxBuffSlingshotleft->Lock(0, 0, (void**)&pVtx, 0);
	//頂点座標
	pVtx[0].pos = D3DXVECTOR3(s_posSlingshot.x - 20, s_posSlingshot.y - 20, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(s_posSlingshot.x + 20, s_posSlingshot.y - 20, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(s_posSlingshot.x - 20, s_posSlingshot.y + 20, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(s_posSlingshot.x + 20, s_posSlingshot.y + 20, 0.0f);
	
	//RHWの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラーの設定
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//テクスチャの座標設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//頂点バッファをアンロック
	s_pVtxBuffSlingshotleft->Unlock();


	//---------------------
	//みぎの設定
	//---------------------
	s_posSlingshot = D3DXVECTOR3(720.0f, 650.0f, 0.0f);
	
	pDevice = GetDevice();

	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/pipo-gwspinitem007.png",
		&s_pTextureSlingshotlight);

	//頂点バッファ
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,//ここ頂点フォーマット
		&s_pVtxBuffSlingshotlight,
		NULL);

	//VERTEX_2D*pVtx; //頂点へのポインタ
					//頂点バッファをロックし頂点情報へのポインタを取得
	s_pVtxBuffSlingshotlight->Lock(0, 0, (void**)&pVtx, 0);
	//頂点座標
	pVtx[0].pos = D3DXVECTOR3(s_posSlingshot.x - 20, s_posSlingshot.y - 20, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(s_posSlingshot.x + 20, s_posSlingshot.y - 20, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(s_posSlingshot.x - 20, s_posSlingshot.y + 20, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(s_posSlingshot.x + 20, s_posSlingshot.y + 20, 0.0f);
	
	//RHWの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラーの設定
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//テクスチャの座標設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//頂点バッファをアンロック
	s_pVtxBuffSlingshotlight->Unlock();

	

}

//===================
//破棄処理
//===================
void UninitSlingshot(void)
{
	//テクスチャの破棄
	if (s_pTextureSlingshotleft != NULL)
	{
		s_pTextureSlingshotleft->Release();
		s_pTextureSlingshotleft = NULL;
	}

	//頂点バッファの破棄
	if (s_pVtxBuffSlingshotleft != NULL)
	{
		s_pVtxBuffSlingshotleft->Release();
		s_pVtxBuffSlingshotleft = NULL;
	}

	//テクスチャの破棄
	if (s_pTextureSlingshotlight != NULL)
	{
		s_pTextureSlingshotlight->Release();
		s_pTextureSlingshotlight = NULL;
	}

	//頂点バッファの破棄
	if (s_pVtxBuffSlingshotlight != NULL)
	{
		s_pVtxBuffSlingshotlight->Release();
		s_pVtxBuffSlingshotlight = NULL;
	}


}

//===================
//更新処理
//===================
void UpdateSlingshot(void)
{
	if (GetMousePress(MOUSE_INPUT_LEFT))
	{

	}
	if (GetMouseTrigger(MOUSE_INPUT_LEFT))
	{

	}

	VERTEX_2D*pVtx; //頂点へのポインタ
					//頂点バッファをロックし頂点情報へのポインタを取得
	s_pVtxBuffSlingshotleft->Lock(0, 0, (void**)&pVtx, 0);
	//頂点座標
	pVtx[0].pos = D3DXVECTOR3(s_posSlingshot.x - 20, s_posSlingshot.y - 20, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(s_posSlingshot.x + 20, s_posSlingshot.y - 20, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(s_posSlingshot.x - 20, s_posSlingshot.y + 20, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(s_posSlingshot.x + 20, s_posSlingshot.y + 20, 0.0f);

	//頂点バッファをアンロック
	s_pVtxBuffSlingshotleft->Unlock();
}

//===================
//描画処理
//===================
void DrawSlingshot(void)
{
	LPDIRECT3DDEVICE9 pDevice;//デバイスのポインタ
//	int nCntSlingshot;


	pDevice = GetDevice();		//代入

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, s_pVtxBuffSlingshotleft, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, s_pTextureSlingshotleft);

	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,
		0,
		2);

	//---------------------
	//みぎの設定
	//---------------------
	pDevice = GetDevice();		//代入

								//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, s_pVtxBuffSlingshotlight, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, s_pTextureSlingshotlight);

	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,
		0,
		2);

}

